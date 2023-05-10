
const int DOOR_SENSOR_PIN = 19;  // Arduino pin connected to door sensor's pin

int currentDoorState; // current state of door sensor
int lastDoorState;    // previous state of door sensor

void setup() {
  Serial.begin(9600);                     // initialize serial
  pinMode(DOOR_SENSOR_PIN, INPUT_PULLUP); // set arduino pin to input pull-up mode

  currentDoorState = digitalRead(DOOR_SENSOR_PIN); // read state
}

void loop() {
  lastDoorState = currentDoorState;              // save the last state
  currentDoorState  = digitalRead(DOOR_SENSOR_PIN); // read new state

  if (lastDoorState == LOW && currentDoorState == HIGH) { // state change: LOW -> HIGH
    Serial.println("The door-opening event is detected");
    // TODO: turn on alarm, light or send notification ...
  }
  else
  if (lastDoorState == HIGH && currentDoorState == LOW) { // state change: HIGH -> LOW
    Serial.println("The door-closing event is detected");
    // TODO: turn off alarm, light or send notification ...
  }
}
