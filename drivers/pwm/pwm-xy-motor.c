/*
 * drivers/pwm/pwm-sunxi-dev.c
 *
 * Allwinnertech pulse-width-modulation controller driver
 *
 * Copyright (C) 2019 AllWinner
 *
 *
 * This file is licensed under the terms of the GNU General Public
 * License version 2. This program is licensed "as is" without any
 * warranty of any kind, whether express or implied.
 */
#include <asm/io.h>
#include <linux/cdev.h>
#include <linux/clk.h>
#include <linux/delay.h>
#include <linux/device.h>
#include <linux/fs.h>
#include <linux/gpio.h>
#include <linux/init.h>
#include <linux/interrupt.h>
#include <linux/kernel.h>
#include <linux/miscdevice.h>
#include <linux/module.h>
#include <linux/of_gpio.h>
#include <linux/pinctrl/consumer.h>
#include <linux/platform_device.h>
#include <linux/pwm.h>
#include <linux/slab.h>
#include <linux/uaccess.h>

#define PWM_ERR(fmt, arg...) pr_err("%s()%d - " fmt, __func__, __LINE__, ##arg)
#define DEBUG
#ifdef DEBUG
#define MOTOR_DEBUG(fmt, arg...)                                               \
	printk("%s()%d - " fmt, __func__, __LINE__, ##arg)
#else
#define MOTOR_DEBUG(fmt, arg...)
#endif

/* commands' magic number */
#define SSP_DRV_MAGICNUM 'm'
/* commands' number */
#define NR_SSP_MOTOR_POSITION_GET 1
#define NR_SSP_DIR_SPEED_SET 2
#define NR_SSP_MOTOR_STOP 3
#define NR_SSP_MOTOR_RUNNED_TIME_GET 4
#define NR_SSP_MOTOR_STEP_SPEED_SET 5

/* cmd maker */
#define SSP_IOCTL_CMD_MAKE(cmd) _IO(SSP_DRV_MAGICNUM, cmd)

/* export */
/* cmds */
#define SSP_MOTOR_POSITION_GET SSP_IOCTL_CMD_MAKE(NR_SSP_MOTOR_POSITION_GET)
#define SSP_DIR_SPEED_SET SSP_IOCTL_CMD_MAKE(NR_SSP_DIR_SPEED_SET)
#define SSP_MOTOR_STOP SSP_IOCTL_CMD_MAKE(NR_SSP_MOTOR_STOP)
#define SSP_MOTOR_RUNNED_TIME_GET                                              \
	SSP_IOCTL_CMD_MAKE(NR_SSP_MOTOR_RUNNED_TIME_GET)
#define SSP_MOTOR_STEP_SPEED_SET SSP_IOCTL_CMD_MAKE(NR_SSP_MOTOR_STEP_SPEED_SET)

/*--------------logic contril parameters defined--------------*/
/* motor_ab -->x ; motor_cd-->y*/
#define MOTOR_AB 1
#define MOTOR_CD 2

/* step range set, 24BYJ48-550 motor: 4096 setp/r */
//need to 8 step align
#define AB_STEPS 8192
#define CD_STEPS 1088

/*define direction*/
#define X_MOTOR_FORWARD 0
#define X_MOTOR_BACKWARD 1
#define Y_MOTOR_FORWARD 1
#define Y_MOTOR_BACKWARD 0

#define DIR_NONE 0
#define DIR_UP 1
#define DIR_DOWN 2
#define DIR_LEFT 4
#define DIR_RIGHT 3

#define SPEED_NUM_MAX 11
/*This array can get motor speed (ns/step) */
int motor_speed_table[SPEED_NUM_MAX] = {1465, 1413, 1361,
					1309, 1257, 1205,
					1153, 1101, 1049,
					997,  997}; /* ns/step */

/*--------------struct defined-------------------*/
struct pwm_config_group {
	int group_channel;
	int group_run_count;
	int pwm_polarity;
	int pwm_period;
};

struct motor_pwm_dev {
	struct device *dev;
	int x_limit_gpio;
	int x_init;
	int y_init;
	int init_flag;
	struct motor_status *ab;
	struct motor_status *cd;
};

/* this struct is motor runing status*/
struct motor_status {
	int index;
	int direction;
	int speed;
	int is_running;
	int max_step;
	int irq;
	struct timeval start_time;
	struct timeval end_time;
	struct hrtimer timer;
	struct work_struct init_work;
	struct work_struct motor_work;
};

struct pzt_ctrl {
	/* x,y is position,
	 * fat left meant x =0 , to right will x++
	 * fat up meant y =0 , to down will y++ */
	int x;
	int y;
	/* dir is direction:
	 * 0:none
	 * 1:up
	 * 2:down
	 * 3:right
	 * 4:left*/
	unsigned int dir;
	/*set motor speed 0~10*/
	unsigned int speed;
	/*motor running time ,it can conversion step*/
	unsigned int run_time;
	/*motor run status
	 * 0: stop
	 * 1: running*/
	unsigned int is_running;
	/* this will report motor running time of sum
	 * motor_runned_time[0] : ab motor
	 * motor_runned_time[0] : cd motor*/
	unsigned int motor_runned_time[2];
};

/*--------------global variable-------------------*/
struct motor_pwm_dev *motor_pwm_dev;

struct motor_status motor_status_ab = {
	.index = MOTOR_AB,
	.max_step = AB_STEPS,
};
struct motor_status motor_status_cd = {
	.index = MOTOR_CD,
	.max_step = CD_STEPS
};

struct pzt_ctrl ptz_ctrl_k2u;
struct pzt_ctrl ptz_ctrl_u2k;

struct pwm_device *pwm[8] = {NULL};
/*--------------motor pwm interface-------------------*/
static int motor_start(int index, int step, int polarity, int step_ns)
{

	unsigned int ret, i, group;
	unsigned char name[30];
	struct pwm_config_group *code_group;
	struct pwm_config_group config = {1, 1, 0, 1000};

	config.group_channel = index;
	 /* because motor will run 8 step earch period */
	config.group_run_count = step / 8;
	config.pwm_polarity = polarity;
	config.pwm_period = step_ns * 8 / 10;

	code_group = &config;
	group = code_group->group_channel;
	if (group < 1) {
		return -EINVAL;
	}

	for (i = 4 * (group - 1); i < 4 * group; i++) {
		sprintf(name, "sunxi_pwm%d", i);
		if (pwm[i] == NULL) {
			pwm[i] = pwm_request(i, name);

			if (IS_ERR_OR_NULL(pwm[i])) {
				PWM_ERR("pwm err\n");
				return -ENODEV;
			}
		}

		pwm[i]->chip_data = code_group;

		 /* the argument can’t be same as the first */
		ret = pwm_config(pwm[i], 0, 1);
		if (ret < 0) {
			PWM_ERR("pwm ioctl err0\n");
			return -EINVAL;
		}
		ret = pwm_config(pwm[i], 0x2ee, 0x7cf);
		if (ret < 0) {
			PWM_ERR("pwm ioctl err\n");
			return -EINVAL;
		}

		pwm_enable(pwm[i]);
	}
	return 0;
}

static int motor_stop(int index)
{
	int i;
	unsigned int group;
	struct pwm_config_group *code_group;
	struct pwm_config_group config = {1, 1, 0, 1000};

	config.group_channel = index;

	code_group = &config;
	group = code_group->group_channel;

	if (group < 1) {
		PWM_ERR("group para err\n");
		return -EINVAL;
	}

	for (i = 4 * (group - 1); i < 4 * group; i++) {
		if (pwm[i] == NULL) {
			PWM_ERR("PWM[%d] is NULL\n", i);
			return -1;
		}
		pwm[i]->chip_data = code_group;

		if (pwm[i]) {
			pwm_disable(pwm[i]);
		}
	}
	return 0;
}

/*-------------motor logic control interface------------------*/
static int xy_motor_position_init(void)
{
#if 0
	/* let x/y to find 0 postition*/
	schedule_work(&motor_pwm_dev->ab->init_work);
	schedule_work(&motor_pwm_dev->cd->init_work);
#endif
	return 0;
}

static int xy_motor_stop_and_get_position(int index)
{
	struct motor_status *status;
	unsigned int time;
	unsigned int max_time;
	int p_offset;
#if 0
	if (!motorPwmPev->init_flag) {
		pr_err("motor position was not init \n");
		return -1;
	}
#endif
	if (index == MOTOR_AB)
		status = &motor_status_ab;
	else if (index == MOTOR_CD)
		status = &motor_status_cd;
	else
		return -1;

	/*checking the status*/
	if (!status->is_running || !status->start_time.tv_usec)
		return -1;

	/*stop timer*/
	hrtimer_cancel(&status->timer);

	/*stop motor*/
	motor_stop(status->index);

	/* get end time */
	do_gettimeofday(&status->end_time);

	/* get motor running time ns*/
	time = (status->end_time.tv_sec - status->start_time.tv_sec) * 1000000 +
			(status->end_time.tv_usec - status->start_time.tv_usec);

	/*get position_offset = time / speed*/
	p_offset = time / motor_speed_table[status->speed];

	/* update data */
	if (status->index == MOTOR_AB) {
		if (status->direction == X_MOTOR_FORWARD)
			ptz_ctrl_k2u.x += p_offset;
		else
			ptz_ctrl_k2u.x -= p_offset;

#ifdef GPIO_LIMIT_DET
		/* x limit checking */
		if (!gpio_get_value_cansleep(motor_pwm_dev->x_limit_gpio)) {
			/* x already in limit positions*/
			if (status->direction == Y_MOTOR_FORWARD)
				ptz_ctrl_k2u.x = status->max_step;
			else
				ptz_ctrl_k2u.x = 0;
		}
#else
		/* x limit checking */
		/* x already in limit positions*/
		max_time = status->max_step * motor_speed_table[motor_status_ab.speed];
		if (max_time == time || max_time > time)
			if (status->direction == X_MOTOR_FORWARD)
				ptz_ctrl_k2u.x = status->max_step;
			else
				ptz_ctrl_k2u.x = 0;
#endif
		ptz_ctrl_k2u.motor_runned_time[0] = time / 1000;

	} else if (status->index == MOTOR_CD) {
		if (status->direction == Y_MOTOR_FORWARD)
			ptz_ctrl_k2u.y += p_offset;
		else
			ptz_ctrl_k2u.y -= p_offset;

		/* y limit checking */
		/* y already in limit positions*/
		max_time = status->max_step * motor_speed_table[motor_status_cd.speed];
		if (max_time == time || max_time > time)
			if (status->direction == Y_MOTOR_FORWARD)
				ptz_ctrl_k2u.y = status->max_step;
			else
				ptz_ctrl_k2u.y = 0;

		ptz_ctrl_k2u.motor_runned_time[1] = time / 1000;
	}

	/*clean status*/
	status->start_time.tv_usec = 0;
	status->end_time.tv_usec = 0;
	status->is_running = 0;

	MOTOR_DEBUG("stop motor :%d, cost time:%d ms \n", status->index, (time/1000));
	MOTOR_DEBUG("Now x:%d, y:%d\n", ptz_ctrl_k2u.x, ptz_ctrl_k2u.y);
	return 0;
}

#if 0
static int xy_motor_position_set(int index, int step_pos)
{
	int ret;
	int move_step;

	if (!motor_pwm_dev->init_flag) {
		return -1;
		pr_err("motor position was not init \n");
	}

	/*first stop motor*/
	motor_stop(index);

	if (index == MOTOR_AB) {
		move_step = step_pos - ptz_ctrl_k2u.x;
		/*save the x final position*/
		ptz_ctrl_k2u.x = step_pos;
	} else if (index == MOTOR_CD) {
		move_step = step_pos - ptz_ctrl_k2u.y;
		/*save the y final position*/
		ptz_ctrl_k2u.y = step_pos;
	} else {
		return -1;
	}

	if (move_step < 0)
		if (index == MOTOR_AB)
			motor_start(index, (move_step * -1), X_MOTOR_FORWARD);
		else
			motor_start(index, (move_step * -1), Y_MOTOR_FORWARD);

	else
		if (index == MOTOR_AB)
			motor_start(index, move_step, X_MOTOR_BACKWARD);
		else
			motor_start(index, move_step, Y_MOTOR_BACKWARD);

	return 0;
}
#endif

static int xy_motor_enable_by_time(int index, int set_dir, unsigned int ms)
{
	struct motor_status *motor_status;
#if 0
	if (!motorPwmPev->init_flag) {
		pr_err("motor position was not init \n");
		return -1;
	}
#endif
	if (index == MOTOR_AB)
		motor_status = &motor_status_ab;
	else if (index == MOTOR_CD)
		motor_status = &motor_status_cd;
	else
		return -1;

#if 0
	//	MOTOR_DEBUG("set before x:%d, y:%d \n", ptz_ctrl_k2u.x,
	//ptz_ctrl_k2u.y);
	/* x/y limit checking */
	//	if (motor_status->index == MOTOR_AB) {
	//		/* x already in limit positions*/
	//		if(!gpio_get_value_cansleep(motor_pwm_dev->x_limit_gpio))
	//{
	//			/*x = 0 limit*/
	//			if (ptz_ctrl_k2u.x < 3 && set_dir ==
	//X_MOTOR_FORWARD)
	//				return 0;
	//			/*x = max limit*/
	//			else if (set_dir == X_MOTOR_BACKWARD)
	//				return 0;
	//		}
	//	} else {
	//		/*y has not limit detect, so checking y val whether in
	//limit position*/
	//		if (ptz_ctrl_k2u.y <= 0 && set_dir == Y_MOTOR_BACKWARD)
	//			return 0;
	//		else if (ptz_ctrl_k2u.y >= motor_status->max_step &&
	//						      set_dir ==
	//Y_MOTOR_FORWARD)
	//			return 0;
	//	}
#endif

	MOTOR_DEBUG("dir %d ,timer set ms:%d \n", set_dir, ms);
	/*checking is running?*/
	if (!motor_status->is_running) {
		/*start timer*/
		hrtimer_start(&motor_status->timer, ms_to_ktime(ms),
			      HRTIMER_MODE_REL);

		/* get start time & update motor status*/
		do_gettimeofday(&motor_status->start_time);
		motor_status->direction = set_dir;
		motor_status->is_running = 1;

		/*let motor move ,and stop when time out*/
		motor_start(motor_status->index, motor_status->max_step,
			    set_dir, motor_speed_table[motor_status->speed]);

	} else {
		/*the motor is running, so need to change*/
		if (motor_status->direction == set_dir) {
			/*cancle timer*/
			hrtimer_cancel(&motor_status->timer);
			/* restart timer */
			hrtimer_start(&motor_status->timer, ms_to_ktime(ms),
				      HRTIMER_MODE_REL);
		} else { /*need to change dir*/
			/*stop and get now position*/
			xy_motor_stop_and_get_position(motor_status->index);

			/*start timer*/
			hrtimer_start(&motor_status->timer, ms_to_ktime(ms),
				      HRTIMER_MODE_REL);

			/* get start time & update motor status*/
			do_gettimeofday(&motor_status->start_time);
			motor_status->direction = set_dir;
			motor_status->is_running = 1;

			/*let motor move ,and stop when time out*/
			motor_start(motor_status->index, motor_status->max_step,
				    set_dir,
				    motor_speed_table[motor_status->speed]);
		}
	}

#ifdef GPIO_LIMIT_DET
	/*To try the motor was not move when start motor.*/
	if (motor_status->index == MOTOR_AB) {
		/* x already in limit positions*/
		if (!gpio_get_value_cansleep(motor_pwm_dev->x_limit_gpio)) {
			/*wait 10 step, and try the limit det again*/
			msleep(motor_speed_table[motor_status->speed] * 10);
			if (!gpio_get_value_cansleep(
				motor_pwm_dev->x_limit_gpio))
				/*motor can not move, because it was in limit
				 * position*/
				xy_motor_stop_and_get_position(
				    motor_status->index);
		}
	}
#endif

	return 0;
}

static int xy_motor_speed_set(int index, int speed)
{
	struct motor_status *motor_status;

	if (index == MOTOR_AB)
		motor_status = &motor_status_ab;
	else if (index == MOTOR_CD)
		motor_status = &motor_status_cd;
	else
		return -1;

	if (speed >= SPEED_NUM_MAX) {
		pr_err("not support the speed \n");
		return -1;
	}

	/*first stop motor*/
	xy_motor_stop_and_get_position(motor_status->index);

	MOTOR_DEBUG("set %d motor speed %d \n", index, speed);
	motor_status->speed = speed;

	return 0;
}

static void xy_init_work(struct work_struct *work)
{
	unsigned int time;
	struct motor_status *status =
	    container_of(work, struct motor_status, init_work);

	/*motor fast move to x or y = 0*/
	xy_motor_speed_set(status->index, 0);

	if (status->index == MOTOR_AB) {
		motor_start(status->index, status->max_step, X_MOTOR_BACKWARD,
			    motor_speed_table[status->speed]);

#ifdef GPIO_LIMIT_DET
		/*first run a moment*/
		msleep(motor_speed_table[status->speed] * 2 / 1000);
		/* let motor_ab touch limit detectiong*/
		MOTOR_DEBUG(
		    "gpio val: %d \n",
		    gpio_get_value_cansleep(motor_pwm_dev->x_limit_gpio));
		while (gpio_get_value_cansleep(motor_pwm_dev->x_limit_gpio))
			msleep(1);
#else
		/* motor_cd has not gpio to detect, so will go all step*/
		time = status->max_step * motor_speed_table[motor_status_ab.speed] / 1000;
		MOTOR_DEBUG("x need to %d ms time to init \n", time);
		msleep(time);
#endif

		motor_pwm_dev->x_init = 1;
		ptz_ctrl_k2u.x = 0;
		MOTOR_DEBUG("x_work finish\n");
	} else {
		motor_start(status->index, status->max_step, Y_MOTOR_BACKWARD,
			    motor_speed_table[status->speed]);
		/* motor_cd has not gpio to detect, so will go all step*/
		time = status->max_step * motor_speed_table[motor_status_cd.speed] / 1000;
		xy_motor_enable_by_time(status->index, Y_MOTOR_BACKWARD, time);
		MOTOR_DEBUG("y need to %d ms time to init \n", time);
		msleep(time);

		motor_pwm_dev->y_init = 1;
		ptz_ctrl_k2u.y = 0;
		MOTOR_DEBUG("y_work finish\n");
	}

	/* if x and y are both init, will set init_flag*/
	if (motor_pwm_dev->x_init && motor_pwm_dev->y_init)
		motor_pwm_dev->init_flag = 1;
}

#ifdef GPIO_LIMIT_DET
static irqreturn_t motor_gpio_irq(int irq, void *dev_id)
{
	MOTOR_DEBUG("into gpio irq \n");
	/*stop the motor and get position*/
	xy_motor_stop_and_get_position(MOTOR_AB);
	return IRQ_HANDLED;
}
#endif

static void motor_irq_wrok(struct work_struct *work)
{
	struct motor_status *status =
	    container_of(work, struct motor_status, motor_work);

	MOTOR_DEBUG("motor%d into irq work \n", status->index);
	/*stop the motor and get position*/
	xy_motor_stop_and_get_position(status->index);
}

enum hrtimer_restart motor_hrtimer_func(struct hrtimer *timer)
{
	struct motor_status *status =
	    container_of(timer, struct motor_status, timer);

	schedule_work(&status->motor_work);

	return HRTIMER_NORESTART;
}

static long ssp_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
	unsigned int __user *argp = (unsigned int __user *)arg;
	int set_dir;

	MOTOR_DEBUG("into ioctrl \n");
	switch (cmd) {
	case SSP_MOTOR_POSITION_GET:
		/* ensure xy is within the safe area */
		if (ptz_ctrl_k2u.x > AB_STEPS) {
			ptz_ctrl_k2u.x = AB_STEPS;
		} else if (ptz_ctrl_k2u.x < 0) {
			ptz_ctrl_k2u.x = 0;
		}
		if (ptz_ctrl_k2u.y > CD_STEPS) {
			ptz_ctrl_k2u.y = CD_STEPS;
		} else if (ptz_ctrl_k2u.y < 0) {
			ptz_ctrl_k2u.y = 0;
		}

		if (copy_to_user(argp, &ptz_ctrl_k2u,
				 sizeof(struct pzt_ctrl))) {
			pr_err("ssp---copy ptz_ctrl to user args failed!\n");
			return -EFAULT;
		}
		break;

	case SSP_MOTOR_RUNNED_TIME_GET:
		if (copy_to_user(argp, &ptz_ctrl_k2u,
				 sizeof(struct pzt_ctrl))) {
			pr_err("ssp---copy ptz_ctrl to user args failed!\n");
			return -EFAULT;
		}

		ptz_ctrl_k2u.motor_runned_time[0] = 0;
		ptz_ctrl_k2u.motor_runned_time[1] = 0;
		break;

	case SSP_DIR_SPEED_SET:
		MOTOR_DEBUG("%d motor move by time \n", ptz_ctrl_u2k.dir);
		if (copy_from_user(&ptz_ctrl_u2k, argp,
				   sizeof(struct pzt_ctrl))) {
			pr_err("ssp---copy ptz_ctrl args from user failed!\n");
			return -EFAULT;
		}

		if (ptz_ctrl_u2k.dir == 0)
			break;

		if (ptz_ctrl_u2k.run_time == 0) {
			if ((DIR_RIGHT == ptz_ctrl_u2k.dir) ||
			    (DIR_LEFT == ptz_ctrl_u2k.dir)) {
				ptz_ctrl_u2k.run_time =
				    AB_STEPS *
				    motor_speed_table[motor_status_ab.speed] / 1000;
			} else {
				ptz_ctrl_u2k.run_time =
				    CD_STEPS *
				    motor_speed_table[motor_status_cd.speed] / 1000;
			}
			/* set speed to slow */
			ptz_ctrl_u2k.speed = 10;
		}

		if (ptz_ctrl_u2k.speed > SPEED_NUM_MAX)
			ptz_ctrl_u2k.speed = SPEED_NUM_MAX - 1;
		MOTOR_DEBUG("set speed : %d \n", ptz_ctrl_u2k.speed);



		/*which motor ?*/
		if (ptz_ctrl_u2k.dir > 0 && ptz_ctrl_u2k.dir < 3) { /*motor_cd*/

			motor_status_cd.speed = ptz_ctrl_u2k.speed;

			if (ptz_ctrl_u2k.dir == 1)
				set_dir = Y_MOTOR_BACKWARD;
			else
				set_dir = Y_MOTOR_FORWARD;

			/*enable motor start by time*/
			xy_motor_enable_by_time(MOTOR_CD, set_dir,
						ptz_ctrl_u2k.run_time);

		} else if (ptz_ctrl_u2k.dir > 2) { /*motor_ab*/

			motor_status_ab.speed = ptz_ctrl_u2k.speed;

			if (ptz_ctrl_u2k.dir == 3)
				set_dir = X_MOTOR_FORWARD;
			else
				set_dir = X_MOTOR_BACKWARD;

			/*enable motor start by time*/
			xy_motor_enable_by_time(MOTOR_AB, set_dir,
						ptz_ctrl_u2k.run_time);
		}

		break;

	case SSP_MOTOR_STOP:
		ptz_ctrl_u2k.run_time = 0;
		MOTOR_DEBUG("stop morot \n");
		xy_motor_stop_and_get_position(MOTOR_AB);
		xy_motor_stop_and_get_position(MOTOR_CD);
		break;

	case SSP_MOTOR_STEP_SPEED_SET:
		if (copy_from_user(&ptz_ctrl_u2k, argp,
				   sizeof(struct pzt_ctrl))) {
			pr_err("ssp---copy ptz_ctrl args from user failed!\n");
			return -EFAULT;
		}
		xy_motor_speed_set(MOTOR_AB, ptz_ctrl_u2k.speed);
		xy_motor_speed_set(MOTOR_CD, ptz_ctrl_u2k.speed);

		break;

	default:
		pr_err("ssp---ssp_ioctl, No such ssp command %#x!\n", cmd);
		return -1;
	}

	MOTOR_DEBUG("finish motor ioctrl \n");
	return 0;
}

static int ssp_open(struct inode *inode, struct file *file)
{
	MOTOR_DEBUG("now, init the motor\n");
	memset(&ptz_ctrl_k2u, 0, sizeof(struct pzt_ctrl));
	xy_motor_position_init();
	return 0;
}

static int ssp_close(struct inode *inode, struct file *file)
{

	return 0;
}

struct file_operations ssp_fops = {.owner = THIS_MODULE,
				   .unlocked_ioctl = ssp_ioctl,
				   .open = ssp_open,
				   .release = ssp_close};

static struct miscdevice ssp_dev = {
    .minor = MISC_DYNAMIC_MINOR, .name = "ssp", .fops = &ssp_fops,
};

static int xy_motor_driver_probe(struct platform_device *pdev)
{
	int ret;
	struct motor_pwm_dev *motor_dev;

	motor_dev = kzalloc(sizeof(struct motor_pwm_dev), GFP_KERNEL);
	if (!motor_dev)
		return -ENOMEM;

	motor_pwm_dev = motor_dev;

	platform_set_drvdata(pdev, motor_dev);

	/* set init status to null*/
	motor_dev->x_init = 0;
	motor_dev->y_init = 0;
	motor_dev->init_flag = 0;
	motor_dev->ab = &motor_status_ab;
	motor_dev->cd = &motor_status_cd;

#ifdef GPIO_LIMIT_DET
	struct device_node *np = pdev->dev.of_node;

	/* get and set gpio to input mode*/
	motor_dev->x_limit_gpio = of_get_named_gpio(np, "xlimit-gpios", 0);
	if (motor_dev->x_limit_gpio < 0) {
		pr_err("can not get xlimit gpios");
	}

	if (!gpio_is_valid(motor_dev->x_limit_gpio)) {
		pr_err("xlimit-gpios is invalid \n");
		goto error;
	}
	if (devm_gpio_request(&pdev->dev, motor_dev->x_limit_gpio, "motor")) {
		pr_err("failed to request gpio\n");
		goto error;
	}

	gpio_direction_input(motor_dev->x_limit_gpio);

	/*to request x irq*/
	motor_pwm_dev->ab->irq = gpio_to_irq(motor_dev->x_limit_gpio);
	ret = request_irq(motor_pwm_dev->ab->irq, motor_gpio_irq,
			  IRQF_TRIGGER_FALLING, "x_motor", &pdev->dev);
	if (ret) {
		pr_err("reques x motor erro \n");
		goto error;
	}

	enable_irq_wake(motor_pwm_dev->ab->irq);
#endif

	ret = misc_register(&ssp_dev);
	if (0 != ret) {
		pr_err("ssp---hi_ssp_init: register ssp_0 device failed! \n");
		goto error;
	}

	/*init workqueue*/
	INIT_WORK(&motor_pwm_dev->ab->init_work, xy_init_work);
	INIT_WORK(&motor_pwm_dev->cd->init_work, xy_init_work);
	INIT_WORK(&motor_pwm_dev->ab->motor_work, motor_irq_wrok);
	INIT_WORK(&motor_pwm_dev->cd->motor_work, motor_irq_wrok);

	/*init timer*/
	hrtimer_init(&motor_status_ab.timer, CLOCK_MONOTONIC, HRTIMER_MODE_REL);
	motor_status_ab.timer.function = motor_hrtimer_func;
	hrtimer_init(&motor_status_cd.timer, CLOCK_MONOTONIC, HRTIMER_MODE_REL);
	motor_status_cd.timer.function = motor_hrtimer_func;

	pr_err("ssp---hi_ssp_init ok!\n");
	return 0;

error:
	kfree(motor_dev);
	return -1;
}

static int xy_motor_driver_remove(struct platform_device *pdev)
{
	int i;
	printk("ssp---hi_ssp_exit \n");

	/*free pwm*/
	for (i = 0; i < 8; i++) {
		if (pwm[i] != NULL) {
			pwm_free(pwm[i]);
			pwm[i] = NULL;
		}
	}

	misc_deregister(&ssp_dev);

#ifdef GPIO_LIMIT_DET
	free_irq(motor_pwm_dev->ab->irq, &pdev->dev);

	gpio_free(motor_pwm_dev->x_limit_gpio);
#endif

	cancel_work_sync(&motor_pwm_dev->ab->init_work);
	cancel_work_sync(&motor_pwm_dev->cd->init_work);
	cancel_work_sync(&motor_pwm_dev->ab->motor_work);
	cancel_work_sync(&motor_pwm_dev->cd->motor_work);

	kfree(motor_pwm_dev);
	return 0;
}

static const struct of_device_id xy_pwm_motor_dt_ids[] = {
	{.compatible = "xy,pwm_motor"},
	{},
};

static struct platform_driver sunxi_led_driver = {
    .probe = xy_motor_driver_probe,
    .remove = xy_motor_driver_remove,
    .driver = {
	    .name = "xy-pwm-motor",
	    .owner = THIS_MODULE,
	    .of_match_table = xy_pwm_motor_dt_ids,
	},
};

module_platform_driver(sunxi_led_driver);

MODULE_AUTHOR("K.L <wuguanling@allwinnertech.com>");
MODULE_DESCRIPTION("PWM ctrl MOROT");
MODULE_LICENSE("GPL");
