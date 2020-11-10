#include <Servo.h>
Servo servo1, servo2;
#define PI 3.1416;
const int Xpin=A0;
const int Ypin=A1;
const int Zpin=A2;
const int sleep=2;
int Xval, Yval, Zval;
double Xg, Yg, Zg;
double Xdeg, Ydeg, Zdeg;

void setup() {
    pinMode(sleep, OUTPUT);
    digitalWrite(sleep, HIGH);
    Serial.begin(9600);
    servo2.attach(8);
    servo1.attach(6);
    servo1.write(90);
    servo2.write(90);
}
void loop() {
    
    
    Xval=analogRead(Xpin);
    Yval=analogRead(Ypin);
    Zval=analogRead(Zpin);

    // Xg=double(Xval-330)/160; //double為計算精位浮點數
    // Xg=constrain(Xg, -1, 1); //constrain為規定數值的範圍
    // Xdeg=asin(Xg)*180/PI;

    // Yg=double(Yval-330)/160;
    // Yg=constrain(Yg, -1, 1);
    // Ydeg=asin(Yg)*180/PI;

    // Zg=double(Zval-330)/160;
    // Zg=constrain(Zg, -1, 1);
    // Zdeg=asin(Zg)*180/PI;

    Xval=map(Xval, 170, 490, 0, 180);
    Yval=map(Yval, 170, 490, 0, 180);
    servo1.write(Xval);
    servo2.write(Yval);
    delay(500);
}
