// Display on SSD
// connected at PORTA
// Table of values, or look up table (LUT) with the BCD codes
//for every digit from 0 to 9. Every bit corresponds to a LED,
//1 means the LED is lit and 0 means it is not giving light.
const unsigned char ssdlut[] = {0b00111111, 0b00000110,
                                0b01011011, 0b01001111, 0b01100110, 0b01101101, 0b01111101,
                                0b00000111, 0b01111111, 0b01101111
                               };
const unsigned char ssdhex[]={0b01110111, 0b01111111, 0b00111001, 0b00111111, 0b01111001, 0b01110001};                        
// the size of the lut
const int lutsize = 10;
const int lutsize_hex = 6;
int cpos = 0; // current position
int cdigit = 0; // first digit from the two
unsigned char outvalue = 0;
unsigned char outvalue2 = 0x80;
int u,z;

long previousTime = millis();
long currentTime;

void setup() {
  // setting port A as output
  DDRA = 0b11111111;
}


void loop() {

  currentTime = millis();
  if( currentTime - previousTime >= 1000 ) 
  {
      
      cpos++;
      previousTime = currentTime;
  }
    
      u=cpos%10;
      z=(cpos/10)%10;
      outvalue = 0;
      PORTA = (ssdlut[u % 10] | outvalue); // we make an OR
      delay(2);
      outvalue2 = 0x80;
      PORTA = (ssdlut[z % 10] | outvalue2); // we make an OR
      delay(2);

  
 // outvalue = cdigit > 0 ? 0x80 : 0;
  // which cathode are we choosing ? (00000000 sau 10000000)
  // the cathode is wired to bit7 from port A, through this
  //operation we are setting bit 7 on
  //logical 1 or
  //0, alternatively, the following bits will be attached
  //through a logical OR operation in the
  //following
  //line of code
 // PORTA = (ssdhex[cpos] | outvalue); // we make an OR
  //between the value from the LUT
  // and the selected cathode
 // cpos++; // we increment the current position
 // if (cpos >= lutsize_hex) { // if we reached the final position
 //   cpos = 0; // we come back at 0
 //   cdigit ^= 1; // if the previus digit was 0 we make it a
    //1 and vice versa
 // }
  // wait 0.5 sec
  //delay(20);
}
