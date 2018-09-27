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
float baseSpeed = 0.2;
float diff= 0.05;
float tour = 4000;


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
  AvancerEnLigneDroite(4000); 
  TournerDroite(90);
  AvancerEnLigneDroite(1500);
  TournerGauche(180);   
  AvancerEnLigneDroite(3000);
  TournerGauche(180);
  AvancerEnLigneDroite(1500);
  TournerDroite(90);
  AvancerEnLigneDroite(4000);
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
  MOTOR_SetSpeed(1,baseSpeed);
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
  MOTOR_SetSpeed(0,baseSpeed);
  MOTOR_SetSpeed(1,0);
  do{
    roueGauche = ENCODER_Read(0);
    //Serial.println(roueGauche);
  }while(roueGauche < tour*degre/90);
  //Serial.println("fini tourner");
  MOTOR_SetSpeed(0,0);
  MOTOR_SetSpeed(1,0);
}

void AvancerEnLigneDroite(int distance){
  ENCODER_Reset(0);
  ENCODER_Reset(1);
  MOTOR_SetSpeed(0,baseSpeed);
  MOTOR_SetSpeed(1,baseSpeed);
  do
  {
    roueGauche = ENCODER_Read(0);
    roueDroite = ENCODER_Read(1);
    
    if(abs(roueGauche-roueDroite)<10) diff = 0.05;
    else if (abs(roueGauche-roueDroite)<100) diff = 0.25;
    else diff = 0.5;

    if (roueGauche > roueDroite) {
      MOTOR_SetSpeed(0,baseSpeed*(1-diff));
      MOTOR_SetSpeed(1,baseSpeed*(1+diff));
      //Serial.print("   Droite= ");
      //Serial.print(baseSpeed*(1+diff));
      //Serial.print("  Gauche = ");
      //Serial.print(baseSpeed*(1-diff));

    }
    else if (roueDroite > roueGauche) {
      MOTOR_SetSpeed(0,baseSpeed*(1+diff));
      MOTOR_SetSpeed(1,baseSpeed*(1-diff));
      //Serial.print("   Droite= ");
      //Serial.print(baseSpeed*(1-diff));
      //Serial.print("  Gauche = ");
      //Serial.print(baseSpeed*(1+diff));
    } 
    else
    {
      MOTOR_SetSpeed(0,baseSpeed);
      MOTOR_SetSpeed(1,baseSpeed);
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