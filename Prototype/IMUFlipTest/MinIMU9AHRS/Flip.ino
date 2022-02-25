#define PIN_ENABLE 6
#define PIN_PHASE 3


void flip(void){
   digitalWrite(PIN_ENABLE, HIGH);  //Flip around
   digitalWrite(PIN_PHASE, HIGH);
   delay(5000);

   digitalWrite(PIN_ENABLE, LOW); // Turn Off the motor
   digitalWrite(PIN_PHASE, LOW);
}
