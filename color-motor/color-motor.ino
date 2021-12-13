#include <Servo.h>

#define S0 3
#define S1 4
#define S2 6
#define S3 7
#define echoPin 2
#define trigPin 1
#define sensorOut 5
int motor1pin1 = 13;
int motor1pin2 = 12;
int motor2pin1 = 11;
int motor2pin2 = 10;
Servo myservo;

int frequencyRed = 0;
int frequencyGreen = 0;
int frequencyBlue = 0;

long duration; // variable for the duration of sound wave travel
int distance;
float i=0;
int pos = 9;

void setup() {

  myservo.attach(9);
  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
  Serial.begin(9600); // // Serial Communication is starting with 9600 of baudrate speed
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);
  
  // Setting frequency-scaling to 20%
  digitalWrite(S0,HIGH);
  digitalWrite(S1,LOW);
  

}





void drive(int r, int g, int b) {
  if( r < g && r < b ){
    Serial.print("STOP!");
    digitalWrite(motor1pin1, LOW);
    digitalWrite(motor1pin2, LOW);
    digitalWrite(motor2pin1, LOW);
    digitalWrite(motor2pin2, LOW);
    for (pos = 180; pos >= 0; pos -= 2) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
                          // waits 15ms for the servo to reach the position
  }
  }
  if( g < b && g < r ) {
    Serial.print("reverse");
    digitalWrite(motor1pin1, LOW);
    digitalWrite(motor1pin2, HIGH);
    digitalWrite(motor2pin1, HIGH);
    digitalWrite(motor2pin2, LOW);

    for (pos = 0; pos <= 180; pos += 2) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
                          // waits 15ms for the servo to reach the position
  }


    
  }
  if( b < g && b < r ) {
    Serial.print("foward");
    digitalWrite(motor1pin1, HIGH);
    digitalWrite(motor1pin2, LOW);
    digitalWrite(motor2pin1, LOW);
    digitalWrite(motor2pin2, HIGH);

     
  }
}


long microsecondsToInches(long microseconds) {
   return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds) {
   return microseconds / 29 / 2;
}

void loop() {
  //motor section of code
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



 
  

    
   // Setting red filtered photodiodes to be read
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  // Reading the output frequency
  frequencyRed = pulseIn(sensorOut, LOW);
  // Printing the value on the serial monitor
  Serial.print("R= ");//printing name
  Serial.print(frequencyRed+10);//printing RED color frequency
  Serial.print("  ");
  delay(100);
  // Setting Green filtered photodiodes to be read
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  // Reading the output frequency
  frequencyGreen = pulseIn(sensorOut, LOW);
  // Printing the value on the serial monitor
  Serial.print("G= ");//printing name
  Serial.print(frequencyGreen);//printing RED color frequency
  Serial.print("  ");
  delay(100);
  // Setting Blue filtered photodiodes to be read
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
  // Reading the output frequency
  frequencyBlue = pulseIn(sensorOut, LOW);
  // Printing the value on the serial monitor
  Serial.print("B= ");//printing name
  Serial.print(frequencyBlue+35);//printing RED color frequency
  Serial.println("  ");
  drive(frequencyRed, frequencyGreen, frequencyBlue);
   
  delay(5);
  
}
