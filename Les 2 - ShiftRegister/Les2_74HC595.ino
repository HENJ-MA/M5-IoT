uint8_t SER = 4, LATCH = 2, CLOCK = 3;
uint8_t val = 0x01;

String myName = "Bananen";

void setup() {
  // put your setup code here, to run once:
  pinMode(SER, OUTPUT);
  pinMode(LATCH, OUTPUT);
  pinMode(CLOCK, OUTPUT);

  digitalWrite(LATCH, LOW);
  digitalWrite(CLOCK, LOW);
  Serial.begin(115200);
}

void loop() {
  DisplayString(myName);
}

void DisplayString(String str) {
  for(uint8_t i = 0; i < str.length(); ++i) {
    Serial.println(str[i]);
    ShiftOutLSBF(str[i]);
    delay(1000);
    ShiftOutLSBF(0);
    delay(200);
  }
}

void ShiftOutMSBF(uint8_t data) {
  digitalWrite(LATCH, LOW);
  for(uint8_t i = 0; i < 8; ++i) {
    digitalWrite(SER, (data >> (7-i)) & 0b1);
    digitalWrite(CLOCK, HIGH);
    digitalWrite(CLOCK, LOW);
  }
  digitalWrite(LATCH, HIGH);
}

void ShiftOutLSBF(uint8_t data) {
  digitalWrite(LATCH, LOW);
  for(uint8_t i = 0; i < 8; ++i) {
    digitalWrite(SER, (data >> i) & 0b1);
    digitalWrite(CLOCK, HIGH);
    digitalWrite(CLOCK, LOW);
  }
  digitalWrite(LATCH, HIGH);
}
