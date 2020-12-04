#include <Adafruit_PWMServoDriver.h>

#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
// 1 100~450 上下
// 2 300~600 前後
// 3 400~600 夾子
void setup() {
    Serial.begin(9600);
    Serial.println("8 channel Servo test!");

    pwm.begin();
    pwm.setOscillatorFrequency(27000000);
    pwm.setPWMFreq(60); 
    pwm.setPWM(0, 0, 380);
    pwm.setPWM(1, 0, 350);
    delay(10);

}
  
void loop(){
    // 轉左
    for (int i=380; i<500; i+=10){
        pwm.setPWM(0, 0, i);
        delay(50);
    }
// 下
    for (int i=400; i>50; i-=10){
        pwm.setPWM(1, 0, i);
        delay(50);
    }
// 前
    for (int i=400; i<550; i+=10){
        pwm.setPWM(2, 0, i);
        delay(50);
    }
    
// 夾物
    pwm.setPWM(3, 0, 600);
    delay(50);
    pwm.setPWM(3, 0, 400);
// 上
    for (int i=50; i<350; i+=10){
        pwm.setPWM(1, 0, i);
        delay(50);
    }
// 後
    for (int i=550; i>400; i-=10){
        pwm.setPWM(2, 0, i);
        delay(50);
    }
// 轉右
    for (int i=500; i>300; i-=10){
        pwm.setPWM(0, 0, i);
        delay(50);
    }
// 前
    for (int i=400; i<550; i+=10){
        pwm.setPWM(2, 0, i);
        delay(50);
    }
// 放夾
    pwm.setPWM(3, 0, 600);
    delay(50);
// 上
    for (int i=50; i<350; i+=10){
        pwm.setPWM(1, 0, i);
        delay(50);
    }
// 後
    for (int i=550; i>400; i-=10){
        pwm.setPWM(2, 0, i);
        delay(50);
    }
   
}
