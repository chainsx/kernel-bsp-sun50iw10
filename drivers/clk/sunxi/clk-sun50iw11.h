/*
 * Copyright (C) 2013 Allwinnertech, huanghuafeng <huafenghuang@allwinnertech.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * Adjustable factor-based clock implementation
 */
#ifndef __MACH_SUNXI_CLK_SUN50IW11_H
#define __MACH_SUNXI_CLK_SUN50IW11_H

#include <linux/clk-provider.h>
#include <linux/clkdev.h>
#include <linux/io.h>
#include "clk-factors.h"



#define BUS_GATE2	    0x0068

#define IR0_CFG		    0x00D0

#define BUS_RST3	    0x02D0
/* PRCM PLL Register List */
#define PLL_CPU             0x1000
#define PLL_PERIPH0         0x1010
#define PLL_AUDIO0          0x1020
#define PLL_AUDIO1          0x1030

#define PLL_PERI0PAT0       0x1110
#define PLL_PERI0PAT1       0x1114
#define PLL_AUDIO0PAT0      0x1120
#define PLL_AUDIO0PAT1      0x1124
#define PLL_AUDIO1PAT0      0x1130
#define PLL_AUDIO1PAT1      0x1134

/* CCMU Register List */
#define CPU_CFG             0x0500
#define PSI_CFG             0x0510
#define AHB_CFG             0x0510
#define APB1_CFG            0x0520
#define APB2_CFG            0x0524
#define MBUS_CFG            0x0540

/* Accelerator */
#define CE_CFG              0x0680
#define CE_GATE             0x068C
#define AIPU_CFG            0x06F0
#define AIPU_GATE           0x06FC

/* SYS Resource */
#define DMA_GATE            0x070C
#define MSGBOX_GATE         0x071C
#define SPINLOCK_GATE       0x072C
#define HSTIMER_GATE        0x073C
#define AVS_GATE            0x0740
#define DBGSYS_GATE         0x078C
#define PSI_GATE            0x079C
#define PWM_GATE            0x07AC

/* Storage Medium */
#define DRAM_CFG            0x0800
#define MBUS_GATE           0x0804
#define DRAM_GATE           0x080C
#define NAND0_CFG           0x0810
#define NAND1_CFG           0x0814
#define NAND_GATE           0x082C
#define SMHC0_CFG           0x0830
#define SMHC1_CFG           0x0834
#define SMHC_GATE           0x084C

/* Common Interface */
#define UART_GATE           0x090C
#define TWI_GATE            0x091C
#define SCR_GATE            0x093C
#define SPI0_CFG            0x0940
#define SPI1_CFG            0x0944
#define SPI_GATE            0x096C
#define GMAC0_25M_CFG       0x0970
#define GMAC_GATE           0x097C
#define IRRX_CFG            0x0990
#define IRRX_GATE           0x099C
#define IRTX_CFG            0x09C0
#define IRTX_GATE           0x09CC
#define I2S0_CFG            0x0A10
#define I2S1_CFG            0x0A14
#define I2S2_CFG            0x0A18
#define I2S_GATE            0x0A1C
#define SPDIF_CFG           0x0A20
#define SPDIF_GATE          0x0A2C
#define USB0_CFG            0x0A70
#define USB1_CFG            0x0A74
#define USB_GATE            0x0A8C
#define LEDC_CFG            0x0BF0
#define LEDC_GATE           0x0BFC

#define SUNXI_CLK_MAX_REG   0x0BFC

/* PRCM Register List */
#define CPUS_AHBS_CFG       0x0000
#define CPUS_APBS0_CFG      0x000C
#define CPUS_APBS1_CFG      0x0010
#define CPUS_LOCKDG_CFG     0x0020
#define CPUS_DG_CFG         0x0024
#define CPUS_LPSD_CFG       0x00D0
#define CPUS_MAD_GATE       0x00DC
#define CPUS_GPADC_GATE     0x00EC
#define CPUS_THS_GATE       0x00FC
#define CPUS_DMA_GATE       0x010C
#define CPUS_TIMER_GATE     0x011C
#define CPUS_TWDOG_GATE     0x012C
#define CPUS_PWM_CFG        0x0130
#define CPUS_PWM_GATE       0x013C
#define CODEC_ADC_CFG       0x0140
#define CODEC_DAC_CFG       0x0144
#define CODEC_GATE          0x014C
#define CPUS_DMIC_CFG       0x0150
#define CPUS_DMIC_GATE      0x015C
#define CPUS_LRADC_GATE     0x016C
#define CPUS_I2S0_CFG       0x0170
#define I2S0_ASRC_CFG       0x0174
#define CPUS_I2S1_CFG       0x0178
#define CPUS_I2S_GATE       0x017C
#define CPUS_UART_GATE      0x018C
#define CPUS_TWI_GATE       0x019C
#define CPUS_PPU_GATE       0x01AC
#define CPUS_DSP_GATE       0x01BC
#define CPUS_IRRX_CFG       0x01C0
#define CPUS_IRRX_GATE      0x01CC
#define CPUS_MSGBOX_GATE    0x01DC
#define CPUS_SPINLOCK_GATE  0x01EC
#define CPUS_DSP_SRAM_GATE  0x01FC
#define CPUS_RTC_GATE       0x020C
#define CPUS_PSARM_CFG      0x0210
#define CPUS_PSARM_GATE     0x021C
#define CPUS_CPUCFG_GATE    0x022C
#define CPUS_CLK_MAX_REG    0x022C

/* RTC Register List */
#define LOSC_OUT_GATE       0x0060
#define DCXO_OUT_CFG        0x0160
#define RTC_SPI_CFG         0x0310

#define F_N8X8_M0X2_P16x2(nv, mv, pv)      (FACTOR_ALL(nv, 8, 8, 0, 0, 0, mv, 0, 2, pv, 16, 2, 0, 0, 0, 0, 0, 0))
#define F_N8X8(nv)                         (FACTOR_ALL(nv, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0))
#define F_N8X8_M1X1_P16x3(nv, mv, pv)      (FACTOR_ALL(nv, 8, 8, 0, 0, 0, mv, 1, 1, pv, 16, 3, 0, 0, 0, 0, 0, 0))
#define F_N8X8_D1V1X1_D2V0X1(nv, d1v, d2v) (FACTOR_ALL(nv, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, d1v, 1, 1, d2v, 0, 1))
#define F_N8X8_D1V1X1(nv, d1v)             (FACTOR_ALL(nv, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, d1v, 1, 1, 0, 0, 0))
#define F_N8X8_D1V4X2_D2V0X2(nv, d1v, d2v) (FACTOR_ALL(nv, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, d1v, 4, 2, d2v, 0, 2))
#define F_N8X8_P16X6_D1V1X1_D2V0X1(nv, pv, d1v, d2v) (FACTOR_ALL(nv, 8, 8, 0, 0, 0, 0, 0, 0, pv, 16, 6, d1v, 1, 1, d2v, 0, 1))

#define PLLCPU(n, freq)        {F_N8X8(n), freq}
#define PLLDDR(n, d1, d2, freq)      {F_N8X8_D1V1X1_D2V0X1(n, d1, d2), freq}
#define PLLPERIPH0(n, m, p, freq)    {F_N8X8_M1X1_P16x3(n, m, p), freq}
#define PLLPERIPH1(n, d1, d2, freq)  {F_N8X8_D1V1X1_D2V0X1(n, d1, d2), freq}
#define PLLGPU(n, d1, d2, freq)      {F_N8X8_D1V1X1_D2V0X1(n, d1, d2), freq}
#define PLLVIDEO0(n, d1, freq)       {F_N8X8_D1V1X1(n, d1), freq}
#define PLLVIDEO1(n, d1, freq)       {F_N8X8_D1V1X1(n, d1), freq}
#define PLLVIDEO2(n, d1, freq)       {F_N8X8_D1V1X1(n, d1), freq}
#define PLLVE(n, d1, d2, freq)       {F_N8X8_D1V1X1_D2V0X1(n, d1, d2), freq}
#define PLLCOM(n, d1, d2, freq)       {F_N8X8_D1V1X1_D2V0X1(n, d1, d2), freq}
#define PLLAUDIO(n, p, d1, d2, freq) {F_N8X8_P16X6_D1V1X1_D2V0X1(n, p, d1, d2), freq}

#endif
