#ifndef DETECTEURSIFFLET_H
#define DETECTEURSIFFLET_H
#include <LibRobus.h>

#define PIN_SIFFLET 0
#define PIN_AMBIANT 1
#define MAX_AMP 500
float ampAmbiant;
float amp5khz;
int duree = 0;


void DetecteurSifflet(){
      
  ampAmbiant = analogRead(PIN_AMBIANT);
  //Serial.print("bruit ambiant= ");
  //Serial.print(ampAmbiant);
  amp5khz = analogRead(PIN_SIFFLET);
  //Serial.print("  |  5Hz= ");
  //Serial.println(amp5khz);
  //MOTOR_SetSpeed(0,.1);
  //MOTOR_SetSpeed(1,.1);

  if (amp5khz > MAX_AMP) {
    //Serial.println("CRISS ARRÊTE");
    duree++;
    //MOTOR_SetSpeed(0,0);
    //MOTOR_SetSpeed(1,0);
    if (duree == 50) {
      //MOTOR_SetSpeed(0,0);
      //MOTOR_SetSpeed(1,0);
      Serial.println("5KHz détecté");
      delay(10000);
    }
  } else {
    duree = 0;
    //Serial.println("c'est chill lgros");
  }
}

void MonitorSifflet(){
    ampAmbiant = analogRead(PIN_AMBIANT);
    Serial.print("bruit ambiant= ");
    Serial.print(ampAmbiant);
    amp5khz = analogRead(PIN_SIFFLET);
    Serial.print("  |  5Hz= ");
    Serial.println(amp5khz);
}

#endif