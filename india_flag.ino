const int latchPin1 = 8;  	//red latch
const int latchPin2 = 9;	//blue green latch
const int clockPin = 12;  
const int dataPin1 = 11;  //red blue
const int dataPin2 = 13;  //green
const int dataPin3 = 10;  //blue(not connected) 
int f = 1;

byte arr_red[14] = {0x00, 0x00, 0x00};
byte arr_green[14] = {0x00, 0x00, 0x00};  //0x00, 0x00, 0x00
byte arr_blue[14] = {0x00, 0x00, 0x00};

void shiftOutBG(uint8_t dpb, uint8_t dpg, uint8_t clkp, uint8_t btordr, uint8_t valb, uint8_t valg){
  uint8_t i;

	for (i = 0; i < 8; i++)  {
		if (btordr == LSBFIRST) {
			digitalWrite(dpb, valb & 1);
			valb >>= 1;
		} else {	
			digitalWrite(dpb, (valb & 128) != 0);
			valb <<= 1;
		}
      
      if (btordr == LSBFIRST) {
			digitalWrite(dpg, valg & 1);
			valg >>= 1;
		} else {	
			digitalWrite(dpg, (valg & 128) != 0);
			valg <<= 1;
		}
			
		digitalWrite(clockPin, HIGH);
		digitalWrite(clockPin, LOW);		
	}
}


void rgb_clm(){

  digitalWrite(latchPin2, LOW);
  for(int i=0; i<14; i++){
  shiftOutBG(dataPin1, dataPin2, clockPin, MSBFIRST, arr_blue[i], arr_green[i]);
  }
  digitalWrite(latchPin2, HIGH);


  digitalWrite(latchPin1, LOW);
  for(int k=0; k<14; k++){
  shiftOut(dataPin1, clockPin, MSBFIRST, arr_red[k]);
  }
  digitalWrite(latchPin1, HIGH);
}

void setup() {
  pinMode(latchPin1, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin1, OUTPUT);
  pinMode(latchPin2,OUTPUT);
  pinMode(dataPin2, OUTPUT);
  pinMode(dataPin3,OUTPUT);
}

void loop() {

int i = 0;

if(f){

for (i = 0; i<6; i++){
  arr_red[i] = 0xff;
}

for (i = 0; i<6; i++){
  arr_blue[i] = 0x00;
}

for (i = 0; i<6; i++){
  arr_green[i] = 0x00;
}
rgb_clm();
delay(500);

arr_red[6] = 0xff;
arr_blue[6] = 0xFF;
arr_green[6] = 0xff;
arr_red[7] = 0xc0;
arr_blue[7] = 0xFF;
arr_green[7] = 0xc0;
arr_red[8] = 0x03;
arr_blue[8] = 0xFF;
arr_green[8] = 0x03;
arr_red[9] = 0xff;
arr_blue[9] = 0xff;
arr_green[9] = 0xff;
rgb_clm();
delay(200);

arr_red[6] = 0xff;
arr_blue[6] = 0xFF;
arr_green[6] = 0xff;
arr_red[7] = 0xff;
arr_blue[7] = 0xFF;
arr_green[7] = 0xff;
arr_red[8] = 0xff;
arr_blue[8] = 0xFF;
arr_green[8] = 0xff;
arr_red[9] = 0xff;
arr_blue[9] = 0xff;
arr_green[9] = 0xff;
rgb_clm();
delay(500);

for (i = 10; i<14; i++){
  arr_red[i] = 0x00;
}

for (i = 10; i<14; i++){
  arr_blue[i] = 0x00;
}

for (i = 10; i<14; i++){
  arr_green[i] = 0xff;
}


rgb_clm();

delay(500);

f != f;
}





}
