
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
  
  Forward8(); //Makes a figure of eight driving forwards
  Backward8(); //Makes a figure of eight driving backwards
  
  Off (1);
  
 exit(1);
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

void SlowReverse(int pause) { // rover reverses slowly
  analogWrite(MOTOR_ON_RIGHT, 70);   
  analogWrite(MOTOR_ON_LEFT, 80);
  digitalWrite(FORWARD_RIGHT, LOW);
  digitalWrite(FORWARD_LEFT, LOW);
  digitalWrite(REVERSE_RIGHT, HIGH);   
  digitalWrite(REVERSE_LEFT, HIGH);
  delay(pause);
}

void Forward8(){ //Drives in a figure of eight moving forwards
  
    Off (1000);
    RotateRight(570);
    rightcounter = 0;
    Off (1000); // corner 1

    SlowForward(3000);

    Off (1000);
    RotateRight(565);
    rightcounter = 0;
    Off (1000); // corner 2

    SlowForward(3000);
    
    Off (1000);
    RotateRight(555);
    rightcounter = 0;
    Off (1000); // corner 3

    SlowForward(3000);
    
    Off (1000);
    RotateRight(570);
    rightcounter = 0;
    Off (1000); // corner 4

    SlowForward(3000);

    Off (1000);
    RotateLeft(550);
    rightcounter = 0;
    Off (1000); // corner 5

    SlowForward(3000);
    
    Off (1000);
    RotateLeft(565);
    rightcounter = 0;
    Off (1000); // corner 6

    SlowForward(3000);
    
    Off (1000);
    RotateLeft(565);
    rightcounter = 0;
    Off (1000); // corner 7

    SlowForward(3000);

    Off (1000);
    RotateLeft(545);
    rightcounter = 0;
    Off (1000); // corner 8

    SlowForward(3000);
    Off (1000);
}

void Backward8(){ //Drives in a figure of eight moving backwards
  
    Off (1000);

    SlowReverse(3000);
    
    Off (1000);
    RotateRight(570);
    rightcounter = 0;
    Off (1000); // corner 4

    SlowReverse(3000);

    Off (1000);
    RotateRight(565);
    rightcounter = 0;
    Off (1000); // corner 7

    SlowReverse(3000);

    Off (1000);
    RotateRight(565);
    rightcounter = 0;
    Off (1000); // corner 6

    SlowReverse(6000);

    Off (1000);
    RotateRight(565);
    rightcounter = 0;
    Off (1000); // corner 2

    SlowReverse(3000);

    Off (1000);
    RotateRight(555);
    rightcounter = 0;
    Off (1000); // corner 3

    SlowReverse(3000);

    Off (1000);
    RotateRight(570);
    rightcounter = 0;
    Off (1000); // corner 4

    SlowReverse(3000);

    Off (1000);
    RotateRight(1200);
    rightcounter = 0;
    Off (1000); // corner 1
}
