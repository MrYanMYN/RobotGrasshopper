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
//      Serial.print("ANG:");
//      Serial.print(ToDeg(roll));
//      Serial.print(",");
//      Serial.print(ToDeg(pitch));
//      Serial.print(",");
//      Serial.print(ToDeg(yaw));
      sendData();
      #endif      
      #if PRINT_ANALOGS==1
      Serial.print(",AN:");
      Serial.print(AN[0]);  //(int)read_adc(0)
      Serial.print(",");
      Serial.print(AN[1]);
      Serial.print(",");
      Serial.print(AN[2]);  
      Serial.print(",");
      Serial.print(AN[3]);
      Serial.print (",");
      Serial.print(AN[4]);
      Serial.print (",");
      Serial.print(AN[5]);
      Serial.print(",");
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
      
}

void sendData(void){
      Serial.begin(38400);
      int count = 0;
      int sendSignal = 0;
      int msg[] = {ToDeg(roll), ToDeg(pitch), ToDeg(yaw)};
    String msg = String(ToDeg(roll), 2) + String(":") + String(ToDeg(pitch), 2) + String(":") + String(ToDeg(yaw), 2);
      for(int i = 0; i < 3; i++){
        Serial.print(msg[i]);
        Serial.print(":");
        Serial.write(msg[i]);
        if(i == 2){
          Serial.println(";");
        }
      }
/*
      while(sendSignal != 1 || sendSignal != 2 || sendSignal != 3){
          if(Serial.available() > 0){
            sendSignal = Serial.read();
            Serial.write(msg[sendSignal]);
          }
        }*/
      Serial.begin(115200);
}
/*long convert_to_dec(float x)
{
  return x*10000000;
}*/
