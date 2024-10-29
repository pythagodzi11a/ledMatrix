#include <Arduino.h>
#include<FastLED.h>


#define NUM_LEDS 64
#define DATA_PIN A0
#define LED_TYPE WS2812
#define COLOR_ORDER RGB

uint8_t max_bright = 120;

CRGB leds[NUM_LEDS];

// put function declarations here:

void setup() {
  // put your setup code here, to run once:
  LEDS.addLeds<LED_TYPE,DATA_PIN,COLOR_ORDER>(leds,NUM_LEDS);
  FastLED.setBrightness(max_bright);
}

void loop() {
  // put your main code here, to run repeatedly:
  
}
