#include <IRremote.h>

const int led1 = 8;
const int led2 = 7;
const int irReceiverPin = 9;

IRrecv irrecv(irReceiverPin);
decode_results results;

void setup() {
  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  irrecv.enableIRIn();  // Start the receiver
}

void loop() {
  if (irrecv.decode(&results)) {
    // Print the received value in hexadecimal
    Serial.print("Received value: 0x");
    Serial.println(results.value, HEX);
    
    switch (results.value) {
      case 0xFF10EF: // Code for Button 1
        digitalWrite(led1, HIGH);  // Turn on LED 1
        Serial.println("LED 1 ON");
        break;
        
      case 0xFF20DF: // Code for Button 2
        digitalWrite(led1, LOW);   // Turn off LED 1
        Serial.println("LED 1 OFF");
        break;
        
      case 0xFF30CF: // Code for Button 3
        digitalWrite(led2, HIGH);  // Turn on LED 2
        Serial.println("LED 2 ON");
        break;
        
      case 0xFF40BF: // Code for Button 4
        digitalWrite(led2, LOW);   // Turn off LED 2
        Serial.println("LED 2 OFF");
        break;
        
      default:
        Serial.println("Unknown code received");
    }

    irrecv.resume();  // Receive the next signal
  }
}
