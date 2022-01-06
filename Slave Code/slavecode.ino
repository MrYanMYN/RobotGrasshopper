int state = 0;
int count = 0;

int pitch = 0;
int yaw = 0;
int roll = 0;

void setup() {
  Serial.begin(38400);
}

void loop() {
//  if(count > 2){
//    count = 0;
//  }

  if(Serial.available() > 0){
    state = Serial.read();

    if(roll == 0){
      roll = state;
      Serial.write(0);
    }
    else if(pitch == 0){
      pitch = state;
      Serial.write(1);
    }
    else if(yaw == 0){
      yaw = state;
      Serial.write(2);
    }

    if(pitch != 0 & yaw != 0 & roll != 0){
      Serial.print(roll);
      Serial.print(" : ");
      Serial.print(pitch);
      Serial.print(" : ");
      Serial.print(yaw);
      Serial.println(" ;;;; ");
      pitch = 0;
      yaw = 0;
      roll= 0;
    }
    
  }

//  Serial.println(String(" X: ") + x + String(" Y: ") + y + String(" Z: ") + z + String(" Count: ") + count + String(" State: ") + state);
}
