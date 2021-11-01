/*
  Analog Input
  - potentiometer
    center pin of the potentiometer to the analog input 0
    one side pin (either one) to ground
    the other side pin to +5V
*/
const int FORWARD_RIGHT = 7;
const int REVERSE_RIGHT = 8;
const int MOTOR_ON_RIGHT = 9;
const int MOTOR_ON_LEFT = 10;
const int FORWARD_LEFT = 11;
const int REVERSE_LEFT = 12;
const int LEFT_FEEDBACK = 2; // Pin numbers on Rover
const int RIGHT_FEEDBACK = 3;

int sensorPinLeft = A7;    // select the input pin for the potentiometer
int sensorPinMid = A6;
int sensorPinRight = A2;
int sensorValueLeft = 0;  // variable to store the value coming from the sensor
int sensorValueMid = 0;
int sensorValueRight = 0;

volatile int leftcounter = 0; // initiate counter to zero for start 
volatile int rightcounter = 0; // counter could always be reset
volatile int loopcounter = 0; // counter for for loop
volatile int brightlight = 1023; // Brightest light reading variable
volatile int newlight = 1023; // current light reading


void setup() {
  Serial.begin(115200);
  pinMode(FORWARD_RIGHT, OUTPUT); // Forward Right
  pinMode(REVERSE_RIGHT, OUTPUT); // Back Right
  pinMode(MOTOR_ON_RIGHT, OUTPUT); //  Right Motor On
  pinMode(MOTOR_ON_LEFT, OUTPUT); // Left Motor On 
  pinMode(FORWARD_LEFT, OUTPUT); // Forward Left
  pinMode(REVERSE_LEFT, OUTPUT); // Back Left
  pinMode(LED_BUILTIN, OUTPUT); // inbuilt LED

}

void loop() {
  // read the value from the sensor:
  sensorValueLeft = analogRead(sensorPinLeft);
  Serial.print ("left: ");
  Serial.print(sensorValueLeft);
  sensorValueMid = analogRead(sensorPinMid);
  Serial.print (" - mid: ");
  Serial.print(sensorValueMid);
  sensorValueRight = analogRead(sensorPinRight);
  Serial.print (" - right: ");
  Serial.println(sensorValueRight);

  while (millis() < 2800){
    Serial.println("in while loop");
    Serial.println(millis());
    sensorValueMid = analogRead(sensorPinMid);
    newlight = sensorValueMid;
    RotateLeft(10);
    Off(1);
    //loopcounter+1;
  
    
    if(newlight < brightlight){
      brightlight = newlight;
    }
      
   }
    
  
  
  sensorValueMid = analogRead(sensorPinMid);
  newlight = sensorValueMid;
  
  if(newlight < (brightlight +5) or newlight > (brightlight -5)){
     SlowForward(10000);
  Serial.println("Going to light");
  Off(1000);
  exit(0);

  }else if (newlight > (brightlight +5) or newlight < (brightlight -5))
  { sensorValueMid = analogRead(sensorPinMid);
    newlight = sensorValueMid;
    Serial.print (" - mid: ");
    Serial.print(newlight);
    Serial.print (" bright: ");
  Serial.print(brightlight);
    RotateLeft(10);
    Serial.println("Turning left");
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

void SlowForward (int pause) { // rover drives forwards slowly
  analogWrite(MOTOR_ON_RIGHT, 70);   
  analogWrite(MOTOR_ON_LEFT, 80);
  digitalWrite(FORWARD_RIGHT, HIGH);
  digitalWrite(FORWARD_LEFT, HIGH);
  digitalWrite(REVERSE_RIGHT, LOW);   
  digitalWrite(REVERSE_LEFT, LOW);
  delay(pause);
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

void RotateRight () { // rover spins right on the spot
  digitalWrite(MOTOR_ON_RIGHT, HIGH);   
  digitalWrite(MOTOR_ON_LEFT, HIGH);
  digitalWrite(FORWARD_RIGHT, LOW);
  digitalWrite(FORWARD_LEFT, HIGH);
  digitalWrite(REVERSE_RIGHT, HIGH);   
  digitalWrite(REVERSE_LEFT, LOW);
  
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
