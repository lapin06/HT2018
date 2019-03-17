// Configuration du Bluetooth esclave

#include<SoftwareSerial.h>
#define RX 3
#define TX 2
SoftwareSerial BlueT(RX,TX);

void setup() {
  
 Serial.begin(9600);
 delay(500);
 Serial.println("Bonjour, helo");
 BlueT.begin(38400);
 Serial.write(char(BlueT.read()));
 delay(500);
}

void loop() {
  while(BlueT.available()){
    Serial.print(char(BlueT.read()));}
    while(Serial.available()){
      BlueT.write(char(Serial.read()));}
  }
