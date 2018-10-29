#ifndef ATTAQUE_H
#define ATTAQUE_H

#include <LibRobus.h>
#include "suivreligne.h"
#include "avancer.h"
#include "suivreballe.h"
#include "deplacementoctogone.h"


void Scorer(){
    MOTOR_SetSpeed(0,0);
    MOTOR_SetSpeed(1,0);
    AX_BuzzerON(5000,200);
    delay(500);
    AX_BuzzerON(5000,200);
    delay(500);
    AX_BuzzerON(5000,200);
    delay(500);
    MOTOR_SetSpeed(0,.7);
    MOTOR_SetSpeed(1,.7);
    delay(1000);
    
    if (DetecterCouleur() != COULEURNOIR) {
        //SI on est pas encore dans le but
        TournerDroiteTemps(100);
        AvancerTemps(800);
        AttendreTemps(1000);
        //TournerGaucheTemps(500);
        MOTOR_SetSpeed(0,-.6);
        MOTOR_SetSpeed(1,.6);
        delay(200);
        AttendreTemps(1000);
        AvancerTemps(200);
        AttendreTemps(1000);
        LeverFourchette();
        TournerDroiteTemps(500);
        // AvancerTemps(200);
        // TournerDroiteTemps(200);
        
    }
    Depogner();
    stateBalle = 0;

}





void Attaque() {

    //Suivre ligne sur bord du mur

    //Si toucher couleur 1. tourner légerement à droite 2. avancerenlignedroite 3.tourner à gauche (tasser le goaler) + flipper la balle (Si arrive de droite)
    //Si toucher couleur 1. tourner légerement à gauche 2. avancerenlignedroite 3.tourner à droite (tasser le goaler) + flipper la balle (Si arrive de gauche)
     if ( couleur == COULEURJAUNE || couleur == COULEURVERT || couleur == COULEURROUGE) {
            //Scorer
            Scorer();

        } else if (couleur == COULEURBLEU) {
            Depogner();
        }
        
        else {
            //suivre une ligne jusqu'à une couleur ennemie
            SuivreLigne();
        }



}












#endif