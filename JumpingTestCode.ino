#define PIN_ENABLE 10
#define PIN_PHASE 16
#define PIN_BUTTON 7

void jump(void){

   int buttonState = digitalRead(PIN_BUTTON);
  
   while(buttonState != HIGH){
    digitalWrite(PIN_PHASE, HIGH); //Load the rope
    analogWrite(PIN_ENABLE,255); 
    delay(100);
    buttonState = digitalRead(PIN_BUTTON);
   }

  digitalWrite(PIN_ENABLE, LOW); // Turn Off the motor
  digitalWrite(PIN_PHASE, LOW);
  delay(1000);

   while(buttonState == HIGH){
        digitalWrite(PIN_PHASE, LOW); //release the rope
        analogWrite(PIN_ENABLE,150 );   
        delay(100);
        buttonState = digitalRead(PIN_BUTTON);   
   }

  digitalWrite(PIN_ENABLE, LOW); // Turn Off the motor
  digitalWrite(PIN_PHASE, LOW);
  delay(100);
   
}




void setup() {
  Serial.begin(115200);
  pinMode(PIN_ENABLE, OUTPUT);
  pinMode(PIN_PHASE, OUTPUT);
  pinMode(PIN_BUTTON, INPUT);
}

void loop() {
   delay(10000);
  jump();
  Serial.print("Attempt!");
  delay(10000);
}
