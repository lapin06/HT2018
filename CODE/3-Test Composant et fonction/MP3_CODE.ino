#include <SoftwareSerial.h> 

#define ARDUINO_RX 5//should connect to TX of the Serial MP3 Player module 
#define ARDUINO_TX 6//connect to RX of the module 
SoftwareSerial mySerial(ARDUINO_RX, ARDUINO_TX);
//init the serial protocol, tell to myserial wich pins are TX and RX 
char data="A";
//////////////////////////////////////////////////////////////////////////////////// 
//all the commands needed in the datasheet(http://geekmatic.in.ua/pdf/Catalex_MP3_board.pdf) 
static int8_t Send_buf[8] = {0} ;//The MP3 player undestands orders in a 8 int string 
                                //0X7E FF 06 command 00 00 00 EF;(if command =01 next song order)  
#define NEXT_SONG 0X01  
#define PREV_SONG 0X02  
#define CMD_PLAY_W_INDEX 0X03 //DATA IS REQUIRED (number of song) 
#define VOLUME_UP_ONE 0X04 
#define VOLUME_DOWN_ONE 0X05 
#define CMD_SET_VOLUME 0X06//DATA IS REQUIRED (number of volume from 0 up to 30(0x1E)) 
#define SET_DAC 0X17 
#define CMD_PLAY_WITHVOLUME 0X22 //data is needed  0x7E 06 22 00 xx yy EF;(xx volume)(yy number of song) 
#define CMD_SEL_DEV 0X09 //SELECT STORAGE DEVICE, DATA IS REQUIRED 
#define DEV_TF 0X02 //HELLO,IM THE DATA REQUIRED 
#define SLEEP_MODE_START 0X0A 
#define SLEEP_MODE_WAKEUP 0X0B 
#define CMD_RESET 0X0C//CHIP RESET 
#define CMD_PLAY 0X0D //RESUME PLAYBACK 
#define CMD_PAUSE 0X0E //PLAYBACK IS PAUSED 
#define CMD_PLAY_WITHFOLDER 0X0F//DATA IS NEEDED, 0x7E 06 0F 00 01 02 EF;(play the song with the directory \01\002xxxxxx.mp3 
#define STOP_PLAY 0X16 
#define PLAY_FOLDER 0X17// data is needed 0x7E 06 17 00 01 XX EF;(play the 01 folder)(value xx we dont care) 
#define SET_CYCLEPLAY 0X19//data is needed 00 start; 01 close 
#define SET_DAC 0X17//data is needed 00 start DAC OUTPUT;01 DAC no output 
//////////////////////////////////////////////////////////////////////////////////// 

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

void setup() 
{ 
  Serial.begin(9600);
mySerial.begin(9600);//Start our Serial coms for our serial monitor! 
delay(500);//Wait chip initialization is complete 
  sendCommand(CMD_SEL_DEV, DEV_TF);//select the TF card   
delay(200);//wait for 200ms 
} 

void loop() { 
  
if (Serial.available()) {  
  data = Serial.read();  
  Serial.println(char(data));
}  

if (data=='1') {
sendCommand(CMD_PLAY_WITHFOLDER, 0X0F00101);//play the first song with volume 15 class 
Serial.println("1");
data="0";
}

if (data=='2') {
sendCommand(CMD_PLAY_WITHFOLDER, 0X0F00102);//play the first song with volume 15 class 
Serial.println("2");
data="0";  
}

if (data=='3') {
sendCommand(CMD_PLAY_WITHFOLDER, 0X0F00103);//play the first song with volume 15 class 
Serial.println("3");
data="0";
}

if (data=='4') {
sendCommand(CMD_PLAY_WITHFOLDER, 0X0F00104);//play the first song with volume 15 class 
Serial.println("4");
data="0"; 
}
if (data=='5') {
sendCommand(CMD_PLAY_WITHFOLDER, 0X0F00105);//play the first song with volume 15 class 
Serial.println("5");
data="0";
}
if (data=='6') {
sendCommand(CMD_PLAY_WITHFOLDER, 0X0F00106);//play the first song with volume 15 class 
Serial.println("6");
data="0";
}
if (data=='7') {
sendCommand(CMD_PLAY_WITHFOLDER, 0X0F00107);//play the first song with volume 15 class 
Serial.println("7");
data="0";
}
if (data=='8') {
sendCommand(CMD_PLAY_WITHFOLDER, 0X0F00108);//play the first song with volume 15 class 
Serial.println("8");
data="0";
}
if (data=='9') {
sendCommand(CMD_PLAY_WITHFOLDER, 0X0F00109);//play the first song with volume 15 class 
Serial.println("9");
data="0";
}
if (data=='a') {
sendCommand(CMD_PLAY_WITHVOLUME, 0X0F001);//play the first song with volume 15 class 
Serial.println("fin");
data="0";
}
if (data=='b') {
sendCommand(CMD_PLAY_WITHVOLUME, 0X0F002);//play the first song with volume 15 class 
Serial.println("dejav");
data="0";
}
if (data=='c') {
sendCommand(CMD_PLAY_WITHVOLUME, 0X0F003);//play the first song with volume 15 class 
Serial.println("b");
data="0";
}
if (data=='d') {
sendCommand(CMD_PLAY_WITHVOLUME, 0X0F004);//play the first song with volume 15 class 
Serial.println("j");
data="0";
}
if (data=='e') {
sendCommand(CMD_PLAY_WITHVOLUME, 0X0F005);//play the first song with volume 15 class 
Serial.println("r");
data="0";
}
if (data=='f') {
sendCommand(CMD_PLAY_WITHVOLUME, 0X0F006);//play the first song with volume 15 class 
Serial.println("v");
data="0";
}
if (data=='g') {
sendCommand(CMD_PLAY_WITHVOLUME, 0X0F007);//play the first song with volume 15 class 
Serial.println("dejar");
data="0";
}
if (data=='h') {
sendCommand(CMD_PLAY_WITHVOLUME, 0X0F008);//play the first song with volume 15 class 
Serial.println("musique");
data="0";
} 
}
