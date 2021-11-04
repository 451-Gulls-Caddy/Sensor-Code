#define S0 5
#define S1 4
#define S2 7
#define S3 6
#define sensorOut 8
int redFrequency = 0;
int blueFrequency = 0;
int greenFrequency = 0;

int redColor = 0;
int blueColor = 0;
int greenColor = 0;

void setup() {
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);
  
  // Setting frequency-scaling to 20%
  digitalWrite(S0,HIGH);
  digitalWrite(S1,LOW);
  
  Serial.begin(9600);
}
void loop() {
  // Setting red filtered photodiodes to be read
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  // Reading the output frequency
  redFrequency = pulseIn(sensorOut, LOW);
  // Remaping the value of the frequency to 0 - 255
  redColor = map(redFrequency,0,255,27,72);
  // Printing the value on the serial monitor
  Serial.print("R= ");//printing name
  Serial.print(redColor);//printing RED color frequency
  Serial.print("  ");
  delay(100);
  // Setting Green filtered photodiodes to be read
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  // Reading the output frequency
  greenFrequency = pulseIn(sensorOut, LOW);
  greenColor = map(greenFrequency, 0,255,30,90);
  // Printing the value on the serial monitor
  Serial.print("G= ");//printing name
  Serial.print(greenColor);//printing RED color frequency
  Serial.print("  ");
  delay(100);
  // Setting Blue filtered photodiodes to be read
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
  // Reading the output frequency
  blueFrequency = pulseIn(sensorOut, LOW);
  blueColor = map(blueFrequency, 0,255,25,70);
  // Printing the value on the serial monitor
  Serial.print("B= ");//printing name
  Serial.print(blueColor);//printing RED color frequency
  Serial.println("  ");
  delay(100);


 // Checks the current detected color and prints
  // a message in the serial monitor
  if(redColor > greenColor && redColor > blueColor){
      Serial.println(" - RED detected!");
  }
  if(greenColor > redColor && greenColor > blueColor){
    Serial.println(" - GREEN detected!");
  }
  if(blueColor > redColor && blueColor > greenColor){
    Serial.println(" - BLUE detected!");
  }
  
}
