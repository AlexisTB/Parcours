#ifndef PIDFRANCIS_H
#define PIDFRANCIS_H

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
const double CENTRE = 3500 ;
const int NB_SENSORS = 8 ; 
#define NUM_SAMPLES_PER_SENSOR  4  // average 4 analog samples per sensor reading
#define EMITTER_PIN QTR_NO_EMITTER_PIN  // emitter is controlled by digital pin 2


void ligneDroite(double p_vitesseCible)
{
  
  
  unsigned char valeursCapteurs[NB_SENSORS] {0,1,2,3,4,5,6,7};
  unsigned int valeurSensors[NB_SENSORS] {0,0,0,0,0,0,0,0};
  QTRSensorsAnalog capteurs(valeursCapteurs , NB_SENSORS,NUM_SAMPLES_PER_SENSOR,EMITTER_PIN);
  for (int i = 0; i < 100; i++)  // make the calibration take about 10 seconds
  {
    capteurs.calibrate();       // reads all sensors 10 times at 2.5 ms per six sensors (i.e. ~25 ms per call)
  }

  const double TEMPS_ATTENTE = 100.0;
  const double P = 0.000048;// 0.00004
  const double I = 0.00000032 ; //0.0000002
  const double D = 0.000075 ; //0.000025
  double erreurI = 0 ; 
  float ancienneErreur = 0 ; 

  MOTOR_SetSpeed(GAUCHE, p_vitesseCible);
  MOTOR_SetSpeed(DROITE, p_vitesseCible);



  while(true)
  {

    delay(TEMPS_ATTENTE);
    int position = capteurs.readLine(valeurSensors);
    Serial.println(position); 

    double erreurP = position - CENTRE;
    erreurI += erreurP  ; 
    double erreurD = erreurP - ancienneErreur;
    ancienneErreur = erreurP;

    MOTOR_SetSpeed(DROITE, p_vitesseCible + P * erreurP + I * erreurI + D * erreurD);
  }
 }

#endif 
