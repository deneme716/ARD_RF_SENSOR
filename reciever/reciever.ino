
#include <VirtualWire.h> // use Virtual library for decode signal from Rx module


int humidity=0;
int temp=0;
int heat_index=0;
char MsgReceived[21]; 
int led = 13; //pin for LED

void setup() 
{
 Serial.begin(9600);
  while (!Serial) ;
  pinMode(led, OUTPUT); 

  // VirtualWire 
  // Bits per sec
  vw_setup(2000);
  // set pin for connect receiver module 
  vw_set_rx_pin(12);  
  // Start the receiver PLL running
  vw_rx_start();       

  

} // END void setup

void loop()
{
  uint8_t buf[VW_MAX_MESSAGE_LEN];
  uint8_t buflen = VW_MAX_MESSAGE_LEN;
  
  //Taking the data from the control base
  if (vw_get_message(buf, &buflen)) 
  {
    digitalWrite(led, HIGH);
    delay(100);
    int i;
    String deneme="";
    int a;
    // Message with a good checksum received, dump it. 
    for (i = 0; i < buflen; i++)
    {            
      // Fill Msg Char array with corresponding 
      // chars from buffer.   
      MsgReceived[i] = char(buf[i]);
      deneme=deneme+MsgReceived[i];
      
      //Serial.print(MsgReceived[i]);
    }

    //sscanf(MsgReceived, "%d",&humidity); // Converts a string to an array
    digitalWrite(led, LOW); 
    a=deneme.toInt();
if (deneme.charAt(0)=='1')
{
  Serial.println(deneme.charAt(0));
}

    Serial.println(a+1);
    memset( MsgReceived, 0, sizeof(MsgReceived));// This line is for reset the StringReceived
  }
}

