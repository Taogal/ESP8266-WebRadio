/*
 * VS1053.h
 *
 *  Created on: 25-04-2011
 *      Author: Przemyslaw Stasiak
 */
//#include "stm32f10x.h"
#pragma once
#include "c_types.h"
//#include "freertos/FreeRTOS.h"
//#include "stdio.h"
//#include "stdlib.h"
//#include "espconn.h"
//#include "osapi.h"
//#include "user/spi_ram_buffer.h"

#define RST_PIN 0
#define CS_PIN 15
#define XDCS_PIN 5 //GPIO5 (!)
#define DREQ_PIN 4 //GPIO4 (!)

#define SET 1
#define RESET 0

#ifndef VS1053_H_
#define VS1053_H_

#define RXNE    0x01
#define TXE     0x02
#define BSY     0x80

#define VS_WRITE_COMMAND 	0x02
#define VS_READ_COMMAND 	0x03
#define SPI_MODE        	0x00
#define SPI_STATUS      	0x01
#define SPI_BASS        	0x02
#define SPI_CLOCKF      	0x03
#define SPI_DECODE_TIME 	0x04
#define SPI_AUDATA      	0x05
#define SPI_WRAM        	0x06
#define SPI_WRAMADDR    	0x07
#define SPI_HDAT0       	0x08
#define SPI_HDAT1       	0x09
#define SPI_AIADDR      	0x0a
#define SPI_VOL         	0x0b
#define SPI_AICTRL0     	0x0c
#define SPI_AICTRL1     	0x0d
#define SPI_AICTRL2     	0x0e
#define SPI_AICTRL3     	0x0f
#define SM_DIFF         	0x01
#define SM_JUMP         	0x02
#define SM_LAYER12			0x02
#define SM_RESET        	0x04
#define SM_CANCEL           0x08
#define SM_OUTOFWAV     	0x08
#define SM_PDOWN        	0x10
#define SM_TESTS        	0x20
#define SM_STREAM       	0x40
#define SM_PLUSV        	0x80
#define SM_DACT         	0x100
#define SM_SDIORD       	0x200
#define SM_SDISHARE     	0x400
#define SM_SDINEW       	0x800
#define SM_ADPCM        	0x1000
#define SM_ADPCM_HP     	0x2000
#define SM_LINE1            0x4000
#define para_endFillByte    0x1E06
//public functions
void 	VS1053_HW_init();
void 	VS1053_SineTest();
void	VS1053_Start();
//void 	VS1053_SendMusicBytes(uint8_t* music,int quantity);
int 	VS1053_SendMusicBytes(uint8_t* music,uint16_t quantity);
void 	VS1053_SoftwareReset();
uint16_t	VS1053_GetBitrate();
uint16_t	VS1053_GetSampleRate();
uint16_t	VS1053_GetDecodeTime();
void	VS1053_flush_cancel(uint8_t mode);// 0 only fillbyte  1 before play    2 close play

//Volume control
uint8_t 	VS1053_GetVolume();
uint8_t 	VS1053_GetVolumeLinear();
void	VS1053_SetVolume(uint8_t xMinusHalfdB);
void 	VS1053_VolumeUp(uint8_t xHalfdB);
void	VS1053_VolumeDown(uint8_t xHalfdB);
//Treble control
int8_t	VS1053_GetTreble();
void	VS1053_SetTreble(int8_t xOneAndHalfdB);
void	VS1053_TrebleUp(uint8_t xOneAndHalfdB);
void	VS1053_TrebleDown(uint8_t xOneAndHalfdB);
void	VS1053_SetTrebleFreq(uint8_t xkHz);
int8_t	VS1053_GetTrebleFreq(void);
//Bass control
uint8_t	VS1053_GetBass();
void	VS1053_SetBass(uint8_t xdB);
void	VS1053_BassUp(uint8_t xdB);
void	VS1053_BassDown(uint8_t xdB);
void	VS1053_SetBassFreq(uint8_t xTenHz);
uint8_t	VS1053_GetBassFreq(void);
// Spacial
uint8_t	VS1053_GetSpatial();
void VS1053_SetSpatial(uint8_t num);
//private functions
void SPIPutChar(uint8_t outB);
uint8_t SPIGetChar();
void Delay(uint32_t nTime);
void ControlReset(uint8_t State);
void SCI_ChipSelect(uint8_t State);
void SDI_ChipSelect(uint8_t State);
void VS1053_WriteRegister(uint8_t addressbyte,
		uint8_t highbyte, uint8_t lowbyte);
uint16_t VS1053_ReadRegister(uint8_t addressbyte);
void VS1053_ResetChip();

uint16_t MaskAndShiftRight(uint16_t Source, uint16_t Mask, uint16_t Shift);

uint8_t VS1053_checkWREQ();

void VS1053_regtest();
void VS1053_sine(char pitch);
void VS1053_SPI_SpeedUp();
void VS1053_SPI_SpeedDown();
//void VS1053_PluginLoad();

#endif /* VS1053_H_ */
