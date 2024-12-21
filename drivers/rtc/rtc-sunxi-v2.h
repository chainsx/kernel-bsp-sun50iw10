/*
 * Some macro and struct of SUNXI RTC-V2.
 *
 * Copyright (C) 2018 Allwinner.
 *
 * Damon <liush@allwinnertech.com>
 *
 * This file is licensed under the terms of the GNU General Public
 * License version 2.  This program is licensed "as is" without any
 * warranty of any kind, whether express or implied.
 */

#ifndef _RTC_SUNXI_V2_H_
#define _RTC_SUNXI_V2_H_

#include "rtc-sunxi-common.h"

#define SUNXI_RTC_BGR_REG             0x20c
#define SUNXI_RTC_GATING_ENABLE               BIT(31)

#define SUNXI_DCXO_CFG                0x40
#define SUNXI_CLK_REQ_ENABLE                  BIT(31)
#define SUNXI_DXCO_ENBALE                     BIT(0)

#define SUNXI_SPI_CLK_CFG_REG         0x50
#define SUNXI_RTC_SPI_CLK_ENABLE              BIT(31)
#define SUNXI_RTC_SPI_CLK_DIV                 0

#define SUNXI_RTC_SPI_CFG_REG         0x54
#define SUNXI_RTC_SPI_OP_BUSY                 31
#define SUNXI_RTC_SPI_CFG_BUSY                30
#define SUNXI_RTC_REG_ACCESS_WAY              24
#define SUNXI_RTC_REG_ACCESS_ADDR             16
#define SUNXI_RTC_REG_ACCESS_WRITE_VAL        8
#define SUNXI_RTC_REG_ACCESS_READ_VAL         0

#define SUNXI_LOSC_CTRL	              0x0
#define SUNXI_RC16M_OUT_ENABLE               BIT(7)
#define SUNXI_LOSC_AUTO_SWT_ENABLE           BIT(6)
#define SUNXI_LOSC_AUTO_SWT_PEND_ENABLE      BIT(5)
#define SUNXI_EXT_LOSC_ENABLE                BIT(4)
#define SUNXI_EXT_LOSC_GSM                   2
#define SUNXI_RTC_CLK_SRC                    0

#define SUNXI_LOSC_AUTO_ST_STA	      0x1
#define SUNXI_EXT_LOSC_STA                   2
#define SUNXI_LOSC_AUTO_SWT_PEND             1
#define SUNXI_LOSC_SRC_SEL_STA               0

#define SUNXI_INTOSC_CLK_PRESCAL      0X2
#define SUNXI_INTOSC_32KCLK_PRESCAL          0

#define SUNXI_RTC_DH_CFG              0X3
#define SUNXI_RTC_HIGH_DAY                   0

#define SUNXI_RTC_DL_CFG              0X4
#define SUNXI_RTC_LOW_DAY                    0

#define SUNXI_RTC_HH_CFG              0X5
#define SUNXI_RTC_HOUR                       0

#define SUNXI_RTC_MM_CFG              0X6
#define SUNXI_RTC_MIN                        0

#define SUNXI_RTC_SS_CFG              0X7
#define SUNXI_RTC_SEC                        0

#define SUNXI_RTC_TIMER_READ_CFG      0X8
#define SUNXI_RTC_TIMER_READ_LOCK_BYPASS     BIT(2)
#define SUNXI_RTC_TIMER_READ_LOCK_ENABLE     BIT(1)
#define SUNXI_RTC_TIMER_VAL_CFG_ENABLE       BIT(0)

#define SUNXI_RTC_DH_RD               0X9
#define SUNXI_RTC_DL_RD               0Xa
#define SUNXI_RTC_HH_RD               0Xb
#define SUNXI_RTC_MM_RD               0Xc
#define SUNXI_RTC_SS_RD               0Xd
#define SUNXI_ALMCFG_DH               0Xe
#define SUNXI_ALMCFG_DL               0Xf
#define SUNXI_ALMCFG_HH               0X10
#define SUNXI_ALMCFG_MM               0X11
#define SUNXI_ALMCFG_SS               0X12

#define SUNXI_ALM0_ENABLE_REG         0X13
#define SUNXI_ALM0_WAKEUP                    2
#define SUNXI_ALM0_IRQ_ENABLE                BIT(1)
#define SUNXI_ALM0_ENABLE                    BIT(0)

#define SUNXI_ALM0_IRQ_STA            0x14
#define SUNXI_ALM0_IRQ_PEND                  0

#define SUNXI_LOSC_OUT_GATE           0X15
#define SUNXI_LOSC_OUT_SEL                   1
#define SUNXI_LOSC_OUT_GATING                0

#endif /* end of _RTC_SUNXI_V2_H_ */
