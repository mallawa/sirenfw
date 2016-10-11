/****************************************************************************
;*	Getaround Inc. 2007                                                     *
;*	Assembler version:  XC8 v1.34                                           *
;*	Filename:                                                               *
;*		main.c (main routine)                                               *
;*	Dependents: 
 *                                                              *
;*                                                                          *
;*	August 13, 2016                                                         *
;*                                                                          *
;*                                                                          *
;****************************************************************************/

#include <xc.h>
#include "adc.h"

//Section: ADC Module APIs

void ADC_Initialize(void)
{
    ADCON = 0x81;         // ADON enabled; CHS AN0;

    TRISAbits.TRISA0 = 1; //  pin (RA0) as input
    ANSELAbits.ANSA0 = 1; // configure (RA0) as analog input

}


adc_result_t ADC_GetConversion(adc_channel_t channel)
{
    // Select the A/D channel
    ADCONbits.CHS = channel;

    // Turn on the ADC module
    ADCONbits.ADON = 1;

    // Start the conversion
    ADCONbits.GO_nDONE = 1;

    // Wait for the conversion to finish
    while (ADCONbits.GO_nDONE);

    // Conversion finished, return the result
    return ADRES;
}

// End of File


