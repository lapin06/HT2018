// Test fonctionnalité LED et Bouton

const int led_rouge=13;
const int bouton=7;
int val=0;

void setup() {

  Serial.begin(9600);
  pinMode(led_rouge,OUTPUT);
  pinMode(bouton,INPUT);
  digitalWrite(led_rouge,LOW);
  delay(2000);
}

void loop() {

  val=digitalRead(bouton); // lecture de la valeur du bouton
  Serial.print(val);
  Serial.print("");
  if (val==HIGH){ // si le bouton n'est pas préssé alors la led est éteinte
    digitalWrite(led_rouge,HIGH);
    Serial.println("HIGH");
  }
  else {      // si le bouton est préssé la led s'allume
     digitalWrite(led_rouge,LOW);
     Serial.println("LOW");
  }
}
