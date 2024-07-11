//Li-Fi Door Lock
//Parth Chande 
//Sharayu Chavan
//Rahul Panda

// Pin number for the laser module
const int laserPin = D1;

// Pin number for the LDR module
const int ldrPin = D2; // Replace A0 with the actual pin number for your LDR module

int RelayPin = D4;

// Variables to store the time stamps for the pulses
unsigned long pulse1Time = 0;
unsigned long pulse2Time = 0;

// Variable to store the received input
String receivedInput = "";

void setup() {
  // Initialize the serial communication
  Serial.begin(9600);

  // Set the laser pin as OUTPUT
  pinMode(laserPin, OUTPUT);

  // Set the LDR pin as INPUT
  pinMode(ldrPin, INPUT);

  pinMode(RelayPin, OUTPUT);
    // Set the relay pin as OUTPUT
}
void loop() {
  // Check if there is any input received from the Serial Monitor
  if (Serial.available() > 0) {
    // Read the input from the Serial Monitor
    receivedInput = Serial.readString();

    // Check if the received input matches the desired input "PARTH"
    if (receivedInput.indexOf("PARTH") != -1) {
      Serial.println("Received input: PARTH");

      // Transmit the first pulse
      digitalWrite(laserPin, HIGH);
      delay(1000);
      digitalWrite(laserPin, LOW);

      // Wait for the first pulse to be received by LDR
      while (analogRead(ldrPin) < 800) { // Adjust the threshold value (800) to match the sensitivity of your LDR
        // Do nothing, wait for the LDR to detect the first pulse
      }

      // Record the time stamp of the first pulse
      pulse1Time = millis();

      // Transmit the second pulse
      delay(1000);
      digitalWrite(laserPin, HIGH);
      delay(1000);
      digitalWrite(laserPin, LOW);

      // Wait for the second pulse to be received by LDR
      while (analogRead(ldrPin) < 800) { // Adjust the threshold value (800) to match the sensitivity of your LDR
        // Do nothing, wait for the LDR to detect the second pulse
      }

      // Record the time stamp of the second pulse
      pulse2Time = millis();

      // Calculate the delay between the two pulses
      unsigned long delayBetweenPulses = pulse2Time - pulse1Time;

      // Check if the delay is 2006ms
      if (delayBetweenPulses >= 2000 && delayBetweenPulses <= 2100) {
        	// Let's turn on the relay...
	      digitalWrite(RelayPin, LOW);
	      delay(3000);
	
      	// Let's turn off the relay...
      	digitalWrite(RelayPin, HIGH);
      	delay(3000);
        
        Serial.println("Door Unlocked");
      }
    }
    if (receivedInput != "PARTH") {
     Serial.print("Received input: ");
     Serial.println(receivedInput);

      // Transmit the first pulse
      digitalWrite(laserPin, HIGH);
      delay(500);
      digitalWrite(laserPin, LOW);

      // Wait for the first pulse to be received by LDR
      while (analogRead(ldrPin) < 800) { // Adjust the threshold value (800) to match the sensitivity of your LDR
        // Do nothing, wait for the LDR to detect the first pulse
      }

      // Record the time stamp of the first pulse
      pulse1Time = millis();

      // Transmit the second pulse
      delay(500);
      digitalWrite(laserPin, HIGH);
      delay(500);
      digitalWrite(laserPin, LOW);

      // Wait for the second pulse to be received by LDR
      while (analogRead(ldrPin) < 800) { // Adjust the threshold value (800) to match the sensitivity of your LDR
        // Do nothing, wait for the LDR to detect the second pulse
      }

      // Record the time stamp of the second pulse
      pulse2Time = millis();

      // Calculate the delay between the two pulses
      unsigned long delayBetweenPulses = pulse2Time - pulse1Time;

      // Check if the delay is 2006ms
      if (delayBetweenPulses >= 1000 && delayBetweenPulses <= 1500) {
        Serial.println("Invalid Password");
      }
    }
  }
}
