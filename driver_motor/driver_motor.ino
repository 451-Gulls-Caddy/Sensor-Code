// Motors
int motor1pin1 = 22;
int motor1pin2 = 24;
int enA = 12;

int motor2pin1 = 23;
int motor2pin2 = 25;
int enB = 13;

int motor3pin1 = 44;
int motor3pin2 = 45;
int enC = 6;

int motor4pin1 = 46;
int motor4pin2 = 47;
int enD = 7;


// Ultra Sound
#define echoPin 9
#define trigPin 10
long duration; // variable for the duration of sound wave travel
int distance;


// Color Sensor
#define S0 1
#define S1 2
#define S2 3
#define S3 4
#define sensorOut 5
int frequencyRed = 0;
int frequencyGreen = 0;
int frequencyBlue = 0;

bool a = false;

// This function lets you control speed of the motors
void speedControl() {
  // Turn on motors
  int i = 140;
  int l = 140;
  analogWrite(enA, i);
  analogWrite(enB, 145);
  analogWrite(enC, i);
  analogWrite(enD, i);

}
void speedControl2() {
  // Turn on motors
  int i = 140;
  int l = 140;
  analogWrite(enA, i);
  analogWrite(enB, 165);
  analogWrite(enC, i);
  analogWrite(enD, i);

}
void stopMovement(){
  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, LOW);
  digitalWrite(motor2pin2, LOW);
  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor3pin1, LOW);
  digitalWrite(motor3pin2, LOW);
  digitalWrite(motor4pin2, LOW);
  digitalWrite(motor4pin1, LOW);
}

void driveLeft(){
  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, HIGH);
  digitalWrite(motor2pin2, HIGH);
  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor3pin1, LOW);
  digitalWrite(motor3pin2, HIGH);
  digitalWrite(motor4pin2, LOW);
  digitalWrite(motor4pin1, HIGH);
  speedControl2();
}

void driveRight() {
  digitalWrite(motor1pin1, HIGH);
  digitalWrite(motor1pin2, LOW);
  digitalWrite(motor2pin2, LOW);
  digitalWrite(motor2pin1, HIGH);
  digitalWrite(motor3pin1, HIGH);
  digitalWrite(motor3pin2, LOW);
  digitalWrite(motor4pin2, HIGH);
  digitalWrite(motor4pin1, LOW);
  speedControl2();
}

void driveBackward(){
  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, HIGH);
  digitalWrite(motor2pin2, LOW);
  digitalWrite(motor2pin1, HIGH);
  digitalWrite(motor3pin1, HIGH);
  digitalWrite(motor3pin2, LOW);
  digitalWrite(motor4pin2, LOW);
  digitalWrite(motor4pin1, HIGH);
  speedControl();
}


void driveForward(){
  digitalWrite(motor1pin1, HIGH);
  digitalWrite(motor1pin2, LOW);
  digitalWrite(motor2pin2, HIGH);
  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor3pin1, LOW);
  digitalWrite(motor3pin2, HIGH);
  digitalWrite(motor4pin2, HIGH);
  digitalWrite(motor4pin1, LOW);
  speedControl();
}



void setup() {
  // put your setup code here, to run once:
  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  pinMode(enA, OUTPUT);
  pinMode(motor2pin1, OUTPUT);
  pinMode(motor2pin2, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(motor3pin1, OUTPUT);
  pinMode(motor3pin2, OUTPUT);
  pinMode(enC, OUTPUT);
  pinMode(motor4pin1, OUTPUT);
  pinMode(motor4pin2, OUTPUT);
  pinMode(enD, OUTPUT);

  // Ultra Sound
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
  Serial.begin(9600);

  // Color Sensor
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);

  // Setting frequency-scaling to 20%
  digitalWrite(S0,HIGH);
  digitalWrite(S1,LOW);
}

int getColor(){
  // Setting red filtered photodiodes to be read
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  // Reading the output frequency
  frequencyRed = pulseIn(sensorOut, LOW);
  // Printing the value on the serial monitor
  Serial.print("R= ");//printing name
  Serial.print(frequencyRed);//printing RED color frequency
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
  Serial.print(frequencyBlue);//printing RED color frequency
  Serial.println("  ");


  // 0 = blue  1 = red   2 = green
  if(frequencyBlue < frequencyRed && frequencyBlue < frequencyGreen)
    return 0;
  else if(frequencyRed < frequencyBlue && frequencyRed < frequencyGreen)
    return 1;
  else
    return 2;
  
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
//  Serial.print("Distance: ");
//  Serial.print(distance);
//  Serial.println(" cm");

   
    
    int color = getColor();
    driveForward();
    if(distance < 15){
      stopMovement();
      delay(1000);
//      if(color == 0){
//        Serial.print("Blue");
//        driveForward();
//      }
      if(color == 1){
        Serial.print("Red");
        while(distance < 15)
           driveLeft();
      }
      else
        Serial.print("Green");
   }
//  driveForward();
//  delay(1000);
//  stopMovement();
//  delay(1000);
//
//  driveBackward();
//  delay(1000);
//  stopMovement();
//  delay(1000);
//  
//  driveLeft();
//  delay(1000);
//  stopMovement();
//  delay(1000);
//
//  driveForward();
//  delay(1000);
//  stopMovement();
//  delay(1000);
//
//  driveBackward();
//  delay(1000);
//  stopMovement();
//  delay(1000);
//
//  driveRight();
//  delay(1000);
//  stopMovement();
//  delay(1000);
//  driveForward();
//  delay(2500);
//  stopMovement();
//  delay(1000);
//
//  driveBackward();
//  delay(2500);
//  stopMovement();
//  delay(1000);

}
