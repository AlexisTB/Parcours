/*
Projet: Le nom du script
Equipe: Votre numero d'equipe
Auteurs: Les membres auteurs du script
Description: Breve description du script
Date: Derniere date de modification
*/

/* ****************************************************************************
Inclure les librairies de functions que vous voulez utiliser
**************************************************************************** */

#include <LibRobus.h> // Essentielle pour utiliser RobUS
#include "avancer.h"
#include "tourner.h"

/* ****************************************************************************
Variables globales et defines
**************************************************************************** */
// -> defines...
// L'ensemble des fonctions y ont acces


/* ****************************************************************************
Vos propres fonctions sont creees ici
**************************************************************************** */
void maFonction(){
  // code
}


/* ****************************************************************************
Fonctions d'initialisation (setup)
**************************************************************************** */
// -> Se fait appeler au debut du programme
// -> Se fait appeler seulement un fois
// -> Generalement on y initilise les varibbles globales

void setup(){
  BoardInit();
  //MOTOR_SetSpeed(0,baseSpeed); //0.093
  //MOTOR_SetSpeed(1,baseSpeed);
  ENCODER_Reset(0);
  ENCODER_Reset(1);
  Serial.begin(9600);
  
  //AvancerEnLigneDroiteInt(200);
  //Calibration();
  //TournerSurLui(180);
  //TournerDroit(90);
  //TournerGauche(90);

  //A
  AvancerEnLigneDroiteInt(200);  
  //B
  TournerGauche(90);
  AvancerEnLigneDroiteInt(35); //40
  //C
  TournerDroite(90);   
  AvancerEnLigneDroiteInt(20);
  //D
  TournerDroite(90);
  AvancerEnLigneDroiteInt(25); //30
  //E
  TournerGauche(90);
  AvancerEnLigneDroiteInt(8);
  //F
  TournerDroite(45);
  AvancerEnLigneDroiteInt(40);
  //G
  TournerGauche(90);
  AvancerEnLigneDroiteInt(55); //50
  //H
  TournerDroite(50);//45
  AvancerEnLigneDroiteInt(100);//50
  //I
  //TournerDroite(12.5);
  //AvancerEnLigneDroiteInt(50);
  //J 
  
  //FINIALLER
  //delay(20);
  TournerSurLui(180);
  //delay(20);

  AvancerEnLigneDroiteInt(107);//76
  // I
  //TournerGauche(12.5);
  //AvancerEnLigneDroiteInt(31);
  //H
  TournerGauche(55);//50
  AvancerEnLigneDroiteInt(50);
  //G
  TournerDroite(90);
  AvancerEnLigneDroiteInt(37);
  //F
  TournerGauche(45);
  AvancerEnLigneDroiteInt(12);
  //E
  TournerDroite(90);
  AvancerEnLigneDroiteInt(25);
  //D
  TournerGauche(90);
  AvancerEnLigneDroiteInt(20);
  //C
  TournerGauche(90);
  AvancerEnLigneDroiteInt(25);
  //B
  TournerDroite(90);
  //A
  AllerFuckingVite(200);

}


/* ****************************************************************************
Fonctions de boucle infini (loop())
**************************************************************************** */
// -> Se fait appeler perpetuellement suite au "setup"

void loop() {
  // SOFT_TIMER_Update(); // A decommenter pour utiliser des compteurs logiciels
  delay(10);// Delais pour décharger le CPU
}

