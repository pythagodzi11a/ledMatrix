#ifndef __ACT__
#define __ACT__

#include <Arduino.h>
#include <FastLED.h>
#include "expression.h"

void watchAround(){
    display(watchCenter);
    FastLED.show();
    delay(1000);
    FastLED.clear(); 
    
    display(watchLeft);
    FastLED.show();
    delay(1000);
    FastLED.clear();

    display(watchCenter);
    FastLED.show();
    delay(1000);
    FastLED.clear();
    
    display(watchRight);
    FastLED.show();
    delay(1000);
    FastLED.clear();
}


#endif