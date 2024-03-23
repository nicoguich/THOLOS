void onDmxFrame(uint16_t universe, uint16_t length, uint8_t sequence, uint8_t* data)
{

set_id();

ena=data[(id*9)+0];
dir=data[(id*9)+1];
if (dir==0){
pos=(data[(id*9)+2])*-100;
}
else{
 pos=(data[(id*9)+2])*100; 
}
vitesse=(data[(id*9)+3]*10);
set_maxUp=data[(id*9)+4];
set_maxDown=data[(id*9)+5];
moveUp=data[(id*9)+6];
moveDown=data[(id*9)+7];
led=data[(id*9)+8];

//printdata();


if (vitesse_temp!= vitesse){
stepper.setMaxSpeed(vitesse);
vitesse_temp=vitesse;
}


digitalWrite(ena_pin,ena);

if ((moveUp==0)&&(moveDown==0)){
if (stepper.distanceToGo() == 0){
stepper.moveTo(pos);}
}
if ((moveUp==1)&&(moveDown==0)){
  stepper.setSpeed(vitesse);
  stepper.runSpeed();
}

if ((moveUp==0)&&(moveDown==1)){
  stepper.setSpeed(-vitesse);
  stepper.runSpeed();
}
analogWrite(led_pin,led);




/*
Serial.print(digitalRead(15));
Serial.print(" ");
Serial.print(digitalRead(32));
Serial.print(" ");
Serial.print(digitalRead(22));
Serial.print(" "); 
Serial.println(digitalRead(23));
*/
}
