const int latchPin1 = 8;  
const int latchPin2 = 9;
const int clockPin = 12;  
const int dataPin1 = 11;  
const int dataPin2 = 10;
const int dataPin3 = 13; 

byte blue1 = 0xFF;
byte green1 = 0x00;
byte blue2 = 0x00;
byte green2 = 0xFF;
byte red = 0xFF;

void setup() {
  pinMode(latchPin1, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin1, OUTPUT);
  pinMode(latchPin2,OUTPUT);
  pinMode(dataPin2, OUTPUT);
  pinMode(dataPin3,OUTPUT);
  
  Serial.begin(9600);
}

void loop() {

  //setred(red);
  //delay(1000);
  setblue(blue1,green1);
  delay(1000);
  //setgreen(green2,blue2);
  //delay(1000);

}

void setred(int red) {

  byte blue = 0x00;
  byte green = 0x00;
  
  digitalWrite(latchPin2, LOW);
  shiftOut(dataPin2, clockPin, MSBFIRST, green);
  shiftOut(dataPin3, clockPin, MSBFIRST, blue);
  delay(100);
  digitalWrite(latchPin2, HIGH);

  digitalWrite(latchPin1, LOW);
  shiftOut(dataPin1, clockPin, MSBFIRST, red);
  delay(100);
  digitalWrite(latchPin1, HIGH);
}



void setblue(byte blue, byte green) {
  byte red = 0x00;
  digitalWrite(latchPin1, LOW);
  shiftOut(dataPin1, clockPin, MSBFIRST, red);
  delay(100);
  digitalWrite(latchPin1, HIGH);
	
  digitalWrite(latchPin2, LOW);
  shiftOut(dataPin2, clockPin, MSBFIRST, blue);
  shiftOut(dataPin3, clockPin, MSBFIRST, green);
  
  delay(100);
  digitalWrite(latchPin2, HIGH);

}


void setgreen(byte green, byte blue) {
  byte red = 0x00;
  digitalWrite(latchPin1, LOW);
  shiftOut(dataPin1, clockPin, MSBFIRST, red);
  delay(100);
  
  digitalWrite(latchPin1, HIGH);
  digitalWrite(latchPin2, LOW);
  shiftOut(dataPin2, clockPin, MSBFIRST, blue);
  shiftOut(dataPin3, clockPin, MSBFIRST, green);
  delay(100);
  digitalWrite(latchPin2, HIGH);
}







