/*
 * Este código ha sido escrito por Jesus Jara, inspirado en los tutoriales de:
 * http://web.media.mit.edu/~leah/LilyPad/07_sound_code.html
 */

#include "pitches.h"

int leftPin  = 10;
int rightPin = 11;

int escala[] = {
  NOTE_C6, NOTE_D6, NOTE_E6, NOTE_F6, NOTE_G6, NOTE_A6, NOTE_B6, NOTE_C7, 
  NOTE_C7, NOTE_D7, NOTE_E7, NOTE_F7, NOTE_G7, NOTE_A7, NOTE_B7, NOTE_C8};
int random_note;

void setup()	 
{	 
         pinMode(leftPin,  OUTPUT);	
         pinMode(rightPin, OUTPUT);
}	 
 	 
void loop()
{	 
  random_note = random(0,8);
  int i; 
  for(i=0;i<2;i++) { 
    simple_beat(leftPin, escala[random_note]);	 
    simple_beat(rightPin,escala[random_note+4]);
    main_beat(escala[random_note]);
    main_beat(escala[random_note+4]);
    main_beat(escala[random_note+8]);
  };

  random_note = random(0,8);
  for(i=0;i<2;i++) {
      break_melody();
      main_beat(escala[random_note]);
      main_beat(escala[random_note+4]);
      main_beat(escala[random_note+3]);
      main_beat(escala[random_note]);
  };
 
  random_note = random(0,8);
  simple_beat(leftPin, escala[random_note]);	 
  simple_beat(rightPin,escala[random_note+4]);
 
  stereo_noise();
  delay(100);
 
  final_down_melody();
 
}	 
 	 
void beep (unsigned char speakerPin, int frequencyInHertz, long timeInMilliseconds)     // the sound producing function
{	 
          int x;	 
          long delayAmount = (long)(1000000/frequencyInHertz);
          long loopTime = (long)((timeInMilliseconds*1000)/(delayAmount*2));
          for (x=0;x<loopTime;x++)	 
          {	 
              digitalWrite(speakerPin,HIGH);
              delayMicroseconds(delayAmount);
              digitalWrite(speakerPin,LOW);
              delayMicroseconds(delayAmount);
          }	 
}	 


void simple_beat (int selectedPin, int freqValue)
{	 
     int a, b;
     for (a=0;a<2;a++)	 
     {	 
            for (b=0;b<2;b++) {beep(selectedPin,freqValue,20); delay(200);}
            for (b=0;b<3;b++) {beep(selectedPin,freqValue,20); delay(100);}
            for (b=0;b<2;b++) {beep(selectedPin,freqValue,20); delay(200);}
            for (b=0;b<3;b++) {beep(selectedPin,freqValue,20); delay(100);}
            beep(selectedPin,freqValue,20); delay(200);
     }
}

void main_beat (int freqValue)
{	 
     int a;
     for (a=0;a<2;a++)	 
     {	 
            beep(rightPin,freqValue/2,20); beep(leftPin,freqValue,20);   delay(80);
            beep(rightPin,freqValue/3,20); delay(80);
            beep(rightPin,freqValue/2,20); beep(leftPin,freqValue,20);   delay(80);
            beep(rightPin,freqValue/3,20); delay(80);
            beep(rightPin,freqValue/2,20); beep(leftPin,freqValue,20);   delay(80);
            beep(rightPin,freqValue/2,20); beep(leftPin,freqValue,20);   delay(80);
            beep(rightPin,freqValue/2,20); beep(leftPin,freqValue,20);   delay(80);
     }
}

void break_melody()
{	 
     int a;
     for (a=0;a<3;a++)	 
     {	 
          scale(rightPin, 0);
          delay(100);
     }
     for (a=0;a<3;a++)	 
     {	 
          scale(leftPin, 1000);
          delay(100);
     }
     for (a=0;a<4;a++)	 
     {	 
          stereo_scale(1100);
          delay(100);
     }
}

void final_down_melody()
{	 
     int a;
     for (a=0;a<1;a++)	 
     {	 
          beep(rightPin,NOTE_G7/4,500);	//G
          beep(leftPin, NOTE_F7/4,500);	//F
          beep(rightPin,NOTE_E7/4,500);	//E
          beep(leftPin, NOTE_D7/4,500);	//D
          delay(100);
     }
}

void scale(int selectedPin, int minusValue)
{
  int j;
  for (j=8;j>0;j--) 
  {
    beep(selectedPin, escala[random_note+j] - minusValue,10);
  }
}

void stereo_scale(int minusValue)
{
  
  int j;
  for (j=8;j>0;j--) 
  {
    beep(rightPin,escala[random_note+j] - minusValue,10); 
    beep(leftPin, escala[random_note+j] - minusValue,10);
  }
}

void stereo_noise()
{
  int j, k;
  for (j=0;j<60;j++) 
  {
    random_note = random(0,16);
    beep(rightPin,escala[random_note],10);
    beep(leftPin, escala[random_note],10);
  }
  
  //se reduce el random por arriba para bajar al do
  k=16;
  for (j=0;j<30;j++) 
  {
    if (j % 2 == 0) k--;
    random_note = random(0,k);
    beep(rightPin,escala[random_note],10);
    beep(leftPin, escala[random_note],10);
  }
  
  for (j=0;j<30;j++) 
  {
    beep(rightPin,escala[0],10);
    beep(leftPin, escala[0],10);
  }
}
