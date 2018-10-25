#ifndef SUIVRELIGNE_H
#define SUIVRELIGNE_H
#include <LibRobus.h> // Essentielle pour utiliser RobUS
#include"avancer.h"

#define NOIR 800
#define BLANC 500
#define PIN_LIGNE 9

int flipFlop = 0;
float speedSlow = 0.05;
float speedFast = 0.4; //-.9
float offset = 1.05;

uint16_t capteur;

void SuivreLigne(){
    capteur = analogRead(PIN_LIGNE);

    //Détecteur de pogné
    
    if (ENCODER_Read(0) > 20000 || ENCODER_Read (1) > 20000) {
        Depogner();
        // ENCODER_Reset(0);
        // ENCODER_Reset(1);
        flipFlop = 0;
    } 
    else
    {
            
        if (flipFlop == 0) {
            // Serial.print("capteur = ");
            // Serial.println(capteur);

            if (capteur > NOIR) {
                flipFlop = -2;
            }
            // if (capteurs[2] > NOIR || capteurs[3] > NOIR) {
            //     flipFlop = 2;
            // }
            MOTOR_SetSpeed(0,speedFast/offset);
            MOTOR_SetSpeed(1,speedFast);      
        }
            //1 = gauche  ||  2 = droit    
            // -2 tourner gauche 
            // 2 tourner droit

        if (flipFlop == 2 && capteur > NOIR) {
            flipFlop = 1;
            Serial.println("flipFlop = 1");
        }
        if (flipFlop == 1 && capteur < BLANC) {
            flipFlop = -2; 
            Serial.println("flipFlop = -2");
            //Tourner Gauche
            MOTOR_SetSpeed(0,speedSlow);
            MOTOR_SetSpeed(1,speedFast); 
            ENCODER_Reset(1);
        }

        if (flipFlop == -2 && capteur > NOIR) {
            flipFlop = -1;
            Serial.println("flipFlop = -1");
        }
        if (flipFlop == -1 && capteur < BLANC) {
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
    Serial.print("capteur = ");
    Serial.println(capteur);
}

#endif