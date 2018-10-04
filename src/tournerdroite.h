#ifndef TOURNERDROITE_H
#define TOURNERDROITE_H
#include <LibRobus.h> // Essentielle pour utiliser RobUS
#include "avancer.h"

void TournerDroite(float degre){
  ENCODER_Reset(0);
  ENCODER_Reset(1);
  MOTOR_SetSpeed(0,0);
  float tournerSpeed2 = 0.1;
  float encodeurGauche;
  //tourDroit = tourDroit - errTotDroite + errTotGauche;
  do{
    MOTOR_SetSpeed(0,tournerSpeed2);

    if (encodeurGauche > tourDroit*degre/90 - 800){
     if ( tournerSpeed2 > 0.1) tournerSpeed2 -= 0.05 ;
    }
    else if (tournerSpeed2 < .4) tournerSpeed2 += 0.005;
    encodeurGauche = ENCODER_Read(0);
    
    //Serial.println(roueDroite);
    delay(10);
  }while(encodeurGauche < tourDroit*degre/90);
  roueGauche = ENCODER_Read(0);
  roueDroite = ENCODER_Read(1);
  MOTOR_SetSpeed(0,0);
  MOTOR_SetSpeed(1,0);
  delay(100);
  //errTotDroite = roueDroite;
  //errTotGauche = roueGauche - tourDroit*degre/90;
  Serial.println("FINI tourner droite");
  Serial.print("Gauche = ");
  Serial.print(roueGauche);
  Serial.print(" | théorique = ");
  Serial.println(tourDroit*degre/90);
  Serial.print("Droite = ");
  Serial.print(roueDroite);
  Serial.println(" | théorique = 0");
}

#endif