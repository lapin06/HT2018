const int bouton=13;

void setup() {
  pinMode(bouton,INPUT);
  Serial.begin(9600);
  // put your setup code here, to run once:

}

void loop() {
  
  if (digitalRead(bouton)==LOW){
  Serial.println("low");}
  if (digitalRead(bouton)==HIGH){
  Serial.println("HIGH");}
  // put your main code here, to run repeatedly:

}
