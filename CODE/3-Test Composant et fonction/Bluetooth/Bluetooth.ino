#include<SoftwareSerial.h>
#define RX 11
#define TX 12
SoftwareSerial BlueT(RX,TX);


void setup() {
  Serial.begin(9600);
  Serial.println("Bonjour");
  BlueT.begin(38400);
  BlueT.write("okkkk");
  delay(500);
  // put your setup code here, to run once:

}

void loop() {
  while(BlueT.available()){
    Serial.print(char(BlueT.read()));}
    while(Serial.available()){
      BlueT.write(char(Serial.read()));}
  }
  
  // put your main code here, to run repeatedly:
