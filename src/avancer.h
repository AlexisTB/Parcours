#ifndef AVANCER_H
#define AVANCER_H
#include <LibRobus.h> // Essentielle pour utiliser RobUS
#include "rebalancer.h"
#include "global.h"
#include "tournersurlui.h"

void Depogner(){
  MOTOR_SetSpeed(0, -.2);
  MOTOR_SetSpeed(1, -.2);
  delay(1000);
  TournerSurLui(130);
  ENCODER_Reset(0);
  ENCODER_Reset(1);
}

void AvancerEnLigneDroiteInt(float cm){
  int distance = cm*ticParCM;
  int distanceGauche = distance; //- errTotGauche;
  int distanceDroite = distance; //- errTotDroite;

  float erreur;
  float sum=0;
  //float erreurRatio = 10000;
  float sumRatio = 10000000000;
  ENCODER_Reset(0);
  ENCODER_Reset(1);
  avancerSpeed = 0.2; // 0.05
  MOTOR_SetSpeed(0,avancerSpeed);
  MOTOR_SetSpeed(1,avancerSpeed);
  do
  {
    roueGauche = ENCODER_Read(0);
    roueDroite = ENCODER_Read(1)*rightBias;
    erreur = roueGauche - roueDroite;
    sum += erreur;
    
    if(roueGauche > 3200/4) avancerSpeed = 0.5;
    // if (roueGauche > distanceGauche - 1000){
    //  if ( avancerSpeed > 0.11) avancerSpeed -= 0.05 ;
    // }
    // else if (avancerSpeed < .6) avancerSpeed += 0.005;
    
    if (erreur < 10) diff = 0.05;
    else if (erreur < 100) diff = 0.25;
    else diff = .5;

    // MOTOR_SetSpeed(0, avancerSpeed*(1-erreur/erreurRatio -sum/sumRatio));
    // MOTOR_SetSpeed(1, avancerSpeed*(1+erreur/erreurRatio + sum/sumRatio));

    if (erreur<0) {
      MOTOR_SetSpeed(0, avancerSpeed*(1+diff - sum/sumRatio));
      MOTOR_SetSpeed(1, avancerSpeed*(1-diff + sum/sumRatio));
    } 
    else if (erreur>0)
    {
      MOTOR_SetSpeed(0, avancerSpeed*(1-diff  -sum/sumRatio));
      MOTOR_SetSpeed(1, avancerSpeed*(1+diff  +sum/sumRatio));
    } 
    else
    {
      MOTOR_SetSpeed(0, avancerSpeed*1 -sum/sumRatio);
      MOTOR_SetSpeed(1, avancerSpeed*1 +sum/sumRatio);
    }

    Serial.print("erreur = ");
    Serial.print(erreur);
    Serial.print("sum = ");
    Serial.print(sum);
    Serial.println("");
    delay(10);
    if (roueGauche > distanceGauche) MOTOR_SetSpeed(0,0);
    if (roueDroite > distanceDroite) MOTOR_SetSpeed(1,0);

  } while (roueGauche < distanceGauche || roueDroite < distanceDroite);
  errTotGauche = roueGauche - distanceGauche;
  errTotDroite = roueDroite - distanceDroite;
  Serial.println("FINI avancer, spped finale = ");
  Serial.println(avancerSpeed);
  Serial.print("théorique = ");
  Serial.println(distance);
  Serial.print("Gauche = ");
  Serial.println(roueGauche);
  Serial.print("Droite = ");
  Serial.println(roueDroite);
  Serial.print("ERREUR TOT = gauche:");
  Serial.print(errTotGauche);
  Serial.print(" droite:");
  Serial.println(errTotDroite);
  MOTOR_SetSpeed(0,0);
  MOTOR_SetSpeed(1,0);
  delay(100);
}

void AvancerEnLigneDroite(float cm){
  int sens = 1;
  float cheat = 1;//0.9438;
  if(cm<0) sens = -1;
  int32_t distance = abs(cm*ticParCM);
  int32_t distanceGauche = distance; //- errTotGauche;
  int32_t distanceDroite = distance; //- errTotDroite;

  int erreur;
  ENCODER_Reset(0);
  ENCODER_Reset(1);
  avancerSpeed = 0.05; // 0.05
  do
  {
    roueGauche = sens * ENCODER_Read(0);
    roueDroite = sens * ENCODER_Read(1)*rightBias;
    erreur = roueGauche - roueDroite;

    //accélération / décelération
    if (roueDroite > distanceGauche - 1500){ //1500
     if ( avancerSpeed > 0.11) avancerSpeed -= 0.02;
     else avancerSpeed = 0.1;
    }
    else if (avancerSpeed < .6) avancerSpeed += 0.005;
    
    
    // if (erreur < 10) diff = 0.05;
    // else if (erreur < 100) diff = 0.25;
    // else diff = .5;
    

    if (erreur<0) {
      MOTOR_SetSpeed(0, sens *cheat* avancerSpeed*(1+diff));
      MOTOR_SetSpeed(1, sens * avancerSpeed*(1-diff));
    } 
    else if (erreur>0)
    {
      MOTOR_SetSpeed(0, sens * cheat * avancerSpeed*(1-diff));
      MOTOR_SetSpeed(1, sens * avancerSpeed*(1+diff));
    } 
    else
    {
      MOTOR_SetSpeed(0, sens * cheat *avancerSpeed*1);
      MOTOR_SetSpeed(1, sens * avancerSpeed*1);
    }
    
    delay(10);
    if (roueGauche > distanceGauche) MOTOR_SetSpeed(0,0);
    if (roueDroite > distanceDroite) MOTOR_SetSpeed(1,0);
    // Serial.print("erreur = ");
    // Serial.println(erreur);
  } while (roueGauche < distanceGauche || roueDroite < distanceDroite);
  errTotGauche = roueGauche - distanceGauche;
  errTotDroite = roueDroite - distanceDroite;
  Serial.print("FINI avancer, speed finale = ");
  Serial.println(avancerSpeed);
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
  MOTOR_SetSpeed(0,0);
  MOTOR_SetSpeed(1,0);
  delay(10); //100
}

void AvancerEnLigneDroite2(float cm){
  int sens = 1;
  float cheat = 1;//0.9438;
  if(cm<0) sens = -1;
  int32_t distance = abs(cm*ticParCM);
  int32_t distanceGauche = distance; //- errTotGauche;
  int32_t distanceDroite = distance; //- errTotDroite;

  int erreur;
  ENCODER_Reset(0);
  ENCODER_Reset(1);
  avancerSpeed = 0.05; // 0.05
  do
  {
    roueGauche = sens * ENCODER_Read(0);
    roueDroite = sens * ENCODER_Read(1)*rightBias;
    erreur = roueGauche - roueDroite;

    //accélération / décelération
   if (avancerSpeed < .8) avancerSpeed += 0.01;
    
    
    // if (erreur < 10) diff = 0.05;
    // else if (erreur < 100) diff = 0.25;
    // else diff = .5;
    

    if (erreur<0) {
      MOTOR_SetSpeed(0, sens *cheat* avancerSpeed*(1+diff));
      MOTOR_SetSpeed(1, sens * avancerSpeed*(1-diff));
    } 
    else if (erreur>0)
    {
      MOTOR_SetSpeed(0, sens * cheat * avancerSpeed*(1-diff));
      MOTOR_SetSpeed(1, sens * avancerSpeed*(1+diff));
    } 
    else
    {
      MOTOR_SetSpeed(0, sens * cheat *avancerSpeed*1);
      MOTOR_SetSpeed(1, sens * avancerSpeed*1);
    }
    
    delay(10);
    if (roueGauche > distanceGauche) MOTOR_SetSpeed(0,0);
    if (roueDroite > distanceDroite) MOTOR_SetSpeed(1,0);
    // Serial.print("erreur = ");
    // Serial.println(erreur);
  } while (roueGauche < distanceGauche );//|| roueDroite < distanceDroite);
  // errTotGauche = roueGauche - distanceGauche;
  // errTotDroite = roueDroite - distanceDroite;
  // Serial.print("FINI avancer, speed finale = ");
  // Serial.println(avancerSpeed);
  // Serial.print("REBALANCAGE: g= ");
  // Serial.print(errTotGauche);
  // Serial.print(" | d= ");
  // Serial.println(errTotDroite);
  // errTotDroite += RebalancerDroite(-1*errTotDroite);
  // errTotGauche += RebalancerGauche(-1*errTotGauche);

  // Serial.print("ERREUR TOT = gauche:");
  // Serial.print(errTotGauche);
  // Serial.print(" droite:");
  // Serial.println(errTotDroite);
  MOTOR_SetSpeed(0,0);
  MOTOR_SetSpeed(1,0);
  delay(10); //100
}


void AvancerEnPingouin(int cm){
  int32_t goal = cm * ticParCM;
  int32_t distance = 0;
  do
  {
    distance += RebalancerDroite(100);
    distance += RebalancerGauche(100);
  } while (distance < goal);
  
}

#endif