#ifndef TOURNER_H
#define TOURNER_H
#include <LibRobus.h> // Essentielle pour utiliser RobUS
#include "avancer.h"


void TournerGauche(float degre){
  ENCODER_Reset(0);
  ENCODER_Reset(1);
  MOTOR_SetSpeed(0,0);
  float tournerSpeed2 = 0.1;
  float encodeurDroite;
  do{
    MOTOR_SetSpeed(1,tournerSpeed2);

    if (encodeurDroite > tourGauche*degre/90 - 200){
     if ( tournerSpeed2 > 0.1) tournerSpeed2 -= 0.01 ;
    }
    else if (tournerSpeed2 < .4) tournerSpeed2 += 0.01;
    encodeurDroite = ENCODER_Read(1);
    
    //Serial.println(roueDroite);
  }while(encodeurDroite < tourGauche*degre/90);
  Serial.println(tourGauche*degre/90);
  MOTOR_SetSpeed(0,0);
  MOTOR_SetSpeed(1,0);
    delay(100);
}

void TournerDroite(float degre){
  ENCODER_Reset(0);
  ENCODER_Reset(1);
  MOTOR_SetSpeed(0,0);
  float tournerSpeed2 = 0.1;
  float encodeurGauche;
  do{
    MOTOR_SetSpeed(0,tournerSpeed2);

    if (encodeurGauche > tourDroit*degre/90 - 200){
     if ( tournerSpeed2 > 0.1) tournerSpeed2 -= 0.01 ;
    }
    else if (tournerSpeed2 < .4) tournerSpeed2 += 0.01;
    encodeurGauche = ENCODER_Read(0);
    
    //Serial.println(roueDroite);
  }while(encodeurGauche < tourDroit*degre/90);
  Serial.println(tourDroit*degre/90);
  MOTOR_SetSpeed(0,0);
  MOTOR_SetSpeed(1,0);
  delay(100);
}

void TournerSurLui(float degre){
  ENCODER_Reset(0);
  ENCODER_Reset(1);
  tournerSpeed = .2;
  MOTOR_SetSpeed(0,-1*tournerSpeed*.95);
  MOTOR_SetSpeed(1,tournerSpeed);
  do{
    roueDroite = ENCODER_Read(1);
    roueGauche = ENCODER_Read(0);
    // if (roueDroite > tourDroit2 * degre/180 - 200){
    //  if ( tournerSpeed > 0.1) tournerSpeed -= 0.01 ;
    //   MOTOR_SetSpeed(0,-1*tournerSpeed*.95);
    //   MOTOR_SetSpeed(1,tournerSpeed);
    // }
    if (roueGauche < -1*tourGauche2*degre/180) MOTOR_SetSpeed(0,0);
    if (roueDroite > tourDroit2*degre/180) MOTOR_SetSpeed(1,0);
    //Serial.println(roueDroite);
  }while(roueDroite < tourDroit2 * degre/180 || roueGauche >-1* tourGauche2 * degre/180);
  //Serial.println(test*degre/180);
  MOTOR_SetSpeed(0,0);
  MOTOR_SetSpeed(1,0);
  delay(100);
}


#endif