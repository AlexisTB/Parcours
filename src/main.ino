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
#include "suivrelignealexis.h"
#include "capteurcouleur.h"
#include "detecterballe.h"

float voltage;
float distance;
float freq1;
float freq2;
int tempsGlobal = 0;
int duree = 0;
int distanceirhaut;
int distanceirbas;
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

  ENCODER_Reset(0);
  ENCODER_Reset(1);
  Serial.begin(9600);


  //InitCapteurCouleur();
  //SOFT timage

  // SOFT_TIMER_SetCallback(0,&FonctionTestTempsGlobal);
  // SOFT_TIMER_SetDelay(0,1000);
  // SOFT_TIMER_SetRepetition(0,-1);
  // SOFT_TIMER_Enable(0);

  // SERVO_Enable(0);
  

  while(!ROBUS_IsBumper(3)){
    
  }

  // MOTOR_SetSpeed(0,.4); //0.093
  // MOTOR_SetSpeed(1,.4);

  //AvancerEnLigneDroite(30);
 
  // for(int i = 0; i < 5; i++)
  // {
  //   delay(1000);
  //   SERVO_SetAngle(0, 180);
  //   delay(1000);
  //   SERVO_SetAngle(0, 0);
  // }
  // SERVO_Disable(0);
  

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
  
  
  // //DÉTECTEUR DE SIFFLET
  // freq1 = analogRead(8);
  // Serial.print("bruit ambiant= ");
  // Serial.print(freq1);
  // freq2 = analogRead(9);
  // Serial.print("  |  5Hz= ");
  // Serial.println(freq2);
  // //MOTOR_SetSpeed(0,.1);
  // //MOTOR_SetSpeed(1,.1);

  // if (freq2 > 400) {
  //   //Serial.println("CRISS ARRÊTE");
  //   duree++;
  //   MOTOR_SetSpeed(0,0);
  //   MOTOR_SetSpeed(1,0);
  //   if (duree == 50) {
  //     MOTOR_SetSpeed(0,0);
  //     MOTOR_SetSpeed(1,0);
  //     delay(10000);
  //   }
  // } else {
  //   duree = 0;
  //   //Serial.println("c'est chill lgros");
  // }


  // // DÉTECTEUR DE LIGNE
  // Serial.print("3= ");
  // Serial.print(analogRead(3));
  // Serial.print(" | 2= ");
  // Serial.print(analogRead(2));
  // Serial.print(" | 1= ");
  // Serial.print(analogRead(1));
  // Serial.print(" | 0= ");
  // Serial.println(analogRead(0));  
<<<<<<< HEAD
  
  
  if (DetecterBalle()) {
    Serial.println("YOO la balle");
    MOTOR_SetSpeed(0,.2);
    MOTOR_SetSpeed(1,.2);
    flipFlop = 0;
  } 
  else
  {
    SuivreLigne();
    // MOTOR_SetSpeed(0,.05);
    // MOTOR_SetSpeed(1,.2);
  }
  
  
  
  //SuivreLigneAlexis();
    
  //Serial.println(freq2);
  //Serial.print("outputIR = ");
  //Serial.println(9325.1 * pow(outputIR,-1.263));
  // MOTOR_SetSpeed(0,.1);
  // MOTOR_SetSpeed(1,.1);
  // delay(3000);
  // MOTOR_SetSpeed(0,-.1);
  // MOTOR_SetSpeed(1,-.1);
  //DetecterCouleur();

=======
  
  //SuivreLigne();
 // SuivreLigneAlexis();
        // MOTOR_SetSpeed(0,.4);
        // MOTOR_SetSpeed(1,.4);
  //Serial.println(freq2);
  //Serial.print("outputIR = ");




  // Code du goaler
  // Avanceren ligne droite et revenir de 2 cm.
  // MOTOR_SetSpeed(0,.1);
  // MOTOR_SetSpeed(1,.1);
  // delay(500);
  // MOTOR_SetSpeed(0,-.1);
  // MOTOR_SetSpeed(1,-.1);
  // delay(500);

  RebalancerDroite(200);
  MOTOR_SetSpeed (0,.2);
  RebalancerDroite(-200);
  MOTOR_SetSpeed (0,-.2);

// //code DÉTECTEUR
// uint16_t ROBUS_ReadIR(uint8_t 0);
// uint16_t ROBUS_ReadIR(uint8_t 3);



// distanceirhaut = 0;
// distanceirhaut = 0;

// for(int i = 0; i < 4; i++)
// {
//   /* code */

//   distanceirhaut += (int)(9325.1 * pow(ROBUS_ReadIR(3),-1.263));
//   distanceirbas += (int)(9325.1 * pow(ROBUS_ReadIR(0),-1.263));
//   delay(10);
// }

// distanceirhaut = distanceirhaut/4;
// distanceirbas = distanceirbas/4;

// Serial.print("distanceirhaut : ");
// Serial.print(distanceirhaut);

// Serial.print("  ||  distanceirbas : ");
// Serial.println(distanceirbas);



// if (!ROBUS_IsBumper(2)) {
  /* code */

    //mode trouver et avancer sur la balle
    // if (distanceirhaut > distanceirbas + 6  && distanceirbas < 15 && distanceirbas > 5 && distanceirbas > 5) {
    //  // Avancervite et ralentir vers la balle.
    //   MOTOR_SetSpeed(0,.2);
    //   MOTOR_SetSpeed(1,.2);
    // }

//}
>>>>>>> b85d61195a307ccfe59ba5ad4b5e32ae1eb2b91a
  delay(10);// Delais pour décharger le CPU

}

