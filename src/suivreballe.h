#ifndef SUIVREBALLE_H
#define SUIVREBALLE_H
#include <LibRobus.h> // Essentielle pour utiliser RobUS
#include"avancer.h"
#include "detecterballe.h"

int flipFlop2 = 0;
float speedSlow2 = 0.05;
float speedFast2 = 0.2; //-.9
int balle;
bool fuckoff = false;

int SuivreBalle(){

    
    while(!ROBUS_IsBumper(0) && !fuckoff){
        balle = DetecterBalleAlexis();

        //Détecteur de pogné
        
        if (ENCODER_Read(0) > 14000 || ENCODER_Read (1) > 14000) {

            fuckoff = true;
            //pourrait rester pogné s'il croit qu'un robot est la balle et qu'il est pognée // turcotte pense que ca ferait jamais ca // alexis oui
        } 
        else
        {
                //1 = gauche  ||  2 = droit    
                // -2 tourner gauche 
                // 2 tourner droit
            if (flipFlop2 == 0){

                //À FAIRE 
                flipFlop2 = 2;

            }

            if (flipFlop2 == 2 && balle == 1) {

                flipFlop2 = 1;
                Serial.println("flipFlop = 1");

            }
            if (flipFlop2 == 1 && balle == 0) {

                flipFlop2 = -2; 
                Serial.println("flipFlop = -2");
                //Tourner Gauche
                MOTOR_SetSpeed(0,speedSlow2);
                MOTOR_SetSpeed(1,speedFast2); 
                ENCODER_Reset(1);

            }

            if (flipFlop2 == -2 && balle == 1) {

                flipFlop2 = -1;
                Serial.println("flipFlop = -1");

            }
            if (flipFlop2 == -1 && balle == 0) {

                flipFlop2 = 2;
                Serial.println("flipFlop = 2");
                //Tourner Droite
                MOTOR_SetSpeed(0,speedFast2);
                MOTOR_SetSpeed(1,speedSlow2);
                ENCODER_Reset(0);

            }
        }
    }
    
    if (fuckoff) return 0;
    else return 1;

}

#endif