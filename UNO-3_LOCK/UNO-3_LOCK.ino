/* @file CustomKeypad.pde
|| @version 1.0
|| @author Alexander Brevig
|| @contact alexanderbrevig@gmail.com
||
|| @description
|| | Demonstrates changing the keypad size and key values.
|| #
*/
#include <Keypad.h>
#define Password_Length 5
#include <Servo.h>

Servo servo;
int angle = 0;
int buzz = 11;

bool st = false;

char data[Password_Length];
char master[Password_Length] = "2005";

const byte ROWS = 4;  //four rows
const byte COLS = 4;  //four columns

byte count = 0;
char customKey;

//define the cymbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
  { '1', '2', '3', 'A' },
  { '4', '5', '6', 'B' },
  { '7', '8', '9', 'C' },
  { '*', '0', '#', 'D' }
};
byte rowPins[ROWS] = { 9, 8, 7, 6 };  //connect to the row pinouts of the keypad
byte colPins[COLS] = { 5, 4, 3, 2 };  //connect to the column pinouts of the keypad

//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

void setup() {
  Serial.begin(9600);
  servo.attach(10);
  servo.write(angle);
  delay(2000);
  pinMode(buzz, OUTPUT);
  digitalWrite(buzz, LOW);
}

void loop()
 {

  if (digitalRead(12) == HIGH)  //connected to evive pin 9
  {
    //Serial.println("Enter password");
    
    pswData();

    if (count == Password_Length - 1) {
      if (!strcmp(data, master)) {
        st = true;
        Serial.println("correct");
        servo.write(135);
        delay(1000);
        digitalWrite(buzz, LOW);
        clearData();

        while (st == true) {
          pswData();
          if (!strcmp(data, "#")) {
            Serial.println("lock");
            servo.write(30);
            delay(1000);
            st = false;
          }
        }
      } else {
        Serial.println("wrong");
        servo.write(30);
        delay(1000);
        digitalWrite(buzz, HIGH);
      }
      clearData();
    }
  }
  else if(digitalRead(12) == LOW)
  {
    Serial.println("lock");
    servo.write(30);
    delay(2000);
    pinMode(buzz, OUTPUT);
    digitalWrite(buzz, LOW);    
  }
}

void clearData() 
{
  while (count != 0) {
    data[count--] = 0;
  }
  return;
}

void pswData() 
{
  char customKey = customKeypad.getKey();
  if (customKey) {

    data[count] = customKey;
    Serial.print(customKey);
    count++;
  }
}
