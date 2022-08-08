#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int Flex1_value=A0;
int Flex2_value=A1;
int Flex3_value=A2;
int Flex4_value=A3;
int SW=5;
void setup() 
{ 
    Serial.begin(9600);
pinMode(SW,INPUT_PULLUP);
pinMode(Flex1_value,INPUT);
pinMode(Flex2_value,INPUT);
pinMode(Flex3_value,INPUT);
pinMode(Flex4_value,INPUT);
Serial.begin(9600);
   
    Serial.println("military gesture S/M");
    delay(2000);
   
}

void loop() 
{
   if(digitalRead(SW)==0)
   {
    FLEX_READ();
   }



}

void FLEX_READ()
{
int  Flex1_value1=analogRead(Flex1_value);
 int Flex2_value1=analogRead( Flex2_value);
 int Flex3_value1=analogRead( Flex3_value);
  int Flex4_value1=analogRead(Flex4_value);
  Serial.print("FLEX1:");
  Serial.println(Flex1_value1);

  Serial.print("FLEX2:");
  Serial.println(Flex2_value1);
//
  Serial.print("FLEX3:");
  Serial.println(Flex3_value1);

  Serial.print("FLEX4:");
  Serial.println(Flex4_value1);
  delay(1000);
  
  if((Flex1_value1>775)&&(Flex2_value1>780)&&(Flex3_value1<800)&&(Flex4_value1<0))
  {
    Serial.println("A");
 
   delay(1000);
   
  }
 if((Flex1_value1>955)&&(Flex2_value1<955)&&(Flex3_value1<955)&&(Flex4_value1<955))
  {
    Serial.println("B");
   
  
    delay(1000);
  }
  if((Flex1_value1<955)&&(Flex2_value1<55)&&(Flex3_value1<955)&&(Flex4_value1>955))
  {
    Serial.println("C");
    
   
    delay(1000);
  }
   if((Flex1_value1>900)&&(Flex2_value1>500)&&(Flex3_value1>900)&&(Flex4_value1<80))
  {
    Serial.println("D");

   
    delay(1000);
  }
   if((Flex1_value1<900)&&(Flex2_value1<500)&&(Flex3_value1>900)&&(Flex4_value1>80))
  {
    Serial.println("E");
   

   
    delay(1000);
  }
  if((Flex1_value1>900)&&(Flex2_value1>500)&&(Flex3_value1<300)&&(Flex4_value1<80))
  {
    Serial.println("F");

   
    delay(1000);
  }
//   if((X_val>380))
//  {
//    Serial.println("X AXIS-1");
//
//   
//    delay(1000);
//  }
//  if((X_val<300))
//  {
//    Serial.println("X AXIS-2");
//   
//    delay(1000);
//  }
//  if((Y_val>380))
//  {
//    Serial.println("Y AXIS-1");
//    delay(1000);
//  }
//  if((Y_val<300))
//  {
//    Serial.println("Y AXIS-2");
//    delay(1000);
//  }
// 

}
