/*
Projet: Le nom du script
Equipe: Votre numero d'equipe
Auteurs: Les membres auteurs du script
Description: Breve description du script
Date: Derniere date de modification
*/

/* ****************************************************************************
Librairies de functions
**************************************************************************** */

#include <LibRobus.h> 
#include <ADJDS311.h> //Libraire capteur de couleur
#include "avancer.h"
#include "tournersurlui.h"
#include "tournergauche.h"
#include "tournerdroite.h"
#include "fonctions.h"
#include "run.h"
#include "run2.h"
#include "run3.h"
#include "suivreligne.h"
#include "capteurcouleur.h"
#include "detecterballe.h"
#include "areneun.h"
#include "arenedeux.h"
#include "detecteursifflet.h"

/* ****************************************************************************
Variables globales et defines
**************************************************************************** */
int16_t outputIR;
float voltage;
float distance;
int tempsGlobal = 0;
float c;

/* ****************************************************************************
Fonctions
**************************************************************************** */

void FonctionTestTempsGlobal(){

  Serial.print("temps = ");
  Serial.println(tempsGlobal);
  tempsGlobal++;

}


/* ****************************************************************************
Fonctions d'initialisation
**************************************************************************** */
// -> Se fait appeler au debut du programme
// -> Se fait appeler seulement un fois

void setup(){

  BoardInit();
  ENCODER_Reset(0);
  ENCODER_Reset(1);
  Serial.begin(9600);

  SERVO_Enable(0);
  SERVO_SetAngle(0,140);
  //SERVO_Disable(0);

  InitCapteurCouleur();
  //SOFT timage
  // SOFT_TIMER_SetCallback(0,&FonctionTestTempsGlobal);
  // SOFT_TIMER_SetDelay(0,1000);
  // SOFT_TIMER_SetRepetition(0,-1);
  // SOFT_TIMER_Enable(0);


  while(!ROBUS_IsBumper(3)){
    //wait for rear bumper to be pressed
  }
  //AX_BuzzerON(5000,200);
}

/* ****************************************************************************
Fonctions de boucle infini (loop())
**************************************************************************** */

void loop() {

  //SOFT_TIMER_Update(); // A decommenter pour utiliser des compteurs logiciels 

  /* *****************
   // Code du goaler
     **************** */
     
  // Avancer en ligne droite et revenir de 2 cm.
  // MOTOR_SetSpeed(0,.1);
  // MOTOR_SetSpeed(1,.1);
  // delay(500);
  // MOTOR_SetSpeed(0,-.1);
  // MOTOR_SetSpeed(1,-.1);
  // delay(500);

  //DetecterCouleur();
  //analog read
  // Serial.print("3= ");
  // Serial.print(analogRead(3));
  // Serial.print(" | 2= ");
  // Serial.print(analogRead(6));
  // Serial.print(" | 6= ");
  // Serial.print(analogRead(7));
  // Serial.print(" | 7= ");
  // Serial.println(analogRead(PIN_LIGNE));
//  Serial.print("v = ");
//  Serial.print(AX_GetVoltage());
//  Serial.print("  |  I = ");
//   c = AX_GetCurrent();
//   if (c > .85)  AX_BuzzerON(10000,200);
//   Serial.print(c);
//   Serial.println();
  
//DetecterCouleur();
  //if (DetecterBalleAlexis() == 1) Serial.print("BALLE : ");
  //DetecterCouleur();  
  //SuivreLigne();
  AreneDeux();
  //ScanBalle();
  // while(!ROBUS_IsBumper(3)){
  //   //wait for rear bumper to be pressed
  // }
  // if (SuivreBalle() == 1){
  //   AX_BuzzerON(1000,200);
  // } 
  // else
  // {
  //   MOTOR_SetSpeed(0,0);
  //   MOTOR_SetSpeed(1,0);
  // }
  
  //MonitorDetecteurLigne();
  // MOTOR_SetSpeed(0,.2);
  // MOTOR_SetSpeed(1,.2);
  //MonitorInfrarouge();
  //MonitorSifflet();
  //DetecteurSifflet();
  delay(10);// Delais pour décharger le CPU

}

