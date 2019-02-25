#include<Servo.h>;
Servo servo;
const int led_rouge=13;
const int bouton=7;
int val=0;
int etat=1;
int ancien_val=1;

void setup(){

  Serial.begin(9600);
  pinMode(led_rouge,OUTPUT);
  pinMode(bouton,INPUT);
  digitalWrite(led_rouge,LOW);
  servo.attach(2,544,2400);
  delay(2000);
}

void loop (){

  val=digitalRead(bouton);  
  Serial.print(val);
    if((val==LOW)&&(ancien_val==HIGH)){etat=1-etat; delay(20);}
  Serial.println("HIGH");
  ancien_val=val;
  if(etat==HIGH){servo.write(125);digitalWrite(led_rouge,HIGH);delay(200);}
  
  if (etat==LOW){servo.write(25); digitalWrite(led_rouge,LOW);delay(200);}
  Serial.println("LOW");
}
