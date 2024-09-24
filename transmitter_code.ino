#include <IRremote.h>

const int button1 = 2;
const int button2 = 5;
const int button3 = 6;
const int button4 = 7;
const int irLedPin = 3;

IRsend irsend;

void setup() {
  Serial.begin(9600);
  pinMode(button1, INPUT_PULLUP); // Using internal pull-up resistors
  pinMode(button2, INPUT_PULLUP);
  pinMode(button3, INPUT_PULLUP);
  pinMode(button4, INPUT_PULLUP);
  pinMode(irLedPin, OUTPUT);
}

void loop() {
  if (digitalRead(button1) == LOW) {
    Serial.println("Button_1 Pressed");
    irsend.sendNEC(0xFF10EF, 32); // Send code for Button 1
    delay(500); // Debounce delay
  } 
  else if (digitalRead(button2) == LOW) {
    Serial.println("Button_2 Pressed");
    irsend.sendNEC(0xFF20DF, 32); // Send code for Button 2
    delay(500);
  } 
  else if (digitalRead(button3) == LOW) {
    Serial.println("Button_3 Pressed");
    irsend.sendNEC(0xFF30CF, 32); // Send code for Button 3
    delay(500);
  } 
  else if (digitalRead(button4) == LOW) {
    Serial.println("Button_4 Pressed");
    irsend.sendNEC(0xFF40BF, 32); // Send code for Button 4
    delay(500);
  }
}
