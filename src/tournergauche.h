#ifndef TOURNERGAUCHE_H
#define TOURNERGAUCHE_H
#include <LibRobus.h> // Essentielle pour utiliser RobUS
#include "avancer.h"

void TournerGauche(float degre){
  ENCODER_Reset(0);
  ENCODER_Reset(1);
  MOTOR_SetSpeed(0,0);
  float tournerSpeed2 = 0.1;
  float encodeurDroite;
  //tourGauche = tourGauche - errTotGauche + errTotDroite;
  do{
    MOTOR_SetSpeed(1,tournerSpeed2);

    if (encodeurDroite > tourGauche*degre/90 - 800){
     if ( tournerSpeed2 > 0.1) tournerSpeed2 -= 0.05;
    }
    else if (tournerSpeed2 < .4) tournerSpeed2 += 0.005;
    encodeurDroite = ENCODER_Read(1);
    delay(10);
    //Serial.println(roueDroite);
  }while(encodeurDroite < tourGauche*degre/90);
  MOTOR_SetSpeed(0,0);
  MOTOR_SetSpeed(1,0);
  roueGauche = ENCODER_Read(0);
  roueDroite = ENCODER_Read(1);
  delay(100);
  //errTotDroite = roueDroite - tourGauche*degre/90;
  //errTotGauche = roueGauche;
  Serial.println("FINI tourner gauche");
  Serial.print("Gauche = ");
  Serial.print(roueGauche);
  Serial.println(" | théorique = 0");
  Serial.print("Droite = ");
  Serial.print(roueDroite);
  Serial.print(" | théorique = ");
  Serial.println(tourGauche*degre/90);
}

#endif