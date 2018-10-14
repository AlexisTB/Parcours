#ifndef TOURNERGAUCHE_H
#define TOURNERGAUCHE_H
#include <LibRobus.h> // Essentielle pour utiliser RobUS
#include "avancer.h"
#include "rebalancer.h"
#include "global.h"

void TournerGauche(float degre){
  ENCODER_Reset(0);
  ENCODER_Reset(1);
  MOTOR_SetSpeed(0,0);
  int sens = 1;
  
  int32_t distance;
  if(degre<0) {
    sens = -1;
    distance = abs(tourGaucheInverse*degre/90);
  }
  else distance = abs(tourGauche*degre/90);

  float speed = tournerSpeedInit;

  do{
    MOTOR_SetSpeed(1,sens * speed);
    
    roueGauche = ENCODER_Read(0);
    roueDroite = sens * ENCODER_Read(1);

    if (roueDroite > distance - 800){
     if ( speed > 0.1) speed -= 0.02;
     else speed = 0.1;
    }
    else if (speed < .4) speed += 0.005;

    //Serial.println(roueDroite);
    delay(10);
  }while(roueDroite < distance);
  
  MOTOR_SetSpeed(0,0);
  MOTOR_SetSpeed(1,0);
  delay(100); //100

  Serial.println("FINI tourner gauche");
  Serial.print("Gauche = ");
  Serial.print(roueGauche);
  Serial.print(" | théorique = ");
  Serial.println(distance);
  Serial.print("Droite = ");
  Serial.print(roueDroite);
  Serial.println(" | théorique = 0");

  errTotGauche = roueGauche;
  errTotDroite = roueDroite - distance;
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