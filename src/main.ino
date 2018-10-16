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

int16_t outputIR;
float voltage;
float distance;
float freq1;
float freq2;
int tempsGlobal = 0;
int duree = 0;
/* ****************************************************************************
Variables globales et defines
**************************************************************************** */
// -> defines...
// L'ensemble des fonctions y ont acces
void FonctionTestTempsGlobal(){
  Serial.print("temps = ");
  Serial.println(tempsGlobal);
  tempsGlobal++;

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

  //SOFT timage

  // SOFT_TIMER_SetCallback(0,&FonctionTestTempsGlobal);
  // SOFT_TIMER_SetDelay(0,1000);
  // SOFT_TIMER_SetRepetition(0,-1);
  // SOFT_TIMER_Enable(0);

  //SERVO_Enable(0);

  // while(!ROBUS_IsBumper(3)){
    
  // }

  //AvancerEnLigneDroite(30);

  /*SERVOMOTEUR
  // for(int i = 0; i < 5; i++)
  // {
  //   delay(1000);
  //   SERVO_SetAngle(0, 180);
  //   delay(1000);
  //   SERVO_SetAngle(0, 0);
  // }
  // SERVO_Disable(0);
  */

  //Avancer2(4000);

  // //calibrer les tournants
  // for(int i = 0; i < 8; i++)
  // {
  //   //RebalancerDroite(tourGauche);
  //   //RebalancerGauche(tourDroit);
  //   TournerDroite(10); //-44.4
    
  //   TournerDroite(-9.5); //44.8
  //   //TournerSurLui(180);
  //   // TournerDroite(12.5);
  //   // delay(500);
  //   // TournerDroite(-12.3);
  //   delay(500);
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
  //Run3();
  //RebalancerGauche(-100);
  //RebalancerDroite(-6);
}





/* ****************************************************************************
Fonctions de boucle infini (loop())
**************************************************************************** */
// -> Se fait appeler perpetuellement suite au "setup"

void loop() {
  //SOFT_TIMER_Update(); // A decommenter pour utiliser des compteurs logiciels
  //outputIR = ROBUS_ReadIR(0);
  //voltage = outputIR/790;
  
  
  //DÉTECTEUR DE SIFFLET
  freq1 = analogRead(8);
  Serial.print("bruit ambiant= ");
  Serial.print(freq1);
  freq2 = analogRead(9);
  Serial.print("  |  5Hz= ");
  Serial.println(freq2);
  //MOTOR_SetSpeed(0,.1);
  //MOTOR_SetSpeed(1,.1);

  if (freq2 > 400) {
    //Serial.println("CRISS ARRÊTE");
    duree++;
    MOTOR_SetSpeed(0,0);
    MOTOR_SetSpeed(1,0);
    if (duree == 50) {
      MOTOR_SetSpeed(0,0);
      MOTOR_SetSpeed(1,0);
      delay(10000);
    }
  } else {
    duree = 0;
    //Serial.println("c'est chill lgros");
  }


  // // DÉTECTEUR DE LIGNE
  // Serial.print("3= ");
  // Serial.print(analogRead(3));
  // Serial.print(" | 2= ");
  // Serial.print(analogRead(2));
  // Serial.print(" | 1= ");
  // Serial.print(analogRead(1));
  // Serial.print(" | 0= ");
  // Serial.println(analogRead(0));  
  
  

    
  //Serial.println(freq2);
  //Serial.print("outputIR = ");
  //Serial.println(9325.1 * pow(outputIR,-1.263));
  delay(10);// Delais pour décharger le CPU

}

