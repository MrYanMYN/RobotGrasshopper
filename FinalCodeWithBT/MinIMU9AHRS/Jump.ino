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





//
//void jump(void){
//
//   Serial.println("Jumping!");
//    
//   int buttonState = digitalRead(PIN_BUTTON);
//  
//   while(buttonState != HIGH){
//    digitalWrite(PIN_PHASE, HIGH); //Load the rope
//    analogWrite(PIN_ENABLE,255); 
//    delay(100);
//    buttonState = digitalRead(PIN_BUTTON);
//
//
////     if(bluetooth.available())  // If the bluetooth sent any characters
////          {
////            // Send any characters the bluetooth prints to the serial monitor
////            char data = (char)bluetooth.read();
////            Serial.print(data); 
////            if(data == 'S'){
////              digitalWrite(PIN_ENABLE, LOW); // Turn Off the motor
//                //  digitalWrite(PIN_PHASE, LOW);
//                //  Serial.println("Stoped Rotation");
//                //  break;                                                               
////          }
////     }
////    
//   }
//
//  Serial.println("Loaded");
//  digitalWrite(PIN_ENABLE, LOW); // Turn Off the motor
//  digitalWrite(PIN_PHASE, LOW);
//  delay(1000);
//  Serial.println("Releasing");
//
//   while(buttonState == HIGH){
//        digitalWrite(PIN_PHASE, LOW); //release the rope
//        analogWrite(PIN_ENABLE,150);   
//        delay(100);
//        buttonState = digitalRead(PIN_BUTTON);  
//
//         
////     if(bluetooth.available())  // If the bluetooth sent any characters
////          {
////            // Send any characters the bluetooth prints to the serial monitor
////            char data = (char)bluetooth.read();
////            Serial.print(data); 
////            if(data == 'S'){
////              stopRot();
////            }
//// 
////          }
//   }
//
//  Serial.println("Released");
//  digitalWrite(PIN_ENABLE, LOW); // Turn Off the motor
//  digitalWrite(PIN_PHASE, LOW);
//  delay(100);
//   
//}
