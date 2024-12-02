#include <Wire.h> 

#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978
#define REST      0

int tempo = 140;

int buzzer = 12;
int tonePin = 12;

int BuzzerPin = 12;     // Connect Buzzer to Arduino pin 11

int Si2 =1975;
int LaS2=1864;
int La2= 1760;
int SolS2=1661;
int Sol2=1567;
int FaS2=1479;
int Fa2= 1396;
int Mi2= 1318;
int ReS2=1244;
int Re2= 1174;
int DoS2=1108;
int Do2= 1046;

// Low Octave
int Si = 987;
int LaS= 932;
int La = 880;
int SolS=830;
int Sol= 783;
int FaS= 739;
int Fa=  698;
int Mi=  659;
int ReS= 622;
int Re = 587;
int DoS =554;
int Do = 523;

// define the notes
int rounda=0;
int roundp=0;
int white= 0;
int whitep=0;
int black=0;  
int blackp=0;
int quaver=0;
int quaverp =0;
int semiquaver=0;
int semiquaverp=0;
int bpm= 120;

//***************************************************************
//HAPPY BIRTHDAY SONG
//***************************************************************

int melodyHB[] = 
{
  NOTE_C4,4, NOTE_C4,8, 
  NOTE_D4,-4, NOTE_C4,-4, NOTE_F4,-4,
  NOTE_E4,-2, NOTE_C4,4, NOTE_C4,8, 
  NOTE_D4,-4, NOTE_C4,-4, NOTE_G4,-4,
  NOTE_F4,-2, NOTE_C4,4, NOTE_C4,8,

  NOTE_C5,-4, NOTE_A4,-4, NOTE_F4,-4, 
  NOTE_E4,-4, NOTE_D4,-4, NOTE_AS4,4, NOTE_AS4,8,
  NOTE_A4,-4, NOTE_F4,-4, NOTE_G4,-4,
  NOTE_F4,-2,
};

void Happy_Birthday()
{
int notes = sizeof(melodyHB) / sizeof(melodyHB[0]) / 2;

int wholenote = (60000 * 4) / tempo;

int divider = 0, noteDuration = 0;

for (int thisNote = 0; thisNote < notes * 2; thisNote = thisNote + 2) 
{

    divider = melodyHB[thisNote + 1];
    if (divider > 0) 
    {
      // regular note, just proceed
      noteDuration = (wholenote) / divider;
    } 
    else if (divider < 0) 
    {
      // dotted notes are represented with negative durations!!
      noteDuration = (wholenote) / abs(divider);
      noteDuration *= 1.5; // increases the duration in half for dotted notes
    }

    // we only play the note for 90% of the duration, leaving 10% as a pause
    tone(buzzer, melodyHB[thisNote], noteDuration * 0.9);

    // Wait for the specief duration before playing the next note.
    delay(noteDuration);

    // stop the waveform generation before the next note.
    noTone(buzzer);
  }
}

//***************************************************************
//WE WISH YOU A MERRY CHRISTMAS
//***************************************************************
int melodyC[] = 
{
  NOTE_C5,4, //1
  NOTE_F5,4, NOTE_F5,8, NOTE_G5,8, NOTE_F5,8, NOTE_E5,8,
  NOTE_D5,4, NOTE_D5,4, NOTE_D5,4,
  NOTE_G5,4, NOTE_G5,8, NOTE_A5,8, NOTE_G5,8, NOTE_F5,8,
  NOTE_E5,4, NOTE_C5,4, NOTE_C5,4,
  NOTE_A5,4, NOTE_A5,8, NOTE_AS5,8, NOTE_A5,8, NOTE_G5,8,
  NOTE_F5,4, NOTE_D5,4, NOTE_C5,8, NOTE_C5,8,
  NOTE_D5,4, NOTE_G5,4, NOTE_E5,4,

  NOTE_F5,2, NOTE_C5,4, //8 
  NOTE_F5,4, NOTE_F5,8, NOTE_G5,8, NOTE_F5,8, NOTE_E5,8,
  NOTE_D5,4, NOTE_D5,4, NOTE_D5,4,
  NOTE_G5,4, NOTE_G5,8, NOTE_A5,8, NOTE_G5,8, NOTE_F5,8,
  NOTE_E5,4, NOTE_C5,4, NOTE_C5,4,
  NOTE_A5,4, NOTE_A5,8, NOTE_AS5,8, NOTE_A5,8, NOTE_G5,8,
  NOTE_F5,4, NOTE_D5,4, NOTE_C5,8, NOTE_C5,8,
  NOTE_D5,4, NOTE_G5,4, NOTE_E5,4,
  NOTE_F5,2, NOTE_C5,4,

  NOTE_F5,4, NOTE_F5,4, NOTE_F5,4,//17
  NOTE_E5,2, NOTE_E5,4,
  NOTE_F5,4, NOTE_E5,4, NOTE_D5,4,
  NOTE_C5,2, NOTE_A5,4,
  NOTE_AS5,4, NOTE_A5,4, NOTE_G5,4,
  NOTE_C6,4, NOTE_C5,4, NOTE_C5,8, NOTE_C5,8,
  NOTE_D5,4, NOTE_G5,4, NOTE_E5,4,
  NOTE_F5,2, NOTE_C5,4, 
  NOTE_F5,4, NOTE_F5,8, NOTE_G5,8, NOTE_F5,8, NOTE_E5,8,
  NOTE_D5,4, NOTE_D5,4, NOTE_D5,4,
  
  NOTE_G5,4, NOTE_G5,8, NOTE_A5,8, NOTE_G5,8, NOTE_F5,8, //27
  NOTE_E5,4, NOTE_C5,4, NOTE_C5,4,
  NOTE_A5,4, NOTE_A5,8, NOTE_AS5,8, NOTE_A5,8, NOTE_G5,8,
  NOTE_F5,4, NOTE_D5,4, NOTE_C5,8, NOTE_C5,8,
  NOTE_D5,4, NOTE_G5,4, NOTE_E5,4,
  NOTE_F5,2, NOTE_C5,4,
  NOTE_F5,4, NOTE_F5,4, NOTE_F5,4,
  NOTE_E5,2, NOTE_E5,4,
  NOTE_F5,4, NOTE_E5,4, NOTE_D5,4,
  
  NOTE_C5,2, NOTE_A5,4,//36
  NOTE_AS5,4, NOTE_A5,4, NOTE_G5,4,
  NOTE_C6,4, NOTE_C5,4, NOTE_C5,8, NOTE_C5,8,
  NOTE_D5,4, NOTE_G5,4, NOTE_E5,4,
  NOTE_F5,2, NOTE_C5,4, 
  NOTE_F5,4, NOTE_F5,8, NOTE_G5,8, NOTE_F5,8, NOTE_E5,8,
  NOTE_D5,4, NOTE_D5,4, NOTE_D5,4,
  NOTE_G5,4, NOTE_G5,8, NOTE_A5,8, NOTE_G5,8, NOTE_F5,8, 
  NOTE_E5,4, NOTE_C5,4, NOTE_C5,4,
  
  NOTE_A5,4, NOTE_A5,8, NOTE_AS5,8, NOTE_A5,8, NOTE_G5,8,//45
  NOTE_F5,4, NOTE_D5,4, NOTE_C5,8, NOTE_C5,8,
  NOTE_D5,4, NOTE_G5,4, NOTE_E5,4,
  NOTE_F5,2, NOTE_C5,4,
  NOTE_F5,4, NOTE_F5,8, NOTE_G5,8, NOTE_F5,8, NOTE_E5,8,
  NOTE_D5,4, NOTE_D5,4, NOTE_D5,4,
  NOTE_G5,4, NOTE_G5,8, NOTE_A5,8, NOTE_G5,8, NOTE_F5,8,
  NOTE_E5,4, NOTE_C5,4, NOTE_C5,4,
  
  NOTE_A5,4, NOTE_A5,8, NOTE_AS5,8, NOTE_A5,8, NOTE_G5,8, //53
  NOTE_F5,4, NOTE_D5,4, NOTE_C5,8, NOTE_C5,8,
  NOTE_D5,4, NOTE_G5,4, NOTE_E5,4,
  NOTE_F5,2, REST,4
};

int notes = sizeof(melodyC) / sizeof(melodyC[0]) / 2;

int wholenote = (60000 * 4) / tempo;

int divider = 0, noteDuration = 0;

void Christmas()
{
for (int thisNote = 0; thisNote < notes * 2; thisNote = thisNote + 2) {

    // calculates the duration of each note
    divider = melodyC[thisNote + 1];
    if (divider > 0) {
      // regular note, just proceed
      noteDuration = (wholenote) / divider;
    } else if (divider < 0) {
      // dotted notes are represented with negative durations!!
      noteDuration = (wholenote) / abs(divider);
      noteDuration *= 1.5; // increases the duration in half for dotted notes
    }

    // we only play the note for 90% of the duration, leaving 10% as a pause
    tone(buzzer, melodyC[thisNote], noteDuration * 0.9);

    // Wait for the specief duration before playing the next note.
    delay(noteDuration);

    // stop the waveform generation before the next note.
    noTone(buzzer);
  }
}


//***************************************************************
//BELIEVER
//***************************************************************
void Believer()
{
  tone(tonePin, 466, 341.5);
delay(379.444444444);
delay(20.5555555556);
tone(tonePin, 698, 341.5);
delay(379.444444444);
delay(20.5555555556);
tone(tonePin, 622, 341.5);
delay(379.444444444);
delay(20.5555555556);
tone(tonePin, 622, 227.5);
delay(252.777777778);
delay(13.8888888889);
tone(tonePin, 554, 113.5);
delay(126.111111111);
delay(7.22222222222);
tone(tonePin, 622, 341.5);
delay(379.444444444);
delay(20.5555555556);
tone(tonePin, 622, 227.5);
delay(252.777777778);
delay(13.8888888889);
tone(tonePin, 698, 113.5);
delay(126.111111111);
delay(7.22222222222);
tone(tonePin, 622, 227.5);
delay(252.777777778);
delay(13.8888888889);
tone(tonePin, 554, 113.5);
delay(126.111111111);
delay(7.22222222222);
tone(tonePin, 466, 227.5);
delay(252.777777778);
delay(13.8888888889);
tone(tonePin, 415, 113.5);
delay(126.111111111);
delay(7.22222222222);
tone(tonePin, 466, 341.5);
delay(379.444444444);
delay(20.5555555556);
tone(tonePin, 698, 341.5);
delay(379.444444444);
delay(20.5555555556);
tone(tonePin, 622, 341.5);
delay(379.444444444);
delay(20.5555555556);

tone(tonePin, 622, 227.5);
delay(252.777777778);
delay(13.8888888889);
tone(tonePin, 554, 113.5);
delay(126.111111111);
delay(7.22222222222);
tone(tonePin, 622, 341.5);
delay(379.444444444);
delay(20.5555555556);
tone(tonePin, 622, 227.5);
delay(252.777777778);
delay(13.8888888889);
tone(tonePin, 698, 113.5);
delay(126.111111111);
delay(7.22222222222);
tone(tonePin, 622, 227.5);
delay(252.777777778);
delay(13.8888888889);
tone(tonePin, 554, 113.5);
delay(126.111111111);
delay(7.22222222222);
tone(tonePin, 466, 227.5);
delay(252.777777778);
delay(13.8888888889);
tone(tonePin, 415, 113.5);
delay(126.111111111);
delay(7.22222222222);
tone(tonePin, 466, 341.5);
delay(379.444444444);
delay(20.5555555556);
tone(tonePin, 554, 341.5);
delay(379.444444444);
delay(20.5555555556);
tone(tonePin, 932, 683.5);
delay(759.444444444);
delay(40.5555555556);
tone(tonePin, 698, 455.5);
delay(506.111111111);
delay(160.555555556);
tone(tonePin, 698, 113.5);
delay(126.111111111);
delay(7.22222222222);
tone(tonePin, 622, 227.5);
delay(252.777777778);
delay(13.8888888889);
tone(tonePin, 554, 113.5);
delay(126.111111111);
delay(7.22222222222);
tone(tonePin, 466, 227.5);
delay(252.777777778);
delay(13.8888888889);
tone(tonePin, 415, 113.5);
delay(126.111111111);
delay(7.22222222222);

tone(tonePin, 466, 341.5);
delay(379.444444444);
delay(20.5555555556);
tone(tonePin, 554, 341.5);
delay(379.444444444);
delay(20.5555555556);
tone(tonePin, 932, 683.5);
delay(759.444444444);
delay(40.5555555556);
tone(tonePin, 880, 1367.5);
delay(1519.44444444);
delay(80.5555555556);
tone(tonePin, 466, 227.5);
delay(252.777777778);
delay(13.8888888889);
tone(tonePin, 466, 113.5);
delay(126.111111111);
delay(7.22222222222);
tone(tonePin, 698, 341.5);
delay(379.444444444);
delay(20.5555555556);
tone(tonePin, 622, 227.5);
delay(252.777777778);
delay(13.8888888889);
tone(tonePin, 622, 113.5);
delay(126.111111111);
delay(7.22222222222);
tone(tonePin, 622, 227.5);
delay(252.777777778);
delay(13.8888888889);
tone(tonePin, 554, 113.5);
delay(126.111111111);
delay(7.22222222222);
tone(tonePin, 622, 227.5);
delay(252.777777778);
delay(13.8888888889);
tone(tonePin, 622, 113.5);
delay(126.111111111);
delay(7.22222222222);
tone(tonePin, 622, 227.5);
delay(252.777777778);
delay(13.8888888889);
tone(tonePin, 698, 113.5);
delay(126.111111111);
delay(7.22222222222);
tone(tonePin, 622, 227.5);
delay(252.777777778);
delay(13.8888888889);
tone(tonePin, 554, 113.5);
delay(126.111111111);
delay(7.22222222222);
tone(tonePin, 466, 227.5);
delay(252.777777778);
delay(13.8888888889);

tone(tonePin, 415, 113.5);
delay(126.111111111);
delay(7.22222222222);
tone(tonePin, 466, 341.5);
delay(379.444444444);
delay(20.5555555556);
tone(tonePin, 698, 227.5);
delay(252.777777778);
delay(13.8888888889);
tone(tonePin, 698, 113.5);
delay(126.111111111);
delay(7.22222222222);
tone(tonePin, 622, 341.5);
delay(379.444444444);
delay(20.5555555556);
tone(tonePin, 622, 227.5);
delay(252.777777778);
delay(13.8888888889);
tone(tonePin, 554, 113.5);
delay(126.111111111);
delay(7.22222222222);
tone(tonePin, 622, 341.5);
delay(379.444444444);
delay(20.5555555556);
tone(tonePin, 622, 227.5);
delay(252.777777778);
delay(13.8888888889);
tone(tonePin, 698, 113.5);
delay(126.111111111);
delay(7.22222222222);
tone(tonePin, 622, 227.5);
delay(252.777777778);
delay(13.8888888889);
tone(tonePin, 554, 113.5);
delay(126.111111111);
delay(7.22222222222);
tone(tonePin, 466, 227.5);
delay(252.777777778);
delay(13.8888888889);
tone(tonePin, 415, 113.5);
delay(126.111111111);
delay(7.22222222222);
tone(tonePin, 466, 341.5);
delay(379.444444444);
delay(20.5555555556);
tone(tonePin, 554, 341.5);
delay(379.444444444);
delay(20.5555555556);
tone(tonePin, 932, 683.5);
delay(759.444444444);
delay(40.5555555556);
tone(tonePin, 698, 455.5);
delay(506.111111111);
delay(160.555555556);

tone(tonePin, 698, 113.5);
delay(126.111111111);
delay(7.22222222222);
tone(tonePin, 622, 227.5);
delay(252.777777778);
delay(13.8888888889);
tone(tonePin, 554, 113.5);
delay(126.111111111);
delay(7.22222222222);
tone(tonePin, 466, 227.5);
delay(252.777777778);
delay(13.8888888889);
tone(tonePin, 415, 113.5);
delay(126.111111111);
delay(7.22222222222);
tone(tonePin, 466, 341.5);
delay(379.444444444);
delay(20.5555555556);
tone(tonePin, 554, 341.5);
delay(379.444444444);
delay(20.5555555556);
tone(tonePin, 932, 683.5);
delay(759.444444444);
delay(40.5555555556);
tone(tonePin, 880, 911.5);
delay(1012.77777778);
delay(320.555555556);
tone(tonePin, 466, 113.5);
delay(126.111111111);
delay(7.22222222222);
tone(tonePin, 466, 113.5);
delay(126.111111111);
delay(7.22222222222);
tone(tonePin, 466, 227.5);
delay(252.777777778);
delay(13.8888888889);
tone(tonePin, 466, 227.5);
delay(252.777777778);
delay(13.8888888889);
tone(tonePin, 466, 113.5);
delay(126.111111111);
delay(7.22222222222);
tone(tonePin, 466, 113.5);
delay(126.111111111);
delay(7.22222222222);
tone(tonePin, 466, 227.5);
delay(252.777777778);
delay(13.8888888889);
tone(tonePin, 466, 113.5);
delay(126.111111111);
delay(7.22222222222);
tone(tonePin, 466, 113.5);
delay(126.111111111);
delay(7.22222222222);

tone(tonePin, 466, 113.5);
delay(126.111111111);
delay(7.22222222222);
tone(tonePin, 466, 113.5);
delay(126.111111111);
delay(7.22222222222);
tone(tonePin, 466, 227.5);
delay(252.777777778);
delay(13.8888888889);
tone(tonePin, 466, 227.5);
delay(252.777777778);
delay(13.8888888889);
tone(tonePin, 466, 113.5);
delay(126.111111111);
delay(7.22222222222);
tone(tonePin, 466, 113.5);
delay(126.111111111);
delay(7.22222222222);
tone(tonePin, 466, 227.5);
delay(252.777777778);
delay(13.8888888889);
tone(tonePin, 466, 113.5);
delay(126.111111111);
delay(7.22222222222);
tone(tonePin, 466, 113.5);
delay(126.111111111);
delay(7.22222222222);
tone(tonePin, 466, 113.5);
delay(126.111111111);
delay(7.22222222222);
tone(tonePin, 466, 113.5);
delay(126.111111111);
delay(7.22222222222);
tone(tonePin, 554, 227.5);
delay(252.777777778);
delay(13.8888888889);
tone(tonePin, 554, 227.5);
delay(252.777777778);
delay(13.8888888889);
tone(tonePin, 554, 113.5);
delay(126.111111111);
delay(7.22222222222);
tone(tonePin, 554, 113.5);
delay(126.111111111);
delay(7.22222222222);
tone(tonePin, 554, 227.5);
delay(252.777777778);
delay(13.8888888889);
tone(tonePin, 554, 113.5);
delay(126.111111111);
delay(7.22222222222);
tone(tonePin, 554, 113.5);
delay(126.111111111);
delay(7.22222222222);

tone(tonePin, 554, 113.5);
delay(126.111111111);
delay(7.22222222222);
tone(tonePin, 554, 113.5);
delay(126.111111111);
delay(7.22222222222);
tone(tonePin, 523, 113.5);
delay(126.111111111);
delay(7.22222222222);
tone(tonePin, 523, 113.5);
delay(126.111111111);
delay(7.22222222222);
tone(tonePin, 523, 113.5);
delay(126.111111111);
delay(7.22222222222);
tone(tonePin, 523, 113.5);
delay(126.111111111);
delay(7.22222222222);
tone(tonePin, 523, 113.5);
delay(126.111111111);
delay(7.22222222222);
tone(tonePin, 523, 113.5);
delay(126.111111111);
delay(7.22222222222);
tone(tonePin, 523, 113.5);
delay(126.111111111);
delay(7.22222222222);
tone(tonePin, 523, 113.5);
delay(126.111111111);
delay(7.22222222222);
tone(tonePin, 523, 113.5);
delay(126.111111111);
delay(7.22222222222);
tone(tonePin, 523, 113.5);
delay(126.111111111);
delay(7.22222222222);
tone(tonePin, 523, 113.5);
delay(126.111111111);
delay(7.22222222222);
tone(tonePin, 523, 113.5);
delay(126.111111111);
delay(7.22222222222);
tone(tonePin, 466, 227.5);
delay(252.777777778);
delay(13.8888888889);
tone(tonePin, 466, 227.5);
delay(252.777777778);
delay(13.8888888889);
tone(tonePin, 466, 113.5);
delay(126.111111111);
delay(7.22222222222);
tone(tonePin, 466, 113.5);
delay(126.111111111);
delay(7.22222222222);
}

//***************************************************************
//DESPACITO
//***************************************************************
void Despacito()
{
  tone(tonePin, 587, 709.720327982);
    delay(788.578142202);
    delay(10.3082110092);
    tone(tonePin, 554, 709.720327982);
    delay(788.578142202);
    delay(5.15410550459);
    tone(tonePin, 493, 273.683002294);
    delay(304.092224771);
    delay(5.15410550459);
    tone(tonePin, 369, 273.683002294);
    delay(304.092224771);
    delay(5.15410550459);
    tone(tonePin, 369, 134.52215367);
    delay(149.469059633);
    delay(5.15410550459);
    tone(tonePin, 369, 134.52215367);
    delay(149.469059633);
    delay(5.15410550459);
    tone(tonePin, 369, 134.52215367);
    delay(149.469059633);
    delay(5.15410550459);
    tone(tonePin, 369, 134.52215367);
    delay(149.469059633);
    delay(5.15410550459);
    tone(tonePin, 369, 134.52215367);
    delay(149.469059633);
    delay(5.15410550459);
    tone(tonePin, 493, 134.52215367);
    delay(149.469059633);
    delay(5.15410550459);
    tone(tonePin, 493, 134.52215367);
    delay(149.469059633);
    delay(5.15410550459);
    tone(tonePin, 493, 134.52215367);
    delay(149.469059633);
    delay(5.15410550459);
    tone(tonePin, 493, 273.683002294);
    delay(304.092224771);
    delay(5.15410550459);
    tone(tonePin, 440, 134.52215367);
    delay(149.469059633);
    delay(5.15410550459);
    tone(tonePin, 493, 273.683002294);
    delay(304.092224771);
    delay(5.15410550459);
    tone(tonePin, 391, 412.843850917);
    delay(458.715389908);
    delay(5.15410550459);
    tone(tonePin, 391, 134.52215367);
    delay(149.469059633);
    delay(5.15410550459);
    tone(tonePin, 391, 134.52215367);
    delay(149.469059633);
    delay(5.15410550459);
    tone(tonePin, 391, 134.52215367);
    delay(149.469059633);
    delay(5.15410550459);
    tone(tonePin, 391, 134.52215367);
    delay(149.469059633);
    delay(5.15410550459);
    tone(tonePin, 391, 134.52215367);
    delay(149.469059633);
    delay(5.15410550459);
    tone(tonePin, 493, 134.52215367);
    delay(149.469059633);
    delay(5.15410550459);
    tone(tonePin, 493, 134.52215367);
    delay(149.469059633);
    delay(5.15410550459);
    tone(tonePin, 493, 134.52215367);
    delay(149.469059633);
    delay(5.15410550459);
    tone(tonePin, 493, 273.683002294);
    delay(304.092224771);
    delay(5.15410550459);
    tone(tonePin, 554, 134.52215367);
    delay(149.469059633);
    delay(5.15410550459);
    tone(tonePin, 587, 273.683002294);
    delay(304.092224771);
    delay(5.15410550459);
    tone(tonePin, 440, 412.843850917);
    delay(458.715389908);
    delay(5.15410550459);
    tone(tonePin, 440, 134.52215367);
    delay(149.469059633);
    delay(5.15410550459);
    tone(tonePin, 440, 134.52215367);
    delay(149.469059633);
    delay(5.15410550459);
    tone(tonePin, 440, 134.52215367);
    delay(149.469059633);
    delay(5.15410550459);
    tone(tonePin, 440, 41.7482545872);
    delay(46.3869495413);
    delay(36.0787385321);
    tone(tonePin, 440, 37.109559633);
    delay(41.2328440367);
    delay(30.9246330275);
    tone(tonePin, 440, 134.52215367);
    delay(149.469059633);
    delay(5.15410550459);
    tone(tonePin, 587, 134.52215367);
    delay(149.469059633);
    delay(5.15410550459);
    tone(tonePin, 587, 134.52215367);
    delay(149.469059633);
    delay(5.15410550459);
    tone(tonePin, 587, 46.3869495413);
    delay(51.5410550459);
    delay(30.9246330275);
    tone(tonePin, 587, 46.3869495413);
    delay(51.5410550459);
    delay(20.6164220183);
    tone(tonePin, 587, 273.683002294);
    delay(304.092224771);
    delay(5.15410550459);
    tone(tonePin, 659, 134.52215367);
    delay(149.469059633);
    delay(5.15410550459);
    tone(tonePin, 659, 273.683002294);
    delay(304.092224771);
    delay(5.15410550459);
    tone(tonePin, 554, 691.165548165);
    delay(767.961720183);
    delay(314.40043578);
    tone(tonePin, 587, 552.004699541);
    delay(613.338555046);
    delay(5.15410550459);
    tone(tonePin, 554, 552.004699541);
    delay(613.338555046);
    delay(5.15410550459);
    tone(tonePin, 493, 273.683002294);
    delay(304.092224771);
    delay(5.15410550459);
    tone(tonePin, 369, 273.683002294);
    delay(304.092224771);
    delay(5.15410550459);
    tone(tonePin, 369, 134.52215367);
    delay(149.469059633);
    delay(5.15410550459);
    tone(tonePin, 369, 134.52215367);
    delay(149.469059633);
    delay(5.15410550459);
    tone(tonePin, 369, 134.52215367);
    delay(149.469059633);
    delay(5.15410550459);
    tone(tonePin, 369, 134.52215367);
    delay(149.469059633);
    delay(5.15410550459);
    tone(tonePin, 369, 134.52215367);
    delay(149.469059633);
    delay(5.15410550459);
    tone(tonePin, 493, 46.3869495413);
    delay(51.5410550459);
    delay(30.9246330275);
    tone(tonePin, 493, 46.3869495413);
    delay(51.5410550459);
    delay(20.6164220183);
    tone(tonePin, 493, 134.52215367);
    delay(149.469059633);
    delay(5.15410550459);
    tone(tonePin, 493, 134.52215367);
    delay(149.469059633);
    delay(5.15410550459);
    tone(tonePin, 493, 273.683002294);
    delay(304.092224771);
    delay(5.15410550459);
    tone(tonePin, 440, 134.52215367);
    delay(149.469059633);
    delay(5.15410550459);
    tone(tonePin, 493, 273.683002294);
    delay(304.092224771);
    delay(5.15410550459);
    tone(tonePin, 391, 273.683002294);
    delay(304.092224771);
    delay(159.777270642);
    tone(tonePin, 391, 134.52215367);
    delay(149.469059633);
    delay(5.15410550459);
    tone(tonePin, 391, 41.7482545872);
    delay(46.3869495413);
    delay(30.9246330275);
    tone(tonePin, 391, 37.109559633);
    delay(41.2328440367);
    delay(36.0787385321);
    tone(tonePin, 391, 134.52215367);
    delay(149.469059633);
    delay(5.15410550459);
    tone(tonePin, 391, 134.52215367);
    delay(149.469059633);
    delay(5.15410550459);
    tone(tonePin, 391, 134.52215367);
    delay(149.469059633);
    delay(5.15410550459);
    tone(tonePin, 493, 134.52215367);
    delay(149.469059633);
    delay(5.15410550459);
    tone(tonePin, 493, 134.52215367);
    delay(149.469059633);
    delay(5.15410550459);
    tone(tonePin, 493, 134.52215367);
    delay(149.469059633);
    delay(5.15410550459);
    tone(tonePin, 493, 273.683002294);
    delay(304.092224771);
    delay(5.15410550459);
    tone(tonePin, 554, 134.52215367);
    delay(149.469059633);
    delay(5.15410550459);
    tone(tonePin, 587, 273.683002294);
    delay(304.092224771);
    delay(5.15410550459);
    tone(tonePin, 440, 412.843850917);
    delay(458.715389908);
    delay(5.15410550459);
    tone(tonePin, 440, 134.52215367);
    delay(149.469059633);
    delay(5.15410550459);
    tone(tonePin, 440, 64.9417293578);
    delay(72.1574770642);
    delay(5.15410550459);
    tone(tonePin, 440, 64.9417293578);
    delay(72.1574770642);
    delay(5.15410550459);
    tone(tonePin, 440, 134.52215367);
    delay(149.469059633);
    delay(5.15410550459);
    tone(tonePin, 440, 134.52215367);
    delay(149.469059633);
    delay(5.15410550459);
    tone(tonePin, 440, 134.52215367);
    delay(149.469059633);
    delay(5.15410550459);
    tone(tonePin, 587, 134.52215367);
    delay(149.469059633);
    delay(5.15410550459);
    tone(tonePin, 587, 134.52215367);
    delay(149.469059633);
    delay(5.15410550459);
    tone(tonePin, 587, 51.0256444954);
    delay(56.6951605505);
    delay(30.9246330275);
    tone(tonePin, 587, 51.0256444954);
    delay(56.6951605505);
    delay(10.3082110092);
    tone(tonePin, 587, 134.52215367);
    delay(149.469059633);
    delay(5.15410550459);
}

//***************************************************************
//BELLA CIAO
//***************************************************************
void Bella_Ciao()
{
  tone(BuzzerPin,Mi,black);
  delay(black+50);
  tone(BuzzerPin,La,black);
  delay(black+50);
  tone(BuzzerPin,Si,black);
  delay(black+50);
  tone(BuzzerPin,Do2,black);
  delay(black+50);
  tone(BuzzerPin,La,black);
  
  delay(2*white+50);
  
  tone(BuzzerPin,Mi,black);
  delay(black+50);
  tone(BuzzerPin,La,black);
  delay(black+50);
  tone(BuzzerPin,Si,black);
  delay(black+50);
  tone(BuzzerPin,Do2,black);
  delay(black+50);
  tone(BuzzerPin,La,black);
  
  delay(2*white+50);
  
  tone(BuzzerPin,Mi,black);
  delay(black+50);
  tone(BuzzerPin,La,black);
  delay(black+50);
  tone(BuzzerPin,Si,black);
  delay(black+50);
  tone(BuzzerPin,Do2,white*1.3);
  delay(2*black+50);
  
  tone(BuzzerPin,Si,black);
  delay(black+50);
  tone(BuzzerPin,La,black);
  delay(black+50);
  tone(BuzzerPin,Do2,white*1.3);
  delay(2*black+50);
  
  tone(BuzzerPin,Si,black);
  delay(black+50);
  tone(BuzzerPin,La,black);
  delay(black+50);
  tone(BuzzerPin,Mi2,black);
  delay(white+50);
  tone(BuzzerPin,Mi2,black);
  delay(white+100);
  
  tone(BuzzerPin,Mi2,black);
  delay(white+50);
  tone(BuzzerPin,Re2,black);
  delay(black+50);
  tone(BuzzerPin,Mi2,black);
  delay(black+50);
  tone(BuzzerPin,Fa2,black);
  delay(black+50);
  tone(BuzzerPin,Fa2,white*1.3);
  delay(rounda+100);
  
  tone(BuzzerPin,Fa2,black);
  delay(black+50);
  tone(BuzzerPin,Mi2,black);
  delay(black+50);
  tone(BuzzerPin,Re2,black);
  delay(black+50);
  tone(BuzzerPin,Fa2,black);
  delay(black+50);
  tone(BuzzerPin,Mi2,white*1.3);
  delay(rounda+100);
  
  tone(BuzzerPin,Mi2,black);
  delay(black+50);
  tone(BuzzerPin,Re2,black);
  delay(black+50);
   tone(BuzzerPin,Do2,black);
  delay(black+50);
  tone(BuzzerPin,Si,white*1.3);
  delay(white+50);
  tone(BuzzerPin,Mi2,white*1.3);
  delay(white+50);
  tone(BuzzerPin,Si,white*1.3);
  delay(white+50);
  tone(BuzzerPin,Do2,white*1.3);
  delay(white+50);
  tone(BuzzerPin,La,rounda*1.3);
  delay(rounda+50);
}


//***************************************************************
//SETUP
//***************************************************************
void setup() 
{
  digitalWrite(2,LOW);
  digitalWrite(3,LOW);
  Serial.begin(9600);

//FOR BELLA CIAO SETUP
  pinMode(BuzzerPin,OUTPUT);
      
      black= 35000/bpm; 
      blackp=black*1.5;
      white= black*2;
      whitep=white*1.5;
      rounda= black*4;
      roundp= rounda*1.5;
      quaver= black/2;
      quaverp=quaver*1.5;
      semiquaver= black/4;
      semiquaverp=semiquaver*1.5;
}

//***************************************************************
//LOOP
//***************************************************************
void loop() 
{

  delay(1500);
  if(digitalRead(2)==HIGH && digitalRead(3)==HIGH)
  {
    Believer();
    Serial.println("Believer");
  }
  if(digitalRead(3)==HIGH && digitalRead(4)==HIGH)
  {
    Bella_Ciao();
    Serial.println("Bella Ciao");
  }
  if(digitalRead(2)==HIGH)
  {
    Happy_Birthday();
    Serial.println("Happy Birthday");
  }
  if(digitalRead(3)==HIGH)
  {
    Christmas();
    Serial.println("We wish u a merry christmas");
  }
  if(digitalRead(4)==HIGH)
  {
    Despacito();
    Serial.println("Despacito");
  }
}
