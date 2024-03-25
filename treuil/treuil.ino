
#include <AccelStepper.h>
#include <ArtnetWifi.h>
#include <Arduino.h>
#include <EEPROM.h>

//Wifi settings
const char* ssid = "EX_FUTUR";
const char* password = "hoophoop";


AccelStepper stepper(1, 27, 33);////driver,step,dir
WiFiUDP UdpSend;
ArtnetWifi artnet;
const int startUniverse = 0;
const char host[] = "192.168.50.45";


int addr = 0;
#define EEPROM_SIZE 32

int ena_pin=12;
int led_pin=14;

int pos,pos_temp,dir,ena,set_maxUp,set_maxDown,moveUp,moveDown,stop_motor;
int maxDown=0;
int led;
int vitesse=1000,vitesse_temp=1000;
int id;
int id_all=10;
int fin_course_pin=21;
int direct_move=0;
int valid=0;
int nb_adress=11;




void setup()
{
  Serial.begin(115200);
  ConnectWifi();
EEPROM.begin(EEPROM_SIZE);
EEPROM.get(0, maxDown);
Serial.print("maxdown saved:");
Serial.println(maxDown);

  artnet.setArtDmxCallback(onDmxFrame);
  artnet.begin(host);
  artnet.setLength(3);
  artnet.setUniverse(startUniverse);
  pinMode(13,OUTPUT);
  pinMode(ena_pin,OUTPUT);
  pinMode(fin_course_pin,INPUT);
  pinMode(15,INPUT);
  pinMode(32,INPUT);
  pinMode(22,INPUT);
  pinMode(23,INPUT);

  stepper.setMaxSpeed(vitesse);
  stepper.setAcceleration(500);

  set_id();

digitalWrite(ena_pin,LOW);
  
}

void loop()
{
  artnet.read();
  if ((moveUp==0)&&(moveDown==0)){
    if (direct_move==1){
      stepper.stop();
       pos=stepper.currentPosition();
       stepper.moveTo(pos);
      // artnet.setByte((id*10)+2, pos);
      // artnet.write();
       direct_move=0;
    }

  }
  if ((moveUp==1)&&(moveDown==0)){
  direct_move=1;
  stepper.setSpeed(-vitesse);
  stepper.runSpeed();
 
}

if ((moveUp==0)&&(moveDown==1)){
  direct_move=1;
  stepper.setSpeed(vitesse);
  stepper.runSpeed();

}

if (set_maxUp==1){
  moveUp=0;
  stepper.setCurrentPosition(0);
  pos=0;
 // stepper.runToNewPosition(0);

  Serial.println("home");
}
if(digitalRead(fin_course_pin)==HIGH){
       artnet.setByte(299+id, 1);
       artnet.write();

}

if (set_maxDown==1){

  moveDown=0;
EEPROM.put(0, maxDown);
EEPROM.commit();
  maxDown=stepper.currentPosition();
  stepper.runToNewPosition(maxDown);

}



 
  stepper.run(); 
}
