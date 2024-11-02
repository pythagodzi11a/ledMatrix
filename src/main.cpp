#include <Arduino.h>
#include <FastLED.h>
#include "expression.h"
#include "act.h"

// Declaration of functions
void clickTick();

// Button
#define BUTTON A1
#define DEBOUNCE 140

byte buttonStatusCurrent = LOW;
byte buttonStatusPrevious = LOW;

// FastLED 初始化
#define NUM_LEDS 64
#define DATA_PIN A0
#define LED_TYPE WS2812
#define COLOR_ORDER GRB

void setup()
{
  // put your setup code here, to run once:
  pinMode(BUTTON, INPUT_PULLUP);
  Serial.begin(9600);

  LEDS.addLeds<LED_TYPE, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS);
  FastLED.setBrightness(max_bright);

  pinMode(BUTTON, INPUT); // When pressed, turn to high

  selfCheck();

  delay(50);
}

void loop()
{
  // put your main code here, to run repeatedly:
  buttonStatusCurrent = digitalRead(BUTTON);
  clickTick();
  buttonStatusPrevious = buttonStatusCurrent;
}

void clickTick()
{
  static byte pressCount = 0;
  static unsigned long clickMaxPeriod = 1000;
  static unsigned long startTime = 0;
  static bool isStart = false;

  if ((buttonStatusCurrent == LOW) && (buttonStatusPrevious == HIGH))
  {
    if (isStart == false)
    {
      pressCount = 1;
      displayWhite(one);
      FastLED.show();
      delay(100);
      isStart = true;
      startTime = millis();
    }
    else
    {
      pressCount++;
      displayNumber(pressCount);
      startTime = millis();

      FastLED.show();
      delay(100);
    }
    delay(DEBOUNCE);
  }

  if (((millis() - startTime) > clickMaxPeriod) && isStart)
  {
    isStart = false;

    switch (pressCount)
    {
    case 1:
      colorfulHeart();
      FastLED.clear();
      break;

    case 2:
      watchLeftAndRight();
      FastLED.clear();
      break;

    case 3:
      rainbowLight();
      FastLED.clear();
      break;

    case 4:
      colorfulScreen();
      FastLED.clear();
      break;

    case 5:
      displayWhite(sigama);
      FastLED.show();
      break;
    }
  }
}

/*void checkButton(){
  int buttonStatus = digitalRead(BUTTON);

  int nowTime = millis();

  if (millis() - nowTime > 2000){
    switch(checkNum){
      case 1:
      displayWhite(one);
      case 2:
      displayWhite(two);
    }
  }

  if (!buttonStatus){//判断按钮是否按下
    delay(250);
    if (!buttonStatus){//此时确定按钮被按下
      if (millis() - lastCheck > 1000){//如果距离上次按下未超时,判断是否为第一次按下？？？

      Serial.println(checkNum);

      checkNum = 1;


      lastCheck = millis();
      }else{
        lastCheck = millis();
        checkNum++;

        Serial.println(checkNum);

        displayNumber(checkNum);
      }
    }
  }
}
*/