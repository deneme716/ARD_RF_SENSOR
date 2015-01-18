#include <LowPower.h>
#include <VirtualWire.h>

int ledPin = 13;
char Msg[30];// The string that we are going to send trought rf transmitter 
 
void setup() 
{
 Serial.begin(9600); // Debugging only
  pinMode(ledPin,OUTPUT);
  // VirtualWire setup
  vw_setup(2000); // Bits per sec
  vw_set_tx_pin(12);// Set the Tx pin. Default is 12
}
 
void loop() 
{
 
  int humidity = analogRead(0);
//  int temp = random(300);
//  int f = random(300);
//  int hi_f = random(300); 
//  int heat_index  =random(300);
  sprintf(Msg, "%d", humidity);
  digitalWrite(ledPin, HIGH); 
 //LowPower.powerDown(SLEEP_250MS, ADC_OFF, BOD_OFF);  
  delay(100); 
  vw_send((uint8_t *)Msg, strlen(Msg));
  vw_wait_tx(); // Wait until the whole message is gone
  digitalWrite(ledPin, LOW); 
   
  LowPower.powerDown(SLEEP_2S, ADC_OFF, BOD_OFF);    // Instead of delay(4000); 

 // delay(4000);
  }

