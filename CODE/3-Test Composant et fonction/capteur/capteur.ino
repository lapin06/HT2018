const int capteur=3;

void setup() {
  pinMode(rouge,INPUT);

  Serial.begin(9600);
  // put your setup code here, to run once:

}

void loop() {
  if (capteur==HIGH){
    Serial.println("HIGH");
  }
  if (capteur=="LOW"){
    Serial.println("LOW");
  }
  // put your main code here, to run repeatedly:

}
