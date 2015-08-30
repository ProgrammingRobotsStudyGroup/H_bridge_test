// from:
// http://www.instructables.com/id/Duel-Motor-Driver-with-Arduino-using-a-SN754410NE-/?ALLSTEPS

// Use this code to test your motor with the Arduino board:

// if you need PWM, just use the PWM outputs on the Arduino
// and instead of digitalWrite, you should use the analogWrite command

// —————————————————————————  Motors
int motor_left[] = {0, 1};
int motor_right[] = {2, 3}; //{7, 8};
int ledPin =  11;    // LED on Teensy 2.0

// ————————————————————————— Setup
void setup() {
Serial.begin(9600);

// Setup motors
int i;
for(i = 0; i < 2; i++){
pinMode(motor_left[i], OUTPUT);
pinMode(motor_right[i], OUTPUT);
pinMode(ledPin, OUTPUT);
}

}

// ————————————————————————— Loop
void loop() {

drive_forward();
delay(1000);
motor_stop();
Serial.println("1");

drive_backward();
delay(1000);
motor_stop();
Serial.println("2");

turn_left();
delay(1000);
motor_stop();
Serial.println("3");

turn_right();
delay(1000);
motor_stop();
Serial.println("4");

motor_stop();
delay(1000);
motor_stop();
Serial.println("5");

digitalWrite(ledPin, HIGH);   // set the LED on
  delay(1000);                  // wait for a second
  digitalWrite(ledPin, LOW);    // set the LED off
  delay(1000);                  // wait for a second

}

// ————————————————————————— Drive

void motor_stop(){
digitalWrite(motor_left[0], LOW);
digitalWrite(motor_left[1], LOW);

digitalWrite(motor_right[0], LOW);
digitalWrite(motor_right[1], LOW);
delay(25);
}

void drive_forward(){
digitalWrite(motor_left[0], HIGH);
digitalWrite(motor_left[1], LOW);

digitalWrite(motor_right[0], HIGH);
digitalWrite(motor_right[1], LOW);
}

void drive_backward(){
digitalWrite(motor_left[0], LOW);
digitalWrite(motor_left[1], HIGH);

digitalWrite(motor_right[0], LOW);
digitalWrite(motor_right[1], HIGH);
}

void turn_left(){
digitalWrite(motor_left[0], LOW);
digitalWrite(motor_left[1], HIGH);

digitalWrite(motor_right[0], HIGH);
digitalWrite(motor_right[1], LOW);
}

void turn_right(){
digitalWrite(motor_left[0], HIGH);
digitalWrite(motor_left[1], LOW);

digitalWrite(motor_right[0], LOW);
digitalWrite(motor_right[1], HIGH);
}

