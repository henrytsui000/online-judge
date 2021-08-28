void setup() {
   Serial.begin(9600);
   int sensorValue = analogRead(A0);
   float voltage = sensorValue * (5.0 / 1023.0);
   Serial.println(voltage);
   if(voltage < 2.5){
   Serial.println("Dora");

   }else{
   Serial.println("Cora");
   }
}


void loop() {
    
  analogWrite(ledPin, val / 4); // analogRead values go from 0 to 1023, analogWrite values from 0 to 255
}