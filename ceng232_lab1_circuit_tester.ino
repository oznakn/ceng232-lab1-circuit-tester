#define A0_PIN 2
#define A1_PIN 3
#define B0_PIN 4
#define B1_PIN 5

#define X_PIN 9
#define Y_PIN 10
#define Z_PIN 11

#define LED_PIN 13

void set_pin(int n, int pin0, int pin1) {
  switch (n) {
    case 0: {
      digitalWrite(pin1, LOW);
      digitalWrite(pin0, LOW);
      break;
    }

    case 1: {
      digitalWrite(pin1, LOW);
      digitalWrite(pin0, HIGH);
      break;
    }

    case 2: {
      digitalWrite(pin1, HIGH);
      digitalWrite(pin0, LOW);
      break;
    }

    case 3: {
      digitalWrite(pin1, HIGH);
      digitalWrite(pin0, HIGH);
      break;
    }

    default: {
      digitalWrite(pin1, LOW);
      digitalWrite(pin0, LOW);
    }
  }
}

void set_pins(int a, int b) {
  set_pin(a, A0_PIN, A1_PIN);
  set_pin(b, B0_PIN, B1_PIN);
}

void blink() {
  while(true) {
    digitalWrite(LED_PIN, HIGH);
    delay(300);
    digitalWrite(LED_PIN, LOW);
    delay(300);
  }
}

void check(int a, int b, char c, int pin, int value) {
  if (digitalRead(pin) != value) {
    Serial.print(c);
    Serial.print(" pin is not ");
    Serial.print(value);
    Serial.print(" for ");
    Serial.print(a);
    Serial.print(", ");
    Serial.println(b);
    blink();
  }
}

void test() {
  for (int a = 0; a < 4; a++) {
    for (int b = 0; b < 4; b++) {
      set_pins(a, b);

      if (a + b > 2) {
        check(a, b, 'x', X_PIN, 1);
      } else {
        check(a, b, 'x', X_PIN, 0);
      }

      if ((b == 0 && a == 1) || (b != 0 && (a+b) % b == 1)) {
        check(a, b, 'y', Y_PIN, 1);
      } else {
        check(a, b, 'y', Y_PIN, 0);
      }

      if ((a << b) > (b << a)) {
        check(a, b, 'z', Z_PIN, 1);
      } else {
        check(a, b, 'z', Z_PIN, 0);
      }
      
      delay(10); 
    }
  }
  
  digitalWrite(LED_PIN, HIGH);
}

void setup() {
  Serial.begin(9600);
  
  pinMode(A0_PIN, OUTPUT);
  pinMode(A1_PIN, OUTPUT);
  pinMode(B0_PIN, OUTPUT);
  pinMode(B1_PIN, OUTPUT);
  
  pinMode(X_PIN, INPUT);
  pinMode(Y_PIN, INPUT);
  pinMode(Z_PIN, INPUT);

  pinMode(LED_PIN, OUTPUT);

  digitalWrite(A0_PIN, LOW);
  digitalWrite(A1_PIN, LOW);
  digitalWrite(B0_PIN, LOW);
  digitalWrite(B1_PIN, LOW);
  digitalWrite(LED_PIN, LOW);

  test();
}


void loop() {

}
