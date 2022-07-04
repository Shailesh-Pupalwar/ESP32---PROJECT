// Arduino Line Follower Robot Code

#define enA 25//Enable1 L293 Pin enA 
#define in1 27 //Motor1  L293 Pin in1 27 Left Motor Forward
#define in2 26 //Motor1  L293 Pin in1 26 Left Motor Backward
#define in3 16 //Motor2  L293 Pin in1 16
#define in4 17 //Motor2  L293 Pin in1 17
#define enB 14 //Enable2 L293 Pin enB 
#define R_S 33 //ir sensor Right
#define L_S 32 //ir sensor Left
void setup(){ 
   Serial.begin(9600);
pinMode(R_S, INPUT); 
pinMode(L_S, INPUT); 
pinMode(enA, OUTPUT); 
pinMode(in1, OUTPUT); 
pinMode(in2, OUTPUT); 
pinMode(in3, OUTPUT); 
pinMode(in4, OUTPUT); 
pinMode(enB, OUTPUT);
digitalWrite(enA, HIGH); 
digitalWrite(enB, HIGH); 
delay(1000);
}
void loop(){  
if((digitalRead(R_S) == LOW)&&(digitalRead(L_S) == LOW)){Serial.println("Forward");forward();}   //if Right Sensor and Left Sensor are at White color then it will call forword function
if((digitalRead(R_S) == LOW)&&(digitalRead(L_S) == HIGH)){Serial.println("Right");turnRight();} //if Right Sensor is Black and Left Sensor is White then it will call turn Right function  
if((digitalRead(R_S) == HIGH)&&(digitalRead(L_S) == LOW)){Serial.println("Left");turnLeft();}  //if Right Sensor is White and Left Sensor is Black then it will call turn Left function
if((digitalRead(R_S) == HIGH)&&(digitalRead(L_S) == HIGH)){Serial.println("Stop");Stop();} //if Right Sensor and Left Sensor are at Black color then it will call Stop function
int irreadleft=digitalRead(R_S);                                  
Serial.println(irreadleft);
Stop();
delay(200);
}
void forward(){  //forword
digitalWrite(in1, HIGH); //Right Motor forword Pin 
digitalWrite(in2, LOW);  //Right Motor backword Pin 
digitalWrite(in3, HIGH);  //Left Motor backword Pin 
digitalWrite(in4, LOW); //Left Motor forword Pin 
delay(50);
}
void turnRight(){ //turnRight
digitalWrite(in1, HIGH);  //Right Motor forword Pin 
digitalWrite(in2, LOW); //Right Motor backword Pin  
digitalWrite(in3, LOW);  //Left Motor backword Pin 
 digitalWrite(in4, LOW); //Left Motor forword Pin 
 delay(50);
}
void turnLeft(){ //turnLeft
digitalWrite(in1, LOW); //Right Motor forword Pin 
digitalWrite(in2, LOW);  //Right Motor backword Pin 
digitalWrite(in3, HIGH); //Left Motor backword Pin 
digitalWrite(in4, LOW);  //Left Motor forword Pin 
delay(50);
}
void Stop(){ //stop
digitalWrite(in1, LOW); //Right Motor forword Pin 
digitalWrite(in2, LOW); //Right Motor backword Pin 
digitalWrite(in3, LOW); //Left Motor backword Pin 
digitalWrite(in4, LOW); //Left Motor forword Pin 
}
      
