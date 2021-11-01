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

int sensorPinLeft = A7;    // select the input pin for the potentiometer
int sensorPinMid = A6;
int sensorPinRight = A2;
int sensorValueLeft = 0;  // variable to store the value coming from the sensor
int sensorValueMid = 0;
int sensorValueRight = 0;




void setup() {
  // put your setup code here, to run once:
    Serial.begin(115200);
  pinMode(FORWARD_RIGHT, OUTPUT); // Forward Right
  pinMode(REVERSE_RIGHT, OUTPUT); // Back Right
  pinMode(MOTOR_ON_RIGHT, OUTPUT); //  Right Motor On
  pinMode(MOTOR_ON_LEFT, OUTPUT); // Left Motor On 
  pinMode(FORWARD_LEFT, OUTPUT); // Forward Left
  pinMode(REVERSE_LEFT, OUTPUT); // Back Left


}

void loop() {
  // put your main code here, to run repeatedly:
  RotateLeft(2800);
  Off(3000);
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


void RotateLeft (int pause) { // rover spins left on the spot
  digitalWrite(MOTOR_ON_RIGHT, HIGH);   
  digitalWrite(MOTOR_ON_LEFT, HIGH);
  digitalWrite(FORWARD_RIGHT, HIGH);
  digitalWrite(FORWARD_LEFT, LOW);
  digitalWrite(REVERSE_RIGHT, LOW);   
  digitalWrite(REVERSE_LEFT, HIGH);
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
