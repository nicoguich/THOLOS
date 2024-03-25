void onDmxFrame(uint16_t universe, uint16_t length, uint8_t sequence, uint8_t* data)
{

set_id();
if (data[511]==0){
ena=data[(id*nb_adress)+0];
dir=data[(id*nb_adress)+1];
pos=(data[(id*nb_adress)+2])*1;
vitesse=(data[(id*nb_adress)+3]*10);
set_maxUp=data[(id*nb_adress)+4];
set_maxDown=data[(id*nb_adress)+5];
moveUp=data[(id*nb_adress)+6];
moveDown=data[(id*nb_adress)+7];
led=data[(id*nb_adress)+8];
valid=data[(id*nb_adress)+9];
stop_motor=data[(id*nb_adress)+10];
}

////adress all
if (data[511]==255){
Serial.println("all activate");
ena=data[(id_all*nb_adress)+0];
dir=data[(id_all*nb_adress)+1];
pos=(data[(id_all*nb_adress)+2])*1;
vitesse=(data[(id_all*nb_adress)+3]*10);
set_maxUp=data[(id_all*nb_adress)+4];
set_maxDown=data[(id_all*nb_adress)+5];
moveUp=data[(id_all*nb_adress)+6];
moveDown=data[(id_all*nb_adress)+7];
led=data[(id_all*nb_adress)+8];
valid=data[(id_all*nb_adress)+9];
stop_motor=data[(id_all*nb_adress)+10];
}




if (vitesse_temp!= vitesse){
stepper.setMaxSpeed(vitesse);
vitesse_temp=vitesse;
}
if (valid==1){
stepper.moveTo(map(pos,0,100,0,maxDown));

}
if (stop_motor==1){
  direct_move=0;
 stepper.stop();
}
digitalWrite(ena_pin,ena);
analogWrite(led_pin,led);


send_artnet();

//printdata();
}
