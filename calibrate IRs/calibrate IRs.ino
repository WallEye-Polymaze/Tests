const int numSensors = 8; // Number of IR sensors
const int sensorPins[numSensors] = {A0, A1, A2, A3, A4, A5, A6, A7}; // Analog input pins for the sensors

int sensorThresholds[numSensors]; // Array to store the sensor thresholds

void setup() {
  Serial.begin(9600); // Initialize serial communication

  // Calibrate the sensors to determine the thresholds
  calibrateSensors();
}

void loop() {
  // Read the sensor values
  int sensorValues[numSensors];
  for (int i = 0; i < numSensors; i++) {
    sensorValues[i] = analogRead(sensorPins[i]);
  }

  // Determine the line based on the thresholds
  for (int i = 0; i < numSensors; i++) {
    if (sensorValues[i] > sensorThresholds[i]) {
      Serial.print("Sensor ");
      Serial.print(i);
      Serial.println(": On line");
    } else {
      Serial.print("Sensor ");
      Serial.print(i);
      Serial.println(": Off line");
    }
  }

  delay(100); // Adjust the delay as needed
}

void calibrateSensors() {
  Serial.println("Calibrating sensors...");
  delay(2000); // Allow time to position the sensors over the line

  // Read sensor values multiple times to determine the average
  int numSamples = 10;
  for (int i = 0; i < numSamples; i++) {
    for (int j = 0; j < numSensors; j++) {
      sensorThresholds[j] += analogRead(sensorPins[j]);
    }
    delay(10);
  }

  // Calculate the average threshold for each sensor
  for (int i = 0; i < numSensors; i++) {
    sensorThresholds[i] /= numSamples; // divides the value of sensorThresholds[i] by numSamples ( average) and assigns the result back to sensorThresholds[i].
  }

  Serial.println("Sensor calibration complete.");
}

