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

#include "device_initialize.h"


#define _XTAL_FREQ 8000000


unsigned long long i=0; // counter for installation time
unsigned long long j=0; // counter to determine time elapsed between 
int k;
bit install = 0;       // this bit will only be set after instalation time                     

void interrupt ISR(void){
    // check for Timer 2 overflow
    if(PIR1bits.TMR2IF == 1 ){
        
        ++i;
        if(i==1024000 && !install){  // We only run this if statement up on complete shutdown     
                                     // or restart of the micro
        install =1;                  // Alerting var i and clock freq can change the instalation time. 
        i=0;
        }
        
        
        
       PIR1bits.TMR2IF = 0;  
    }
}

// Main application
void main(void)
{
    SYSTEM_Initialize();    // Initialize the device
    INTCONbits.PEIE = 1; // enable peripheral interrupts
    INTCONbits.GIE  = 1;  // global interrupt enable
    PIE1bits.TMR2IE = 1;
    //counter=0;

    TRISAbits.TRISA2 = 0;     // Set Channel RA2 ( siren ) as output
    //TRISAbits.TRISA1 = 0;   // Set Channel RA1 as output
    //LATAbits.LATA1 = 1;     // Set RA0 (LED D1) high
    LATAbits.LATA2 = 0;      //set siren off
    
    while(1)
    {
        
        while() {
        
        
        
        while(install) {
            
        if(ADC_GetConversion (channel_AN0)>12 && j==0)  {// 5mA or more if connect plugged in 
                
                 
        LATAbits.LATA2 = 0; //siren off, set output register to 0 and GPIO set to low (0V)
                            // SSR is active and change from NO to NC
        
        }
        while(ADC_GetConversion (channel_AN0)<12 && j==0 ){  // less than 5mA draw when connect 
                                                             // is disconnected   
            for (k=0;k<10;k++)    //wait 10sec and then fire the siren
          
            {
              __delay_ms(1000); 
            }
               
                
                LATAbits.LATA2 = 1; // set output register to 1 ie GPIO set to high (5V)
                                    // SSR is not active
                j=102400;           // set the value of j here. altering value of j and  
                                    // internal clock freq will set 
                                    // How long siren should remain fired even though
        }                           // connect is plugged back immediately 
        
            
        }
        
    }
    
    
}
    