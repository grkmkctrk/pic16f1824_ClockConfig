#include "oscConfig.h"

void main(void) {

    OSC_INIT();
    PIN_CONF();
    
    while(1){
        // LED_rowbyrow();
        LED_cout();
    }

    return;
}
