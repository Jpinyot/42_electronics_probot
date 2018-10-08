#include "Type.h"
#include "p32xxxx.h"
#include <sys/attribs.h>

u16		start_button(void)
{
	TRISBbits.TRISB8 = 1;
//	LATBbits.LATB8 = 0;
	
	return (LATBbits.LATB8);
}
