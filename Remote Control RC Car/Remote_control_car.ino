#include "BluetoothSerial.h"
/* Check if Bluetooth configurations are enabled in the SDK */
/* If not, then you have to recompile the SDK */
#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;
char receivedChar;
#define enA 25
#define in1 27 
#define in2 26 
#define in3 16 
#define in4 17 
#define enB 14 

//ESP32 pins (MR=Right Motor) (ML=Left Motor) (1=Forward) (2=Backward)
const int MR1 = 27; 
const int MR2 = 26; 
const int ML1 = 17;
const int ML2 = 16;
void setup() {
  Serial.begin(115200);
  /* If no name is given, default 'ESP32' is applied */
  /* If you want to give your own name to ESP32 Bluetooth device, then */
  /* specify the name as an argument SerialBT.begin("myESP32Bluetooth"); */
  SerialBT.begin("ESP32_iBOT"); //You can change your Bluetooth device name
  pinMode(MR1, OUTPUT); 
  pinMode(MR2, OUTPUT);
  pinMode(ML1, OUTPUT);
  pinMode(ML2, OUTPUT);
  Serial.println("Bluetooth Started! Ready to pair...");
}
void Forward(){
        //RIGHT MOTOR
      digitalWrite(MR1,HIGH);
      digitalWrite(MR2,LOW);
      //LEFT MOTOR
      digitalWrite(ML1,LOW);
      digitalWrite(ML2,HIGH);
}
void Backward(){
      digitalWrite(MR1,LOW);
      digitalWrite(MR2,HIGH);
      digitalWrite(ML1,HIGH);
      digitalWrite(ML2,LOW);
}
void Left(){
      digitalWrite(MR1,LOW);
      digitalWrite(MR2,HIGH);
      digitalWrite(ML1,LOW);
      digitalWrite(ML2,HIGH);
}
void Right(){
      digitalWrite(MR1,HIGH);
      digitalWrite(MR2,LOW);
      digitalWrite(ML1,HIGH);
      digitalWrite(ML2,LOW);
}
void Stop(){
      digitalWrite(MR1,LOW); 
      digitalWrite(MR2,LOW);
      digitalWrite(ML1,LOW); 
      digitalWrite(ML2,LOW); 
}

void loop() {
  
//  if (Serial.available())
//  {
//    SerialBT.write(Serial.read());
//  }
  if (SerialBT.available())
  {
    receivedChar =(char)SerialBT.read();
    Serial.write(receivedChar);
    
    if(receivedChar == 'F')
    {
      Forward();
    }
    if(receivedChar == 'B')
    {
      Backward(); 
    }         
     if(receivedChar == 'L')
    {
      Left();
    }        
    if(receivedChar == 'R')
    {
      Right(); 
    }
    if(receivedChar == 'S')
    {
      Stop();
    }
  }
  delay(20);
}
