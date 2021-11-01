void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
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

  if (sensorValueMid < 90){
    Off(100);
    SlowForward();
  }else{
    RotateRight(1)
  }
  
  


}
