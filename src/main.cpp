#include <Arduino.h>
#include <FastLED.h>
#include "expression.h"
#include "act.h"

//FastLED 初始化
#define NUM_LEDS 64
#define DATA_PIN A0
#define LED_TYPE WS2812
#define COLOR_ORDER GRB

void setup() {
  // put your setup code here, to run once:
  LEDS.addLeds<LED_TYPE,DATA_PIN,COLOR_ORDER>(leds,NUM_LEDS);
  FastLED.setBrightness(max_bright);

  watchAround();

  display(sigama);
  FastLED.show();
  delay(1000);
  FastLED.clear();
}

void loop() {
  // put your main code here, to run repeatedly:
}