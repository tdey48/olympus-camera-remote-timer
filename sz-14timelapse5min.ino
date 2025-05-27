const int HALF_PRESS_PIN = 2;  // 半押し（PC817 #1）
const int FULL_PRESS_PIN = 3;  // 全押し（PC817 #2）

void setup() {
  pinMode(HALF_PRESS_PIN, OUTPUT);
  pinMode(FULL_PRESS_PIN, OUTPUT);
  digitalWrite(HALF_PRESS_PIN, LOW);
  digitalWrite(FULL_PRESS_PIN, LOW);
}

void loop() {
  // 初回を0秒とした5分スケジュール

  delay(150000);       // +2分30秒
  halfPress(1000);     // 半押し1秒（省エネ防止）

  delay(149000);       // +2分29秒 → 計4分59秒
  halfPress(1000);     // 半押し1秒（省エネ防止）

  delay(1000);         // +1秒 → 計5分
  fullPress(1000);     // シャッター（半押し+全押し）

  // 再度ループ（次の5分周期へ）
}

void halfPress(unsigned long duration_ms) {
  digitalWrite(HALF_PRESS_PIN, HIGH);
  delay(duration_ms);
  digitalWrite(HALF_PRESS_PIN, LOW);
}

void fullPress(unsigned long duration_ms) {
  digitalWrite(HALF_PRESS_PIN, HIGH);
  digitalWrite(FULL_PRESS_PIN, HIGH);
  delay(duration_ms);
  digitalWrite(FULL_PRESS_PIN, LOW);
  digitalWrite(HALF_PRESS_PIN, LOW);
}
