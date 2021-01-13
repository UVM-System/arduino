int  val;
const int delay_time = 50;

void setup() {
  // put your setup code here, to run once:
  for (int i = 2; i <= 13; i++) {
    init_pin(i);
  }
  Serial.begin(9600);
}

void loop() {
  val = Serial.read();
  if (val >= 'm' && val <= 'x') {
    press_pin(val - 'm', 1);
  }

}
void press_pin(int pin_num, int count) {
  for (int i = 0; i < count; i++) {
    digitalWrite(pin_num, LOW);
    delay(delay_time);
    digitalWrite(pin_num, HIGH);
    delay(delay_time);
  }
}
void init_pin(int pin_num) {
  pinMode(pin_num, OUTPUT);
  digitalWrite(pin_num, HIGH);
}
