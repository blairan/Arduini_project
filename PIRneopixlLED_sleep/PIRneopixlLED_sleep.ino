#include <Enerlib.h>
#include <Adafruit_NeoPixel.h>

Energy energy;

const int PIR = 2;
const int pin = 8;
const int numpixel = 8;
int var;
Adafruit_NeoPixel pixels=Adafruit_NeoPixel(numpixel, pin, NEO_GRB + NEO_KHZ800);
byte times = 5;            // 記錄執行次數
volatile byte state = 0;   // 暫存執行狀態
void wakeISR() {
   if (energy.WasSleeping()) {
    state = 1;
  } else {
    state = 2;
  }
}

void OnLED(){
  for (int i = 0; i < numpixel; i++)
  {
    pixels.setPixelColor(i, pixels.Color(170, 150, 50));
    pixels.show();
    delay(10);
  }
}

void OffLED(){
  for (int i = 0; i < numpixel; i++)
  {
    pixels.setPixelColor(i, pixels.Color(0, 0, 0));
    pixels.show();
    delay(10);
  }
}

void setup(){ 
  pixels.begin();
  pixels.clear();
  Serial.begin(9600);
  pinMode(PIR, INPUT);
  
  attachInterrupt(0, wakeISR, CHANGE);  // 附加中斷服務常式
  
  Serial.println("Running...");
}

void loop(){
  if (state == 1) {
    Serial.println("Was sleeping...");
  } else if (state == 2) {
    Serial.println("Was awake...");
  }
  
  state = 0;
  var = digitalRead(PIR);
  if (var == HIGH){
    OnLED();
    delay(15000);
  }else{
    OffLED();
    times++;
    delay(times);
    Serial.println(times);
  }
  if (times > 5) {
    times = 0;
    Serial.println("Go to sleep...");
    energy.PowerDown();
  }
}
