unsigned long frame;
unsigned long lastPulse;
unsigned long waiting;


void SpeedCheck();


void setup() {
  // put your setup code here, to run once:
pinMode(3, INPUT);
attachInterrupt(3, SpeedCheck, RISING);
Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  //Speed = 0.00002301/(frame/1000000.0);
  if (waiting < millis()){
      noInterrupts();
      Serial.println(frame);
      waiting = millis() + 50;
      interrupts();
  }
}

void SpeedCheck(){
  frame = micros() - lastPulse;
  lastPulse = micros();
}
