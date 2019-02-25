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




String feutre(String r,String c,String stockr,String z,String R,int rouge){
  //Si le marqueur choisi est le rouge par exemple envoie la lettre rouge=r 
      if(digitalRead(rouge)==HIGH){
       delay(300);//car les capteurs sont sensibles
       delay(1000); //nombre aléatoire d'attente pour ne pas éveiller les soupçons
       //que la boite a feutre soit relier a celle du lapin 
       Serial.println("vous pouvez changer rapidement si vous voulez ?");
       BlueT.print(c);//texte relatif au rouge proposant un changement de feutre
       Serial.println(c);
       delay(20000);//attente durant le dialogue du lapin + quelques second pour
       //laicer changer le feutre si besoin
       if(digitalRead(rouge)==HIGH){// Si le feutre n'a pas été repossé
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
      
      //attend un peu une fois avoir appuyé sur le bouton discretement 
      //pour ne pas eveiller les soupçons
      delay(5000);
      
      //Envoie pret au deux boite puis fait allumer les leds par sécurité du fonctionnement
      BlueT.print("P");
      BlueT.print("\r\n");
      digitalWrite(led,LOW);
      delay(900);
      digitalWrite(led, HIGH);

     
  while (total<5){ //tant que tout les feutres n'ont pas été choisit, reste dans la boucle
  
  //Si le programme att car rien ne ce passe
  if((digitalRead(jaune)==LOW)&& (digitalRead(vert)==LOW)&&(digitalRead(rouge)==LOW)&& (digitalRead(bleu)==LOW)){
    delay(100);
    Serial.println("attend");
    attente=attente+1;
    if (attente==1000){//si attente trop longue alors diffuse un message
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

      feutre("r","c",stockr,"z","R",rouge);
      feutre("b","h",stockb,"y","B",bleu);
      feutre("v","a",stockv,"w","V",vert);
      feutre("j","n",stockj,"x","J",jaune);
  
      
 
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


  
    
 
