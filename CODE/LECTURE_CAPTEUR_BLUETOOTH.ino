//1.0: LECTURE DES CAPTEURS

#include<SoftwareSerial.h>
#define RX 10
#define TX 11
SoftwareSerial BlueT(RX,TX);

const int led=8;
const int bouton=13;

const int rouge=6;
const int bleu=3;
const int vert=4;
const int jaune=5;
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

  digitalWrite(led,HIGH);
  
  Serial.begin(9600);
  Serial.println("EN ATTENTE");
  BlueT.begin(9600);
}

  
void loop() { 
  if (digitalRead(bouton)==LOW){
    while(digitalRead(bouton)==HIGH){

  Serial.println("PRET");
  digitalWrite(led,LOW);
  delay(900);
  digitalWrite(led, HIGH);
  
  delay(5000);
  BlueT.print("PRET");
  while (total<5){
  
  //Si le programme att car rien ne ce passe
  if((digitalRead(jaune)==LOW)&& (digitalRead(vert)==LOW)&&(digitalRead(rouge)==LOW)&& (digitalRead(bleu)==LOW)){
    delay(1000);
    Serial.println("attend");
    attente=attente+1;
    if (attente==100){
      Serial.println("jattend prennez un nouveau feutre");
      BlueT.print("ATTEND");
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
    BlueT.print("DEUX");
    total=total+1;
    
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
       
       Serial.println(a);
       Serial.println("vous pouvez changer rapidement si vous voulez ?");
       delay(5000);
       if(digitalRead(rouge)==HIGH){
        BlueT.print(a);
       
        Serial.println("Je sais pas si vous avez changer mais bon continuons");
         //verification choix non deja pris juste avant
        String stockr2=a;
                if (stockr==stockr2){
                 Serial.println("petit coquin tu as deja prit ce feutre");
                 BlueT.print("DEJAR"); //si feutre rouge deja prit "deja"+"r"
                 total=total-1;
                 while(digitalRead(rouge)==HIGH){
                  a="r";}}
                else{
                Serial.println("tout va bien");
                BlueT.print("OKR");
                stockr=stockr2;}
        //tant qu'il a le marqueur rouge on attend...attention s'il decide d'en prendre un autre apres le rouge, nous verrons ici qu'il en a prit deux!
        while((digitalRead(rouge)==HIGH)&&(digitalRead(vert)==LOW)&&(digitalRead(jaune)==LOW)&&(digitalRead(bleu)==LOW)){
        a="r";}
       }
       else{
        total=total-1;
       }
  }


  
      if(digitalRead(bleu)==HIGH){
       delay(300);
       a="b";
       Serial.println(a);
       BlueT.print(a);
                String stockb2=a;
                if (stockb==stockb2){
                 Serial.println("petit coquin tu as deja prit ce feutre");
                 BlueT.print("DEJAB");
                 total=total-1;
                 while(digitalRead(bleu)==HIGH){
                  a="v";}}
                else{
                Serial.println("tout va bien");
                BlueT.print("OKB");
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
                 
                String stockv2=a;
                 
                if (stockv==stockv2){
                 Serial.println("petit coquin tu as deja prit ce feutre");
                 BlueT.print("DEJAV");
                 total=total-1;
                 while(digitalRead(vert)==HIGH){
                  a="v";}}
                else{
                Serial.println("tout va bien");
                BlueT.print("OKV");
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
     
                String stockj2=a;
                 
                if (stockj==stockj2){
                 Serial.println("petit coquin tu as deja prit ce feutre");
                 BlueT.print("DEJAJ");
                 total=total-1;
                 while(digitalRead(jaune)==HIGH){
                  a="j";}}
                else{
                Serial.println("tout va bien");
                BlueT.print("OKJ");
                stockj=stockj2;}
      
      }
      while((digitalRead(jaune)==HIGH)&&(digitalRead(bleu)==LOW)&&(digitalRead(rouge)==LOW)&&(digitalRead(vert)==LOW)){
      a="j";
  }


 
   
  total=total+1;
  attente=0;
  Serial.println(total);
  Serial.println("nouveau feutre");
  BlueT.print("NEW");
  delay(800);


      
    }
    }
    
    
    
    if(total>3){
    Serial.println("Ouverture boite!");
    BlueT.print("FIN");
    while (total>3){
      a="prediction";
      delay;
   }
    }
    }
    }

  }
}
  
    
 
