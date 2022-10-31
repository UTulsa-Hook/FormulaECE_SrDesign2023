void setup() {
  Serial.begin(96000);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
}

int freq = 1000000/1000; // frequency is denominator
int duty = 50;
int analogDuty = duty*255/100;
int A = freq/100*duty;
int B = freq/100*(100-duty);

void loop() {
  if (Serial.available()) {
    String data = Serial.readStringUntil('\n');
    Serial.print("Sent to Arduino: ");
    Serial.println(data);
    duty = data.toInt();
    analogDuty = duty*255/100;
    A = freq/100*duty;
    B = freq/100*(100-duty);
  }
  analogWrite(6, analogDuty);
  if (A == 0) {
    digitalWrite(5, LOW);
    return;
  }
  if (B == 0) {
    digitalWrite(5, HIGH);
    return;
  }
  digitalWrite(5, HIGH);
  delayMicroseconds(A);
  digitalWrite(5, LOW);
  delayMicroseconds(B-10);
}
