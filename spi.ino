#include <SPI.h>

const int latchPin1 = 8;
const int latchPin2 = 9;
const int dataPin1 = 11;
const int dataPin2 = 10;
const int dataPin3 = 13;
int i;

byte blue1 = 0xFF;
byte green1 = 0x00;
byte blue2 = 0x00;
byte green2 = 0xFF;
byte red = 0xFF;

void setup() {
  SPI.begin();
  pinMode(latchPin1, OUTPUT);
  pinMode(latchPin2, OUTPUT);
}

void loop() {
  setRed(red);
  delay(10);
  setBlue(blue1, green1);
  delay(10);
  setGreen(green2, blue2);
  delay(10);
}

void setRed(byte red) {
  digitalWrite(latchPin2, LOW);
  for (i = 0; i < 14; i++){
    SPI.transfer(0x00); // Green
    SPI.transfer(0x00); // Blue
  }
  digitalWrite(latchPin2, HIGH);

  digitalWrite(latchPin1, LOW);
  for (i = 0; i < 14; i++){
    SPI.transfer(red); // Red
  }
  digitalWrite(latchPin1, HIGH);
}

void setBlue(byte blue, byte green) {
  digitalWrite(latchPin1, LOW);
  for (i = 0; i < 14; i++){
    SPI.transfer(0x00); // Red
   }
  digitalWrite(latchPin1, HIGH);

  digitalWrite(latchPin2, LOW);
  for (i = 0; i < 14; i++){
    SPI.transfer(blue); // Blue
    SPI.transfer(green); // Green
  }
  digitalWrite(latchPin2, HIGH);
}

void setGreen(byte green, byte blue) {
  digitalWrite(latchPin1, LOW);
  for (i = 0; i < 14; i++){
    SPI.transfer(0x00); // Red
  }
  digitalWrite(latchPin1, HIGH);

  digitalWrite(latchPin2, LOW);
  for (i = 0; i < 14; i++){
    SPI.transfer(blue); // Blue
    SPI.transfer(green); // Green
  }
  digitalWrite(latchPin2, HIGH);
}
