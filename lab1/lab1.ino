void setup() {
  // put your setup code here, to run once:
  pinMode(4, INPUT_PULLUP);
  DDRA = 0b11111111;
}

void loop() {
  // put your main code here, to run repeatedly:
  b1 = digitalRead(4);

  for (int i = 0; i < 6 ; i++)
  {
    stat = b1 << i;
    PORTA = stat;
    delay(150);
  }
}

