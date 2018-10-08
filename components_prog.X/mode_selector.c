#include "Type.h"
#include "p32xxxx.h"
#include <sys/attribs.h>

void    modeselector(void)
{
    TRISEbits.TRISE7 = 1;
	TRISFbits.TRISF2 = 0;	//RED
    TRISFbits.TRISF3 = 0;	//GREEN
    LATFbits.LATF2 = 0;
    LATFbits.LATF3 = 0;
//GRID
	if (!PORTEbits.RE7)
	{
		LATFbits.LATF2 = 0;
		LATFbits.LATF3 = 1;
    }
//BLUETOOTH
    if (PORTEbits.RE7)
	{
		LATFbits.LATF2 = 1;
		LATFbits.LATF3 = 0;
    }
}