/*
    Matrix Sample codes
 
 Codes by:
 e-Gizmo Mechatronix Central
 http://www.e-gizmo.com

 */

#include "cmap.h"

int d;
unsigned char char_pointer;
char Display_Ram[38];
unsigned char mask;
char LED_DATA[]= "     Welcome to e-Gizmo Mechatronix Central!!!        ~";
char count;	
unsigned char shift_counter;

#define INTEN 6000

const char CLK = 5; 
const char DAT = 6; 
const char STR = 7; 
const char K0 = A0; 
const char K1 = A1; 
const char K2 = A2; 
const char K3 = A3; 
const char K4 = 8; 
const char K5 = 9; 
const char K6 = 10; 
const char K7 = 11; 

void setup() {                
  pinMode(CLK, OUTPUT);     
  pinMode(DAT, OUTPUT);     
  pinMode(STR, OUTPUT);     
  pinMode(K0, OUTPUT);     
  pinMode(K1, OUTPUT);     
  pinMode(K2, OUTPUT);     
  pinMode(K3, OUTPUT);     
  pinMode(K4, OUTPUT);     
  pinMode(K5, OUTPUT);     
  pinMode(K6, OUTPUT);     
  pinMode(K7, OUTPUT);  

  digitalWrite(K0,HIGH);  
  digitalWrite(K1,HIGH);  
  digitalWrite(K2,HIGH);  
  digitalWrite(K3,HIGH);  
  digitalWrite(K4,HIGH);  
  digitalWrite(K5,HIGH);  
  digitalWrite(K6,HIGH);  
  digitalWrite(K7,HIGH);  

  for(d=0;d<32;d++)
  {
    clock();
  }
  strobe();
  d = 0;
}

void loop(){
  Display();
  shift();
}		

void shift(void) 
{
  Display_Ram[0] = Display_Ram[1];
  Display_Ram[1] = Display_Ram[2];
  Display_Ram[2] = Display_Ram[3];
  Display_Ram[3] = Display_Ram[4];
  Display_Ram[4] = Display_Ram[5];
  Display_Ram[5] = Display_Ram[6];
  Display_Ram[6] = Display_Ram[7];
  Display_Ram[7] = Display_Ram[8];
  Display_Ram[8] = Display_Ram[9];
  Display_Ram[9] = Display_Ram[10];
  Display_Ram[10] = Display_Ram[11];
  Display_Ram[11] = Display_Ram[12];
  Display_Ram[12] = Display_Ram[13];
  Display_Ram[13] = Display_Ram[14];
  Display_Ram[14] = Display_Ram[15];
  Display_Ram[15] = Display_Ram[16];
  Display_Ram[16] = Display_Ram[17];
  Display_Ram[17] = Display_Ram[18];
  Display_Ram[18] = Display_Ram[19];
  Display_Ram[19] = Display_Ram[20];
  Display_Ram[20] = Display_Ram[21];
  Display_Ram[21] = Display_Ram[22];
  Display_Ram[22] = Display_Ram[23];
  Display_Ram[23] = Display_Ram[24];
  Display_Ram[24] = Display_Ram[25];
  Display_Ram[25] = Display_Ram[26];
  Display_Ram[26] = Display_Ram[27];
  Display_Ram[27] = Display_Ram[28];
  Display_Ram[28] = Display_Ram[29];
  Display_Ram[29] = Display_Ram[30];
  Display_Ram[30] = Display_Ram[31];
  Display_Ram[31] = Display_Ram[32];
  Display_Ram[32] = Display_Ram[33];
  Display_Ram[33] = Display_Ram[34];
  Display_Ram[34] = Display_Ram[35];
  Display_Ram[35] = Display_Ram[36];
  Display_Ram[36] = Display_Ram[37];
  shift_counter++;
  if(shift_counter == 6){
    shift_counter = 0;
    load();
  }
}

void Display(void)
{
  mask = 0x01;
  scan();
  digitalWrite(K7,LOW);
  for(d=0;d<INTEN;d++){}
  digitalWrite(K7,HIGH);

  mask = 0x02;
  scan();
  digitalWrite(K6,LOW);
  for(d=0;d<INTEN;d++){}
  digitalWrite(K6,HIGH);

  mask = 0x04;
  scan();
  digitalWrite(K5,LOW);
  for(d=0;d<INTEN;d++){}
  digitalWrite(K5,HIGH);

  mask = 0x08;
  scan();
  digitalWrite(K4,LOW);
  for(d=0;d<INTEN;d++){}
  digitalWrite(K4,HIGH);

  mask = 0x10;
  scan();
  digitalWrite(K3,LOW);
  for(d=0;d<INTEN;d++){}
  digitalWrite(K3,HIGH);

  mask = 0x20;
  scan();
  digitalWrite(K2,LOW);
  for(d=0;d<INTEN;d++){}
  digitalWrite(K2,HIGH);

  mask = 0x40;
  scan();
  digitalWrite(K1,LOW);
  for(d=0;d<INTEN;d++){}
  digitalWrite(K1,HIGH);

  mask = 0x80;
  scan();
  digitalWrite(K0,LOW);
  for(d=0;d<INTEN;d++){}
  digitalWrite(K0,HIGH);
}

void load(void){
  char counter1;
  if(LED_DATA[char_pointer+1] == '~')
    char_pointer = 0;
  for(counter1 = 0; counter1 < 5; counter1++){
    Display_Ram[32 + counter1] = character_data[(LED_DATA[char_pointer] - 0x20)][counter1];
  }	
  Display_Ram[37] = 00;	
  char_pointer++;
}

void Clear_Display_Ram(void){
  unsigned char rcount;
  for(rcount = 0; rcount < 37; rcount++)
    Display_Ram[rcount] = 0xff;
}

void scan(void){
  for (count=32;count>(-1);count--){
    if ((Display_Ram[count] & mask) == mask)
      digitalWrite(DAT,LOW);
    else
      digitalWrite(DAT,HIGH);
    clock();
  }
  strobe();
}

void clock(void){
  digitalWrite(CLK,HIGH);			// clock hi
  digitalWrite(CLK,LOW);		        // clock low
}

void strobe(void){
  digitalWrite(STR,HIGH);			// strobe hi
  digitalWrite(STR,LOW);			// strobe low
}

