#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
//x 150~600
const int x=A0;
const int y=A1;
const int z=A2;
const int grad=A3;
int xpos=450;
int ypos=450;
int zpos=450;
int gradpos=200;
int X_VAL; //left/right
int Y_VAL; //forward/back
int Z_VAL; //up/down
int grad_VAL;

void setup(){
    Serial.begin(9600);
    Serial.println("Servo value is diplay");
    pwm.begin();
    pwm.setOscillatorFrequency(27000000);
    pwm.setPWMFreq(60);
    pwm.setPWM(0, 0, 380);
    pwm.setPWM(1, 0, 380);
    pwm.setPWM(2, 0, 380);
    pwm.setPWM(3, 0, 200);
    delay(10);
}

void loop(){
    X_VAL=analogRead(x);
    X_VAL=map(X_VAL, 0, 1023, 150, 600);
    Y_VAL=analogRead(y);
    Y_VAL=map(Y_VAL, 0, 1023, 150, 600);
    Z_VAL=analogRead(z);
    Z_VAL=map(Z_VAL, 0, 1023, 150, 600);
    grad_VAL=analogRead(grad);
    grad_VAL=map(grad_VAL, 0, 1023, 150, 600);

    if (X_VAL<200){
      delay(50);
      if (xpos>150){
        xpos-=10;
        pwm.setPWM(0, 0, xpos);
        Serial.print("THE xpos is = ");
        Serial.println(xpos);
      }
    }else if (X_VAL>500){
      delay(50);
      if (xpos<600){
        xpos+=10;
        pwm.setPWM(0, 0, xpos);
        Serial.print("THE xpos is = ");
        Serial.println(xpos);
        
      }
    }

    if (Y_VAL<200){
      delay(50);
      if (ypos>270){
        ypos-=10;
        pwm.setPWM(1, 0, ypos);
        Serial.print("THE ypos is = ");
        Serial.println(ypos);
      }
    }else if (Y_VAL>500){
      delay(50);
      if (ypos<600){
        ypos+=10;
        pwm.setPWM(1, 0, ypos);
        Serial.print("THE ypos is = ");
        Serial.println(ypos);
      }
    }

     if (Z_VAL<280){
      delay(50);
      if (zpos>280){
        zpos-=10;
        pwm.setPWM(2, 0, zpos);
        Serial.print("THE ypos is = ");
        Serial.println(zpos);
      }
    }else if (Z_VAL>500){
      delay(50);
      if (zpos<600){
        zpos+=10;
        pwm.setPWM(2, 0, zpos);
        Serial.print("THE zpos is = ");
        Serial.println(zpos);
      }
    }
    
    if (grad_VAL<200){
      delay(50);
      if (gradpos>200){
        gradpos-=10;
        pwm.setPWM(3, 0, gradpos);
        Serial.print("THE gradpos is = ");
        Serial.println(gradpos);
      }
    }else if (grad_VAL>500){
      delay(50);
      if (gradpos<450){
        gradpos+=10;
        pwm.setPWM(3, 0, gradpos);
        Serial.print("THE gradpos is = ");
        Serial.println(gradpos); 
      }
    }
}
