#include <TM1637Display.h>

// TM1637
#define CLK  D8
#define DIO  D7
TM1637Display tm1637(CLK, DIO);

// Cụm 1
#define RED1     D1
#define YELLOW1  D2
#define GREEN1   D3
// Cụm 2
#define RED2     D4
#define YELLOW2  D5
#define GREEN2   D6

// Chân cảm biến IR
#define IR_PIN   D0  // Chân D0 cho cảm biến IR

void setup() {
  tm1637.setBrightness(7);

  pinMode(RED1, OUTPUT);
  pinMode(YELLOW1, OUTPUT);
  pinMode(GREEN1, OUTPUT);
  pinMode(RED2, OUTPUT);
  pinMode(YELLOW2, OUTPUT);
  pinMode(GREEN2, OUTPUT);

  pinMode(IR_PIN, INPUT);  // Chân IR là đầu vào

  // Tắt tất cả đèn
  allLightsOff();
}

void loop() {
  // ===== Pha 1: Cụm 1 Xanh – Cụm 2 Đỏ =====
  digitalWrite(RED1, LOW);
  digitalWrite(GREEN1, HIGH);
  digitalWrite(YELLOW1, LOW);

  digitalWrite(RED2, HIGH);
  digitalWrite(YELLOW2, LOW);
  digitalWrite(GREEN2, LOW);

  int irState = digitalRead(IR_PIN);  // Đọc tín hiệu từ cảm biến IR

  if (irState == HIGH) {
    countdown(10);  // Nếu có xe (cảm biến IR nhận tín hiệu), đếm ngược 10 giây
  } else {
    countdown(5);  // Nếu không có xe, đếm ngược 5 giây
  }

  // ===== Pha 2: Cụm 1 Vàng – Cụm 2 Đỏ =====
  digitalWrite(GREEN1, LOW);
  digitalWrite(YELLOW1, HIGH);

  countdown(3); // Đếm ngược 3 giây

  // ===== Pha 3: Cụm 1 Đỏ – Cụm 2 Xanh =====
  digitalWrite(YELLOW1, LOW);
  digitalWrite(RED1, HIGH);

  digitalWrite(RED2, LOW);
  digitalWrite(GREEN2, HIGH);

  irState = digitalRead(IR_PIN);  // Đọc lại tín hiệu IR

  if (irState == HIGH) {
    countdown(10);  // Nếu có xe, đếm ngược 10 giây
  } else {
    countdown(5);  // Nếu không có xe, đếm ngược 5 giây
  }

  // ===== Pha 4: Cụm 1 Đỏ – Cụm 2 Vàng =====
  digitalWrite(GREEN2, LOW);
  digitalWrite(YELLOW2, HIGH);

  countdown(3); // Đếm ngược 3 giây

  digitalWrite(YELLOW2, LOW);
  digitalWrite(RED2, HIGH);
}

void countdown(int seconds) {
  for (int i = seconds; i >= 0; i--) {
    tm1637.showNumberDec(i, false); // Hiển thị số đếm ngược trên TM1637
    delay(1000); // Đợi 1 giây
  }
}

void allLightsOff() {
  digitalWrite(RED1, LOW);
  digitalWrite(YELLOW1, LOW);
  digitalWrite(GREEN1, LOW);
  digitalWrite(RED2, LOW);
  digitalWrite(YELLOW2, LOW);
  digitalWrite(GREEN2, LOW);
}
