int latchPin = 4;
int clockPin =7;
int dataPin = 8; // SSD pins
const unsigned char ssdlut[] = {0b00111111, 0b00000110,
0b01011011, 0b01001111, 0b01100110, 0b01101101, 0b01111101,
0b00000111, 0b01111111, 0b01101111};
// 1011011 -2
// deci invers 0100100 
const unsigned char anodelut[] = {0b00000001, 0b00000010,
0b00000100, 0b00001000};
const unsigned char digits[] = {4,3,2,8}; // The number to be
//displayed is 1234. You can change it.
int number=1234;
int copy;
int b1;
int interval=1000;
int p;
void setup ()
{

pinMode(A2, INPUT_PULLUP);
 pinMode(latchPin,OUTPUT);
 pinMode(clockPin,OUTPUT);
 pinMode(dataPin,OUTPUT); // The three pins connected to
 // the shift register must be output pins
 Serial.begin(9600);
}

void loop()
{
  
   p=1000;
  b1 = digitalRead(A2);
  if(b1==LOW && value!=counter)
   {
    number=number+1;
   }
  
 for(int i=0; i<=3; i++) // For each of the 4 digits
 {
  copy=number;
  unsigned char digit;
    copy=copy/p;
  if(i==0)
  {
    digit=copy;
  }
  else
 {digit=copy%10;}
 // the current digit 
  p=p/10;
 unsigned char cathodes = ~ssdlut[digit]; // The
 //cathodes of the current digit, we’ll
 //negate the value from the original LUT

 digitalWrite(latchPin,LOW); // Activate the latch to
 //allow writing
 shiftOut(dataPin,clockPin,MSBFIRST,cathodes); //
 //shift out the cathode byte
 shiftOut(dataPin,clockPin,MSBFIRST, anodelut[i]);
 // shift out the anode byte
 digitalWrite(latchPin,HIGH); // De-activate the latch
 //signal
 delay(5); // Short wait
 }

}


/*int latchPin = 4;
int clockPin = 7;
int dataPin = 8; // SSD pins

const unsigned char ssdlut[] = {0b00111111, 0b00000110,
                                0b01011011, 0b01001111, 0b01100110, 0b01101101, 0b01111101,
                                0b00000111, 0b01111111, 0b01101111
                               };
const unsigned char anodelut[] = {0b00000001, 0b00000010,
                                  0b00000100, 0b00001000
                                 };

int number = 99;
int digits[4];


unsigned long previousMillis = 0;        // will store last time LED was updated

const long interval = 1000;           // interval at which to blink (milliseconds)
const int buttonPinInc = A1;
const int buttonPinDec = A2;
const int soundPin = 3;
int lastDigitalValInc = 1;
int lastDigitalValDec = 1;

void setup ()
{

  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT); // The three pins connected to
  // the shift register must be output pins
  pinMode(buttonPinInc, INPUT_PULLUP);
  pinMode(buttonPinDec, INPUT_PULLUP);

  pinMode(soundPin, OUTPUT);

}
void loop()
{
  
   unsigned long currentMillis = millis();

   if(currentMillis - previousMillis >= interval) {

     previousMillis = currentMillis;
     number++;
   }
  
  //digitalWrite(soundPin, 1);
  int digitalValInc = digitalRead(buttonPinInc);
  int digitalValDec = digitalRead(buttonPinDec);

  if (LOW == digitalValInc && (digitalValInc != lastDigitalValInc))
  {
    number++;
    //digitalWrite(soundPin, 0);

  }

  lastDigitalValInc = digitalValInc;


  if (LOW == digitalValDec && (digitalValDec != lastDigitalValDec))
  {
    number--;
    //digitalWrite(soundPin, 0);

  }

  lastDigitalValDec = digitalValDec;


  digits[0] = number / 1000;
  digits[1] = number / 100 % 10;
  digits[2] = number / 10 % 10;
  digits[3] = number % 10;

  for (char i = 0; i <= 3; i++) // For each of the 4 digits
  {

    unsigned char digit = digits[i];
    unsigned char cathodes = ~ssdlut[digit]; // The
    //cathodes of the current digit, we’ll
    //negate the value from the original LUT

    digitalWrite(latchPin, LOW); // Activate the latch to
    //allow writing
    shiftOut(dataPin, clockPin, MSBFIRST, cathodes); //
    //shift out the cathode byte
    shiftOut(dataPin, clockPin, MSBFIRST, anodelut [i] );
    // shift out the anode byte
    digitalWrite(latchPin, HIGH); // De-activate the latch
    //signal
    delay(2); // Short wait

  }

}*/
