#ifndef AVANCER_H
#define AVANCER_H
#include <LibRobus.h> // Essentielle pour utiliser RobUS
#include "rebalancer.h"
#include "global.h"

#define NOIR 800
#define BLANC 100

void SuivreLigne(){
    int capteurs[8];
    
    for(int i = 0; i < sizeof(capteurs); i++)
    {
        capteurs[i] = analogRead(i);
    }

    MOTOR_SetSpeed(0,.95);
    MOTOR_SetSpeed(0,.1);

    
    // if (capteurs[3] > NOIR && capteurs[4] > NOIR) {
        //sur la ligne noire
         if (capteurs[2] < BLANC && capteurs[5] < BLANC) {
        //chill;
        }
    } 

    if (capteurs[2] < BLANC){
        //tourner Gauche    
    } 
    if (capteurs[1] < BLANC){
        //tourner Droite  
    }  

    
    
    
   
    
    
}

#endif