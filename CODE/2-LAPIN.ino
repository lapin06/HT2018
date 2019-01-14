//LAPIN
#include<SoftwareSerial.h>
#define RX 2
#define TX 3
SoftwareSerial BlueT(RX, TX);

const int led=4;

void setup() {
 Serial.begin(9600);
 Serial.println("Bonjour, helo");
 BlueT.begin(38400);
 pinMode(led, OUTPUT);
 
 digitalWrite(led,LOW);
 Serial.println("LOW");
 delay(900);
 digitalWrite(led,HIGH);
 
  // put your setup code here, to run once:

}

void loop() {
  
  while(BlueT.available()){
    Serial.print(char(BlueT.read()));}
    while(Serial.available()){
      BlueT.write(char(Serial.read()));
  
  if (BlueT.read() == "PRET") {
    digitalWrite(led,LOW);
    delay(900);
    digitalWrite(led,HIGH);
    //BONJOUR TOUT LE MONDE ! je suis magicduino je suis ici pour vous eblouir, monsieur ou madame j'espere que vous etes ouvert d'esprit car je vais lire dans votre esprit. Je sais que je peux faire peur avec ma
    // petite voix de robots mais n'aillez crainte...je suis bien meilleur qu'eu(merci c'est gentil pour nous)Derien. Pour commencez veuillez prendre le dessin en noir et blanc  et montrer le de maniere elegante
    //Wouaou vous faites une super belle assistante, vous etes libre ce soir ? (wow calmos magicduino) "sifflement" , bon repornons. Pour commencer veuillez choisir un feutre avec elegence.
  }
  
  if (BlueT.read()=="ATTEND"){
    //vous avez le droit de vous depecher si vous voulez
  }
  
  if (BlueT.read()=="DEUX"){
    //VOUS AVEZ DONC CHOISIT UN FEUTRE, EUU ATTENDAIT JE SENS QUELQUE CHOSE
    //VOUS ESSAYEZ DE ME DUPER VOUS AVEZ PRIX DEUX FEUTRES! je suis un lapin mais je suis pas stupide je m'appelle pas helo ou theo
  }

  
  if (BlueT.read()=="DEJAR"){
    //maitenant que vous avez choisi un feutre vous allez...euu attendez a MOINS QUE VOUS SOYEZ UN PEU BEBTE VOUS VEZ DEJA colorié alors reposé le et prenez en un autre
  }
  if (BlueT.read()=="DEJAB"){
    //c'est un tres bon choix pour colorié , mais dommage que vous l'aillez deja pris ! alors reporsez moi ce stylo je ne suis pas debile.
  }
  if (BlueT.read()=="DEJAV"){
    //Vous allez a present prendre le feutre et leveé le bras en l'aire , allez-y , oui allez-y et mainteant faite un tour sur vous meme, vraiment, voila c'était juste pour vou spunir car vous avez deja pris ce feutre!!!
    //reposez le et prenez en un autre !
  }
  if (BlueT.read()=="DEJAJ"){
    //j'imagine que c'est bon vous avez choisi un feutre , je ne vois rien dans cette boite...bon maintenant je vais vous demander gentillement de le remettre a sa place parceque vous etes vous aussi un escro vous avez deja pris ce feutre !!!
  }


  if (BlueT.read()=="r"){
  }
  if (BlueT.read()=="v"){
  }
  if (BlueT.read()=="j"){
  }
  if (BlueT.read()=="b"){
  }

  
  if (BlueT.read()=="OKR"){
  }
  if (BlueT.read()=="OKB"){
  }
  if (BlueT.read()=="OKV"){
  }
  if (BlueT.read()=="OKJ"){
  }

  
  if (BlueT.read()=="FIN"){
  }
  }
}
      // put your main code here, to run repeatedly:
