//1 - 1 1 1 1 1
//2 - 1111  1111 -->    1111
//3 - 11111 --> 1111 --> 111 --> 11 --> 1
//4 - 1  1  1  1  1  1
//5 - 11 1 1 1
//6 - 11111 11111
//7 - 11 1 1 1 1 11 1 1 1 1

#define t 30
#define t1 20
#define t2 100
#define t3 50

void setup() 
{
  digitalWrite(22,LOW);
  // set up pins 2 to 13 as outputs
  for (int i = 2; i <= 13; i++) 
  {
    pinMode(i, OUTPUT);
  }

  OFF();
}
/////////////////////////////////////////////////////////////////////////////////Effect 1
void loop() 
{
  if (digitalRead(22) == HIGH) //Evive pin 12
  {
    ON();
  }
  else
  {
    OFF();
  }
}

void ON() 
{
  for (int i = 2; i <= 13; i++) 
  {
    digitalWrite(i, HIGH);
  }
}
void OFF()
{
  for (int i = 2; i <= 13; i++) 
  {
    digitalWrite(i, LOW);
  }
}
