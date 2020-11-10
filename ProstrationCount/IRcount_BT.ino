#include <Led4digit74HC595.h>
#include <SoftwareSerial.h>

SoftwareSerial BluetoothSerial(3, 4); // TX, RX
Led4digit74HC595 myLedDisplay(A2, A1, A0);  // Pins:(SCLK, RCLK, DIO)

int var;
unsigned long temp;
int c = 0;


void setup() {
    Serial.begin(9600);
    Serial.println("Start...");
    BluetoothSerial.begin(9600);
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
      if (c<=10){
        temp=millis();
        c++;
        myLedDisplay.setNumber(c);  // Set number to be show on display
        Serial.println(c);
        BluetoothSerial.write("c");
        BluetoothSerial.write(c);
      }else{
        c=0;
      }
    }
  }
}
