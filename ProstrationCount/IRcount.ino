/*
  Simple test 7 segment LED x 4 bits digital tube display with 2 x 74HC595
  This module must use multiplexing bits, not possible set static show bits all at once!

  Count number from -20 to +9999 every one second
*/ 

#include <Led4digit74HC595.h>

Led4digit74HC595 myLedDisplay(A2, A1, A0);  // Pins:(SCLK, RCLK, DIO)
int var;
unsigned long temp;
int count = 0;


void setup() {
    Serial.begin(9600);
    Serial.println("Start...");
    myLedDisplay.setDecimalPoint(0);
    myLedDisplay.setNumber(0);  // Set number to be show on display
                                //初始值預設為0
}


void loop() {  
  myLedDisplay.loopShow();  // Must be call in every program loop - automatic multiplexing and show numbers on display
  var=digitalRead(8);
  if( millis() - temp >= 3000) //一個回圈裡被包含在秒裡,意思是遮斷紅外線3秒內不會再次作用
  {
    if (var==LOW){
      if (count<=10){
        temp=millis();
        count++;
        myLedDisplay.setNumber(count);  // Set number to be show on display
        Serial.println(count);
      }else{
        count=0;
      }
    }
  }
}
