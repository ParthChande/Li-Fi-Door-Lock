# Li-Fi Door Lock

This project demonstrates a Li-Fi (Light Fidelity) based door lock system using an Arduino. The system uses a laser and a Light Dependent Resistor (LDR) to transmit and receive signals. The door lock opens when a specific input is received and verified.


## Components Used

- Arduino board
- Laser module
- Light Dependent Resistor (LDR)
- Relay module
- Connecting wires
- Breadboard

## How It Works

1. The system waits for an input string from the Serial Monitor.
2. If the input matches "PARTH", the system transmits a specific sequence of light pulses using the laser.
3. The LDR receives the pulses, and the system records the time stamps of these pulses.
4. If the delay between pulses matches the expected delay, the relay is activated to unlock the door.
5. If the input does not match "PARTH", a different sequence of pulses is sent and the system displays an "Invalid Password" message.

## Setup

1. Connect the laser module to pin D1 on the Arduino.
2. Connect the LDR module to pin D2 on the Arduino.
3. Connect the relay module to pin D4 on the Arduino.
4. Upload the code from `src/LiFiDoorLock.ino` to the Arduino.

## Usage

1. Open the Serial Monitor in the Arduino IDE.
2. Enter the input string (e.g., "PARTH") and press Enter.
3. Observe the behavior of the laser, LDR, and relay.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
