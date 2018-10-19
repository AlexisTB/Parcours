#ifndef REBALANCER_H
#define REBALANCER_H
#include <LibRobus.h> // Essentielle pour utiliser RobUS
#include "global.h"


int RebalancerGauche(int distance){
  ENCODER_Reset(0);
  ENCODER_Reset(1);
  int sens = 1;
  if(distance < 0) sens = -1;
  do
  {
    roueGauche = ENCODER_Read(0);
    roueDroite = ENCODER_Read(1);
  
    MOTOR_SetSpeed(0, sens*.1);
    MOTOR_SetSpeed(1, 0);

  } while (roueGauche * sens < sens * distance);

  // Serial.print("roueGauche = ");
  // Serial.println(roueGauche);

  MOTOR_SetSpeed(0, 0);
  MOTOR_SetSpeed(1, 0);
  return roueGauche;
}

int RebalancerDroite(int distance){
  ENCODER_Reset(0);
  ENCODER_Reset(1);
  int sens = 1;
  if(distance < 0) sens = -1;
  do
  {
    roueGauche = ENCODER_Read(0);
    roueDroite = ENCODER_Read(1);
  
    MOTOR_SetSpeed(0, sens*.1);
    MOTOR_SetSpeed(1, sens*.1);

  } while (roueDroite * sens < sens * distance);

  // Serial.print("roueDroite = ");
  // Serial.println(roueDroite);

  MOTOR_SetSpeed(0, 0);
  MOTOR_SetSpeed(1, 0);
  return roueDroite;
}

#endif