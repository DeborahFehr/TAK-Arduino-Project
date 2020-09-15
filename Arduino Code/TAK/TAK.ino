 #include <Servo.h>

Servo servo;
int relais_pin=6;
int vib_pin=7;
int servo_pin=8;

void setup() {
  pinMode(relais_pin, OUTPUT);
  pinMode(vib_pin,INPUT);
  servo.attach(servo_pin); 
  servo.write(180); 
}

void loop() {
  // DETECTION
  int vib_val;
  vib_val=digitalRead(vib_pin);

  if(vib_val==1){
    delay(30); // Experimentell bestimmen
    vib_val=digitalRead(vib_pin);

    // VERIFICATION
    if(vib_val==1){
      // SHOOTING
      digitalWrite(relais_pin, HIGH); // Pumpe AN
      servo.write(30); 
      delay(1000); 
      // RESET
      digitalWrite(relais_pin, LOW); // Pumpe AUS
      servo.write(180); 
      delay(5000); // Cooldown
      }
  }
}
