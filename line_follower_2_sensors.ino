// Sensor pins
const int leftSensorPin = 34;
const int rightSensorPin = 35;

// Motor driver pins
const int rightMotor[2] = {25, 26}; // Right motor IN1, IN2
const int leftMotor[2]  = {27, 14}; // Left motor IN3, IN4

void setup() {
  pinMode(leftSensorPin, INPUT);
  pinMode(rightSensorPin, INPUT);

  pinMode(rightMotor[0], OUTPUT);
  pinMode(rightMotor[1], OUTPUT);
  pinMode(leftMotor[0], OUTPUT);
  pinMode(leftMotor[1], OUTPUT);

  Serial.begin(115200);
}

void loop() {
  bool leftDetected = digitalRead(leftSensorPin) == LOW;   // black = LOW
  bool rightDetected = digitalRead(rightSensorPin) == LOW; // black = LOW

  if (leftDetected && rightDetected) {
    moveForward();
  } else if (leftDetected && !rightDetected) {
    turnRight();  // swapped
  } else if (!leftDetected && rightDetected) {
    turnLeft();   // swapped
  } else {
    stopMotors();
  }
}

// Movement functions
void moveForward() {
  digitalWrite(rightMotor[0], HIGH);
  digitalWrite(rightMotor[1], LOW);
  digitalWrite(leftMotor[0], HIGH);
  digitalWrite(leftMotor[1], LOW);
}

void turnLeft() {
  digitalWrite(rightMotor[0], HIGH);
  digitalWrite(rightMotor[1], LOW);
  digitalWrite(leftMotor[0], LOW);
  digitalWrite(leftMotor[1], HIGH);
}

void turnRight() {
  digitalWrite(rightMotor[0], LOW);
  digitalWrite(rightMotor[1], HIGH);
  digitalWrite(leftMotor[0], HIGH);
  digitalWrite(leftMotor[1], LOW);
}

void stopMotors() {
  digitalWrite(rightMotor[0], LOW);
  digitalWrite(rightMotor[1], LOW);
  digitalWrite(leftMotor[0], LOW);
  digitalWrite(leftMotor[1], LOW);
}
