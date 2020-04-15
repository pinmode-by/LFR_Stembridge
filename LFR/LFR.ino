// Line Folower Robot (STEMBRIDGE) 
// controller : Arduino nano
// driver     : TB6612
// 

// motor's pins
const byte AIN1 = 7;    // direction of left motor
const byte AIN2 = 4;    // direction of left motor
const byte BIN1 = 8;    // direction of right motor
const byte BIN2 = 9;    // direction of right motor
const byte PWMA = 5;    // left motor PWM
const byte PWMB = 6;    // right motor PWM

const byte BUTTON = 10;
const byte NUM_SENS = 8;

// pins PCB for Analog line 
byte pins[] = {A7, A6, A5, A4, A3, A2, A1, A0}; 
int sensors[NUM_SENS]; 

// functions declaration
void drive(int left, int right);
void pinsSetup();
void readSensors();

void setup() {
  
   Serial.begin(9600);
   pinsSetup();

} 

void loop() {
  

} 

void drive(int left, int right) {
   left = constrain(left, -255, 255);
   right = constrain(right, -255, 255);

   if (left >= 0) {
      digitalWrite(AIN1, LOW);
      digitalWrite(AIN2, HIGH);
   }
   else {
      digitalWrite(AIN1, HIGH);
      digitalWrite(AIN2, LOW);
   }

   if (right >= 0) {
      digitalWrite(BIN1, LOW);
      digitalWrite(BIN2, HIGH);
   }
   else {
      digitalWrite(BIN1, HIGH);
      digitalWrite(BIN2, LOW);
   }
      analogWrite(PWMA, abs(left));
      analogWrite(PWMB, abs(right));
} // drive


void pinsSetup() {
    pinMode(AIN1, OUTPUT);
    pinMode(AIN2, OUTPUT);
    pinMode(BIN1, OUTPUT);
    pinMode(BIN2, OUTPUT);
    pinMode(BUTTON, INPUT_PULLUP);
}

void readSensors() {
   for (int i = 0; i < NUM_SENS; ++i) {
       sensors[i] = analogRead(pins[i]);  
   }
}