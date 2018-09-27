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

/* ****************************************************************************
Variables globales et defines
**************************************************************************** */
// -> defines...
// L'ensemble des fonctions y ont acces
int roueDroite;
int roueGauche;
float avancerSpeed = 0.6;
float tournerSpeed = 0.2;
float diff= 0.05;
float ticParCM = 3200/(7.7*PI);
float tour = 4000;
int test = 4000;


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
  //A
  AvancerEnLigneDroite(200); 
  //B
  TournerGauche(90);
  AvancerEnLigneDroite(40);
  //C
  TournerDroite(90);   
  AvancerEnLigneDroite(30);
  //D
  TournerDroite(90);
  AvancerEnLigneDroite(30);
  //E
  TournerGauche(90);
  AvancerEnLigneDroite(8);
  //F
  TournerDroite(35);
  AvancerEnLigneDroite(50);
  //G
  TournerGauche(90);
  AvancerEnLigneDroite(45);
  //H
  TournerDroite(45);
  AvancerEnLigneDroite(50);
  //I
  TournerDroite(18);
  AvancerEnLigneDroite(50);
  //J
  TournerSurLui(1);
  // 
  
}


/* ****************************************************************************
Fonctions de boucle infini (loop())
**************************************************************************** */
// -> Se fait appeler perpetuellement suite au "setup"

void loop() {
  // SOFT_TIMER_Update(); // A decommenter pour utiliser des compteurs logiciels

  //roueGauche = ENCODER_Read(0);
  //Serial.print("Encodeur Gauche = ");
  //Serial.println(roueGauche);

  //roueDroite = ENCODER_Read(1);
  //Serial.print("Encodeur Droite = " );
  //Serial.println(roueDroite);

  delay(10);// Delais pour décharger le CPU
}

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
  MOTOR_SetSpeed(0,avancerSpeed);
  MOTOR_SetSpeed(1,avancerSpeed);
  do
  {
    roueGauche = ENCODER_Read(0);
    roueDroite = ENCODER_Read(1);
    
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
      //Serial.print("   Droite= ");
      //Serial.print(baseSpeed*(1));
      //Serial.print("  Gauche = ");
      //Serial.print(baseSpeed*(1));
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
