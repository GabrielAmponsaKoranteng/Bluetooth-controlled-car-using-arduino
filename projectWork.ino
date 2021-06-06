const int positiveLeftPin = 4;
const int negativeLeftPin = 5;
const int positiveRightPin = 6;
const int negativeRightPin = 7;

// read the bluetooth state
int state = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(positiveLeftPin, OUTPUT);     // 
  pinMode(negativeLeftPin, OUTPUT);
  pinMode(positiveRightPin, OUTPUT);
  pinMode(negativeRightPin, OUTPUT);

  /*
   * start serial monitor
   */
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  /*
   * loop to control from bluetooth device
   */ 
  if (Serial.available() > 0) {

    // read bluetooth device
    state = Serial.read();


    // move the car forward
    if (state == '0') {
      digitalWrite(positiveLeftPin, HIGH);
      digitalWrite(negativeLeftPin, LOW);
      digitalWrite(positiveRightPin, HIGH);
      digitalWrite(negativeRightPin, LOW);
    }

    // move the car backward
    if (state == '1') {
      digitalWrite(positiveLeftPin, LOW);
      digitalWrite(negativeLeftPin, HIGH);
      digitalWrite(positiveRightPin, LOW);
      digitalWrite(negativeRightPin, HIGH);
    }

    // move the car right
    if (state == '2') {
      digitalWrite(positiveLeftPin, HIGH);
      digitalWrite(negativeLeftPin, LOW);
      digitalWrite(positiveRightPin, LOW);
      digitalWrite(negativeRightPin, HIGH);
    }

    // move the car left
    if (state == '3') {
      digitalWrite(positiveLeftPin, LOW);
      digitalWrite(negativeLeftPin, HIGH);
      digitalWrite(positiveRightPin, HIGH);
      digitalWrite(negativeRightPin, LOW);
    }

    // stop the car
    if (state == '4') {
      digitalWrite(positiveLeftPin, LOW);
      digitalWrite(negativeLeftPin, LOW);
      digitalWrite(positiveRightPin, LOW);
      digitalWrite(negativeRightPin, LOW);
    }
    
  } 

  /*
  else {
      digitalWrite(positiveLeftPin, LOW);
      digitalWrite(negativeLeftPin, LOW);
      digitalWrite(positiveRightPin, LOW);
      digitalWrite(negativeRightPin, LOW);
  }
  
  */
  
}
