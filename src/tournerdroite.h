#ifndef TOURNERDROITE_H
#define TOURNERDROITE_H
#include <LibRobus.h> // Essentielle pour utiliser RobUS
#include "avancer.h"
#include "rebalancer.h"
#include "global.h"


void TournerDroite(float degre){
  ENCODER_Reset(0);
  ENCODER_Reset(1);
  MOTOR_SetSpeed(0,0);
  int sens = 1;

  int32_t distance;
  if(degre<0) {
    sens = -1;
    distance = abs(tourDroitInverse*degre/90);
  }
  else distance = abs(tourDroit*degre/90);

  float speed = tournerSpeedInit;

  do{
    MOTOR_SetSpeed(0,sens * speed);
    
    roueGauche = sens * ENCODER_Read(0);
    roueDroite = ENCODER_Read(1);

    if (roueGauche > distance - 800){
     if ( speed > 0.1) speed -= 0.02;
     else speed = 0.1;
    }
    else if (speed < .4) speed += 0.005;

    //Serial.println(roueDroite);
    delay(10);
  }while(roueGauche < distance);
  
  MOTOR_SetSpeed(0,0);
  MOTOR_SetSpeed(1,0);
  delay(100); //100

  Serial.print("FINI tourner droite, speed finale = ");
  Serial.println(speed);
  Serial.print("Gauche = ");
  Serial.print(roueGauche);
  Serial.print(" | théorique = ");
  Serial.println(distance);
  Serial.print("Droite = ");
  Serial.print(roueDroite);
  Serial.println(" | théorique = 0");

  errTotGauche = roueGauche - distance;
  errTotDroite = roueDroite;
  Serial.print("REBALANCAGE: g= ");
  Serial.print(errTotGauche);
  Serial.print(" | d= ");
  Serial.println(errTotDroite);
  errTotDroite += RebalancerDroite(-1*errTotDroite);
  errTotGauche += RebalancerGauche(-1*errTotGauche);
  Serial.print("ERREUR TOT = gauche:");
  Serial.print(errTotGauche);
  Serial.print(" droite:");
  Serial.println(errTotDroite);
}

#endif