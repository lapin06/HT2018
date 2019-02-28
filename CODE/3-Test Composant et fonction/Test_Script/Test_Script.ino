


#include<SoftwareSerial.h>
#define RX 11
#define TX 12
SoftwareSerial BlueT(RX,TX);


void setup() {
  Serial.begin(9600);
  BlueT.begin(38400);
  Serial.println("EN ATTENTE");//test si tout est operationel
  BlueT.print("$$$$$$$$$$$\r\n");


  // put your setup code here, to run once:
BlueT.print("F");
BlueT.print("\r\n");

}

void loop() {
  // put your main code here, to run repeatedly:

}
