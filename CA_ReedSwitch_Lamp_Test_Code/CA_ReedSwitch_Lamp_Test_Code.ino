#define Sensor 19
#define LED 18
 
void setup() {
  Serial.begin(9600);
  pinMode(Sensor, INPUT);
  pinMode(LED, OUTPUT);
}
 
void loop() {
  bool value = digitalRead(Sensor);
  Serial.println(value);
 
  if (value == 0) // means that the reed switch is open, OV supply 
  {
    digitalWrite(LED, HIGH);
    Serial.println("LED on");
  } else
  {
    digitalWrite(LED, LOW);
    Serial.println("LED off");
  }
}
