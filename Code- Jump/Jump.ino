bool reverse = false  //change if backwards

// The robot jump function
void jump(void)
{   
  if(!reverse){
    digitalWrite(enablePin, HIGH);
    digitalWrite(phasePin, HIGH);
    delay(900);
    digitalWrite(enablePin, LOW);
    delay(1500);
    digitalWrite(enablePin, HIGH);
    digitalWrite(phasePin, LOW);
    delay(200);
  }
  else{
    digitalWrite(enablePin, HIGH);
    digitalWrite(phasePin, LOW);
    delay(900);
    digitalWrite(enablePin, LOW);
    delay(1500);
    digitalWrite(enablePin, HIGH);
    digitalWrite(phasePin, HIGH);
    delay(200);
  }
  // There is a need to change the delay values to fit your robot
}

/*long convert_to_dec(float x)
{
  return x*10000000;
}*/
