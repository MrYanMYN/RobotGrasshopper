/*

MinIMU-9-Arduino-AHRS
Pololu MinIMU-9 + Arduino AHRS (Attitude and Heading Reference System)

Copyright (c) 2011-2016 Pololu Corporation.
http://www.pololu.com/

MinIMU-9-Arduino-AHRS is based on sf9domahrs by Doug Weibel and Jose Julio:
http://code.google.com/p/sf9domahrs/

sf9domahrs is based on ArduIMU v1.5 by Jordi Munoz and William Premerlani, Jose
Julio and Doug Weibel:
http://code.google.com/p/ardu-imu/

MinIMU-9-Arduino-AHRS is free software: you can redistribute it and/or modify it
under the terms of the GNU Lesser General Public License as published by the
Free Software Foundation, either version 3 of the License, or (at your option)
any later version.

MinIMU-9-Arduino-AHRS is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for
more details.

You should have received a copy of the GNU Lesser General Public License along
with MinIMU-9-Arduino-AHRS. If not, see <http://www.gnu.org/licenses/>.

*/

void printdata(void)
{   
      Serial.print("!");

      #if PRINT_EULER == 1
      Serial.print("ANG:");
      Serial.print(ToDeg(roll));
      Serial.print(",");
      Serial.print(ToDeg(pitch));
      Serial.print(",");
      Serial.print(ToDeg(yaw));
      #endif      
      #if PRINT_ANALOGS==1
      Serial.print(",Gyro: [Rad]");
      Serial.print(AN[0]);  //(int)read_adc(0)
      Serial.print(",");
      Serial.print(AN[1]);
      Serial.print(",");
      Serial.print(AN[2]);  
      Serial.print(",Acce: [m/s^2]");       
      Serial.print((AN[3] / 256.0) * 9.81); //Converting 256 levels to m/s^2
      Serial.print (",");
      Serial.print((AN[4] / 256.0) * 9.81); //Converting 256 levels to m/s^2
      Serial.print (",");
      Serial.print((AN[5] / 256.0) * 9.81); //Converting 256 levels to m/s^2
      Serial.print(",Magno: [?] ");
      Serial.print(c_magnetom_x);
      Serial.print (",");
      Serial.print(c_magnetom_y);
      Serial.print (",");
      Serial.print(c_magnetom_z);
      #endif
      #if PRINT_DCM == 1
      Serial.print (",DCM:");
      Serial.print(DCM_Matrix[0][0]);
      Serial.print (",");
      Serial.print(DCM_Matrix[0][1]);
      Serial.print (",");
      Serial.print(DCM_Matrix[0][2]);
      Serial.print (",");
      Serial.print(DCM_Matrix[1][0]);
      Serial.print (",");
      Serial.print(DCM_Matrix[1][1]);
      Serial.print (",");
      Serial.print(DCM_Matrix[1][2]);
      Serial.print (",");
      Serial.print(DCM_Matrix[2][0]);
      Serial.print (",");
      Serial.print(DCM_Matrix[2][1]);
      Serial.print (",");
      Serial.print(DCM_Matrix[2][2]);
      #endif
      Serial.println();

      if(AN[5] < -9.5){
        flip();
      }

//      if(MyBlue.available()){
//      while(MyBlue.available())
//        {
//          char inChar = (char)MyBlue.read(); //read the input
//          inputString += inChar;        //make a string of the characters coming on serial
//        }
//        MyBlue.println(inputString);
////        while (Serial.available() > 0)  
////        { junk = Serial.read() ; }      // clear the serial buffer
//        if(inputString != NULL){
//          MyBlue.println("Here!");  //in case of 'a' turn the LED on
//          jump();
//        }
//        inputString = "";
//      }
        
        if(bluetooth.available())  // If the bluetooth sent any characters
          {
            // Send any characters the bluetooth prints to the serial monitor
            char data = (char)bluetooth.read();
            Serial.print(data); 
            if(data == '⸮' || data == '?' || data=='A'){
              jump();
            }
//            if(data == 'C'){
//              load();
//            }
//            if(data == 'D'){
//              releas();
//            }
 
          }
          if(Serial.available())  // If stuff was typed in the serial monitor
          {
            // Send any characters the Serial monitor prints to the bluetooth
            bluetooth.print((char)Serial.read());
          }
          // and loop forever and ever!
      
}

/*long convert_to_dec(float x)
{
  return x*10000000;
}*/
