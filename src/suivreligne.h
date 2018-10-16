#ifndef SUIVRELIGNE_H
#define SUIVRELIGNE_H
#include <LibRobus.h> // Essentielle pour utiliser RobUS


#define NOIR 600
#define BLANC 100

void SuivreLigne(){
    int capteurs[8];
    int flipFlop = 2;

    for(int i = 0; i < sizeof(capteurs) - 1; i++)
    {
        capteurs[i] = analogRead(i);
    }

    //MOTOR_SetSpeed(0,-.095);
    //MOTOR_SetSpeed(1,-.1);

    
    // // if (capteurs[3] > NOIR && capteurs[4] > NOIR) {
    //     //sur la ligne noire
    //      if (capteurs[2] < BLANC && capteurs[5] < BLANC) {
    //     //chill;
    //     }
    // } 

    // if (capteurs[2] > NOIR && flipFlop == 0){
    //  //tourner Droite  
    //     flipFlop = 1;
    //     MOTOR_SetSpeed(0,-.10);
    //     MOTOR_SetSpeed(1,-.05);    
        
    // } 
    // if (capteurs[1] > NOIR && flipFlop == 1){
    //     flipFlop = 0;
    //    //tourner Gauche
    //     MOTOR_SetSpeed(0,-.05);
    //     MOTOR_SetSpeed(1,-.10); 
    // }  

    // if (flipFlop == 2 && capteurs[1] == 0) flipFlop = 1; 
    // if (flipFlop == 1 && capteurs[1] == 0) flipFlop = 1; 

    if (flipFlop == 2) {
 
        if (capteurs[1] > NOIR) {
            flipFlop = 1;
            Serial.println("flipFlop = 1");
        }
    } 
    if (flipFlop == 1 && capteurs[1] < BLANC) {
        flipFlop = -2; 
        Serial.println("flipFlop = -2");
    }
    if (flipFlop == -2)
    {
        MOTOR_SetSpeed(0,-.05);
        MOTOR_SetSpeed(1,-.1); 
        if (capteurs[1] > NOIR) {
           flipFlop = -1;
           Serial.println("flipFlop = -1");
        }
    }
    if (flipFlop == -1 && capteurs[1] < BLANC) {
        flipFlop = 2;
        Serial.println("flipFlop = -2");
        MOTOR_SetSpeed(0,-.10);
        MOTOR_SetSpeed(1,-.05);
    }


}

#endif