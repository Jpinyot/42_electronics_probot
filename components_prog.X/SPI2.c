#include "Type.h"
#include "p32xxxx.h"
#include <sys/attribs.h>
//
//void	spi2(u8 img)
//{
//	TRISGbits.TRISG9 = 0; //MR
//	TRISGbits.TRISG7 = 0; //DATAA2; // High to enable data input
//	LATGbits.LATG7 = 1;		//MR
//	LATGbits.LATG9 = 1;		//MR
//
//
//	IEC1bits.SPI2EIE = 0; //spi interrupts disabled
//	IEC1bits.SPI2EIE = 0;
//	IEC1bits.SPI2TXIE = 0;
//
//	SPI2CONbits.ON = 0;	//Turn off SPI
//	SPI2BUF = 0;		//Clear the receive buffer
//	SPI2BRG = 3; //FSCK = 2.5MHz
//
//	SPI2STATbits.SPIROV = 0; //clear ovrflow flag
//
////	SPI2CONbits.FRMEN = 0; //framed SPI support disabled //mod
//	SPI2CONbits.SIDL = 0; //Continue operation in IDLE mode
////	SPI2CONbits.DISSDO = 0; //SDO1 pin is controlled by the module //mod
//	SPI2CONbits.MODE16 = 0;
//	SPI2CONbits.MODE32 = 0;
//	SPI2CONbits.CKP = 1;  //IDLE state for clock is hihg, active state is low
////	SPI2CONbits.CKE = 0; //Output data changes on transition from idle to active
//	SPI2CONbits.SSEN = 0; //NOt in slave mode
//	SPI2CONbits.MSTEN = 1; //Master mode
//	SPI2CONbits.SMP = 1; //INput data sampled at the end of data output time
//
//	SPI2CONbits.ON = 1; //Turn module ON
//
//	SPI2STATbits.SPIROV = 0; //clear ovrflow flag
//	while (!SPI2STATbits.SPITBE); //While buf is not empty wait
//	SPI2BUF=img; //Data is send out on SPI
//	while (!SPI2STATbits.SPIRBF); //Wait for transfer to be completed
////	LATGbits.LATG9 = 0;		//LOW clears the registers and forces all ouptus LOW
//}
