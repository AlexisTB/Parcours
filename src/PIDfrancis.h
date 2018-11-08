#ifndef AVANCER_H
#define AVANCER_H

#include <QTRSensors.h>
#include <LibRobus.h>
#include "global.h"

/*
Projet: Le nom du script
Equipe: Votre numero d'equipe
Auteurs: Les membres auteurs du script
Description: Breve description du script
Date: Derniere date de modification
*/

const int GAUCHE = 0 ; 
const int DROITE = 1 ;



void goInAStraightLineDammit(double p_vitesseCible, float p_distanceCible)
{
  const double TEMPS_ATTENTE = 100.0;
  const float P = 0.0045; 
  const float I = 0.215 ; 
  const float D = 0.00075 ; 
  double erreurI = 0 ; 

  MOTOR_SetSpeed(GAUCHE, p_vitesseCible/TICK_PAR_SECONDE_V_MAX);
  MOTOR_SetSpeed(DROITE, p_vitesseCible/TICK_PAR_SECONDE_V_MAX);

  int totalTickMaitre = 0 ;
  int totalTickEsclave = 0 ;

  int ancienTotalTickMaitre = 0 ;
  int ancienTotalTickEsclave = 0 ;

  ENCODER_ReadReset(GAUCHE);
  ENCODER_ReadReset(DROITE);

  float distanceCumule = 0 ; 
  float ancienneErreur = 0 ; 

  while(distanceCumule < p_distanceCible)
  {
    delay(TEMPS_ATTENTE);

    totalTickMaitre = ENCODER_Read (GAUCHE);
    totalTickEsclave = ENCODER_Read(DROITE);
    distanceCumule = CIRCONFERENCE * totalTickMaitre/TICK_PAR_TOUR;
    
    double erreurP = ((totalTickMaitre - ancienTotalTickMaitre)-(totalTickEsclave - ancienTotalTickEsclave))/TEMPS_ATTENTE;
    erreurI += (totalTickMaitre - ancienTotalTickMaitre)-(totalTickEsclave - ancienTotalTickEsclave) ; 
    double erreurD = erreurP - ancienneErreur;
    ancienneErreur = erreurP;

    ancienTotalTickEsclave = totalTickEsclave;
    ancienTotalTickMaitre = totalTickMaitre;

    MOTOR_SetSpeed(DROITE, p_vitesseCible + P * erreurP + I * erreurI/TEMPS_ATTENTE + D * erreurD*TEMPS_ATTENTE);
    Serial.println(erreurI);
  }
}

#endif 
