//#define PIN_ENABLE 10
//#define PIN_PHASE 16
//#define PIN_BUTTON 7
//
//void load(void){
//   while(buttonState != HIGH){
//    digitalWrite(PIN_PHASE, HIGH); //Load the rope
//    analogWrite(PIN_ENABLE,127); 
//    delay(100);
//    buttonState = digitalRead(PIN_BUTTON);
//
//    
//     if(bluetooth.available())  // If the bluetooth sent any characters
//          {
//            // Send any characters the bluetooth prints to the serial monitor
//            char data = (char)bluetooth.read();
//            Serial.print(data); 
//            if(data == 'S'){
//              //  digitalWrite(PIN_ENABLE, LOW); // Turn Off the motor
                //  digitalWrite(PIN_PHASE, LOW);
                //  Serial.println("Stoped Rotation");
                //  break;
//            }
// 
//          }
//   }
//   }
//
//  Serial.println("Loaded");
//  digitalWrite(PIN_ENABLE, LOW); // Turn Off the motor
//  digitalWrite(PIN_PHASE, LOW);
//}
//
//void releas(void){
//  while(buttonState == HIGH){
//        digitalWrite(PIN_PHASE, LOW); //release the rope
//        analogWrite(PIN_ENABLE,255);   
//        delay(100);
//        buttonState = digitalRead(PIN_BUTTON);   
//
//        
//     if(bluetooth.available())  // If the bluetooth sent any characters
//          {
//            // Send any characters the bluetooth prints to the serial monitor
//            char data = (char)bluetooth.read();
//            Serial.print(data); 
//            if(data == 'S'){
//              digitalWrite(PIN_ENABLE, LOW); // Turn Off the motor
                //  digitalWrite(PIN_PHASE, LOW);
                //  Serial.println("Stoped Rotation");
                //  break;
//            }
// 
//          }
//   }
//   }
//
//  Serial.println("Released");
//  digitalWrite(PIN_ENABLE, LOW); // Turn Off the motor
//  digitalWrite(PIN_PHASE, LOW);
//}
