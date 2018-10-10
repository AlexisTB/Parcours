#ifndef TOURNERSURLUI_H
#define TOURNERSURLUI_H
#include <LibRobus.h> // Essentielle pour utiliser RobUS
#include "avancer.h"
#include "global.h"

//Fonction archivée
void TournerSurLui(float degre){
  ENCODER_Reset(0);
  ENCODER_Reset(1);

  float speed = tournerSpeedInit;

  do{
    //MOTOR_SetSpeed(0,speed);

    // if (roueGauche > tour*degre/90 - 800){
    //  if ( speed > 0.1) speed -= 0.05 ;
    // }
    // else if (speed < .4) speed += 0.005;
    MOTOR_SetSpeed(0,speed);
    MOTOR_SetSpeed(1,-1*speed);


    roueGauche = ENCODER_Read(0);
    roueDroite = ENCODER_Read(1) * rightBias;

    
    if (roueGauche > tour*degre/180 - 800){
     if ( speed > 0.1) speed -= 0.05 ;
     else speed = 0.1;
    }
    else if (speed < .4) speed += 0.005;

    if (roueGauche > test*degre/180) MOTOR_SetSpeed(0,0);
    if (-1*roueDroite > test*degre/180) MOTOR_SetSpeed(1,0);
    //Serial.println(roueDroite);
    delay(10);
  }while(roueGauche < test*degre/180 || -1 * roueDroite < test*degre/180);
  
  MOTOR_SetSpeed(0,0);
  MOTOR_SetSpeed(1,0);
  delay(100);
  
  Serial.println("FINI tourner sur lui");
  Serial.print("Gauche = ");
  Serial.print(roueGauche);
  Serial.print(" | théorique = ");
  Serial.println(test*degre/180);
  Serial.print("Droite = ");
  Serial.print(roueDroite);
  Serial.println(" | théorique = 0");

  errTotGauche = roueGauche - test*degre/180;
  errTotDroite = roueDroite - (-1*test*degre/180);
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