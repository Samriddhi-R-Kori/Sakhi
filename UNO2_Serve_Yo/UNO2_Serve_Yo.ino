//UNO 2
//SERVER
//YO

#include <Stepper.h>
#include <Servo.h>

Servo el;  //elbow
Servo pa;  //palm

int p = 13;  //palm pin
int yoo = 180;
int m = 10;

int e = 12;  //elbow
int me = 180;
int b = 90;  //bend

int c = 1;
int r7;

const int stepsPerRevolution = 2038;

Stepper myStepper = Stepper(stepsPerRevolution, 8, 10, 9, 11);

void setup() {
  Serial.begin(9600);
  myStepper.setSpeed(15);

  el.attach(e);
  el.write(180);
  pa.attach(p);
  pa.write(0);

  digitalWrite(13, LOW);
  digitalWrite(7, LOW);
  digitalWrite(5, LOW);
}

void loop() {

  //SERVER
  if (digitalRead(7) == HIGH) {
    c = 0;
    while (c == 0) {
      Serial.println("START");
      Serial.println(c);
      serve();
      c++;
      Serial.println(c);
    }
  }
  if (digitalRead(7) == LOW) {
    el.write(me);
    delay(500);
  }

  //YO
  if (digitalRead(6) == HIGH) {
    c = 0;
    while (c == 0) {
      Serial.println("START");
      Serial.println(c);
      yo();
      c++;
      Serial.println(c);
    }
  }
  if (digitalRead(6) == LOW) {
    pa.write(m);
    delay(500);
  }
}

void serve() {
  Serial.println("SERVER");
  el.write(10);
  delay(500);
  return;
}

  void yo()
{
  Serial.println("YOO");
  el.write(0);
  delay(2000);
  Serial.println("elbow bent");
  pa.write(180);
  delay(3000);
  Serial.println("yo done");
  //pa.write(yoo);
  //delay(1000);
  pa.write(0);
  delay(500);
  Serial.println("yo lowered");
  for(int i = 0;i<=180;i+=5)
  {
  el.write(i);
  delay(100);
  }
  Serial.println("elbow down");
  return;
}
