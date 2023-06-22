const int numSensors = 8;                     // Number of IR sensors
const int sensorPins[numSensors] = {34, 35, 32, 33, 25, 26, 27, 14}; // Analog input pins for the sensors
int sensorThresholds[numSensors];         // Array to store the sensor thresholds

void setup() {
  Serial.begin(9600);                     // Initialize serial communication
  // Read sensor values multiple times to determine the maximum threshold
  int numSamples = 10;
  for (int i = 0; i < numSamples; i++) {
    for (int j = 0; j < numSensors; j++) {
      int sensorValue = analogRead(sensorPins[j]);
      sensorThresholds[j] = max(sensorThresholds[j], sensorValue);
    }
    delay(10);
  }
}

void loop() {
  // Read the sensor values
  int sensorValues[numSensors];
  for (int i = 0; i < numSensors; i++) {
    sensorValues[i] = analogRead(sensorPins[i]);
  }

  // Determine the maximum threshold for each sensor
  for (int i = 0; i < numSensors; i++) {
    sensorThresholds[i] = max(sensorThresholds[i], sensorValues[i]);
  }

 
}
