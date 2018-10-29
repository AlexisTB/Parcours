#ifndef SUIVRELIGNE_H
#define SUIVRELIGNE_H
#include <LibRobus.h> // Essentielle pour utiliser RobUS
#include"avancer.h"
#include "deplacementoctogone.h"

#define NOIR 800
#define BLANC 700
#define PIN_LIGNE 9

float speedSlow = 0.05;
float speedFast = 0.5; //-.9
float offset = 1.05;

uint16_t capteur;

void TrouverLigne(){
    flipFlop = 0;
}

void SuivreLigne(){
    capteur = analogRead(PIN_LIGNE);

    //Détecteur de pogné

    if ((ENCODER_Read(0) > 20000 || ENCODER_Read (1) > 20000) ) {
        if(stateBalle == 2){
            DepognerAvecBalle();
        } else{
            Depogner();
        }  
        ENCODER_Reset(0);
        ENCODER_Reset(1);
        flipFlop = 0;
    } 
    else
    {
            
        if (flipFlop == 0) {
            // Serial.print("capteur = ");
            // Serial.println(capteur);

            if (capteur > NOIR) { 
                flipFlop = 2; //-2 //NOTE: on pourrait techniquement utiliser un autre capteur pour 
                                        //regarder de quel coté tourner dans cette situation
            }
            // if (capteurs[2] > NOIR || capteurs[3] > NOIR) {
            //     flipFlop = 2;
            // }
            MOTOR_SetSpeed(0,speedFast/offset*.6);
            MOTOR_SetSpeed(1,speedFast*.6);      
        }
            //1 = gauche  ||  2 = droit    
            // -2 tourner gauche 
            // 2 tourner droit

        else if (flipFlop == 2 && capteur > NOIR) {
            flipFlop = 1;
            Serial.println("flipFlop = 1");
        } 
        
        else if (flipFlop == 1 && capteur < BLANC) {
            flipFlop = -2; 
            Serial.println("flipFlop = -2");
            //Tourner Gauche
            MOTOR_SetSpeed(0,speedSlow);
            MOTOR_SetSpeed(1,speedFast); 
            ENCODER_Reset(1);
        }

        else if (flipFlop == -2 && capteur > NOIR) {
            flipFlop = -1;
            Serial.println("flipFlop = -1");
        }

        else if (flipFlop == -1 && capteur < BLANC) {
            flipFlop = 2;
            Serial.println("flipFlop = 2");
            //Tourner Droite
            MOTOR_SetSpeed(0,speedFast);
            MOTOR_SetSpeed(1,speedSlow );
            ENCODER_Reset(0);
        }
    }
    
    

}

void MonitorDetecteurLigne(){
    
    capteur = analogRead(PIN_LIGNE);
    Serial.print("couleur ligne = ");
    Serial.println(capteur);
}

#endif