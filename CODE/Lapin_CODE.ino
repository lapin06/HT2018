#include<SoftwareSerial.h>
#define RX 5
#define TX 6
SoftwareSerial mySerial(RX,TX);

#define Arduino_RX 10
#define Arduino_TX 11
SoftwareSerial BlueT(Arduino_RX, Arduino_TX);

#include<Servo.h>;
Servo servo;
const int led_rouge=13;
char data="A";
const int bouton=7;
int val=0; 
int etat=1;
int ancien_val=1;
  
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

 servo.attach(2,544,2400);
 pinMode(led_rouge,OUTPUT);
 pinMode(bouton,INPUT);
 digitalWrite(led_rouge,HIGH);

}
 Serial.begin(9600);
 mySerial.begin(9600);
 delay(500); 
 sendCommand(CMD_SEL_DEV, DEV_TF);//select the TF card   
 delay(200);
 servo.write(180);
 delay(5000);
 servo.write(85);

 Serial.println("Bonjour, helo");
 BlueT.begin(38400);

}
void loop() {
  
  /* Bouton et servomoteur */
 val=digitalRead(bouton);  // val prend la valeur de l'état du bouton 
    if((val==LOW)&&(ancien_val==HIGH)){etat=1-etat; delay(20);} // si le bouton change d'état alors l'etat prend la valeur 1-état
  ancien_val=val; //on change la nouvelle valeur
  if(etat==HIGH){servo.write(180);digitalWrite(led_rouge,HIGH);delay(200);}
  if(etat==LOW){servo.write(85); digitalWrite(led_rouge,LOW);delay(200);}

while(BlueT.available()){
data=BlueT.read();
Serial.println(char(data));
  if (data == 'P') {
    Serial.print("P");
    digitalWrite(led_rouge,LOW);
    delay(2000);
    digitalWrite(led_rouge,HIGH);
    delay(5000);
    sendCommand(CMD_PLAY_WITHFOLDER, 0X0F00102);    
  }
  
 if (data == 'A') {
    Serial.print("A");
    sendCommand(CMD_PLAY_WITHFOLDER, 0X0F00101);
  }

 if (data == '2') {
    Serial.print("2");
    sendCommand(CMD_PLAY_WITHFOLDER, 0X0F00103);
  }

  if (data == 'z') {
    Serial.print("z");
    sendCommand(CMD_PLAY_WITHVOLUME, 0X0F007);
  }

  if (data == 'y') {
    Serial.println("y");
    sendCommand(CMD_PLAY_WITHFOLDER, 0X0F00108);
    }

  if (data == 'w') {
    Serial.println("w");
    sendCommand(CMD_PLAY_WITHVOLUME, 0X0F002);
  }

  if (data == 'x') {
    Serial.println("x");
    sendCommand(CMD_PLAY_WITHFOLDER, 0X0F00109); 
  }


 if (data == 'R') {
    Serial.println("R");
    sendCommand(CMD_PLAY_WITHVOLUME, 0X0F005); 
    
  }

 if (data == 'V') {
    Serial.println("V");
    sendCommand(CMD_PLAY_WITHVOLUME, 0X0F006); 
  
  }

  if (data == 'J') {
    Serial.println("J");
    sendCommand(CMD_PLAY_WITHVOLUME, 0X0F004); 
   
  }

  if (data == 'B') {
    Serial.println("B");
    sendCommand(CMD_PLAY_WITHVOLUME, 0X0F003);
    
  }

  
 if (data == 'c') {
    Serial.println("c");
    sendCommand(CMD_PLAY_WITHFOLDER, 0X0F00106);
    
  }

  if (data == 'h') {
     Serial.println("h");
     sendCommand(CMD_PLAY_WITHFOLDER, 0X0F00104);
   
  }

  if (data == 'a') {
    Serial.println("a");
    sendCommand(CMD_PLAY_WITHFOLDER, 0X0F00107);
    
  }

  if (data == 'n') {
   Serial.println("n");
   sendCommand(CMD_PLAY_WITHFOLDER, 0X0F00105); 
    
  }

  if (data == 'F') {
    Serial.println("F");
    sendCommand(CMD_PLAY_WITHVOLUME, 0X0F001);//play the first song with volume 15 class 
    delay(55200);
    Serial.println("////////////////"); 
   
    servo.write(180);
    delay(2000);
    Serial.println("musique finale");
    sendCommand(CMD_PLAY_WITHVOLUME, 0X0F008);
  }
}
}
