#include <Servo.h> // servo library 
Servo servo1;
Servo servo2;
Servo servo3;

const int x=A0;
const int y=A1;
const int g=A5;

int valx;
int valy;
int valg;
int test;

int xpos=90;
int ypos=90;


//測試伺服器最大最小角度
void testServo(){
  test=analogRead(valx);
  test=map(valx, 0, 1023, 0, 179);
  Serial.println(valx);
  servo1.write(valx);
  delay(500);
}

void setup() {
  Serial.begin(9600);
  servo1.attach(8);
  servo1.write(90);
  servo2.attach(10);
  servo2.write(90);
  servo3.attach(12);
}

void loop() {
  //testServo();
  valx=analogRead(x);
  valy=analogRead(y);
  valg=analogRead(g);

  valx=map(valx, 0, 1023, 0, 179); //偵測上下
  valy=map(valy, 0, 1023, 0, 179); //偵測前後
  valg=map(valg, 0, 1023, 0, 179); //爪子
  if (valx>150){
    delay(50);
    if (xpos<170){
      xpos+=10;
      Serial.println(valx);
      servo1.write(xpos);
    }
    }else if (valx<30){
    delay(50);
    if (xpos>50){
      xpos-=10;
      Serial.println(valx);
      servo1.write(xpos);
    } 
  }
  if (valy>150){
    delay(50);
    if (ypos<170){
      ypos+=10;
      Serial.println(valy);
      servo2.write(ypos);
    }
    }else if (valy<30){
    delay(50);
    if (ypos>30){
      ypos-=10;
      Serial.println(valy);
      servo2.write(ypos);
    }
  }

  //爪子
  servo3.write(valg);
  
}
