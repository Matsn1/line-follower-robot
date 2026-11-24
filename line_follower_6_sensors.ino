// ********** Motor Pins (Updated) **********
#define m1 25  // Right Motor FORWARD
#define m2 26  // Right Motor BACKWARD
#define m3 27  // Left Motor FORWARD
#define m4 14  // Left Motor BACKWARD

// ********** IR Sensor Pins (Based on Your Image) **********
#define ir1 32  // IR Left 1 (Left Most)
#define ir2 33  // IR Left 2 (Left)
#define ir3 15  // IR Left 3 (Center Left)
#define ir4 4   // Center Right
#define ir5 16  // Right
#define ir6 17  // Right Most

void setup() {
  Serial.begin(115200);

  pinMode(m1, OUTPUT); pinMode(m2, OUTPUT);
  pinMode(m3, OUTPUT); pinMode(m4, OUTPUT);

  pinMode(ir1, INPUT); pinMode(ir2, INPUT); pinMode(ir3, INPUT);
  pinMode(ir4, INPUT); pinMode(ir5, INPUT); pinMode(ir6, INPUT);
}

void loop() {
  int s1 = digitalRead(ir1);  // Left Most
  int s2 = digitalRead(ir2);  // Left
  int s3 = digitalRead(ir3);  // Center Left
  int s4 = digitalRead(ir4);  // Center Right
  int s5 = digitalRead(ir5);  // Right
  int s6 = digitalRead(ir6);  // Right Most

  Serial.print(s1); Serial.print(s2); Serial.print(s3);
  Serial.print(s4); Serial.print(s5); Serial.println(s6);

  if (s3 == 0 && s4 == 0 && s2 == 1 && s5 == 1) {
    moveForward();
  }
  else if (s1 == 0) {
    sharpLeft();
  }
  else if (s2 == 0) {
    turnLeft();
  }
  else if (s5 == 0) {
    turnRight();
  }
  else if (s6 == 0) {
    sharpRight();
  }
  else if (s3 == 0 && s2 == 0) {
    turnLeft();
  }
  else if (s4 == 0 && s5 == 0) {
    turnRight();
  }
  else if (s1 == 1 && s2 == 1 && s3 == 1 && s4 == 1 && s5 == 1 && s6 == 1) {
    stopMotors();
  }
}

// ********** Motor Control Functions **********

void moveForward() {
  digitalWrite(m1, HIGH); digitalWrite(m2, LOW);  // Right forward
  digitalWrite(m3, HIGH); digitalWrite(m4, LOW);  // Left forward
}

void turnLeft() {
  digitalWrite(m1, HIGH); digitalWrite(m2, LOW);
  digitalWrite(m3, LOW); digitalWrite(m4, LOW);
}

void sharpLeft() {
  digitalWrite(m1, HIGH); digitalWrite(m2, LOW);
  digitalWrite(m3, LOW); digitalWrite(m4, HIGH);
}

void turnRight() {
  digitalWrite(m1, LOW); digitalWrite(m2, LOW);
  digitalWrite(m3, HIGH); digitalWrite(m4, LOW);
}

void sharpRight() {
  digitalWrite(m1, LOW); digitalWrite(m2, HIGH);
  digitalWrite(m3, HIGH); digitalWrite(m4, LOW);
}

void stopMotors() {
  digitalWrite(m1, LOW); digitalWrite(m2, LOW);
  digitalWrite(m3, LOW); digitalWrite(m4, LOW);
}   also this was a line following car i made before in a small competition i dont know if it is useful