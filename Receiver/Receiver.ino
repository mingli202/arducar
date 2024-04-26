#include <Arduino.h>
#include <SoftwareSerial.h>

// for bluetooth
const int rx = A1; // connected to TXD
const int tx = A2; // connected to RXD
SoftwareSerial bt(rx, tx);

void forward();
void backward();
void left();
void right();
void stop();

class Motor {
private:
  int input1;
  int input2;
  int engine;

public:
  Motor(int in1, int in2, int en) {
    input1 = in1;
    input2 = in2;
    engine = en;
  }

  void forward() {
    digitalWrite(input1, LOW);
    digitalWrite(input2, HIGH);
    analogWrite(engine, 255);
  }

  void backward() {
    digitalWrite(input1, HIGH);
    digitalWrite(input2, LOW);
    analogWrite(engine, 255);
  }

  void stop() { analogWrite(engine, 0); }

  void setup() {
    pinMode(input1, OUTPUT);
    pinMode(input2, OUTPUT);
    pinMode(engine, OUTPUT);
  }
};

// (in1, in2, en)
Motor left1(7, 5, 6);
Motor left2(4, 2, 3);
Motor right1(10, 8, 9);
Motor right2(13, 11, 12);

void setup() {
  left1.setup();
  left2.setup();
  right1.setup();
  right2.setup();

  bt.begin(9600);
}

void loop() {

  // Read from the Bluetooth module and send to the Arduino Serial Monitor
  if (bt.available() || false) {
    int state = bt.read();
    // 48 is the ascii code for "0" forward
    // 49 is the ascii code for "1" backward
    // 50 is the ascii code for "2" left
    // 51 is the ascii code for "3" right
    // 52 is the ascii code for "4" stop

    // switch statement for every movement received
    switch (state) {
    case 48:
      forward();
      break;
    case 49:
      backward();
      break;
    case 50:
      left();
      break;
    case 51:
      right();
      break;
    case 52:
      stop();
      break;
    }
  }
}

void forward() {
  left1.forward();
  left2.forward();
  right1.forward();
  right2.forward();
}

void backward() {
  left1.backward();
  left2.backward();
  right1.backward();
  right2.backward();
}

void left() {
  left1.backward();
  left2.backward();
  right1.forward();
  right2.forward();
}

void right() {
  left1.forward();
  left2.forward();
  right1.backward();
  right2.backward();
}

void stop() {
  left1.stop();
  left2.stop();
  right1.stop();
  right2.stop();
}
