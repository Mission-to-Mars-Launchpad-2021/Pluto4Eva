// set pins
const int FORWARD_RIGHT = 7;
const int REVERSE_RIGHT = 8;
const int MOTOR_ON_RIGHT = 9;
const int MOTOR_ON_LEFT = 10;
const int FORWARD_LEFT = 11;
const int REVERSE_LEFT = 12;



void setup() {
  // put your setup code here, to run once:
  pinMode(FORWARD_RIGHT, OUTPUT); // Forward Right
  pinMode(REVERSE_RIGHT, OUTPUT); // Back Right
  pinMode(MOTOR_ON_RIGHT, OUTPUT); //  Right Motor On
  pinMode(MOTOR_ON_LEFT, OUTPUT); // Left Motor On 
  pinMode(FORWARD_LEFT, OUTPUT); // Forward Left
  pinMode(REVERSE_LEFT, OUTPUT); // Back Left

  Serial.begin(115200);
}

void loop() {
  //Slide to the left
  RotateLeft(600);
  Forward(500);
  RotateRight(600);
  Off(400); //Slide to the right
  RotateRight(600);
  Forward(500);
  RotateLeft(600);
  Off(800); //Criss cross
  RotateLeft(300);
  RotateRight(600);
  Off(1000); //Criss cross
  RotateLeft(600);
  RotateRight(600);
  Off(1000); //Cha Cha real smooth
  RotateRight(4000);

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



  
  
