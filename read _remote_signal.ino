#include <IRremote.h>

const int irReceiverPin = 9;
IRrecv irrecv(irReceiverPin);
decode_results results;

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();  // Start the receiver
}

void loop() {
  if (irrecv.decode(&results)) {
    // Print the received value in hexadecimal
    Serial.print("Received value: 0x");
    Serial.println(results.value, HEX);
    
    irrecv.resume(); // Ready to receive the next signal
  }
}

