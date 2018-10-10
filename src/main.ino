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
#include "run.h"
#include "run2.h"
#include "run3.h"


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


  //Avancer2(4000);

  // //calibrer les tournants
  // for(int i = 0; i < 4; i++)
  // {
  //   //RebalancerDroite(tourGauche);
  //   //RebalancerGauche(tourDroit);
  //   //TournerDroite(-44.4); //-44.4
  //   //TournerGauche(44.8); //44.8
  //   //TournerSurLui(180);
  //   // TournerDroite(12.5);
  //   // delay(500);
  //   // TournerDroite(-12.3);
  //   // delay(500);
  // }

  //TesterTournants2();

  // AvancerEnLigneDroite(200);
  // AvancerEnLigneDroite(-200);
  //TournerSurLui(180);
  // TournerGauche(90);//180 homemade
  // TournerGauche(90);//180 homemade
  // TournerGauche(90);//180 homemade
  // TournerDroite(90);
  //AvancerEnLigneDroite(180);

  //AvancerEnPingouin(400);
  

  //Calibration();
  //TournerGauche(-90);
  //TournerDroite(-90);
  //AllerFuckingVite(-200);
  //RebalancerGauche(35);

  //TesterTournants3();
  Run3();
  //RebalancerGauche(-100);
  //RebalancerDroite(-6);
}

void TesterTournants(){
  //Tous les tournants du parcours sans les lignes droites
  TournerGauche(90);
  delay(500);
  TournerDroite(90); 
  delay(500);
  TournerDroite(90);
  delay(500);
  TournerGauche(90);
  delay(500);
  TournerDroite(45);
  delay(500);
  TournerGauche(90);
  delay(500);
  TournerDroite(45);
  delay(500);
  TournerGauche(270);//180 homemade
  delay(500); 
  TournerDroite(90); // =180 homemade
  delay(500);
  TournerGauche(45);//50
  delay(500);
  TournerDroite(90);
  delay(500);
  TournerGauche(45);
  delay(500);
  TournerDroite(90);
  delay(500);
  TournerGauche(90);
  delay(500);
  TournerGauche(90);
  delay(500);
  TournerDroite(90);
  delay(500);
}

void TesterTournants2(){
  TournerGauche(90);
  delay(500);
  TournerGauche(90);
  delay(500);
  TournerGauche(90);
  delay(500);
  TournerGauche(90);
  delay(500);

  TournerDroite(90);
  delay(500);
  TournerDroite(90);
  delay(500);
  TournerDroite(90);
  delay(500);
  TournerDroite(90);
  delay(500);

  TournerGauche(-90);
  delay(500);
  TournerGauche(-90);
  delay(500);
  TournerGauche(-90);
  delay(500);
  TournerGauche(-90);
  delay(500);

  TournerDroite(-90);
  delay(500);
  TournerDroite(-90);
  delay(500);
  TournerDroite(-90);
  delay(500);
  TournerDroite(-90);
  delay(500);
  
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
  TournerDroite(44.4);//55

  //I
  //TournerDroite(12.5);

  //J 
  
  //FINIALLER
  delay(100);
  // TournerGauche(270);//180 homemade
  // TournerDroite(90);

  //I
  //TournerDroite(-12.5);
  //H
  TournerDroite(-45);//55
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


/* ****************************************************************************
Fonctions de boucle infini (loop())
**************************************************************************** */
// -> Se fait appeler perpetuellement suite au "setup"

void loop() {
  // SOFT_TIMER_Update(); // A decommenter pour utiliser des compteurs logiciels
  delay(10);// Delais pour décharger le CPU
}

