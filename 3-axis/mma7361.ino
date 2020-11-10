#define PI 3.1416;
const int Xpin=A0;
const int Ypin=A1;
const int Zpin=A2;
const int sleep=2;
int Xval, Yval, Zval;
double Xg, Yg, Zg;
double Xdeg, Ydeg, Zdeg;
void setup() {
  Serial.begin(9600);
  pinMode(sleep, OUTPUT);
  digitalWrite(sleep, HIGH);
}

void loop() {
  Xval=analogRead(Xpin);
  Yval=analogRead(Ypin);
  Zval=analogRead(Zpin);

  Xg=double(Xval-330)/160;
  Xg=constrain(Xg, -1, 1);
  Xdeg=asin(Xg)*180/PI;

  Yg=double(Yval-330)/160;
  Yg=constrain(Yg, -1, 1);
  Ydeg=asin(Yg)*180/PI;

  Zg=double(Zval-330)/160;
  Zg=constrain(Zg, -1, 1);
  Zdeg=asin(Zg)*180/PI;

  Serial.print("VALUE(X:Y:Z)= ");
  Serial.print(Xval);
  Serial.print(" : ");
  Serial.print(Yval);
  Serial.print(" : ");
  Serial.print(Zval);
  Serial.print(" ");
  Serial.println();

  Serial.print("G(X:Y:Z)= ");
  Serial.print(Xdeg);
  Serial.print(" : ");
  Serial.print(Ydeg);
  Serial.print(" : ");
  Serial.print(Zdeg);
  Serial.print(" ");
  Serial.println();
  delay(1000);
}
