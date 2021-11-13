#include "oscConfig.h"

void OSC_INIT(void){
    /**
     * SPLLEN bit ignored because of PLLEN activated on configuration
     * i choose 8 MHz because when PLL active there is no 8 MHz of high frequency oscillator  
     * instead of that there is 32 MHz PLL
     */
    OSCCON &= 0x00;
    OSCCON |= (7 << 4); // 0b01110000
    
    /**
     * No need any tuning using 32 MHz PLL
     * Also no need Brown-out configuration
     */
    OSCTUNE = 0x00;
    BORCON  = 0x00;
    
    while(!OSCSTATbits.PLLR); // wait during PLL is not ready   
}

void WDT_INIT(void){
    // WDTE is disabled now so this bit ignored
    WDTCON &= (0 << 0);
}

void PIN_CONF(void){
    /**
     * Let's turn as output first 3 pins of A port 
     */
    LATA   &= ~(7 << 0); // cleaning.
    TRISA  &= ~(7 << 0); // outputs.
    ANSELA |= (7 << 0);; // digital input.
    WPUA   &= (0x00);     // there is no any input.
    OPTION_REGbits.nWPUEN = 1; // you can check why in the datasheet
    
    /**
     * If you wanna turn to the pins for your special purpose 
     * you should check the APFCON registers
     */
    APFCON0 &= (0x00);
    APFCON1 &= (0x00);
    
}

void LED_rowbyrow(void){
    LATA &= ~(7 << 0);
    unsigned char i = 0;
    for (
            ; 
            i < 3; 
            LATA = 1 << i++,
            __delay_ms(1000)
        );
}

void LED_cout(void){
    LATA &= ~(7 << 0);
    unsigned char i = 0;
    while( i < 8 ){
        LATA = (i++);
        __delay_ms(1000);
    }
}


