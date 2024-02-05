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
arr_red[0] = 0x55; 
arr_red[1] = 0x55;
arr_red[2] = 0x55;
arr_red[3] = 0x55;
arr_red[4] = 0x55;
arr_red[5] = 0x55;
arr_red[6] = 0x55;
arr_red[7] = 0x55;
arr_red[8] = 0x55;
arr_red[9] = 0x55;
arr_red[10] = 0x55;
arr_red[11] = 0x55;
arr_red[12] = 0x55;
arr_red[13] = 0x55;




arr_blue[0] = 0xaa;
arr_blue[1] = 0xaa;
arr_blue[2] = 0xaa;
arr_blue[3] = 0xaa;
arr_blue[4] = 0xaa;
arr_blue[5] = 0xaa;
arr_blue[6] = 0xaa;
arr_blue[7] = 0xaa;
arr_blue[8] = 0xaa;
arr_blue[9] = 0xaa;
arr_blue[10] = 0xaa;
arr_blue[11] = 0xaa;
arr_blue[12] = 0xaa;
arr_blue[13] = 0xaa;



arr_green[0] = 0x00;
arr_green[1] = 0x00;
arr_green[2] = 0x00;
arr_green[3] = 0x00;
arr_green[4] = 0x00;
arr_green[5] = 0x00;
arr_green[6] = 0x00;
arr_green[7] = 0x00;
arr_green[8] = 0x00;
arr_green[9] = 0x00;
arr_green[10] = 0x00;
arr_green[11] = 0x00;
arr_green[12] = 0x00;
arr_green[13] = 0x00;
rgb_clm();

delay(500);

arr_red[0] = 0x00; 
arr_red[1] = 0x00;
arr_red[2] = 0x00;
arr_red[3] = 0x00;
arr_red[4] = 0x00;
arr_red[5] = 0x00;
arr_red[6] = 0x00;
arr_red[7] = 0x00;
arr_red[8] = 0x00;
arr_red[9] = 0x00;
arr_red[10] = 0x00;
arr_red[11] = 0x00;
arr_red[12] = 0x00;
arr_red[13] = 0x00;




arr_blue[0] = 0x55;
arr_blue[1] = 0x55;
arr_blue[2] = 0x55;
arr_blue[3] = 0x55;
arr_blue[4] = 0x55;
arr_blue[5] = 0x55;
arr_blue[6] = 0x55;
arr_blue[7] = 0x55;
arr_blue[8] = 0x55;
arr_blue[9] = 0x55;
arr_blue[10] = 0x55;
arr_blue[11] = 0x55;
arr_blue[12] = 0x55;
arr_blue[13] = 0x55;





arr_green[0] = 0xaa;
arr_green[1] = 0xaa;
arr_green[2] = 0xaa;
arr_green[3] = 0xaa;
arr_green[4] = 0xaa;
arr_green[5] = 0xaa;
arr_green[6] = 0xaa;
arr_green[7] = 0xaa;
arr_green[8] = 0xaa;
arr_green[9] = 0xaa;
arr_green[10] = 0xaa;
arr_green[11] = 0xaa;
arr_green[12] = 0xaa;
arr_green[13] = 0xaa;


rgb_clm();

delay(500);

arr_red[0] = 0xaa; 
arr_red[1] = 0xaa;
arr_red[2] = 0xaa;
arr_red[3] = 0xaa;
arr_red[4] = 0xaa;
arr_red[5] = 0xaa;
arr_red[6] = 0xaa;
arr_red[7] = 0xaa;
arr_red[8] = 0xaa;
arr_red[9] = 0xaa;
arr_red[10] = 0xaa;
arr_red[11] = 0xaa;
arr_red[12] = 0xaa;
arr_red[13] = 0xaa;






arr_blue[0] = 0x00;
arr_blue[1] = 0x00;
arr_blue[2] = 0x00;
arr_blue[3] = 0x00;
arr_blue[4] = 0x00;
arr_blue[5] = 0x00;
arr_blue[6] = 0x00;
arr_blue[7] = 0x00;
arr_blue[8] = 0x00;
arr_blue[9] = 0x00;
arr_blue[10] = 0x00;
arr_blue[11] = 0x00;
arr_blue[12] = 0x00;
arr_blue[13] = 0x00;





arr_green[0] = 0x55;
arr_green[1] = 0x55;
arr_green[2] = 0x55;
arr_green[3] = 0x55;
arr_green[4] = 0x55;
arr_green[5] = 0x55;
arr_green[6] = 0x55;
arr_green[7] = 0x55;
arr_green[8] = 0x55;
arr_green[9] = 0x55;
arr_green[10] = 0x55;
arr_green[11] = 0x55;
arr_green[12] = 0x55;
arr_green[13] = 0x55;
rgb_clm();
delay(500);
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
