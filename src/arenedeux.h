#ifndef ARENEDEUX_H
#define ARENEDEUX_H

#include <LibRobus.h>
#include "detecterballe.h"
#include "suivreligne.h"
#include "avancer.h"
#include "suivreballe.h"
#include "attaque.h"
#include "global.h"
#include "deplacementoctogone.h"
#include "detecteursifflet.h"


void AreneDeux () {

    
    if (DetecteurSifflet() == 1) {
        MOTOR_SetSpeed(0,0);
        MOTOR_SetSpeed(1,0);
        delay(10000);
        flipFlop = 0;
    }
    
    if (stateBalle !=2) stateBalle = DetecterBalleAlexis();

    if (ROBUS_IsBumper(0) || stateBalle == 2) {
        //si une balle est dans le robot
        BaisserFourchette();
        if ( DetecterBalleAlexis() == 0) stateBalle = 0;
        else stateBalle = 2;

        if ( couleur == COULEURJAUNE || couleur == COULEURVERT || couleur == COULEURROUGE) {
            //Scorer
            Scorer();

        } else if (couleur == COULEURBLEU) {
            TournerDroiteTemps(1000);
        }
        
        else {
            //suivre une ligne jusqu'à une couleur ennemie
            SuivreLigne();
        }
    } 
    else
    {
        LeverFourchette();
        
        //NOTE: AMÉLIORATION: si détecte couleur sans balle, se dépogner
        if ( stateBalle == 1) {
            AX_BuzzerON(1000,200);
            //Amélioration possible: Selon flipflop tourner vers la balle;

            //code louche pour s'approcher de la balle
            MOTOR_SetSpeed(0,vitesseNormale);
            MOTOR_SetSpeed(1,vitesseNormale);          
            
        } else if (stateBalle == -1) {
            Depogner();
        } else
        {
            SuivreLigne();
            
            if (tempsGlobal % 15 == 0 && tempsGlobal > 15) {
                stateBalle = ScanBalle();
                
                if (stateBalle == 1) {
                    MOTOR_SetSpeed(0,-.4);
                    MOTOR_SetSpeed(1,.4);
                    delay(100);
                } else flipFlop = 0;
                
            }
            
        }
        
    }
    

}


#endif