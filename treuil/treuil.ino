
#include <AccelStepper.h>
#include <ArtnetWifi.h>
#include <Arduino.h>

//Wifi settings
const char* ssid = "EX_FUTUR";
const char* password = "hoophoop";


AccelStepper stepper(1, 27, 33);////driver,step,dir
WiFiUDP UdpSend;
ArtnetWifi artnet;

int ena_pin=12;
int led_pin=14;

int pos,dir,ena,set_maxUp,set_maxDown,moveUp,moveDown;
int maxUp,maxDown;
int led;
int vitesse=1000,vitesse_temp=1000;
int id;



void setup()
{
  Serial.begin(115200);
  ConnectWifi();


  artnet.setArtDmxCallback(onDmxFrame);
  artnet.begin();
  pinMode(13,OUTPUT);
  pinMode(ena_pin,OUTPUT);
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
  stepper.run();

  
}
