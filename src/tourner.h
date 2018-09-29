#ifndef TOURNER_H
#define TOURNER_H
#include <LibRobus.h> // Essentielle pour utiliser RobUS
#include "avancer.h"


void TournerGauche(float degre){
  ENCODER_Reset(0);
  ENCODER_Reset(1);
  MOTOR_SetSpeed(0,0);
  MOTOR_SetSpeed(1,tournerSpeed);
  do{
    roueDroite = ENCODER_Read(1);
    //Serial.println(roueDroite);
  }while(roueDroite < tour*degre/90);
  Serial.println(tour*degre/90);
  MOTOR_SetSpeed(0,0);
  MOTOR_SetSpeed(1,0);
}

void TournerDroite(float degre){
  ENCODER_Reset(0);
  ENCODER_Reset(1);
  MOTOR_SetSpeed(0,tournerSpeed);
  MOTOR_SetSpeed(1,0);
  do{
    roueGauche = ENCODER_Read(0);
    //Serial.println(roueGauche);
  }while(roueGauche < tour*degre/90);
  //Serial.println("fini tourner");
  MOTOR_SetSpeed(0,0);
  MOTOR_SetSpeed(1,0);
}

void TournerSurLui(float degre){
  ENCODER_Reset(0);
  ENCODER_Reset(1);
  MOTOR_SetSpeed(0,-.2);
  MOTOR_SetSpeed(1,.2);
  do{
    roueDroite = ENCODER_Read(1);
    roueGauche = ENCODER_Read(0);
    if (roueGauche < -1*tourGauche*degre/90) MOTOR_SetSpeed(0,0);
    if (roueDroite > tourDroit*degre/90) MOTOR_SetSpeed(1,0);
    //Serial.println(roueDroite);
  }while(roueDroite < tourDroit * degre/90 || roueGauche <-1* tourGauche * degre/90);
  Serial.println(test*degre/180);
  MOTOR_SetSpeed(0,0);
  MOTOR_SetSpeed(1,0);
}


#endif