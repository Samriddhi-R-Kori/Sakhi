//ALZHIEMERS TABLET WATER
//ANTI-THEFT MODE

#include <Servo.h>

Servo servo;
int s = 8;  //servo

long duration;
int distance;
int e = 6;  //echo
int t = 7;  //trig

int b = 12;  //buzzer
int x = 0;   //call distance method
int wb = 9;  // water button
int sw;

boolean st = true;   //stop tablet
boolean swa = true;  //stop water
int m = 5;           //motion

void setup() 
{
  servo.attach(s);
  servo.write(65);

  pinMode(t, OUTPUT);
  pinMode(e, INPUT);
  pinMode(m, INPUT);
  digitalWrite(m, LOW);

  digitalWrite(11, LOW);  //Tablet
  digitalWrite(23, LOW);  //water
  digitalWrite(24, LOW);  //Antitheft mega to evive --> SMS & Call
  pinMode(b, OUTPUT);
  digitalWrite(b, LOW);

  pinMode(wb, INPUT);
  digitalWrite(wb, 1);

  st = true;
  swa = true;


  Serial.begin(9600);
}

void loop() 
{
  if (digitalRead(11) == HIGH) 
  {
    //st=true;
    tablet();
  }
  if (digitalRead(23) == HIGH) 
  {
    //swa=true;
    water();
  }

  if ((digitalRead(11) == LOW && digitalRead(23) == LOW)) 
  {
    Serial.println("LOW");
  }
}

void tablet() 
{
  while (st == true) 
  {
    if ((digitalRead(11) == HIGH)) 
    {
      Serial.print("Tablet  ");
      x = dis();
      while (x > 25) 
      {
        x = dis();
        digitalWrite(b, HIGH);
        Serial.println(distance);
        Serial.println("  buzzz");
      }
      Serial.println("servo");
      digitalWrite(b, LOW);
      for (int i = 65;i>=25;i-=5)
      {
      servo.write(i);
      delay(100);
      }
      delay(2000);
      servo.write(65);
      delay(500);
      digitalWrite(11, LOW);
      st = false;
    }
  }
}

void water() 
{
  while (swa == true) 
  {
    Serial.print("swa");
    if ((digitalRead(23) == 1)) 
    {
      Serial.print("Water  ");
      digitalWrite(b, HIGH);
      sw = digitalRead(wb);
      delay(250);
      Serial.println(sw);
      if (sw == 0) 
      {
        sw = digitalRead(wb);
        delay(250);
        Serial.println(sw);
        Serial.println("  buzzz");
      }
      if (sw == 1) 
      {
        digitalWrite(b, LOW);
        digitalWrite(23, LOW);
        swa = false;
      }
    }
    //digitalWrite(23, LOW);
  }
}

int dis() 
{
  digitalWrite(t, LOW);
  delayMicroseconds(2);
  digitalWrite(t, HIGH);
  delayMicroseconds(10);
  digitalWrite(t, LOW);
  duration = pulseIn(e, HIGH);
  distance = duration * 0.034 / 2;
  //Serial.println(distance);
  return distance;
}