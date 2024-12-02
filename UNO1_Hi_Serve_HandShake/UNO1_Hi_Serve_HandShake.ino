//UNO 1
//SERVER
//HI
//HANDSHAKE

#include <Stepper.h>
#include <Servo.h>

Servo palm;
Servo el;//elbow
int p = 4; //palm pin
int m = 110;
int l = 170;
int r = 50;

int e = 12; //elbow
int me = 0;
int b = 125; //bend
int le = 170;
int re = 50;

int c = 1;
int r7;

const int stepsPerRevolution = 2038;

Stepper myStepper = Stepper(stepsPerRevolution, 8, 10, 9, 11);

void setup()
{
  Serial.begin(9600);
  myStepper.setSpeed(15);

  palm.attach(p);
  palm.write(m);
  el.attach(e);
  el.write(me);

  digitalWrite(13, LOW);
  digitalWrite(7, LOW);
  digitalWrite(5, LOW);
}

void loop()
{
  
  //SERVER
  if ( digitalRead(7) == HIGH)
  {
    c = 0;
    while (c == 0)
    {
      Serial.println("START");
      Serial.println(c);
      serve();
      c++;
      Serial.println(c);
    }
  }
  if (digitalRead(7) == LOW)
  {
    el.write(me);
    delay(500);
  }
  
//HIIII
  if (digitalRead(13) == HIGH)
    {
     c=0;
      while (c == 0)
      {
        Serial.println("START");
        Serial.println(c);
        hi();
        c++;
        Serial.println(c);
      }
    }

//Hand Shake
      if (digitalRead(5) == HIGH)
    {
     c=0;
      while (c == 0)
      {
        Serial.println("START");
        Serial.println(c);
        handShake();
        c++;
        Serial.println(c);
      }
    }
}

void serve()
{
  Serial.println("SERVER");
  el.write(150);
  delay(500);
  return;
}

void hi()
{
  Serial.println("HI");
  myStepper.step(-stepsPerRevolution / 3);
  delay(500);
  el.write(b);
  delay(500);
  for (int i = 0; i <= 5; i++)
  {
    palm.write(r);
    delay(250);
    palm.write(l);
    delay(250);
  }
  palm.write(m);
  delay(250);
  myStepper.step(stepsPerRevolution / 6);
  delay(500);
  for(int i=b;i>=me;i-=5)
  {
  el.write(i);
  delay(100);
  }
  
  return;
}

void handShake()
{
   Serial.println("Shake hand");
  myStepper.step(-stepsPerRevolution / 3);
  delay(1000);
  el.write(160);
  delay(500);
  for (int i =0;i<=3;i++)
  {
    for(int i=180;i>=100;i-=5)
    {
      el.write(i);
      delay(50); 
    }  
  }
  myStepper.step(stepsPerRevolution / 6);
  delay(500);  
  el.write(me);
  return;
}
