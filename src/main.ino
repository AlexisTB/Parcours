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
#include "tournersurlui.h"
#include "tournergauche.h"
#include "tournerdroite.h"
#include "fonctions.h"

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
  int errTot= 0; // accumulated error

  while(!ROBUS_IsBumper(3)){
    
  }

  //AvancerEnLigneDroiteInt(100);
  //Calibration();
  
  //TournerGauche(90);

  //AllerFuckingVite(200);

  //RebalancerGauche(35);

  //A
  Serial.println("A");
  AvancerEnLigneDroiteInt(210);  
  //B
  Serial.println("B");
  TournerGauche(90);
  AvancerEnLigneDroiteInt(35); 
  //C
  Serial.println("C");
  TournerDroite(90);   
  AvancerEnLigneDroiteInt(20);
  //D
  Serial.println("D");
  TournerDroite(90);
  AvancerEnLigneDroiteInt(25); 
  //E
  Serial.println("E");
  TournerGauche(90);
  AvancerEnLigneDroiteInt(15);//8
  //F
  Serial.println("F");
  TournerDroite(45);
  AvancerEnLigneDroiteInt(40);
  //G
  Serial.println("G");
  TournerGauche(90);
  AvancerEnLigneDroiteInt(60); //50
  //H
  Serial.println("H");
  TournerDroite(45);
  AvancerEnLigneDroiteInt(110);
  //I
  Serial.println("I");
  //AvancerEnLigneDroiteInt(50);
  //J 
  Serial.println("J");
  
  //FINIALLER
  //delay(20);
  TournerSurLui(180);

  //TEST
  // errTotDroite = 0;
  // errTotGauche = 0;
  delay(200);

  AvancerEnLigneDroiteInt(110);//76
  // I
  Serial.println("I");
  //AvancerEnLigneDroiteInt(31);
  //H
  Serial.println("H");
  TournerGauche(45);//50
  AvancerEnLigneDroiteInt(50);
  //G
  Serial.println("G");
  TournerDroite(90);
  AvancerEnLigneDroiteInt(37);
  //F
  Serial.println("F");
  TournerGauche(45);
  AvancerEnLigneDroiteInt(12);
  //E
  Serial.println("E");
  TournerDroite(90);
  AvancerEnLigneDroiteInt(25);
  //D
  Serial.println("D");
  TournerGauche(90);
  AvancerEnLigneDroiteInt(20);
  //C
  Serial.println("C");
  TournerGauche(90);
  AvancerEnLigneDroiteInt(25);
  //B
  Serial.println("B");
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

