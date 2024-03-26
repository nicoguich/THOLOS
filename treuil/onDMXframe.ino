void onDmxFrame(uint16_t universe, uint16_t length, uint8_t sequence, uint8_t* data)
{

set_id();

if (data[(id*nb_adress)+0]!=ena_temp){
ena=data[(id*nb_adress)+0];
ena_temp=ena;}

if (data[(id*nb_adress)+1]!=dir_temp){
dir=data[(id*nb_adress)+1];
dir_temp=dir;}

if (data[(id*nb_adress)+2]!=pos_temp){
pos=(data[(id*nb_adress)+2])*1;
pos_temp=pos;}

if (data[(id*nb_adress)+3]!=vitesse_temp){
vitesse=(data[(id*nb_adress)+3]*10);
vitesse_temp=data[(id*nb_adress)+3];}

if (data[(id*nb_adress)+4]!=set_maxUp_temp){
set_maxUp=data[(id*nb_adress)+4];
set_maxUp_temp=set_maxUp;}

if (data[(id*nb_adress)+5]!=set_maxDown_temp){
set_maxDown=data[(id*nb_adress)+5];
set_maxDown_temp=set_maxDown;}

if (data[(id*nb_adress)+6]!=moveUp_temp){
moveUp=data[(id*nb_adress)+6];
moveUp_temp=moveUp;}

if (data[(id*nb_adress)+7]!=moveDown_temp){
moveDown=data[(id*nb_adress)+7];
moveDown_temp=moveDown;}

if (data[(id*nb_adress)+8]!=led_temp){
led=data[(id*nb_adress)+8];
led_temp=led;}

if (data[(id*nb_adress)+9]!=valid_temp){
valid=data[(id*nb_adress)+9];
valid_temp=valid;}

if (data[(id*nb_adress)+10]!=stop_motor_temp){
stop_motor=data[(id*nb_adress)+10];
stop_motor_temp=stop_motor;}


////adress all

if (data[(id_all*nb_adress)+0]!=ena_tempall){
ena=data[(id_all*nb_adress)+0];
ena_tempall=ena;}

if (data[(id_all*nb_adress)+1]!=dir_tempall){
dir=data[(id_all*nb_adress)+1];
dir_tempall=dir;}

if (data[(id_all*nb_adress)+2]!=pos_tempall){
pos=(data[(id_all*nb_adress)+2])*1;
pos_tempall=pos;}

if (data[(id_all*nb_adress)+3]!=vitesse_tempall){
vitesse=(data[(id_all*nb_adress)+3]*10);
vitesse_tempall=data[(id_all*nb_adress)+3];}

if (data[(id_all*nb_adress)+4]!=set_maxUp_tempall){
set_maxUp=data[(id_all*nb_adress)+4];
set_maxUp_tempall=set_maxUp;}

if (data[(id_all*nb_adress)+5]!=set_maxDown_tempall){
set_maxDown=data[(id_all*nb_adress)+5];
set_maxDown_tempall=set_maxDown;}

if (data[(id_all*nb_adress)+6]!=moveUp_tempall){
moveUp=data[(id_all*nb_adress)+6];
moveUp_tempall=moveUp;}

if (data[(id_all*nb_adress)+7]!=moveDown_tempall){
moveDown=data[(id_all*nb_adress)+7];
moveDown_tempall=moveDown;}

if (data[(id_all*nb_adress)+8]!=led_tempall){
led=data[(id_all*nb_adress)+8];
led_tempall=led;}

if (data[(id_all*nb_adress)+9]!=valid_tempall){
valid=data[(id_all*nb_adress)+9];
valid_tempall=valid;}

if (data[(id_all*nb_adress)+10]!=stop_motor_tempall){
stop_motor=data[(id_all*nb_adress)+10];
stop_motor_tempall=stop_motor;}






stepper.setMaxSpeed(vitesse);

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
