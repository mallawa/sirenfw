 /****************************************************************************
;*	Getaround Inc. 2007                                                     *
;*	Assembler version:  XC8 v1.34                                           *
;*	Filename:                                                               *
;*		main.c (main routine)                                               *
;*	Dependents:                                                             *
;*                                                                          *
;*	August 13, 2016                                                         *
;*                                                                          *
;*                                                                          *
;****************************************************************************/

#include <xc.h>
#include "tmr2.h"

void TMR2_Initialize(void)
{
    // TMR2ON off; T2CKPS 1:1; T2OUTPS 1:1;
    T2CON = 0x04;

    // PR2 255;
    PR2 = 0xFF;

    // TMR2 0x00;
    TMR2 = 0x00;

    // Clearing IF flag.
    PIR1bits.TMR2IF = 0;
}

/*void TMR2_StartTimer(void)
{
    // Start the Timer by writing to TMRxON bit
    T2CONbits.TMR2ON = 1;
} */

// End of File

