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
  //Lancement du tour si on appuie sur le bouton
  if (digitalRead(bouton)==LOW){
    while(digitalRead(bouton)==HIGH){//des que le bouton a été 
      //relaché les enregistrements commencent
      
      
      Serial.println("PRET");
      BlueT.print("P");
      BlueT.print("\r\n");
      delay(1000);
      digitalWrite(led,LOW);
      delay(900);
      digitalWrite(led, HIGH);
      delay(4000);
      //attend un peu une fois avoir appuyé sur le bouton discretement 
      //pour ne pas eveiller les soupçons
      
      //Envoie pret au deux boite puis fait allumer les leds par sécurité du fonctionnement
      

     
  while (total<5){ //tant que tout les feutres n'ont pas été choisit, reste dans la boucle
  
  //Si le programme att car rien ne ce passe
  if((digitalRead(jaune)==LOW)&& (digitalRead(vert)==LOW)&&(digitalRead(rouge)==LOW)&& (digitalRead(bleu)==LOW)){
    delay(100);
    Serial.println("attend");
    attente=attente+1;
    if (attente==8000){//si attente trop longue alors diffuse un message
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



        
     //Si un seul marqueur a été prit alors le programme général se lance
     else{

      //Si le marqueur choisi est le rouge par exemple envoie la lettre rouge=r 
      if(digitalRead(rouge)==HIGH){
       delay(300);//car les capteurs sont sensibles
       a="r";
       delay(3000); //nombre aléatoire d'attente pour ne pas éveiller les soupçons
       //que la boite a feutre soit relier a celle du lapin 
       Serial.println("vous pouvez changer rapidement si vous voulez ?");
       BlueT.print("c");//texte relatif au rouge proposant un changement de feutre
       Serial.println("c");
       delay(27000);//attente durant le dialogue du lapin + quelques second pour
       //laicer changer le feutre si besoin
       if(digitalRead(rouge)==HIGH){// Si le feutre n'a pas été repossé
        BlueT.print(a);//texte faisant semblant de ne pas savoir, continuant sur le rouge
        BlueT.print("\r\n");
        Serial.println("Pas changé");
        //verification choix non deja pris juste avant
        String stockr2=a;
                if (stockr==stockr2){//si deja pris
                 Serial.println("deja");
                 BlueT.print("z"); //si feutre rouge deja prit "deja"+"r"
                 BlueT.print("\r\n");
                 total=total-1;
                 while(digitalRead(rouge)==HIGH){
                    a="r";}}
                 else{//si jamais pris
                    Serial.println("tout va bien");
                    BlueT.print("R");
                    BlueT.print("\r\n");
                    stockr=stockr2;}
        //tant qu'il a le marqueur rouge on attend...attention s'il decide d'en prendre un autre apres le rouge, nous verrons ici qu'il en a prit deux!
        while((digitalRead(rouge)==HIGH)&&(digitalRead(vert)==LOW)&&(digitalRead(jaune)==LOW)&&(digitalRead(bleu)==LOW)){
        a="r";
        }
       }
       else{//Si le feutre a été reposé entre temps 
        total=total-1;
       }
       
       }
    


  
      if(digitalRead(bleu)==HIGH){
       delay(2500);
       a="b";
       Serial.println("vous pouvez changer rapidement si vous voulez ?");
       BlueT.print("h");
       Serial.println("h");
       delay(28000);
       if(digitalRead(bleu)==HIGH){
        BlueT.print(a);
        BlueT.print("\r\n");
        Serial.println("pas changé");
        delay(5000);
        String stockb2=a;
        if (stockb==stockb2){
          Serial.println("deja");
          BlueT.print("y");
          BlueT.print("\r\n");
          total=total-1;
          while(digitalRead(bleu)==HIGH){
            a="b";
          }
        }
        else{
          Serial.println("tout va bien");
          BlueT.print("B");
          BlueT.print("\r\n");
          stockb=stockb2;
        }
               
      while((digitalRead(bleu)==HIGH)&&(digitalRead(vert)==LOW)&&(digitalRead(rouge)==LOW)&&(digitalRead(jaune)==LOW)){
      a="b";
      }
     }
      else{
        total= total-1;
      }
    }






    
      
      if(digitalRead(vert)==HIGH){
        delay(2500);
        a="v";   
        Serial.println("vous pouvez changer rapidement si vous voulez ?");
        BlueT.print("a");
        Serial.println("a");
        delay(26000);
        if (digitalRead(vert)==HIGH){
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
        else{
          total=total-1;
        }
      }




  
      if (digitalRead(jaune)==HIGH){
        delay(3000);
        a="j";
       Serial.println("vous pouvez changer rapidement si vous voulez ?");
       BlueT.print("n");
       Serial.println("n");
       delay(20000);
       if (digitalRead(jaune)==HIGH){
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
                stockj=stockj2;
                }
      
       
      while((digitalRead(jaune)==HIGH)&&(digitalRead(bleu)==LOW)&&(digitalRead(rouge)==LOW)&&(digitalRead(vert)==LOW)){
      a="j";
     }
      }
      else{
        total=total-1;
      }
  }


 
  //Pour chaque feutre choisi 
  total=total+1;
  attente=0;
  Serial.println(total);
  Serial.println("nouveau feutre");
  delay(800);


      
    }
    }
    
    
    
    if(total>3){//Si tous les feutre on été pris 
    Serial.println("Ouverture boite!");
    BlueT.print("F");
    BlueT.print("\r\n");
    delay(20000000);
    while (total>3){//att une fois le tour fini par securité
      a="prediction";
      delay;
   }
    }
    }
    }
  }
}
/*
public String feutre(r,c,stockr,z,R){
  //Si le marqueur choisi est le rouge par exemple envoie la lettre rouge=r 
      if(digitalRead(r)==HIGH){
       delay(300);//car les capteurs sont sensibles
       delay(1000); //nombre aléatoire d'attente pour ne pas éveiller les soupçons
       //que la boite a feutre soit relier a celle du lapin 
       Serial.println("vous pouvez changer rapidement si vous voulez ?");
       BlueT.print(c);//texte relatif au rouge proposant un changement de feutre
       Serial.println(c);
       delay(20000);//attente durant le dialogue du lapin + quelques second pour
       //laicer changer le feutre si besoin
       if(digitalRead(r)==HIGH){// Si le feutre n'a pas été repossé
        BlueT.print(r);//texte faisant semblant de ne pas savoir, continuant sur le rouge
        BlueT.print("\r\n");
        Serial.println("Pas changé");
        //verification choix non deja pris juste avant
        String stockr2=r;
                if (stockr==stockr2){//si deja pris
                 Serial.println("deja");
                 BlueT.print(z); //si feutre rouge deja prit "deja"+"r"
                 BlueT.print("\r\n");
                 total=total-1;
                 while(digitalRead(rouge)==HIGH){
                    a="r";}}
                 else{//si jamais pris
                    Serial.println("tout va bien");
                    BlueT.print(R);
                    BlueT.print("\r\n");
                    stockr=stockr2;}
        //tant qu'il a le marqueur rouge on attend...attention s'il decide d'en prendre un autre apres le rouge, nous verrons ici qu'il en a prit deux!
        while((digitalRead(rouge)==HIGH)&&(digitalRead(vert)==LOW)&&(digitalRead(jaune)==LOW)&&(digitalRead(bleu)==LOW)){
        r="r";
        }
       }
       else{//Si le feutre a été reposé entre temps 
        total=total-1;
       }
       
       }
    
}
*/
  
/*
 * 
 * --------------------Parttie Bonus ---------------------------- *
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


  
    
 
