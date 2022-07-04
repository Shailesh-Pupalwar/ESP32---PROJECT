#define echoPin 32 // attach pin D2 Arduino to pin Echo of HC-SR04   
#define trigPin 33 //attach pin D3 Arduino to pin Trig of HC-SR04   

// defines variables
long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement

void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
  Serial.begin(9600); // // Serial Communication is starting with 9600 of baudrate speed
  Serial.println("Ultrasonic Sensor HC-SR04 Test"); // print some text in Serial Monitor
}

void loop() {
  // Clears the trigPin condition
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
}
/*******SETUP CODE*****************************************/
const int LeftMotorForward = 16;
const int LeftMotorBackward = 17;
const int RightMotorForward = 27;
const int RightMotorBackward = 26;
const int enA=14;
const int enB=25;

const int trigPin =33;
const int echoPin =32;

int x_theta =400; // time required to rotate 60 degree
int distance_1;
int distance_2;

void setup()
{
  Serial.begin(9600);
  // Set L298N Control Pins as Output
  pinMode(RightMotorForward, OUTPUT);
  pinMode(LeftMotorForward, OUTPUT);
  pinMode(LeftMotorBackward, OUTPUT);
  pinMode(RightMotorBackward, OUTPUT);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
}

/*****************LOOP*****************************/
void loop()
{  
  digitalWrite(enA,HIGH);
  digitalWrite(enB,HIGH);
  if(readPing()>10)// 10 is critical distance
  {
    moveForward();
  }
  else
  {
    
    Stop();
    delay(1000);

    /*Turns 90 left and takes reading and comes back to original position */
    turnLeft();
    delay(x_theta);
    Stop();
    delay(1000);
    distance_1=readPing();
    turnRight();
    delay(x_theta);
    Stop();
    delay(1000);

    /**turn the motor right 90 degrees */
    turnRight();
    delay(x_theta);
    Stop();
    delay(1000);
    distance_2=readPing();
    turnLeft();
    delay(x_theta);
    Stop();
    delay(1000);

    
    if(distance_1>distance_2)
    {
      turnLeft();
      delay(x_theta);
      Stop();
      delay(500);
      Serial.write("case-1");
     
    }
    else
    {
      turnRight();
      delay(x_theta);
      Stop();
      delay(500);
      Serial.write("case-2");
    }
          
  }
   
}

int readPing()      // Read Ping Function for Ultrasonic Sensor.
{
  int duration;
  int distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  return distance;
}

void Stop()       // Move Stop Function for Motor Driver.
{
  digitalWrite(RightMotorForward, LOW);
  digitalWrite(RightMotorBackward, LOW);
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(LeftMotorBackward, LOW);
}

void moveForward()    // Move Forward Function for Motor Driver.
{
    digitalWrite(RightMotorForward, HIGH);
    digitalWrite(RightMotorBackward, LOW);
    digitalWrite(LeftMotorForward, HIGH);
    digitalWrite(LeftMotorBackward, LOW);
}

void moveBackward()   // Move Backward Function for Motor Driver.
{
  digitalWrite(RightMotorForward, LOW);
  digitalWrite(RightMotorBackward, HIGH);
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(LeftMotorBackward, HIGH);
}

void turnRight()      // Turn Right Function for Motor Driver.
{
  digitalWrite(RightMotorForward, LOW);
  digitalWrite(RightMotorBackward, HIGH);
  digitalWrite(LeftMotorForward, HIGH);
  digitalWrite(LeftMotorBackward, LOW);
}

void turnLeft()       // Turn Left Function for Motor Driver.
{
  digitalWrite(RightMotorForward, HIGH);
  digitalWrite(RightMotorBackward, LOW);
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(LeftMotorBackward, HIGH);
}
/**************************LOOP ENDS***********************************/
