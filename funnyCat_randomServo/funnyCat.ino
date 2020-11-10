#include <Servo.h>
Servo servo1, servo2;
byte leserLed=3;
byte pan;
byte tilt;
int speed;
int s1Min=20;
int s1Max=160;
int s2Min=40;
int s2Max=140;
int speedMin=100;
int speedMax=800;
void setup() {

    Serial.begin(9600);
    pinMode(leserLed, OUTPUT);
    digitalWrite(leserLed, HIGH);
    servo2.attach(8);
    servo1.attach(6);
    servo1.write(90);
    servo2.write(90);
}
void loop() {
    speed=random(speedMin, speedMax);
    pan=random(s1Min, s1Max);
    tilt=random(s2Min, s2Max);
    if (pan>90){
        pan+=10;
    }else if (pan<90){
        pan-=10;
    }
    if (tilt>90){
        tilt+=10;
    }else if (tilt<90){
        tilt-=10;
    }
    servo1.write(pan);
    servo2.write(tilt);
    Serial.print(pan);
    Serial.println(tilt);
    delay(speed);
  
}
