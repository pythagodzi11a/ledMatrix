#ifndef __ACT__
#define __ACT__

#include <Arduino.h>
#include <FastLED.h>
#include "expression.h"

int checkNum = 0;
unsigned long lastCheck = 0;

void colorfulScreen()
{
    for (int HSV_H = 0; HSV_H < 255; HSV_H++)
    {
        for (int light = 0; light < NUM_LEDS; light++)
        {
            leds[light] = CHSV(HSV_H, 255, 255);
        }
        FastLED.show();
        delay(25);
        FastLED.clear();
    }
}

void selfCheck()
{
    for (int lightNum = 0; lightNum < NUM_LEDS; lightNum++)
    {
        leds[lightNum] = CRGB::GreenYellow;
    }
    FastLED.show();
    delay(500);
    FastLED.clear();

    for (int lightNum = 0; lightNum < NUM_LEDS; lightNum++)
    {
        leds[lightNum] = CRGB::White;
    }
    FastLED.show();
    delay(500);
    FastLED.clear();

    displayWhite(tick);
    FastLED.show();
    delay(1000);
    FastLED.clear();
}

void rainbowLight()
{
    fill_rainbow(leds, 64, 0, 3);
    FastLED.show();
    delay(500);
    FastLED.clear();
}

void watchLeftAndRight()
{
    displayWhite(watchCenter);
    FastLED.show();
    delay(100);
    FastLED.clear();

    displayWhite(watchLeft);
    FastLED.show();
    delay(100);
    FastLED.clear();

    displayWhite(watchCenter);
    FastLED.show();
    delay(100);
    FastLED.clear();

    displayWhite(watchRight);
    FastLED.show();
    delay(1000);
    FastLED.clear();
}

void colorfulHeart()
{
    for (int colorSet = 0; colorSet < 255; colorSet++)
    {
        displayColor(heart, colorSet, 255, 255);
        FastLED.show();
    }
}

void switchFace()
{
    int randomNum = random(1, 3);

    switch (randomNum)
    {
    case 1:
        watchLeftAndRight();
        break;

    case 2:
        colorfulScreen();
        break;

    case 3:
        rainbowLight();
        break;

    case 4:
        break;
    }
}

void displayNumber(int num)
{
    switch (num)
    {
    case 1:
        FastLED.clear();
        displayWhite(one);
        FastLED.show();
        break;

    case 2:
        FastLED.clear();
        displayWhite(two);
        FastLED.show();
        break;

    case 3:
        FastLED.clear();
        displayWhite(three);
        FastLED.show();
        break;

    case 4:
        FastLED.clear();
        displayWhite(four);
        FastLED.show();
        break;

    case 5:
        FastLED.clear();
        displayWhite(five);
        FastLED.show();
        break;

    case 6:
        FastLED.clear();
        displayWhite(six);
        FastLED.show();
        break;

    case 7:
        FastLED.clear();
        displayWhite(seven);
        FastLED.show();
        break;

    case 8:
        FastLED.clear();
        displayWhite(eight);
        FastLED.show();
        break;

    case 9:
        FastLED.clear();
        displayWhite(nine);
        FastLED.show();
        break;

    default:
        FastLED.clear();
        displayWhite(wrong);
        FastLED.show();
        delay(1000);
        displayWhite(zero);
        FastLED.show();
        checkNum = 0;
        break;
    }
}

#endif