#include <Arduino.h>

#define ir1 34
#define ir2 35
#define ir3 32
#define ir4 33
#define ir5 25
#define ir6 26
#define ir7 27
#define ir8 14
#define irN 12



#define thr1 3600
#define thr2 3600
#define thr3 3600
#define thr4 3600
#define thr5 3600
#define thr6 3600
#define thr7 3600
#define thr8 3600

int st1, st2, st3, st4, st5, st6, st7, st8, stN, isblack;


void setup() {
  Serial.begin(9600);

  // Configure sensor pins as inputs
  pinMode(ir1, INPUT);
  pinMode(ir2, INPUT);
  pinMode(ir3, INPUT);
  pinMode(ir4, INPUT);
  pinMode(ir5, INPUT);
  pinMode(ir6, INPUT);
  pinMode(ir7, INPUT);
  pinMode(ir8, INPUT);
  pinMode(irN, INPUT);
}

void loop() {
  st1 = analogRead(ir1);
  st2 = analogRead(ir2);
  st3 = analogRead(ir3);
  st4 = analogRead(ir4);
  st5 = analogRead(ir5);
  st6 = analogRead(ir6);
  st7 = analogRead(ir7);
  st8 = analogRead(ir8); 
  stN = digitalRead(irN);



  Serial.print(" ST1: ");
  Serial.print(st1);
  Serial.print("\t ST2: ");
  Serial.print(st2);
  Serial.print("\t ST3: ");
  Serial.print(st3);
  Serial.print("\t ST4: ");
  Serial.print(st4);
  Serial.print("\t ST5: ");
  Serial.print(st5);
  Serial.print("\t ST6: ");
  Serial.print(st6);
  Serial.print("\t ST7: ");
  Serial.print(st7);
  Serial.print("\t ST8: ");
  Serial.println(st8);


  if (st1 > thr1 )    st1 = 1 ; else st1 = 0;
  if (st2 > thr2 )    st2 = 1 ; else st2 = 0;
  if (st3 > thr3 )    st3 = 1 ; else st3 = 0;
  if (st4 > thr4 )    st4 = 1 ; else st4 = 0;
  if (st5 > thr5 )    st5 = 1 ; else st5 = 0;
  if (st6 > thr6 )    st6 = 1 ; else st6 = 0;
  if (st7 > thr7 )    st7 = 1 ; else st7 = 0;
  if (st8 > thr8 )    st8 = 1 ; else st8 = 0;

  Serial.print(" IR1: ");
  Serial.print(st1);
  Serial.print("\t IR2: ");
  Serial.print(st2);
  Serial.print("\t IR3: ");
  Serial.print(st3);
  Serial.print("\t IR4: ");
  Serial.print(st4);
  Serial.print("\t IR5: ");
  Serial.print(st5);
  Serial.print("\t IR6: ");
  Serial.print(st6);
  Serial.print("\t IR7: ");
  Serial.print(st7);
  Serial.print("\t IR8: ");
  Serial.print(st8);
  Serial.print("\t STN: ");
  Serial.println(stN);
  Serial.println(" ");

  
}
