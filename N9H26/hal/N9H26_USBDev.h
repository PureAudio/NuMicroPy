/**************************************************************************//**
 * @file     N9H26_USBDev.h
 * @version  V1.00
 * @brief    N9H26 USB HAL header file for micropython
 *
 * SPDX-License-Identifier: Apache-2.0
 * @copyright (C) 2020 Nuvoton Technology Corp. All rights reserved.
 *****************************************************************************/
#ifndef __N9H26_USBDEV_H__
#define __N9H26_USBDEV_H__

#include <inttypes.h>

/* Define the vendor id and product id */
#define USBD_VID        	0x0416
#define USBD_MSC_VCP_PID    0xDC01

typedef enum{
	eUSBDEV_MODE_NONE = 0,
	eUSBDEV_MODE_HID = 0x1,
//	eUSBDEV_MODE_VCP = 0x2,
//	eUSBDEV_MODE_HID_VCP = 0x3,
	eUSBDEV_MODE_MSC_VCP = 0x4,	
} E_USBDEV_MODE;

typedef struct{
	E_USBDEV_MODE eUSBMode;
	int bConnected;
}S_USBDEV_STATE;


typedef int32_t (*PFN_USBDEV_VCPRecvSignal)(uint8_t *pu8Buf, uint32_t u32Size);

E_USBDEV_MODE USBDEV_GetMode(S_USBDEV_STATE *psUSBDevState);

S_USBDEV_STATE *USBDEV_Init(
	uint16_t u16VID,
	uint16_t u16PID,
	E_USBDEV_MODE eUSBMode
);

S_USBDEV_STATE *USBDEV_UpdateState(void);

int32_t USBDEV_Start(
	S_USBDEV_STATE *psUSBDevState
);

void USBDEV_Deinit(
	S_USBDEV_STATE *psUSBDevState
);

int32_t USBDEV_VCPCanRecv(
	S_USBDEV_STATE *psUSBDevState
);

int32_t USBDEV_VCPRecvData(
	uint8_t *pu8DataBuf,
	uint32_t u32DataBufLen,
	uint32_t u32Timeout,
	S_USBDEV_STATE *psUSBDevState
);

int32_t USBDEV_VCPCanSend(
	S_USBDEV_STATE *psUSBDevState
);

int32_t USBDEV_VCPSendData(
	uint8_t *pu8DataBuf,
	uint32_t u32DataBufLen,
	uint32_t u32Timeout,
	S_USBDEV_STATE *psUSBDevState
);

void USBDEV_MSCEnDisable(
	int32_t i32EnDisable
);

int32_t USBDEV_DataBusConnect(void);


void USBDEV_VCPRegisterSingal(
	PFN_USBDEV_VCPRecvSignal pfnSignal
);

void MSCTrans_Process(void);


#endif