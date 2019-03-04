//1.0: LECTURE DES CAPTEURS
// avec fonction
#include<SoftwareSerial.h>
#define RX 11
#define TX 12
SoftwareSerial BlueT(RX,TX);

const int led=8;

const int bouton=9;
const int bouton2=15;// version bonus

const int rouge=3;
const int bleu=4;
const int vert=5;
const int jaune=7;
String a;

String stockv="k";
String stockr="k";
String stockj="k";
String stockb="k";

int total=0;
int attente=0;

void setup() {
  // put your setup code here, to run once:
   pinMode(rouge,INPUT);
  pinMode(bleu,INPUT);
  pinMode(vert,INPUT);
  pinMode(jaune,INPUT);

  pinMode(led,OUTPUT);
  pinMode(bouton,INPUT);
  pinMode(bouton2,INPUT);//bonus

  digitalWrite(led,HIGH);
  
  Serial.begin(9600);
  BlueT.begin(38400);
  Serial.println("EN ATTENTE");//test si tout est operationel
  BlueT.print("$$$$$$$$$$$\r\n");

}

void loop() {
  // put your main code here, to run repeatedly:
 if (digitalRead(bouton)==LOW){
    Serial.println("PRET2");
    BlueT.println("*B");
    BlueT.println("*R");
    BlueT.println("*V");
    BlueT.println("*J");

 }
  if(digitalRead(bleu)==HIGH){ 
    BlueT.println("*B");
    
    }
  if(digitalRead(rouge)==HIGH){
    BlueT.println("*R");
    }
  if(digitalRead(vert)==HIGH){
    BlueT.println("*V");
    }
  if(digitalRead(jaune)==HIGH){
    BlueT.println("*J");
  }
  else{
    delay(10);
  }
}
