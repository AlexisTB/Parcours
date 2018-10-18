#ifndef SUIVRELIGNEALEXIS_H
#define SUIVRELIGNEALEXIS_H
#include <LibRobus.h> // Essentielle pour utiliser RobUS


#define NOIR 600
#define BLANC 100

void SuivreLigneAlexis(){
    int capteurs[8];
    int flipFlop = 0;

    for(int i = 0; i < sizeof(capteurs) - 1; i++)
    {
        capteurs[i] = analogRead(i);
    }
    
    // // if (capteurs[3] > NOIR && capteurs[4] > NOIR) {
    //     //sur la ligne noire
    //      if (capteurs[2] < BLANC && capteurs[5] < BLANC) {
    //     //chill;
    //     }
    // } 

    if (capteurs[2] < BLANC){
     //tourner Droite  
        MOTOR_SetSpeed(0,-.10);
        MOTOR_SetSpeed(1,-.05);    
        
    } else if (capteurs[1] < BLANC ){
       //tourner Gauche
        MOTOR_SetSpeed(0,-.05);
        MOTOR_SetSpeed(1,-.10); 
    } else if (capteurs[0] > NOIR ){
       //tourner Droite
        MOTOR_SetSpeed(0,-.10);
        MOTOR_SetSpeed(1,-.05);    
    } else if (capteurs[3] > NOIR ){
       //tourner Gauche
        MOTOR_SetSpeed(0,-.05);
        MOTOR_SetSpeed(1,-.10); 
    }else {
        MOTOR_SetSpeed(0,-.095);
        MOTOR_SetSpeed(1,-.1);
    }  


    
    
    
   
    
    
}

#endif