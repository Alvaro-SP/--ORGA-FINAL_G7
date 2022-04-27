#include <Separador.h>

const int s4 = 4;
const int s5 = 5;
const int s6 = 6;
const int s7 = 7;
const int s8 = 8;
const int s9 = 9;
const int s10 = 10;
const int s11 = 11;
const int s12 = 12;
const int s13 = 13;

String cadena = "";
String r1 = "";
String r2 = "";
String r3 = "";
String r4 = "";
String r5 = "";
String rSeis = "";

Separador s;

void setup()
{
  pinMode(s4,OUTPUT);
  pinMode(s5,OUTPUT);
  pinMode(s6,OUTPUT);
  pinMode(s7,OUTPUT);
  pinMode(s8, OUTPUT);
  pinMode(s9, OUTPUT);
  pinMode(s10, OUTPUT);
  pinMode(s11, OUTPUT);
  pinMode(s12, OUTPUT);
  pinMode(s13, OUTPUT);
  
  Serial.begin(9600);
}

void loop(){
  if(digitalRead(s6) == HIGH){
     Serial.println("11111");
     delay(20);
    }
  else if(digitalRead(s5) == HIGH){
     Serial.println("00000");
     delay(20);
    }
  else if(digitalRead(s5) == LOW){
    Serial.println("null");
    delay(20);
  }
  while(Serial.available())
  {
    reiniciar();
    
    cadena = Serial.readString();
    cadena.replace("\n", "");
    r1 =  s.separa(cadena,',',0);
    if(r1 == "0"){
      //Serial.println("Es para el tablero del jugador 1");
      digitalWrite (s8, HIGH);
      r2 =  s.separa(cadena,',',1);
      r3 =  s.separa(cadena,',',2);
      r4 =  s.separa(cadena,',',3);
      r5 =  s.separa(cadena,',',4);
      rSeis =  s.separa(cadena,',',5);
//      Serial.println("R2:"+r2);
//      Serial.println("R3:"+r3);
//      Serial.println("R4:"+r4);
//      Serial.println("R5:"+r5);
//      Serial.println("R6:"+rSeis+"comprobando");
      
      if(r2 == "1"){
        digitalWrite (s13, HIGH);
      }
      else{
        digitalWrite (s13, LOW);
      }
      if(r3 == "1"){
        digitalWrite (s12, HIGH);
      }
      else{
        digitalWrite (s12, LOW);
      }
      if(r4 == "1"){
        digitalWrite (s11, HIGH);
      }
      else{
        digitalWrite (s11, LOW);
      }
      if(r5 == "1"){
        digitalWrite (s10, HIGH);
      }
      else{
        digitalWrite (s10, LOW);
      }
      if(rSeis == "1"){
        digitalWrite (s9, HIGH);
      }
      else{
        digitalWrite (s9, LOW);
      }
      digitalWrite(s4,HIGH);
    }
    
    else if(r1 == "1"){
    digitalWrite (s7, HIGH);
    r2 =  s.separa(cadena,',',1);
    r3 =  s.separa(cadena,',',2);
    r4 =  s.separa(cadena,',',3);
    r5 =  s.separa(cadena,',',4);
    if(r2 == "1"){
        digitalWrite (s13, HIGH);
      }
      else{
        digitalWrite (s13, LOW);
      }
      if(r3 == "1"){
        digitalWrite (s12, HIGH);
      }
      else{
        digitalWrite (s12, LOW);
      }

      if(r4 == "1"){
        digitalWrite (s10, HIGH);
      }
      else{
        digitalWrite (s10, LOW);
      }
      if(r5 == "1"){
        digitalWrite (s9, HIGH);
      }
      else{
        digitalWrite (s9, LOW);
      }
      //para el enter
      digitalWrite(s4,HIGH);
    }
  }
  
  delay(100);
}

void reiniciar(){
  digitalWrite (s4, LOW);
  digitalWrite (s7, LOW);
  digitalWrite (s8, LOW);
  digitalWrite (s9, LOW);
  digitalWrite (s10, LOW);
  digitalWrite (s11, LOW);
  digitalWrite (s12, LOW);
  digitalWrite (s13, LOW);
  
}
