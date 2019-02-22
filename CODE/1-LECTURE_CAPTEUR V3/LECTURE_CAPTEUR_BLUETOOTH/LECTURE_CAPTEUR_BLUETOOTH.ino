//1.0: LECTURE DES CAPTEURS

#include<SoftwareSerial.h>
#define RX 11
#define TX 12
SoftwareSerial BlueT(RX,TX);

const int led=8;

const int bouton=14;
const int bouton2=15;

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
  pinMode(rouge,INPUT);
  pinMode(bleu,INPUT);
  pinMode(vert,INPUT);
  pinMode(jaune,INPUT);

  pinMode(led,OUTPUT);
  pinMode(bouton,INPUT);
  pinMode(bouton2,INPUT);

  digitalWrite(led,HIGH);
  
  Serial.begin(9600);
  Serial.println("EN ATTENTE");
  BlueT.begin(38400);
//  BlueT.print("En attente");
 // BlueT.print("\r\n");
}

  
void loop() { 
  if (digitalRead(bouton)==LOW){
    while(digitalRead(bouton)==HIGH){

  Serial.println("PRET");
  BlueT.print("P");
  BlueT.print("\r\n");
  digitalWrite(led,LOW);
  delay(900);
  digitalWrite(led, HIGH);
  
  delay(5000);
 
  while (total<5){
  
  //Si le programme att car rien ne ce passe
  if((digitalRead(jaune)==LOW)&& (digitalRead(vert)==LOW)&&(digitalRead(rouge)==LOW)&& (digitalRead(bleu)==LOW)){
    delay(100);
    Serial.println("attend");
    attente=attente+1;
    if (attente==1000){
      Serial.println("jattend prennez un nouveau feutre");
      BlueT.print("A");
      BlueT.print("\r\n");
      attente=0;
    }
  }




  //S'il se passe quelque chose, au moins un feutre a été retiré, alors:
  else{

     //verifions que deux marqueur ou plus non pas été pris, pas un petit spectateur coquin
     if((((digitalRead(jaune)==HIGH))&&((digitalRead(vert)==HIGH)||(digitalRead(rouge)==HIGH)||(digitalRead(bleu)==HIGH))) 
        ||(((digitalRead(bleu)==HIGH))&&((digitalRead(vert)==HIGH)||(digitalRead(rouge)==HIGH)||(digitalRead(jaune)==HIGH)))
        ||(((digitalRead(rouge)==HIGH))&&((digitalRead(vert)==HIGH)||(digitalRead(jaune)==HIGH)||(digitalRead(bleu)==HIGH)))
        ||(((digitalRead(vert)==HIGH))&&((digitalRead(jaune)==HIGH)||(digitalRead(rouge)==HIGH)||(digitalRead(bleu)==HIGH)))){
    Serial.println("deux");
    BlueT.print("2");
    BlueT.print("\r\n");
    
        //tant qu'ils ne les a pas reposer tous sanf 1 attend...
        while((((digitalRead(jaune)==HIGH))&&((digitalRead(vert)==HIGH)||(digitalRead(rouge)==HIGH)||(digitalRead(bleu)==HIGH))) 
        ||(((digitalRead(bleu)==HIGH))&&((digitalRead(vert)==HIGH)||(digitalRead(rouge)==HIGH)||(digitalRead(jaune)==HIGH)))
        ||(((digitalRead(rouge)==HIGH))&&((digitalRead(vert)==HIGH)||(digitalRead(jaune)==HIGH)||(digitalRead(bleu)==HIGH)))
        ||(((digitalRead(vert)==HIGH))&&((digitalRead(jaune)==HIGH)||(digitalRead(rouge)==HIGH)||(digitalRead(bleu)==HIGH)))){
       a="2";
       }
        }



        
     //Si un seul marqueur a été prit alors
     else{

      //Si le marqueur choisi est le rouge par exemple envoie la lettre rouge 
      if(digitalRead(rouge)==HIGH){
       delay(300);//car les capteurs sont sensibles
       a="r";
       Serial.println("vous pouvez changer rapidement si vous voulez ?");
       BlueT.print("c");
       Serial.println("c");
       delay(20000);
       if(digitalRead(rouge)==HIGH){
        BlueT.print(a);
        BlueT.print("\r\n");
        delay(5000);
        if(digitalRead(rouge)==HIGH){
        Serial.println("Je sais pas si vous avez changer mais bon continuons");
         //verification choix non deja pris juste avant
        String stockr2=a;
                if (stockr==stockr2){
                 Serial.println("petit coquin tu as deja prit ce feutre");
                 BlueT.print("z"); //si feutre rouge deja prit "deja"+"r"
                 BlueT.print("\r\n");
                 total=total-1;
                 while(digitalRead(rouge)==HIGH){
                  a="r";}}
                else{
                Serial.println("tout va bien");
                BlueT.print("R");
                BlueT.print("\r\n");
                stockr=stockr2;}
        //tant qu'il a le marqueur rouge on attend...attention s'il decide d'en prendre un autre apres le rouge, nous verrons ici qu'il en a prit deux!
        while((digitalRead(rouge)==HIGH)&&(digitalRead(vert)==LOW)&&(digitalRead(jaune)==LOW)&&(digitalRead(bleu)==LOW)){
        a="r";}
       }
       else{
        total=total-1;
       }
       
       }
    }


  
      if(digitalRead(bleu)==HIGH){
       delay(300);
       a="b";
       Serial.println(a);
       BlueT.print(a);
       BlueT.print("\r\n");
                String stockb2=a;
                if (stockb==stockb2){
                 Serial.println("petit coquin tu as deja prit ce feutre");
                 BlueT.print("y");
                 BlueT.print("\r\n");
                 total=total-1;
                 while(digitalRead(bleu)==HIGH){
                  a="v";}}
                else{
                Serial.println("tout va bien");
                BlueT.print("B");
                BlueT.print("\r\n");
                stockb=stockb2;}
                
      while((digitalRead(bleu)==HIGH)&&(digitalRead(vert)==LOW)&&(digitalRead(rouge)==LOW)&&(digitalRead(jaune)==LOW)){
      a="b";
  }



  
      }
      if(digitalRead(vert)==HIGH){
        delay(300);
        a="v";   
        Serial.println(a);       
        BlueT.print(a);
        BlueT.print("\r\n");
                 
                String stockv2=a;
                 
                if (stockv==stockv2){
                 Serial.println("petit coquin tu as deja prit ce feutre");
                 BlueT.print("w");
                 BlueT.print("\r\n");
                 total=total-1;
                 while(digitalRead(vert)==HIGH){
                  a="v";}}
                else{
                Serial.println("tout va bien");
                BlueT.print("V");
                BlueT.print("\r\n");
                stockv=stockv2;
                
                }
                
          
      while((digitalRead(vert)==HIGH)&&(digitalRead(bleu)==LOW)&&(digitalRead(rouge)==LOW)&&(digitalRead(jaune)==LOW)){
      a="v";}
  }




  
      if (digitalRead(jaune)==HIGH){
        delay(300);
      a="j";
      
      Serial.println(a); 
      BlueT.print(a);
      BlueT.print("\r\n");
     
                String stockj2=a;
                 
                if (stockj==stockj2){
                 Serial.println("petit coquin tu as deja prit ce feutre");
                 BlueT.print("x");
                 BlueT.print("\r\n");
                 total=total-1;
                 while(digitalRead(jaune)==HIGH){
                  a="j";}}
                else{
                Serial.println("tout va bien");
                BlueT.print("J");
                BlueT.print("\r\n");
                stockj=stockj2;}
      
      }
      while((digitalRead(jaune)==HIGH)&&(digitalRead(bleu)==LOW)&&(digitalRead(rouge)==LOW)&&(digitalRead(vert)==LOW)){
      a="j";
  }


 
   
  total=total+1;
  attente=0;
  Serial.println(total);
  Serial.println("nouveau feutre");
 // BlueT.print("NEW");
 // BlueT.print("\r\n");
  delay(800);


      
    }
    }
    
    
    
    if(total>3){
    Serial.println("Ouverture boite!");
    BlueT.print("F");
    BlueT.print("\r\n");
    while (total>3){
      a="prediction";
      delay;
   }
    }
    }
    }

  }
/*
  if (digitalRead(bouton2)==LOW){
    Serial.println("PRET2");
   
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
   //}
   */
  }

  
    
 
