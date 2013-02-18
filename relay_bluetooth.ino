/*
  Mega multple serial test
 
 Receives from the main serial port, sends to the others. 
 Receives from serial port 1, sends to the main serial (Serial 0).
 
 This example works only on the Arduino Mega
 
 The circuit: 
 * Any serial device attached to Serial port 1
 * Serial monitor open on Serial port 0:
 
 created 30 Dec. 2008
 modified 20 May 2012
 by Tom Igoe & Jed Roach
 
 This example code is in the public domain.
 
 */
String command = "";
int relayPin = 7;

void setup() {
  // initialize both serial ports:
  Serial.begin(115200);
  Serial1.begin(115200);
  pinMode(relayPin, OUTPUT);
}

void loop() {
  // read from port 1, send to port 0:
  if (Serial1.available()) {
    int inByte = Serial1.read();
    switch (inByte) {
    case 48:
      digitalWrite(relayPin,LOW);
      break;
    case 49:
      digitalWrite(relayPin,HIGH);
      break;
    }
    Serial.print(inByte);
    // No repeats 
  }
  //command = "";
  // read from port 0, send to port 1:
  if (Serial.available()) {
    int inByte = Serial.read();
    Serial1.write(inByte); 
  }
}
