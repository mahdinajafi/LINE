// NOTE: THIS CODE IS FOR THE LINER FOLLOWER ROBOT
// WRITE BY MAHDI NAJAFI LOCATION: INNO HUB_MODER "HQ"

// Sensor pins
int left   = 2;
int center = 3;
int right  = 4;

// Motor pins (L298N)
int motorLeft1  = 6;   // IN1
int motorLeft2  = 7;   // IN2
int motorRight1 = 8;   // IN3
int motorRight2 = 10;  // IN4
int enableLeft  = 5;   // ENA (PWM)
int enableRight = 9;   // ENB (PWM)

int baseSpeed = 255;   // 0-255, lower = slower
int Fspeed = 100; //speed for the straightforward 

void setup() {
  // Sensors are inputs
  pinMode(left,   INPUT);
  pinMode(center, INPUT);
  pinMode(right,  INPUT);

  // Motor pins are outputs
  pinMode(motorLeft1,  OUTPUT);
  pinMode(motorLeft2,  OUTPUT);
  pinMode(motorRight1, OUTPUT);
  pinMode(motorRight2, OUTPUT);
  pinMode(enableLeft,  OUTPUT);
  pinMode(enableRight, OUTPUT);

  // Start with motors off
  digitalWrite(motorLeft1,  LOW);
  digitalWrite(motorLeft2,  LOW);
  digitalWrite(motorRight1, LOW);
  digitalWrite(motorRight2, LOW);
  analogWrite(enableLeft,  0);
  analogWrite(enableRight, 0);

  delay(3000);   // wait 1.5 seconds before starting
}

void loop() {
  // Read the sensors (0 or 1)
  int L = digitalRead(left);
  int C = digitalRead(center);
  int R = digitalRead(right);

  // Most common IR sensor: black line = 1, white = 0
  // If your black line = 0, change every ==1 to ==0

  if (C == 1) {
    // Center sees black → go forward
    analogWrite(enableLeft,  baseSpeed);
    analogWrite(enableRight, baseSpeed);
    digitalWrite(motorLeft1,  HIGH);
    digitalWrite(motorLeft2,  LOW);
    digitalWrite(motorRight1, HIGH);
    digitalWrite(motorRight2, LOW);
  }
  
  else if (L == 1) {
    // Left sees black → turn left (stop left motor)
    analogWrite(enableLeft,  baseSpeed);
    analogWrite(enableRight, baseSpeed);
    digitalWrite(motorLeft1,  HIGH);
    digitalWrite(motorLeft2,  LOW);
    digitalWrite(motorRight1, LOW);
    digitalWrite(motorRight2, LOW);
  }
  
  else if (R == 1) {
    // Right sees black → turn right (stop right motor)
    analogWrite(enableLeft,  baseSpeed);
    analogWrite(enableRight, baseSpeed);
    digitalWrite(motorLeft1,  LOW);
    digitalWrite(motorLeft2,  LOW);
    digitalWrite(motorRight1, HIGH);
    digitalWrite(motorRight2, LOW);
  }

  delay(10);   // small delay makes it more calm
}
