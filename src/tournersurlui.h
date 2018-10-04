#ifndef TOURNERSURLUI_H
#define TOURNERSURLUI_H
#include <LibRobus.h> // Essentielle pour utiliser RobUS
#include "avancer.h"


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
    delay(10);
  }while(roueDroite < tourDroit2 * degre/180 || roueGauche >-1* tourGauche2 * degre/180);
  //Serial.println(test*degre/180);
  MOTOR_SetSpeed(0,0);
  MOTOR_SetSpeed(1,0);
  delay(100);
  Serial.println("FINI tourner sur lui");
  Serial.print("Gauche = ");
  Serial.print(roueGauche);
  Serial.print(" | théorique = ");
  Serial.println(-1* tourGauche2 * degre/180);
  Serial.print("Droite = ");
  Serial.print(roueDroite);
  Serial.print(" | théorique = ");
  Serial.println(tourDroit2 * degre/180);
}


#endif