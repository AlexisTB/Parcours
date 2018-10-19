#ifndef SUIVRELIGNE_H
#define SUIVRELIGNE_H
#include <LibRobus.h> // Essentielle pour utiliser RobUS


#define NOIR 600
#define BLANC 100

int flipFlop = 0;
float speedSlow = 0.05;
float speedFast = 0.2; //-.9
float offset = 1.05;


void SuivreLigne(){
    int capteurs[8];

    for(int i = 0; i < sizeof(capteurs) - 1; i++)
    {
        capteurs[i] = analogRead(i);
    }

    
    if (flipFlop == 0) {
        
        if (capteurs[0] > NOIR || capteurs[1] > NOIR) {
            flipFlop = -2;
        }
        if (capteurs[2] > NOIR || capteurs[3] > NOIR) {
            flipFlop = 2;
        }
        MOTOR_SetSpeed(0,speedFast/offset);
        MOTOR_SetSpeed(1,speedFast);      
    }
        //1 = gauche  ||  2 = droit    
        // -2 tourner gauche 
        // 2 tourner droit

    if (flipFlop == 2 && capteurs[1] > NOIR) {
        flipFlop = 1;
        Serial.println("flipFlop = 1");
    }
    if (flipFlop == 1 && capteurs[1] < BLANC) {
        flipFlop = -2; 
        Serial.println("flipFlop = -2");
        //Tourner Gauche
        MOTOR_SetSpeed(0,speedSlow);
        MOTOR_SetSpeed(1,speedFast); 
    }

    if (flipFlop == -2 && capteurs[1] > NOIR) {
        flipFlop = -1;
        Serial.println("flipFlop = -1");
    }
    if (flipFlop == -1 && capteurs[1] < BLANC) {
        flipFlop = 2;
        Serial.println("flipFlop = 2");
        //Tourner Droite
        MOTOR_SetSpeed(0,speedFast);
        MOTOR_SetSpeed(1,speedSlow );
    }


}

#endif