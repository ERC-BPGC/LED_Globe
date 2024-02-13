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
if(f){
arr_red[0]=0x80;
rgb_clm();
delay(50);
arr_red[0]=0x40;
rgb_clm();
delay(50);
arr_red[0]=0x20;
rgb_clm();
delay(50);
arr_red[0]=0x10;
rgb_clm();
delay(50);
arr_red[0]=0x8;
rgb_clm();
delay(50);
arr_red[0]=0x4;
rgb_clm();
delay(50);
arr_red[0]=0x2;
rgb_clm();
delay(50);
arr_red[0]=0x1;
rgb_clm();
delay(50);
arr_red[1]=0x80;
rgb_clm();
delay(50);
arr_red[1]=0x40;
rgb_clm();
delay(50);
arr_red[1]=0x20;
rgb_clm();
delay(50);
arr_red[1]=0x10;
rgb_clm();
delay(50);
arr_red[1]=0x8;
rgb_clm();
delay(50);
arr_red[1]=0x4;
rgb_clm();
delay(50);
arr_red[1]=0x2;
rgb_clm();
delay(50);
arr_red[1]=0x1;
rgb_clm();
delay(50);
arr_red[2]=0x80;
rgb_clm();
delay(50);
arr_red[2]=0x40;
rgb_clm();
delay(50);
arr_red[2]=0x20;
rgb_clm();
delay(50);
arr_red[2]=0x10;
rgb_clm();
delay(50);
arr_red[2]=0x8;
rgb_clm();
delay(50);
arr_red[2]=0x4;
rgb_clm();
delay(50);
arr_red[2]=0x2;
rgb_clm();
delay(50);
arr_red[2]=0x1;
rgb_clm();
delay(50);
arr_red[3]=0x80;
rgb_clm();
delay(50);
arr_red[3]=0x40;
rgb_clm();
delay(50);
arr_red[3]=0x20;
rgb_clm();
delay(50);
arr_red[3]=0x10;
rgb_clm();
delay(50);
arr_red[3]=0x8;
rgb_clm();
delay(50);
arr_red[3]=0x4;
rgb_clm();
delay(50);
arr_red[3]=0x2;
rgb_clm();
delay(50);
arr_red[3]=0x1;
rgb_clm();
delay(50);
arr_red[4]=0x80;
rgb_clm();
delay(50);
arr_red[4]=0x40;
rgb_clm();
delay(50);
arr_red[4]=0x20;
rgb_clm();
delay(50);
arr_red[4]=0x10;
rgb_clm();
delay(50);
arr_red[4]=0x8;
rgb_clm();
delay(50);
arr_red[4]=0x4;
rgb_clm();
delay(50);
arr_red[4]=0x2;
rgb_clm();
delay(50);
arr_red[4]=0x1;
rgb_clm();
delay(50);
arr_red[5]=0x80;
rgb_clm();
delay(50);
arr_red[5]=0x40;
rgb_clm();
delay(50);
arr_red[5]=0x20;
rgb_clm();
delay(50);
arr_red[5]=0x10;
rgb_clm();
delay(50);
arr_red[5]=0x8;
rgb_clm();
delay(50);
arr_red[5]=0x4;
rgb_clm();
delay(50);
arr_red[5]=0x2;
rgb_clm();
delay(50);
arr_red[5]=0x1;
rgb_clm();
delay(50);
arr_red[6]=0x80;
rgb_clm();
delay(50);
arr_red[6]=0x40;
rgb_clm();
delay(50);
arr_red[6]=0x20;
rgb_clm();
delay(50);
arr_red[6]=0x10;
rgb_clm();
delay(50);
arr_red[6]=0x8;
rgb_clm();
delay(50);
arr_red[6]=0x4;
rgb_clm();
delay(50);
arr_red[6]=0x2;
rgb_clm();
delay(50);
arr_red[6]=0x1;
rgb_clm();
delay(50);
arr_red[7]=0x80;
rgb_clm();
delay(50);
arr_red[7]=0x40;
rgb_clm();
delay(50);
arr_red[7]=0x20;
rgb_clm();
delay(50);
arr_red[7]=0x10;
rgb_clm();
delay(50);
arr_red[7]=0x8;
rgb_clm();
delay(50);
arr_red[7]=0x4;
rgb_clm();
delay(50);
arr_red[7]=0x2;
rgb_clm();
delay(50);
arr_red[7]=0x1;
rgb_clm();
delay(50);
arr_red[8]=0x80;
rgb_clm();
delay(50);
arr_red[8]=0x40;
rgb_clm();
delay(50);
arr_red[8]=0x20;
rgb_clm();
delay(50);
arr_red[8]=0x10;
rgb_clm();
delay(50);
arr_red[8]=0x8;
rgb_clm();
delay(50);
arr_red[8]=0x4;
rgb_clm();
delay(50);
arr_red[8]=0x2;
rgb_clm();
delay(50);
arr_red[8]=0x1;
rgb_clm();
delay(50);
arr_red[9]=0x80;
rgb_clm();
delay(50);
arr_red[9]=0x40;
rgb_clm();
delay(50);
arr_red[9]=0x20;
rgb_clm();
delay(50);
arr_red[9]=0x10;
rgb_clm();
delay(50);
arr_red[9]=0x8;
rgb_clm();
delay(50);
arr_red[9]=0x4;
rgb_clm();
delay(50);
arr_red[9]=0x2;
rgb_clm();
delay(50);
arr_red[9]=0x1;
rgb_clm();
delay(50);
arr_red[10]=0x80;
rgb_clm();
delay(50);
arr_red[10]=0x40;
rgb_clm();
delay(50);
arr_red[10]=0x20;
rgb_clm();
delay(50);
arr_red[10]=0x10;
rgb_clm();
delay(50);
arr_red[10]=0x8;
rgb_clm();
delay(50);
arr_red[10]=0x4;
rgb_clm();
delay(50);
arr_red[10]=0x2;
rgb_clm();
delay(50);
arr_red[10]=0x1;
rgb_clm();
delay(50);
arr_red[11]=0x80;
rgb_clm();
delay(50);
arr_red[11]=0x40;
rgb_clm();
delay(50);
arr_red[11]=0x20;
rgb_clm();
delay(50);
arr_red[11]=0x10;
rgb_clm();
delay(50);
arr_red[11]=0x8;
rgb_clm();
delay(50);
arr_red[11]=0x4;
rgb_clm();
delay(50);
arr_red[11]=0x2;
rgb_clm();
delay(50);
arr_red[11]=0x1;
rgb_clm();
delay(50);
arr_red[12]=0x80;
rgb_clm();
delay(50);
arr_red[12]=0x40;
rgb_clm();
delay(50);
arr_red[12]=0x20;
rgb_clm();
delay(50);
arr_red[12]=0x10;
rgb_clm();
delay(50);
arr_red[12]=0x8;
rgb_clm();
delay(50);
arr_red[12]=0x4;
rgb_clm();
delay(50);
arr_red[12]=0x2;
rgb_clm();
delay(50);
arr_red[12]=0x1;
rgb_clm();
delay(50);
arr_red[13]=0x80;
rgb_clm();
delay(50);
arr_red[13]=0x40;
rgb_clm();
delay(50);
arr_red[13]=0x20;
rgb_clm();
delay(50);
arr_red[13]=0x10;
rgb_clm();
delay(50);
arr_red[13]=0x8;
rgb_clm();
delay(50);
arr_red[13]=0x4;
rgb_clm();
delay(50);
arr_red[13]=0x2;
rgb_clm();
delay(50);
arr_red[13]=0x1;
rgb_clm();
delay(50);




f != f;
}



/*
  rgb_clm();
  delay(500);
  arr_red[0] = 0x00; arr_red[1] = 0x55; arr_red[2] = 0xaa;
  arr_green[0] = 0xaa; arr_green[1] = 0x00; arr_green[2] = 0x55;
  arr_blue[0] = 0x55; arr_blue[1] = 0xaa; arr_blue[2] = 0x00;
  rgb_clm();
  delay(500);
  arr_red[0] = 0xaa; arr_red[1] = 0x00; arr_red[2] = 0x55;
  arr_green[0] = 0x55; arr_green[1] = 0xaa; arr_green[2] = 0x00;
  arr_blue[0] = 0x00; arr_blue[1] = 0x55; arr_blue[2] = 0xaa;
  rgb_clm();
  delay(500);*/

}