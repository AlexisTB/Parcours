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
<<<<<<< HEAD
int roueDroite;
int roueGauche;
float avancerSpeed;
float baseSpeed = 0.2;
float topSpeed = 0.6;
float tournerSpeed = 0.6;
float diff= 0.05;
float ticParCM = 3200/(7.7*PI);
float tour = 4000;
int test = 4000;
=======
>>>>>>> testDroite


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
<<<<<<< HEAD
  

  
  //CODE ALLER
  
=======
  int errTot= 0; // accumulated error

  while(!ROBUS_IsBumper(3)){
    
  }

  //AvancerEnLigneDroiteInt(100);
  //Calibration();
  
  //TournerGauche(90);

  //AllerFuckingVite(200);

  //RebalancerGauche(35);

>>>>>>> testDroite
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
<<<<<<< HEAD
  TournerDroite(35);
  AvancerEnLigneDroite(38);
=======
  Serial.println("F");
  TournerDroite(45);
  AvancerEnLigneDroiteInt(40);
>>>>>>> testDroite
  //G
  Serial.println("G");
  TournerGauche(90);
<<<<<<< HEAD
  AvancerEnLigneDroite(55);
=======
  AvancerEnLigneDroiteInt(60); //50
>>>>>>> testDroite
  //H
  Serial.println("H");
  TournerDroite(45);
  AvancerEnLigneDroiteInt(110);
  //I
<<<<<<< HEAD
  TournerDroite(14);
  AvancerEnLigneDroite(50);
  //J
  TournerSurLui(1);
  // 
=======
  Serial.println("I");
  //AvancerEnLigneDroiteInt(50);
  //J 
  Serial.println("J");
>>>>>>> testDroite
  
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

<<<<<<< HEAD
void TournerGauche(float degre){
  ENCODER_Reset(0);
  ENCODER_Reset(1);
  MOTOR_SetSpeed(0,0);
  MOTOR_SetSpeed(1,tournerSpeed);
  do{
    roueDroite = ENCODER_Read(1);
    //Serial.println(roueDroite);
  }while(roueDroite < tour*degre/90);
  Serial.println(tour*degre/90);
  MOTOR_SetSpeed(0,0);
  MOTOR_SetSpeed(1,0);
}

void TournerDroite(float degre){
  ENCODER_Reset(0);
  ENCODER_Reset(1);
  MOTOR_SetSpeed(0,tournerSpeed);
  MOTOR_SetSpeed(1,0);
  do{
    roueGauche = ENCODER_Read(0);
    //Serial.println(roueGauche);
  }while(roueGauche < tour*degre/90);
  //Serial.println("fini tourner");
  MOTOR_SetSpeed(0,0);
  MOTOR_SetSpeed(1,0);
}

void AvancerEnLigneDroite(int cm){
  int distance = cm*ticParCM;
  ENCODER_Reset(0);
  ENCODER_Reset(1);
  avancerSpeed = baseSpeed;
  MOTOR_SetSpeed(0,avancerSpeed);
  MOTOR_SetSpeed(1,avancerSpeed);

  do
  {
    roueGauche = ENCODER_Read(0);
    roueDroite = ENCODER_Read(1);
    
    Serial.print("avancerSpeed = ");
    Serial.print(avancerSpeed); 
    
    if (roueGauche >( distance - (8 * ticParCM)))
    {
      if(avancerSpeed>baseSpeed) avancerSpeed -= 0.05;   
    }
     else if (avancerSpeed < topSpeed)
    {
      avancerSpeed += 0.02;
    } 

 
    
     

    if(abs(roueGauche-roueDroite)<10) diff = 0.05;
    else if (abs(roueGauche-roueDroite)<100) diff = 0.25;
    else diff = 0.5;

    
    if (roueGauche > roueDroite) {
      MOTOR_SetSpeed(0,avancerSpeed*(1-diff));
      MOTOR_SetSpeed(1,avancerSpeed*(1+diff));
      //Serial.print("   Droite= ");
      //Serial.print(baseSpeed*(1+diff));
      //Serial.print("  Gauche = ");
      //Serial.print(baseSpeed*(1-diff));

    }
    else if (roueDroite > roueGauche) {
      MOTOR_SetSpeed(0,avancerSpeed*(1+diff));
      MOTOR_SetSpeed(1,avancerSpeed*(1-diff));
      //Serial.print("   Droite= ");
      //Serial.print(baseSpeed*(1-diff));
      //Serial.print("  Gauche = ");
      //Serial.print(baseSpeed*(1+diff));
    } 
    else
    {
      MOTOR_SetSpeed(0,avancerSpeed);
      MOTOR_SetSpeed(1,avancerSpeed);
      Serial.print("   Droite= ");
      Serial.print(baseSpeed*(1));
      Serial.print("  Gauche = ");
      Serial.print(baseSpeed*(1));
    }
    //Serial.println();
    Serial.println(roueGauche);
  } while (roueGauche < distance && roueDroite < distance);
  Serial.print("FINI avancer");
  MOTOR_SetSpeed(0,0);
  MOTOR_SetSpeed(1,0);
   
}

void TournerSurLui(float degre){
  ENCODER_Reset(0);
  ENCODER_Reset(1);
  MOTOR_SetSpeed(0,-tournerSpeed);
  MOTOR_SetSpeed(1,tournerSpeed);
  do{
    roueDroite = ENCODER_Read(1);
    roueGauche = ENCODER_Read(0);
    //Serial.println(roueDroite);
  }while(roueDroite < test);
  Serial.println(tour*degre/90);
  MOTOR_SetSpeed(0,0);
  MOTOR_SetSpeed(1,0);
}
=======
>>>>>>> testDroite
