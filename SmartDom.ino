#ifdef ARDUINO_ARCH_ESP32
#include <WiFi.h>
#else
#include <ESP8266WiFi.h>
#endif

#include <Espalexa.h>

//  Sin Usar /////////
#define D3 14
#define D4 12
#define D5 13
#define D6 15
#define D7 3
//////////////////////

#define D1 16 //Luz 1
#define D2 5 //Luz 2 
#define D8 1//Cerradura

#define D0 4               //aux?

const char* ssid = "Tu Ssid";
const char* password = "Tu Contraseña";

Espalexa espAlexa;

void Funcion_D8(uint8_t brightness);
void Funcion_D2(uint8_t brightness);
void Funcion_(uint8_t brightness);


void setup() {
  Serial.begin(115200);
  pinMode(D0,OUTPUT); //aux

//  Sin Usar /////////
  pinMode(D3,OUTPUT);
  pinMode(D4,OUTPUT); 
  pinMode(D5,OUTPUT);
  pinMode(D6,OUTPUT);
  pinMode(D7,OUTPUT);
//////////////////////


  pinMode(D1,OUTPUT);
  pinMode(D2,OUTPUT); 
  pinMode(D8,OUTPUT);
  
  digitalWrite(D0,HIGH); //aux

//  Sin Usar /////////
  digitalWrite(D3,HIGH);
  digitalWrite(D4,HIGH);
  digitalWrite(D5,HIGH);    
  digitalWrite(D6,HIGH);    
  digitalWrite(D7,HIGH);    
//////////////////////

  digitalWrite(D1,HIGH);
  digitalWrite(D2,HIGH);
  digitalWrite(D8,HIGH);    
  ConectarWifi();
  espAlexa.addDevice("Luz 1", Funcion_D1);
  espAlexa.addDevice("Luz 2", Funcion_D2);
  espAlexa.addDevice("D8", Funcion_D8);
  
  espAlexa.begin();
}
///////////////////// VOID LOOP ////////////////////////////////////////////////////
void loop(){
  ConectarWifi();
  espAlexa.loop();
  delay(1);}
   
/////////////////// FUNCION PARA CONECTAR EL WIFI ///////////////////////////////////
void ConectarWifi() {
  if(WiFi.status() != WL_CONNECTED) {
     WiFi.mode(WIFI_STA);
     WiFi.begin(ssid, password);
     Serial.println("");
     Serial.println("Connecting to WiFi");
     while(WiFi.status() != WL_CONNECTED) {
           digitalWrite(D0, HIGH);
           delay(500);
           Serial.print(".");}
    Serial.print("Connected to ");
    Serial.println(ssid);
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());
    digitalWrite(D0, LOW);}}

/////////////////// FUNCION PARA EL PIN D1 ///////////////////////////// Luz 1
void Funcion_D1(uint8_t brightness){
     if(brightness){digitalWrite(D1, !digitalRead(D1));}
     else{digitalWrite(D1, HIGH);}}     

/////////////////// FUNCION PARA EL PIN D2 ///////////////////////////// Luz 2
void Funcion_D2(uint8_t brightness){
     if(brightness){digitalWrite(D2, !digitalRead(D2));}
     else{digitalWrite(D2,HIGH);}}
     
/////////////////// FUNCION PARA EL PIN D8 /////////////////////////////  Cerradura
void Funcion_D8(uint8_t brightness){
     if(brightness){digitalWrite(D8, LOW);}
     else{digitalWrite(D8, HIGH);}}
     
      
