#include<SoftwareSerial.h>
#define RX 10
#define TX 11
SoftwareSerial BlueT(RX,TX);

void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
 delay(500);
 Serial.println("Bonjour, helo");
 BlueT.begin(38400);
 delay(500);
}

void loop() {
  while(BlueT.available()){
   Serial.print(char(BlueT.read()));
   if (BlueT.read()=='P'){
      BlueT.write("recu");
      Serial.print("OKP");
    }
  }
}
