#define PIN_ENABLE 10
#define PIN_PHASE 16
#define PIN_BUTTON 7
  

void jump(void){

   Serial.println("Jumping!");
    
   int buttonState = digitalRead(PIN_BUTTON);
  
   while(buttonState != HIGH){
    digitalWrite(PIN_PHASE, HIGH); //Load the rope
    analogWrite(PIN_ENABLE,127); 
    delay(100);
    buttonState = digitalRead(PIN_BUTTON);
   }

  digitalWrite(PIN_ENABLE, LOW); // Turn Off the motor
  digitalWrite(PIN_PHASE, LOW);
  delay(1000);

   while(buttonState == HIGH){
        digitalWrite(PIN_PHASE, LOW); //release the rope
        analogWrite(PIN_ENABLE,255);   
        delay(100);
        buttonState = digitalRead(PIN_BUTTON);   
   }

  digitalWrite(PIN_ENABLE, LOW); // Turn Off the motor
  digitalWrite(PIN_PHASE, LOW);
  delay(100);
   
}
