/*
 * This file is part of the MicroPython project, http://micropython.org/
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2013, 2014 Damien P. George
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
// This file contains pin definitions that are specific to the m48x port.
// This file should only ever be #included by pin.h and not directly.

#include "NuMicro.h"
#include "gpio_reg.h"

enum {
  PORT_A,
  PORT_B,
  PORT_C,
  PORT_D,
  PORT_E,
  PORT_F,
  PORT_G,
  PORT_H,
};

enum {
  AF_FN_OPA,
  AF_FN_ACMP,
  AF_FN_EADC,
  AF_FN_SPIM,
  AF_FN_EBI,
  AF_FN_QSPI,
  AF_FN_EMAC,
  AF_FN_SPI,
  AF_FN_SD,
  AF_FN_SC,
  AF_FN_USCI,
  AF_FN_UART,
  AF_FN_I2C,
  AF_FN_CAN,
  AF_FN_ECAP,
  AF_FN_TAMPER,
  AF_FN_ETM,
  AF_FN_BPWM,
  AF_FN_EPWM,
  AF_FN_QEI,
  AF_FN_TMR,
  AF_FN_USB,
  AF_FN_HSUSB,
  AF_FN_DAC,
  AF_FN_INT,
  AF_FN_SWDH,
  AF_FN_I2S,
};

enum {
  AF_PIN_TYPE_OPA_P = 0,
  AF_PIN_TYPE_OPA_N,
  AF_PIN_TYPE_OPA_O,

  AF_PIN_TYPE_ACMP_WLAT = 0,
  AF_PIN_TYPE_ACMP_P0,
  AF_PIN_TYPE_ACMP_P1,
  AF_PIN_TYPE_ACMP_P2,
  AF_PIN_TYPE_ACMP_P3,
  AF_PIN_TYPE_ACMP_N,
  AF_PIN_TYPE_ACMP_O,

  AF_PIN_TYPE_EADC_CH0 = 0,
  AF_PIN_TYPE_EADC_CH1,
  AF_PIN_TYPE_EADC_CH2,
  AF_PIN_TYPE_EADC_CH3,
  AF_PIN_TYPE_EADC_CH4,
  AF_PIN_TYPE_EADC_CH5,
  AF_PIN_TYPE_EADC_CH6,
  AF_PIN_TYPE_EADC_CH7,
  AF_PIN_TYPE_EADC_CH8,
  AF_PIN_TYPE_EADC_CH9,
  AF_PIN_TYPE_EADC_CH10,
  AF_PIN_TYPE_EADC_CH11,
  AF_PIN_TYPE_EADC_CH12,
  AF_PIN_TYPE_EADC_CH13,
  AF_PIN_TYPE_EADC_CH14,
  AF_PIN_TYPE_EADC_CH15,
  AF_PIN_TYPE_EADC_ST,

  AF_PIN_TYPE_SPIM_MOSI = 0,
  AF_PIN_TYPE_SPIM_MISO,
  AF_PIN_TYPE_SPIM_CLK,
  AF_PIN_TYPE_SPIM_SS,
  AF_PIN_TYPE_SPIM_D2,
  AF_PIN_TYPE_SPIM_D3,

  AF_PIN_TYPE_EBI_ADR0 = 0,
  AF_PIN_TYPE_EBI_ADR1,
  AF_PIN_TYPE_EBI_ADR2,
  AF_PIN_TYPE_EBI_ADR3,
  AF_PIN_TYPE_EBI_ADR4,
  AF_PIN_TYPE_EBI_ADR5,
  AF_PIN_TYPE_EBI_ADR6,
  AF_PIN_TYPE_EBI_ADR7,
  AF_PIN_TYPE_EBI_ADR8,
  AF_PIN_TYPE_EBI_ADR9,
  AF_PIN_TYPE_EBI_ADR10,
  AF_PIN_TYPE_EBI_ADR11,
  AF_PIN_TYPE_EBI_ADR12,
  AF_PIN_TYPE_EBI_ADR13,
  AF_PIN_TYPE_EBI_ADR14,
  AF_PIN_TYPE_EBI_ADR15,
  AF_PIN_TYPE_EBI_ADR16,
  AF_PIN_TYPE_EBI_ADR17,
  AF_PIN_TYPE_EBI_ADR18,
  AF_PIN_TYPE_EBI_ADR19,
  AF_PIN_TYPE_EBI_AD0,
  AF_PIN_TYPE_EBI_AD1,
  AF_PIN_TYPE_EBI_AD2,
  AF_PIN_TYPE_EBI_AD3,
  AF_PIN_TYPE_EBI_AD4,
  AF_PIN_TYPE_EBI_AD5,
  AF_PIN_TYPE_EBI_AD6,
  AF_PIN_TYPE_EBI_AD7,
  AF_PIN_TYPE_EBI_AD8,
  AF_PIN_TYPE_EBI_AD9,
  AF_PIN_TYPE_EBI_AD10,
  AF_PIN_TYPE_EBI_AD11,
  AF_PIN_TYPE_EBI_AD12,
  AF_PIN_TYPE_EBI_AD13,
  AF_PIN_TYPE_EBI_AD14,
  AF_PIN_TYPE_EBI_AD15,
  AF_PIN_TYPE_EBI_ALE,
  AF_PIN_TYPE_EBI_MCLK,
  AF_PIN_TYPE_EBI_nWR,
  AF_PIN_TYPE_EBI_nRD,
  AF_PIN_TYPE_EBI_nWRH,
  AF_PIN_TYPE_EBI_nWRL,
  AF_PIN_TYPE_EBI_nCS0,
  AF_PIN_TYPE_EBI_nCS1,
  AF_PIN_TYPE_EBI_nCS2,

  AF_PIN_TYPE_QSPI_MOSI0 = 0,
  AF_PIN_TYPE_QSPI_MISO0,
  AF_PIN_TYPE_QSPI_MOSI1,
  AF_PIN_TYPE_QSPI_MISO1,
  AF_PIN_TYPE_QSPI_CLK,
  AF_PIN_TYPE_QSPI_SS,

  AF_PIN_TYPE_EMAC_RMII_REFCLK = 0,
  AF_PIN_TYPE_EMAC_RMII_RXERR,
  AF_PIN_TYPE_EMAC_RMII_CRSDV,
  AF_PIN_TYPE_EMAC_PPS,
  AF_PIN_TYPE_EMAC_RMII_RXD0,
  AF_PIN_TYPE_EMAC_RMII_RXD1,
  AF_PIN_TYPE_EMAC_RMII_TXEN,
  AF_PIN_TYPE_EMAC_RMII_TXD0,
  AF_PIN_TYPE_EMAC_RMII_TXD1,
  AF_PIN_TYPE_EMAC_RMII_MDC,
  AF_PIN_TYPE_EMAC_RMII_MDIO,

  AF_PIN_TYPE_SPI_MOSI = 0,
  AF_PIN_TYPE_SPI_MISO,
  AF_PIN_TYPE_SPI_CLK,
  AF_PIN_TYPE_SPI_SS,
  AF_PIN_TYPE_SPI_I2SMCLK,

  AF_PIN_TYPE_SD_DAT0 = 0,
  AF_PIN_TYPE_SD_DAT1,
  AF_PIN_TYPE_SD_DAT2,
  AF_PIN_TYPE_SD_DAT3,
  AF_PIN_TYPE_SD_CLK,
  AF_PIN_TYPE_SD_CMD,
  AF_PIN_TYPE_SD_nCD,

  AF_PIN_TYPE_SC_CLK = 0,
  AF_PIN_TYPE_SC_DAT,
  AF_PIN_TYPE_SC_RST,
  AF_PIN_TYPE_SC_PWR,
  AF_PIN_TYPE_SC_nCD,

  AF_PIN_TYPE_USCI_CLK = 0,
  AF_PIN_TYPE_USCI_CTL0,
  AF_PIN_TYPE_USCI_CTL1,
  AF_PIN_TYPE_USCI_DAT0,
  AF_PIN_TYPE_USCI_DAT1,

  AF_PIN_TYPE_UART_RXD = 0,
  AF_PIN_TYPE_UART_nRTS,
  AF_PIN_TYPE_UART_TXD,
  AF_PIN_TYPE_UART_nCTS,

  AF_PIN_TYPE_I2C_SDA = 0,
  AF_PIN_TYPE_I2C_SCL,
  AF_PIN_TYPE_I2C_SMBSUS,
  AF_PIN_TYPE_I2C_SMBAL,

  AF_PIN_TYPE_CAN_RXD = 0,
  AF_PIN_TYPE_CAN_TXD,

  AF_PIN_TYPE_ECAP_IC0 = 0,
  AF_PIN_TYPE_ECAP_IC1,
  AF_PIN_TYPE_ECAP_IC2,

  AF_PIN_TYPE_TAMPER_TAMPER = 0,

  AF_PIN_TYPE_ETM_TRACE_CLK = 0,
  AF_PIN_TYPE_ETM_TRACE_DATA0,
  AF_PIN_TYPE_ETM_TRACE_DATA1,
  AF_PIN_TYPE_ETM_TRACE_DATA2,
  AF_PIN_TYPE_ETM_TRACE_DATA3,

  AF_PIN_TYPE_BPWM_CH0 = 0,
  AF_PIN_TYPE_BPWM_CH1,
  AF_PIN_TYPE_BPWM_CH2,
  AF_PIN_TYPE_BPWM_CH3,
  AF_PIN_TYPE_BPWM_CH4,
  AF_PIN_TYPE_BPWM_CH5,

  AF_PIN_TYPE_EPWM_CH0 = 0,
  AF_PIN_TYPE_EPWM_CH1,
  AF_PIN_TYPE_EPWM_CH2,
  AF_PIN_TYPE_EPWM_CH3,
  AF_PIN_TYPE_EPWM_CH4,
  AF_PIN_TYPE_EPWM_CH5,
  AF_PIN_TYPE_EPWM_SYNC_OUT,
  AF_PIN_TYPE_EPWM_SYNC_IN,
  AF_PIN_TYPE_EPWM_BRAKE0,
  AF_PIN_TYPE_EPWM_BRAKE1,

  AF_PIN_TYPE_QEI_A = 0,
  AF_PIN_TYPE_QEI_B,
  AF_PIN_TYPE_QEI_INDEX,

  AF_PIN_TYPE_TMR_TMR = 0,
  AF_PIN_TYPE_TMR_EXT,
  AF_PIN_TYPE_TMR_INDEX,

  AF_PIN_TYPE_USB_VBUS = 0,
  AF_PIN_TYPE_USB_D_N,
  AF_PIN_TYPE_USB_D_P,
  AF_PIN_TYPE_USB_OTG_ID,
  AF_PIN_TYPE_USB_VBUS_EN,
  AF_PIN_TYPE_USB_VBUS_ST,

  AF_PIN_TYPE_HSUSB_VBUS_EN = 0,
  AF_PIN_TYPE_HSUSB_VBUS_ST,

  AF_PIN_TYPE_DAC_ST = 0,
  AF_PIN_TYPE_DAC_OUT,

  AF_PIN_TYPE_INT_INT = 0,

  AF_PIN_TYPE_SWDH_DAT = 0,
  AF_PIN_TYPE_SWDH_CLK,

  AF_PIN_TYPE_I2S_BCLK = 0,
  AF_PIN_TYPE_I2S_MCLK,
  AF_PIN_TYPE_I2S_DI,
  AF_PIN_TYPE_I2S_DO,
  AF_PIN_TYPE_I2S_LRCK,
};

#if 0
// The HAL uses a slightly different naming than we chose, so we provide
// some #defines to massage things. Also I2S and SPI share the same
// peripheral.

#define GPIO_AF5_I2S2   GPIO_AF5_SPI2
#define GPIO_AF5_I2S3   GPIO_AF5_I2S3ext
#define GPIO_AF6_I2S2   GPIO_AF6_I2S2ext
#define GPIO_AF6_I2S3   GPIO_AF6_SPI3
#define GPIO_AF7_I2S2   GPIO_AF7_SPI2
#define GPIO_AF7_I2S3   GPIO_AF7_I2S3ext

#define I2S2  SPI2
#define I2S3  SPI3

#endif


#define SPIM0 ((void*)SPIM)

#define SD0 SDH0
#define SD1 SDH1

#define OPA0 OPA

#define EBI0 EBI

#define EADC0 EADC

#define ACMP0 ACMP01
#define ACMP1 ACMP01

#define EMAC0 EMAC

#define USCI0 USPI0
#define USCI1 USPI1

#define TMR0 TIMER0
#define TMR1 TIMER1
#define TMR2 TIMER2
#define TMR3 TIMER3

#define TAMPER5 RTC


#define INT0 SYS
#define INT1 SYS
#define INT2 SYS
#define INT3 SYS
#define INT4 SYS
#define INT5 SYS
#define INT6 SYS
#define INT7 SYS


enum {
  PIN_EADC1  = (1 << 0),
  PIN_EADC2  = (1 << 1),
  PIN_EADC3  = (1 << 2),
};

typedef GPIO_T pin_gpio_t;

#define GPIO_MODE_AF_PP          0x4UL
#define GPIO_MODE_AF_OD          0x5UL


#define SYS_GPA_MFPL_PA0MFP_SPIM0_MOSI			SYS_GPA_MFPL_PA0MFP_SPIM_MOSI
#define SYS_GPA_MFPL_PA1MFP_SPIM0_MISO			SYS_GPA_MFPL_PA1MFP_SPIM_MISO
#define SYS_GPE_MFPL_PE4MFP_SPIM0_CLK			SYS_GPE_MFPL_PE4MFP_SPIM_CLK
#define SYS_GPE_MFPL_PE5MFP_SPIM0_SS			SYS_GPE_MFPL_PE5MFP_SPIM_SS
#define SYS_GPA_MFPL_PA5MFP_SPIM0_D2			SYS_GPA_MFPL_PA5MFP_SPIM_D2
#define SYS_GPA_MFPL_PA4MFP_SPIM0_D3			SYS_GPA_MFPL_PA4MFP_SPIM_D3
#define SYS_GPA_MFPL_PA3MFP_SPIM0_SS			SYS_GPA_MFPL_PA3MFP_SPIM_SS
#define SYS_GPA_MFPL_PA2MFP_SPIM0_CLK			SYS_GPA_MFPL_PA2MFP_SPIM_CLK

#define SYS_GPB_MFPL_PB7MFP_EBI0_nCS0			SYS_GPB_MFPL_PB7MFP_EBI_nCS0
#define SYS_GPF_MFPL_PF6MFP_EBI0_nCS0			SYS_GPF_MFPL_PF6MFP_EBI_nCS0
#define SYS_GPB_MFPL_PB7MFP_EBI0_nWRL			SYS_GPB_MFPL_PB7MFP_EBI_nWRL
#define SYS_GPB_MFPL_PB6MFP_EBI0_nCS1			SYS_GPB_MFPL_PB6MFP_EBI_nCS1
#define SYS_GPB_MFPL_PB6MFP_EBI0_nWRH			SYS_GPB_MFPL_PB6MFP_EBI_nWRH
#define SYS_GPE_MFPL_PE5MFP_EBI0_nRD			SYS_GPE_MFPL_PE5MFP_EBI_nRD
#define SYS_GPA_MFPH_PA11MFP_EBI0_nRD			SYS_GPA_MFPH_PA11MFP_EBI_nRD
#define SYS_GPE_MFPL_PE4MFP_EBI0_nWR			SYS_GPE_MFPL_PE4MFP_EBI_nWR
#define SYS_GPA_MFPH_PA10MFP_EBI0_nWR			SYS_GPA_MFPH_PA10MFP_EBI_nWR
#define SYS_GPB_MFPL_PB3MFP_EBI0_ADR2			SYS_GPB_MFPL_PB3MFP_EBI_ADR2
#define SYS_GPB_MFPL_PB2MFP_EBI0_ADR3			SYS_GPB_MFPL_PB2MFP_EBI_ADR3
#define SYS_GPC_MFPH_PC12MFP_EBI0_ADR4			SYS_GPC_MFPH_PC12MFP_EBI_ADR4
#define SYS_GPC_MFPH_PC11MFP_EBI0_ADR5			SYS_GPC_MFPH_PC11MFP_EBI_ADR5
#define SYS_GPH_MFPL_PH2MFP_EBI0_ADR5			SYS_GPH_MFPL_PH2MFP_EBI_ADR5
#define SYS_GPC_MFPH_PC10MFP_EBI0_ADR6			SYS_GPC_MFPH_PC10MFP_EBI_ADR6
#define SYS_GPH_MFPL_PH1MFP_EBI0_ADR6			SYS_GPH_MFPL_PH1MFP_EBI_ADR6
#define SYS_GPC_MFPH_PC9MFP_EBI0_ADR7			SYS_GPC_MFPH_PC9MFP_EBI_ADR7
#define SYS_GPH_MFPL_PH0MFP_EBI0_ADR7			SYS_GPH_MFPL_PH0MFP_EBI_ADR7
#define SYS_GPB_MFPL_PB1MFP_EBI0_ADR8			SYS_GPB_MFPL_PB1MFP_EBI_ADR8
#define SYS_GPB_MFPL_PB0MFP_EBI0_ADR9			SYS_GPB_MFPL_PB0MFP_EBI_ADR9
#define SYS_GPC_MFPH_PC13MFP_EBI0_ADR10			SYS_GPC_MFPH_PC13MFP_EBI_ADR10
#define SYS_GPF_MFPH_PF11MFP_EBI0_ADR14			SYS_GPF_MFPH_PF11MFP_EBI_ADR14
#define SYS_GPF_MFPH_PF10MFP_EBI0_ADR15			SYS_GPF_MFPH_PF10MFP_EBI_ADR15
#define SYS_GPE_MFPH_PE13MFP_EBI0_ADR15			SYS_GPE_MFPH_PE13MFP_EBI_ADR15
#define SYS_GPF_MFPH_PF9MFP_EBI0_ADR16			SYS_GPF_MFPH_PF9MFP_EBI_ADR16
#define SYS_GPF_MFPH_PF8MFP_EBI0_ADR17			SYS_GPF_MFPH_PF8MFP_EBI_ADR17
#define SYS_GPB_MFPH_PB9MFP_EBI0_ADR18			SYS_GPB_MFPH_PB9MFP_EBI_ADR18
#define SYS_GPF_MFPL_PF7MFP_EBI0_ADR18			SYS_GPF_MFPL_PF7MFP_EBI_ADR18
#define SYS_GPB_MFPH_PB8MFP_EBI0_ADR19			SYS_GPB_MFPH_PB8MFP_EBI_ADR19
#define SYS_GPF_MFPL_PF6MFP_EBI0_ADR19			SYS_GPF_MFPL_PF6MFP_EBI_ADR19
#define SYS_GPB_MFPH_PB12MFP_EBI0_AD15			SYS_GPB_MFPH_PB12MFP_EBI_AD15
#define SYS_GPG_MFPL_PG0MFP_EBI0_ADR8			SYS_GPG_MFPL_PG0MFP_EBI_ADR8
#define SYS_GPG_MFPL_PG1MFP_EBI0_ADR9			SYS_GPG_MFPL_PG1MFP_EBI_ADR9
#define SYS_GPG_MFPL_PG5MFP_EBI0_nCS1			SYS_GPG_MFPL_PG5MFP_EBI_nCS1
#define SYS_GPD_MFPL_PD0MFP_EBI0_AD13			SYS_GPD_MFPL_PD0MFP_EBI_AD13
#define SYS_GPD_MFPL_PD1MFP_EBI0_AD12			SYS_GPD_MFPL_PD1MFP_EBI_AD12
#define SYS_GPA_MFPH_PA8MFP_EBI0_ALE			SYS_GPA_MFPH_PA8MFP_EBI_ALE
#define SYS_GPA_MFPH_PA9MFP_EBI0_MCLK			SYS_GPA_MFPH_PA9MFP_EBI_MCLK

#define SYS_GPB_MFPL_PB1MFP_EMAC0_RMII_RXERR	SYS_GPB_MFPL_PB1MFP_EMAC_RMII_RXERR
#define SYS_GPB_MFPH_PB9MFP_EMAC0_RMII_TXD0		SYS_GPB_MFPH_PB9MFP_EMAC_RMII_TXD0
#define SYS_GPB_MFPH_PB8MFP_EMAC0_RMII_TXD1		SYS_GPB_MFPH_PB8MFP_EMAC_RMII_TXD1
#define SYS_GPB_MFPL_PB7MFP_EMAC0_RMII_TXEN		SYS_GPB_MFPL_PB7MFP_EMAC_RMII_TXEN
#define SYS_GPB_MFPL_PB2MFP_EMAC0_RMII_CRSDV	SYS_GPB_MFPL_PB2MFP_EMAC_RMII_CRSDV
#define SYS_GPB_MFPL_PB3MFP_EMAC0_RMII_RXD1		SYS_GPB_MFPL_PB3MFP_EMAC_RMII_RXD1
#define SYS_GPB_MFPL_PB6MFP_EMAC0_PPS			SYS_GPB_MFPL_PB6MFP_EMAC_PPS
#define SYS_GPE_MFPH_PE13MFP_EMAC0_PPS			SYS_GPE_MFPH_PE13MFP_EMAC_PPS

#define SYS_GPB_MFPL_PB3MFP_TMR2_TMR			SYS_GPB_MFPL_PB3MFP_TM2
#define SYS_GPB_MFPL_PB2MFP_TMR3_TMR			SYS_GPB_MFPL_PB2MFP_TM3
#define SYS_GPF_MFPH_PF11MFP_TMR3_TMR			SYS_GPF_MFPH_PF11MFP_TM3
#define SYS_GPH_MFPL_PH2MFP_TMR2_EXT			SYS_GPH_MFPL_PH2MFP_TM2_EXT
#define SYS_GPH_MFPL_PH0MFP_TMR0_EXT			SYS_GPH_MFPL_PH0MFP_TM0_EXT
#define SYS_GPH_MFPL_PH1MFP_TMR1_EXT			SYS_GPH_MFPL_PH1MFP_TM1_EXT
#define SYS_GPB_MFPH_PB12MFP_TMR3_EXT			SYS_GPB_MFPH_PB12MFP_TM3_EXT
#define SYS_GPD_MFPL_PD0MFP_TMR2_TMR			SYS_GPD_MFPL_PD0MFP_TM2
#define SYS_GPA_MFPH_PA8MFP_TMR3_EXT			SYS_GPA_MFPH_PA8MFP_TM3_EXT
#define SYS_GPA_MFPH_PA9MFP_TMR2_EXT			SYS_GPA_MFPH_PA9MFP_TM2_EXT
#define SYS_GPA_MFPH_PA11MFP_TMR0_EXT			SYS_GPA_MFPH_PA11MFP_TM0_EXT
#define SYS_GPA_MFPH_PA10MFP_TMR1_EXT			SYS_GPA_MFPH_PA10MFP_TM1_EXT

#define SYS_GPB_MFPL_PB3MFP_INT2_INT			SYS_GPB_MFPL_PB3MFP_INT2
#define SYS_GPB_MFPL_PB2MFP_INT3_INT			SYS_GPB_MFPL_PB2MFP_INT3
#define SYS_GPB_MFPL_PB6MFP_INT4_INT			SYS_GPB_MFPL_PB6MFP_INT4
#define SYS_GPB_MFPL_PB7MFP_INT5_INT			SYS_GPB_MFPL_PB7MFP_INT5
#define SYS_GPB_MFPH_PB8MFP_INT6_INT			SYS_GPB_MFPH_PB8MFP_INT6
#define SYS_GPB_MFPH_PB9MFP_INT7_INT			SYS_GPB_MFPH_PB9MFP_INT7


#define SYS_GPF_MFPH_PF11MFP_TAMPER5_TAMPER		SYS_GPF_MFPH_PF11MFP_TAMPER5

#define mp_hal_pin_high(p)	((p)->gpio->DOUT |= (1 << (p)->pin))
#define mp_hal_pin_low(p)	((p)->gpio->DOUT &= ~(1 << (p)->pin))

#define mp_hal_pin_read(p)      (((p)->gpio->PIN >> (p)->pin) & 1)
#define mp_hal_pin_write(p, v)	do { if (v) { mp_hal_pin_high(p); } else { mp_hal_pin_low(p); } } while (0)

#define IS_GPIO_MODE(MODE) (((MODE) == GPIO_MODE_INPUT)              ||\
                            ((MODE) == GPIO_MODE_OUTPUT)          	 ||\
                            ((MODE) == GPIO_MODE_OPEN_DRAIN)         ||\
                            ((MODE) == GPIO_MODE_AF_PP)              ||\
                            ((MODE) == GPIO_MODE_AF_OD)              ||\
                            ((MODE) == GPIO_MODE_QUASI))

#define IS_GPIO_PULL(PULL) (((PULL) == GPIO_PUSEL_DISABLE) || ((PULL) == GPIO_PUSEL_PULL_UP) || \
                            ((PULL) == GPIO_PUSEL_PULL_DOWN))

#define IS_GPIO_INT(ATTR) (((ATTR) == GPIO_INT_RISING)              ||\
                            ((ATTR) == GPIO_INT_FALLING)          	 ||\
                            ((ATTR) == GPIO_INT_BOTH_EDGE)         ||\
                            ((ATTR) == GPIO_INT_HIGH)         ||\
                            ((ATTR) == GPIO_INT_LOW))



