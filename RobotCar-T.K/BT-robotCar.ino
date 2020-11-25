#include <SoftwareSerial.h>
SoftwareSerial BTserial(3, 4);
char val;
int E1 = 10; //pwm
int M1 = 12;
int E2 = 11; //pwm
int M2 = 13;
//R_speed & L_speed  0~255
void forward(byte R_SPEED, byte L_SPEED)
{
  analogWrite(E1, R_SPEED);
  analogWrite(E2, L_SPEED);
  digitalWrite(M1, HIGH);
  digitalWrite(M2, HIGH);
  delay(50);
}

void back(byte R_SPEED, byte L_SPEED)
{
  analogWrite(E1, R_SPEED);
  analogWrite(E2, L_SPEED);
  digitalWrite(M1, LOW);
  digitalWrite(M2, LOW);
  delay(50);
}

void right(byte R_SPEED, byte L_SPEED){
  analogWrite(E1, R_SPEED);
  analogWrite(E2, L_SPEED);
  digitalWrite(M1, HIGH);
  digitalWrite(M2, LOW);
  delay(50);
}

void left(byte R_SPEED, byte L_SPEED){
  analogWrite(E1, R_SPEED);
  analogWrite(E2, L_SPEED);
  digitalWrite(M1, LOW);
  digitalWrite(M2, HIGH);
  delay(50);
}

void stop(byte R_SPEED, byte L_SPEED)
{
  analogWrite(E1, R_SPEED);
  analogWrite(E2, L_SPEED);
  digitalWrite(M1, HIGH);
  digitalWrite(M2, HIGH);
  // delay(50);
}

void setup()
{
  BTserial.begin(9600);
  pinMode(M1, OUTPUT);
  pinMode(M2, OUTPUT);
}

void loop()
{
  if (BTserial.available()){
    val=BTserial.read();
    
    if (val=='0'){
      stop(0, 0);
    }else if (val=='1'){
      forward(100, 100);
    }else if (val=='2'){
      back(100, 100);
    }else if (val=='3'){
      left(70, 100);
    }else if (val=='4'){
      right(100, 70);
    }
    
  }
}
