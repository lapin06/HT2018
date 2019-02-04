//LAPIN avec sa voix
#include<SoftwareSerial.h>
#define RX 5
#define TX 6
SoftwareSerial mySerial(RX,TX);

#define Arduino_RX 10
#define Arduino_TX 11
SoftwareSerial BlueT(Arduino_RX, Arduino_TX);

const int led=4;
char data="A";  
static int8_t Send_buf[8] = {0};

#define CMD_PLAY_WITHVOLUME 0X22
#define CMD_SEL_DEV 0X09 //SELECT STORAGE DEVICE, DATA IS REQUIRED 
#define DEV_TF 0X02 //HELLO,IM THE DATA REQUIRED                                  
#define CMD_PLAY_WITHFOLDER 0X0F//DATA IS NEEDED, 0x7E 06 0F 00 01 02 EF;(play the song with the directory \01\002xxxxxx.mp3 

void sendCommand(int8_t command, int16_t dat) { 
  delay(20); 
  Send_buf[0] = 0x7e; //starting byte 
  Send_buf[1] = 0xff; //version 
  Send_buf[2] = 0x06; //the number of bytes of the command without starting byte and ending byte 
  Send_buf[3] = command; // 
  Send_buf[4] = 0x00;//0x00 = no feedback, 0x01 = feedback 
  Send_buf[5] = (int8_t)(dat >> 8);//datah 
  Send_buf[6] = (int8_t)(dat); //datal 
  Send_buf[7] = 0xef; //ending byte 
  for(uint8_t i=0; i<8; i++){ 
    mySerial.write(Send_buf[i]) ; 
  } 
} 
void setup() {

 Serial.begin(9600);
 Serial.println("Bonjour, helo");
 BlueT.begin(38400);
 
 pinMode(led, OUTPUT);
 digitalWrite(led,LOW);
 Serial.println("LOW");
 delay(900);

 digitalWrite(led,HIGH);

 Serial.begin(9600);
  mySerial.begin(9600);
  delay(500); 
  sendCommand(CMD_SEL_DEV, DEV_TF);//select the TF card   
  delay(200); 
}

void loop() {

while(BlueT.available()){
  Serial.print(char(BlueT.read()));
  }
while(Serial.available()){
  BlueT.write(char(Serial.read()));
  
  if (BlueT.read() == "PRET") {
    digitalWrite(led,LOW);
    delay(900);
    digitalWrite(led,HIGH);
    sendCommand(CMD_PLAY_WITHFOLDER, 0X0F00102);
    Serial.println("pret");   
  }

  
  if (BlueT.read()=="ATTEND"){
    sendCommand(CMD_PLAY_WITHFOLDER, 0X0F00101);
    Serial.println("Attend");
  }

  if (BlueT.read()=="DEUX"){
    sendCommand(CMD_PLAY_WITHFOLDER, 0X0F00103);
    Serial.println("Deux");
  }

  if (BlueT.read()=="DEJAR"){
    sendCommand(CMD_PLAY_WITHVOLUME, 0X0F007);
    Serial.println("dejaR");
  }

  if (BlueT.read()=="DEJAB"){
    sendCommand(CMD_PLAY_WITHFOLDER, 0X0F00108);
    Serial.println("dejaB");
    }

  if (BlueT.read()=="DEJAV"){
    sendCommand(CMD_PLAY_WITHVOLUME, 0X0F002);
    Serial.println("dejaV");
  }

  if (BlueT.read()=="DEJAJ"){
    sendCommand(CMD_PLAY_WITHFOLDER, 0X0F00109); 
    Serial.println("dejaJ");
  }


  if (BlueT.read()=="OKR"){
    sendCommand(CMD_PLAY_WITHVOLUME, 0X0F005); 
    Serial.println("r");
  }

  if (BlueT.read()=="OKV"){
    sendCommand(CMD_PLAY_WITHVOLUME, 0X0F006); 
    Serial.println("v");
  }

  if (BlueT.read()=="OKJ"){
    sendCommand(CMD_PLAY_WITHVOLUME, 0X0F004); 
    Serial.println("j");
  }

  if (BlueT.read()=="OKB"){
    sendCommand(CMD_PLAY_WITHVOLUME, 0X0F003);
    Serial.println("b");
  }

  
  if (BlueT.read()=="r"){
    sendCommand(CMD_PLAY_WITHFOLDER, 0X0F00106);
    Serial.println("changerR");
  }

  if (BlueT.read()=="b"){
    sendCommand(CMD_PLAY_WITHFOLDER, 0X0F00104);
    Serial.println("changerB");
  }

  if (BlueT.read()=="v"){
    sendCommand(CMD_PLAY_WITHFOLDER, 0X0F00107);
    Serial.println("changerV");
  }

  if (BlueT.read()=="j"){
    sendCommand(CMD_PLAY_WITHFOLDER, 0X0F00105); 
    Serial.println("changerJ");
  }

  if (BlueT.read()=="FIN"){
    sendCommand(CMD_PLAY_WITHVOLUME, 0X0F001);
    Serial.println("fin");
  }

 }

}
