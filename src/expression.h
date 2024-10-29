#ifndef __EXPRESSION__
#define __EXPRESSION__

#include <stdio.h>
#include <Arduino.h>
#include <FastLED.h>

#define NUM_LEDS 64
#define DATA_PIN A0
#define LED_TYPE WS2812
#define COLOR_ORDER GRB

uint8_t max_bright = 122;

CRGB leds[NUM_LEDS];

byte sigama[] = {
0x00,0x3e,0x12,0x08,0x08,0x12,0x3e,0x00
};
byte watchCenter[] = {
0x00,0x00,0x66,0x66,0x00,0x18,0x00,0x00
};
byte watchLeft[] = {
0x00,0x00,0xcc,0xcc,0x00,0x18,0x00,0x00
};
byte watchRight[] = {
0x00,0x00,0x33,0x33,0x00,0x18,0x00,0x00
};



void display(byte* hexData) {
  for (int row = 0; row < 8; row++) {
    byte rowData = hexData[row];
    for (int col = 0; col < 8; col++) {
      // 检查该LED是否应该亮
      if (rowData & (1 << (7 - col))) {
        leds[row * 8 + col] = CRGB::GreenYellow; 
        } else {
          leds[row * 8 + col] = CRGB::Black; 
      }
    }
  }
}

#endif