#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"
#include "printf.h"
#include "settings.h"
#include "radio.h"
String stringFromBt ="";
int len=0;
RF24 radio(CE, CSN); // Establish a new RF24 object

void setup() 
{
  Serial.begin(9600); //open serial port
  printf_begin();     //needed for Debug NRF24 Module
  PinMode();          //set I/O pins
  RadioSetup();       //setup & start NRF24 
  LedStartUp();       //test onboard LEDS 
}

void loop() 
{
   if(Serial.available() > 0)
   {
    stringFromBt=Serial.readString();
    sendData.targetId=stringFromBt.charAt(1)-'0';
    sendData.commandSign=stringFromBt.charAt(3);
    sendData.commandValue=stringFromBt.charAt(4)-'0';  
    
   }
  LedLoop();
  while(!SendData());         // send the flags commands ;
  while(!ReciveData());
    UpdateLed();
    MassageFromReadData();
   // debug();   //To do  - add here response to BT insted of debug;   
    
}
