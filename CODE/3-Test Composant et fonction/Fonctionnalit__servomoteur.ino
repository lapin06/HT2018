// Tester la fonctionnalité du servomoteur
#include<Servo.h>;
Servo servo;

void setup(){
  servo.attach(2,544,2400);

  
}

void loop (){
  servo.write(125);
  delay(2000);
  servo.write(10);
  delay(2000);
  
}
