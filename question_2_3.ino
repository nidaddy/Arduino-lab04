#include "SevSeg.h"
SevSeg sevseg; 
int Hour=0,Min=0;
int Step=1;
int Btn1, Btn2;
void setup() {
  
   byte numDigits =4;

   pinMode(A4,INPUT_PULLUP);
   pinMode(A5,INPUT_PULLUP);
   
   byte digitPins[] = {12,11,10,13};
   byte segmentPins[] = {2,3,4,5,6,7,8,9};
   sevseg.begin(COMMON_CATHODE, numDigits, digitPins, segmentPins);
}

void loop() {
  Btn1= digitalRead (A4);    // Reset
  Btn2 = digitalRead (A5);   // Reverse couting
  if (Btn1==0) 
    Min = Hour = 0;
  if (Btn2==0) 
    Step = -1;           // Reverse
  else Step = 1;

 sevseg.setNumber(Hour * 100 + Min, 4);
  Min = Min + Step;
  if (Min == 60)  
    {  Min = 0; 
      Hour = Hour+1;
      if (Hour == 24)
        {
          Min=0;
          Hour=0;
         }
      } // overflow
  if (Min == -1) 
  { Min =59;
    Hour =Hour-1;
    if (Hour == -1)
      {
        Hour=23;
       }
   }      // underflow


for(int i=0;i<10;i++)
{
   sevseg.refreshDisplay(); 
   sevseg.refreshDisplay();
}
  
}
