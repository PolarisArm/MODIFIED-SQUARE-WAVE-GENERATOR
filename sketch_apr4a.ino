/*
Modified square wave generator
*/


void setup() {
  // put your setup code here, to run once:
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(A0,INPUT);
  pinMode(11,OUTPUT);
  pinMode(3,OUTPUT);

  TCCR1A = 0;
  TCCR1B = 0;
  TCCR2A = 0;
  TCCR2B = 0;
  TCNT2  = 0;
  TCNT1  = 0;
  // TIMER 1 AND 2 USED IN PHASE CORRECT PWM NON INVERTING MODE
  TCCR1A |= (1 << COM1A1) | (1 << COM1B1) |(1 << COM1A0) |(1 << COM1B0)| (1 << WGM10);
  TCCR1B |= (1 << CS10);
  
  TCCR2A |= (1 << COM2A1) | (1 << COM2B1) |(1 << COM2A0) |(1 << COM2B0)| (1 << WGM20);
  TCCR2B |= (1 << CS20);

  OCR1A = 128;
  OCR1B = 128;
  OCR2A = 128;
  OCR2B = 128;
  sei();
}


void loop() {
  // put your main code here, to run repeatedly:
  int a = map(analogRead(A0),0,1023,10,245);
  // OCR1A = a;
  // OCR1B = a-10;
  // OCR2A = a;
  // OCR2B = a-10;

  OCR1A = a;
  OCR1B = 250-a;
  OCR2A = a;
  OCR2B = 250-a;
}
