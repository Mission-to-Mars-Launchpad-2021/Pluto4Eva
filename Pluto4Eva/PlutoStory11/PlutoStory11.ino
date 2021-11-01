
const int FORWARD_RIGHT = 7;
const int REVERSE_RIGHT = 8;
const int MOTOR_ON_RIGHT = 9;
const int MOTOR_ON_LEFT = 10;
const int FORWARD_LEFT = 11;
const int REVERSE_LEFT = 12;
const int LEFT_FEEDBACK = 2; // Pin numbers on Rover
const int RIGHT_FEEDBACK = 3;

volatile int leftcounter = 0; // initiate counter to zero for start 
volatile int rightcounter = 0; // counter could always be reset
volatile int loopcounter = 0; // counter for for loop

#include <NewPing.h>

#define TRIGGER_PIN  13  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     17 // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.


void setup() {
  pinMode(FORWARD_RIGHT, OUTPUT); // Forward Right
  pinMode(REVERSE_RIGHT, OUTPUT); // Back Right
  pinMode(MOTOR_ON_RIGHT, OUTPUT); //  Right Motor On
  pinMode(MOTOR_ON_LEFT, OUTPUT); // Left Motor On 
  pinMode(FORWARD_LEFT, OUTPUT); // Forward Left
  pinMode(REVERSE_LEFT, OUTPUT); // Back Left

  Serial.begin(115200);
  attachInterrupt(digitalPinToInterrupt(LEFT_FEEDBACK),LeftMotorISR,RISING);
  attachInterrupt(digitalPinToInterrupt(RIGHT_FEEDBACK),RightMotorISR,RISING);
}

// the loop function runs over and over again forever
void loop() {
  
  // Just print out the values to show counter operating
  Serial.println("Left Counter");
  Serial.print(leftcounter);
  
  Serial.println("Right Counter");
  Serial.print(rightcounter);
  
   delay(50);                     // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
  Serial.print("Ping: ");
  Serial.print(sonar.ping_cm()); // Send ping, get distance in cm and print result (0 = outside set distance range)
  Serial.println("cm");

  if (sonar.ping_cm()<15){
  SlowForward();
  Serial.print("Zooming");
  rightcounter = 0;
  }
  
  else{
    while (rightcounter<=46){
      SlowReverse();
      Serial.print("reversing");
    }
    
    FastStop(1000);
    Serial.print("Fast stopping");
    exit(0);
  }
   


}

void MotorsOn (int pause) { // motor turns on
  digitalWrite(MOTOR_ON_RIGHT, HIGH);   
  digitalWrite(MOTOR_ON_LEFT, HIGH);
  digitalWrite(REVERSE_RIGHT, LOW);   
  digitalWrite(REVERSE_LEFT, LOW);
  digitalWrite(FORWARD_RIGHT, LOW);
  digitalWrite(FORWARD_LEFT, LOW);
  delay(pause);
}

void Forward (int pause) { // rover drives forwards
  digitalWrite(MOTOR_ON_RIGHT, HIGH);   
  digitalWrite(MOTOR_ON_LEFT, HIGH);
  digitalWrite(FORWARD_RIGHT, HIGH);
  digitalWrite(FORWARD_LEFT, HIGH);
  digitalWrite(REVERSE_RIGHT, LOW);   
  digitalWrite(REVERSE_LEFT, LOW);
  delay(pause);
}

void SlowForward () { // rover drives forwards slowly
  analogWrite(MOTOR_ON_RIGHT, 70);   
  analogWrite(MOTOR_ON_LEFT, 80);
  digitalWrite(FORWARD_RIGHT, HIGH);
  digitalWrite(FORWARD_LEFT, HIGH);
  digitalWrite(REVERSE_RIGHT, LOW);   
  digitalWrite(REVERSE_LEFT, LOW);
}

void Off (int pause) { // rover stops
  digitalWrite(MOTOR_ON_RIGHT, LOW);   
  digitalWrite(MOTOR_ON_LEFT, LOW);
  digitalWrite(REVERSE_RIGHT, LOW);   
  digitalWrite(REVERSE_LEFT, LOW);
  digitalWrite(FORWARD_RIGHT, LOW);
  digitalWrite(FORWARD_LEFT, LOW);
  delay(pause);
}

void Reverse (int pause) { // rover reverses
  digitalWrite(MOTOR_ON_RIGHT, HIGH);   
  digitalWrite(MOTOR_ON_LEFT, HIGH);
  digitalWrite(FORWARD_RIGHT, LOW);
  digitalWrite(FORWARD_LEFT, LOW);
  digitalWrite(REVERSE_RIGHT, HIGH);   
  digitalWrite(REVERSE_LEFT, HIGH);
  delay(pause);
}

void TurnLeft (int pause) { // rover turns left
  analogWrite(MOTOR_ON_RIGHT, 255);   
  analogWrite(MOTOR_ON_LEFT, 70);
  digitalWrite(FORWARD_RIGHT, HIGH);
  digitalWrite(FORWARD_LEFT, HIGH);
  digitalWrite(REVERSE_RIGHT, LOW);   
  digitalWrite(REVERSE_LEFT, LOW);
  delay(pause);
}

void TurnRight (int pause) { // rover turns right
  analogWrite(MOTOR_ON_RIGHT, 70);   
  analogWrite(MOTOR_ON_LEFT, 255);
  digitalWrite(FORWARD_RIGHT, HIGH);
  digitalWrite(FORWARD_LEFT, HIGH);
  digitalWrite(REVERSE_RIGHT, LOW);   
  digitalWrite(REVERSE_LEFT, LOW);
  delay(pause);
}

void RotateRight (int pause) { // rover spins right on the spot
  digitalWrite(MOTOR_ON_RIGHT, HIGH);   
  digitalWrite(MOTOR_ON_LEFT, HIGH);
  digitalWrite(FORWARD_RIGHT, LOW);
  digitalWrite(FORWARD_LEFT, HIGH);
  digitalWrite(REVERSE_RIGHT, HIGH);   
  digitalWrite(REVERSE_LEFT, LOW);
  delay(pause);
}

void RotateLeft (int pause) { // rover spins left on the spot
  digitalWrite(MOTOR_ON_RIGHT, HIGH);   
  digitalWrite(MOTOR_ON_LEFT, HIGH);
  digitalWrite(FORWARD_RIGHT, HIGH);
  digitalWrite(FORWARD_LEFT, LOW);
  digitalWrite(REVERSE_RIGHT, LOW);   
  digitalWrite(REVERSE_LEFT, HIGH);
  delay(pause);
}

void LeftMotorISR(){
  //adds one to counter each left motor revoulution
  leftcounter++;
}

void RightMotorISR(){
  // adds one to the counter on each right motor revoulution
  rightcounter++;
}

void SlowReverse() { // rover reverses slowly
  analogWrite(MOTOR_ON_RIGHT, 70);   
  analogWrite(MOTOR_ON_LEFT, 80);
  digitalWrite(FORWARD_RIGHT, LOW);
  digitalWrite(FORWARD_LEFT, LOW);
  digitalWrite(REVERSE_RIGHT, HIGH);   
  digitalWrite(REVERSE_LEFT, HIGH);
  
}

void FastStop (int pause) { // rover stops
  digitalWrite(MOTOR_ON_RIGHT, HIGH);   
  digitalWrite(MOTOR_ON_LEFT, HIGH);
  digitalWrite(REVERSE_RIGHT, LOW);   
  digitalWrite(REVERSE_LEFT, LOW);
  digitalWrite(FORWARD_RIGHT, LOW);
  digitalWrite(FORWARD_LEFT, LOW);
  delay(pause);
}
