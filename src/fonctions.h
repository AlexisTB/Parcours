#ifndef FONCTIONS_H
#define FONCTIONS_H
#include <LibRobus.h> // Essentielle pour utiliser RobUS
#include "avancer.h"
#include "global.h"

void Calibration(){
    MOTOR_SetSpeed(0,0.095);
    MOTOR_SetSpeed(1,0.1);

    ENCODER_Reset(0);
    ENCODER_Reset(1);
    
    do
    {
        roueDroite = ENCODER_Read(1);
        roueGauche = ENCODER_Read(0);
    } while (roueDroite < 1000);

    Serial.print("roueGauche = ");
    //bias = roueDroite/roueGauche;
    Serial.println(roueGauche);
    Serial.print("roueDroite = ");
    Serial.print(roueDroite);
    MOTOR_SetSpeed(0,0);
    MOTOR_SetSpeed(1,0);
}

void AllerFuckingVite(int cm){
  int sens = 1;
  if(cm<0) sens = -1;
  int32_t distance = abs(cm*ticParCM);
  float erreur;
  float sum=0;
  float erreurRatio = 500;
  float sumRatio = 1000000;
  ENCODER_Reset(0);
  ENCODER_Reset(1);
  avancerSpeed = 0.1;
  MOTOR_SetSpeed(0,sens *0.095*avancerSpeed);
  MOTOR_SetSpeed(1,sens *avancerSpeed);
  do
  {
    roueGauche = sens * ENCODER_Read(0);
    roueDroite = sens * ENCODER_Read(1);
    erreur = roueGauche - roueDroite;
    sum += erreur;
  
    if (avancerSpeed < 1) avancerSpeed += 0.1;//.02
    MOTOR_SetSpeed(0, sens * avancerSpeed*(1-erreur/erreurRatio -sum/sumRatio));
    MOTOR_SetSpeed(1, sens * avancerSpeed*(1+erreur/erreurRatio + sum/sumRatio));
    delay(100);
    if (roueGauche > distance) MOTOR_SetSpeed(0,0);
    if (roueDroite > distance) MOTOR_SetSpeed(1,0);

  } while (roueGauche < distance || roueDroite < distance);
  // delay(20);
  // MOTOR_SetSpeed(0,-.4);
  // MOTOR_SetSpeed(1,-.4);
  // delay(500);
  // MOTOR_SetSpeed(0,.6);
  // MOTOR_SetSpeed(1,.6);
  // delay(500);
  // MOTOR_SetSpeed(0,0);
  // MOTOR_SetSpeed(1,0);
}

void TesterTournants3(){
  //DÉBUT PARCOURS
  //A
  //B
  TournerGauche(90);
  //C
  TournerDroite(90);   
  //D
  TournerDroite(90);
  //E
  TournerGauche(90);
  //F
  TournerDroite(45);
  //G
  TournerGauche(90);
  //H
  TournerDroite(44.9);//55

  //I
  TournerDroite(12.5);

  //J 
  
  //FINIALLER
  delay(100);
  // TournerGauche(270);//180 homemade
  // TournerDroite(90);

  //I
  TournerDroite(-12.3);
  //H
  TournerDroite(-44.4);//55
  //G
  TournerGauche(-90);
  //F
  TournerDroite(-45);
  //E
  TournerGauche(-90);
  //D
  TournerDroite(-90);
  //C
  TournerDroite(-90);
  //B
  TournerGauche(-90);
  //A

}



#endif