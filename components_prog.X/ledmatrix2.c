
#include "Type.h"
#include "p32xxxx.h"
#include <sys/attribs.h>

void    ledmatrix2(u8 img)
{
    IEC0CLR=0x03800000;    // disable all interrupts
//  SPI2CON = 0;           // Stops and resets the SPI2.

//  flag=SPI2BUF;         // clears the receive buffer
    IFS0CLR=0x03800000;    // clear any existing event
    IPC5CLR=0x1f000000;    // clear the priority
    IPC5SET=0x0d000000;    // Set IPL=3, Subpriority 1
    IEC0SET=0x03800000;    // Enable RX, TX and Error interrupts

	TRISFbits.TRISF6 = 0; //clock
	LATFbits.LATF6 = 0;

	TRISGbits.TRISG9 = 1; // MR a low in MR clear the registers and forces all outputs
//	LATGbits.LATG9 = 1;
	LATGbits.LATG9 = 0;
	LATGbits.LATG9 = 1;

	TRISGbits.TRISG7 = 0; //DATAA2;
	LATGbits.LATG7 = 1;

	TRISGbits.TRISG8 = 0; //DATAA1;
	LATGbits.LATG8 = 0;

    u8 i = 0;
	u8 j = 0;
    u8 value = img;
    u8 flag = 1;
    u8 t = 0;

	while (i < 8)
	{
		send_shiftA(value, i);
		LATFbits.LATF6 = 1;
		t = 0;
		while (t++ < 100);
		LATFbits.LATF6 = 0;
		i++;
	}
}
 void send_shiftA(u8 value, u8 i)
{
	u8 t = 0;
	u8 tmp;
	if (value & (0b1 << i))
		tmp = 0b1;
	else
		tmp = 0b0;
	LATGbits.LATG8 = tmp;
}
