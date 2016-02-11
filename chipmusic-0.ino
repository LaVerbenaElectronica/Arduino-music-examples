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
  //simple_beat(rightPin);
  //simple_scale ();
  //int i, j; 
  //for(i=0;i<8;i++) 
  //  { 
  //    j = 10 + i % 2;
  //    simple_base (j); 
  //  }	 
  stereo_modus();
  //simple_scale ();
  //delay(1000);
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

void noise (unsigned char speakerPin, int frequencyInHertz, long timeInMilliseconds)     // the sound producing function
{	 
          int x;	 
          long delayAmount = (long)(1000000/frequencyInHertz);
          long loopTime = (long)((timeInMilliseconds*1000)/(delayAmount));
          for (x=0;x<loopTime;x++)	 
          {	 
              digitalWrite(speakerPin,HIGH);
              delayMicroseconds(1000000/random(frequencyInHertz));
              digitalWrite(speakerPin,LOW);
              delayMicroseconds(1000000/random(frequencyInHertz));
          }	 
}


void simple_base (int selectedPin)
{	 	 
    beep(selectedPin,NOTE_B3, 200); delay(50);
    beep(selectedPin,NOTE_FS4, 200); delay(50);
}


void tri_base (int selectedPin)
{	 	 
     beep(selectedPin,NOTE_FS5, 200); delay(50);
     simple_base(selectedPin);
}

void simple_beat (int selectedPin)
{	 
     int a, b;
     for (a=0;a<3;a++)	 
     {	 
            beep(selectedPin, NOTE_B3, 20); delay(100);
            beep(selectedPin, NOTE_AS3,20); delay(100);
            beep(selectedPin, NOTE_B3, 20); delay(100);
            beep(selectedPin, NOTE_AS3,20); delay(100);
            beep(selectedPin, NOTE_B3, 20); delay(200);
            beep(selectedPin, NOTE_FS3,20); delay(100);
            beep(selectedPin, NOTE_FS3,20); delay(100);
            beep(selectedPin, NOTE_A3, 20); delay(200);
            beep(selectedPin, NOTE_G3, 20); delay(200);
            beep(selectedPin, NOTE_FS3,20); delay(100);
            delay(400);
     }
}

void simple_scale ()
{	 
     int a, b;
     for (a=0;a<2;a++)	 
     {	 
            beep(leftPin,NOTE_E6, 20); delay(100);
            beep(rightPin,NOTE_E6, 20); delay(100);
            beep(leftPin,NOTE_FS6,20); delay(100);
            beep(rightPin,NOTE_G6, 20); delay(100);
            beep(leftPin,NOTE_FS6,100); delay(20);
            beep(rightPin,NOTE_E6, 100); delay(20);
            beep(leftPin,NOTE_D6, 100); delay(20);
            beep(rightPin,NOTE_CS6,100); delay(20);
     }
     
            beep(leftPin,NOTE_E6, 20); delay(100);
            beep(rightPin,NOTE_E6, 20); delay(100);
            beep(leftPin,NOTE_FS6,20); delay(100);
            beep(rightPin,NOTE_G6, 20); delay(100);
            beep(leftPin,NOTE_FS6,400); delay(100);
            beep(rightPin,NOTE_E6, 400); delay(100);
            beep(leftPin,NOTE_D6, 400); delay(100);
            beep(rightPin,NOTE_CS6, 400); delay(100);
}

void stereo_modus()
{	  
      beep(leftPin,NOTE_B4, 200); delay(50);
      tri_base(rightPin);
      beep(leftPin,NOTE_D6,200); delay(50);
      tri_base(rightPin);
      beep(leftPin,NOTE_E5, 200); delay(50);
      tri_base(rightPin);
      beep(leftPin,NOTE_D6, 200); delay(50);
      beep(rightPin,NOTE_B4, 200); delay(50);
      beep(leftPin,NOTE_CS6,200); delay(50);
      beep(rightPin,NOTE_FS5, 200); delay(50);
            
      beep(leftPin,NOTE_B4, 200); delay(50);
      tri_base(rightPin);
      beep(leftPin,NOTE_FS5,200); delay(50);
      tri_base(rightPin);
      beep(leftPin,NOTE_E5, 200); delay(50);
      tri_base(rightPin);
      beep(leftPin,NOTE_D6, 200); delay(50);
      beep(rightPin,NOTE_B4, 200); delay(50);
      beep(leftPin,NOTE_D6,200);   delay(50);
      beep(rightPin,NOTE_E6, 200); delay(50);
      
      beep(leftPin,NOTE_B4, 200); delay(50);
      tri_base(rightPin);
      beep(leftPin,NOTE_CS6,200); delay(50);
      tri_base(rightPin);
      beep(leftPin,NOTE_E5, 200); delay(50);
      tri_base(rightPin);
      beep(leftPin,NOTE_CS6, 200); delay(50);
      beep(rightPin,NOTE_B4, 200); delay(50);
      beep(leftPin,NOTE_FS6,200);   delay(50);
      beep(rightPin,NOTE_E6, 200); delay(50);
      
      beep(leftPin,NOTE_B4, 200); delay(50);
      tri_base(rightPin);
      beep(leftPin,NOTE_FS5,200); delay(50);
      tri_base(rightPin);
      beep(leftPin,NOTE_E5, 200); delay(50);
      tri_base(rightPin);
      beep(leftPin,NOTE_CS6, 200); delay(50);
      beep(rightPin,NOTE_D4, 200); delay(50);
      beep(leftPin,NOTE_FS6,200);   delay(50);
      beep(rightPin,NOTE_FS6, 200); delay(50);

}


void simple_modus (int selectedPin)
{	 
     int a, b;
     for (a=0;a<2;a++)	 
     {	 
            beep(selectedPin,NOTE_B4, 500); delay(500);
            beep(selectedPin,NOTE_FS5,500); delay(500);
            beep(selectedPin,NOTE_E5, 500); delay(500);
            beep(selectedPin,NOTE_D6, 400); delay(100);
            beep(selectedPin,NOTE_CS6,400); delay(100);
            beep(selectedPin,NOTE_B4, 500); delay(500);
            beep(selectedPin,NOTE_FS5,500); delay(500);
            beep(selectedPin,NOTE_E5, 500); delay(500);
            beep(selectedPin,NOTE_D6, 400); delay(100);
            beep(selectedPin,NOTE_E6,400); delay(100);
     }
}

/*
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
}*/
