#ifndef ARENEDEUX_H
#define ARENEDEUX_H

#include <LibRobus.h>
#include "detecterballe.h"
#include "suivreligne.h"
#include "avancer.h"
#include "suivreballe.h"
 
void AreneDeux () {

    SuivreLigne();

    if (DetecterBalleAlexis () == 1) {
        AX_BuzzerON(1000,200);

        // if (SuivreBalle() == 1) {
        //     SERVO_SetAngle(0,80);
        //     MOTOR_SetSpeed(0,.4);
        //     MOTOR_SetSpeed(1,.4);
        // }
        // else {
        //     AX_BuzzerON(4000,100);
        //     delay(200);
        //     AX_BuzzerON(4000,100);
        //     SERVO_SetAngle(0,140);
        //     Depogner();
        //     ENCODER_Reset(0);
        //     ENCODER_Reset(1);
        // }
        MOTOR_SetSpeed(0,.4);
        MOTOR_SetSpeed(1,.4);
        ENCODER_Reset(0);
        ENCODER_Reset(1);
        while(!ROBUS_IsBumper(0) && ENCODER_Read(0) < 12000 && ENCODER_Read(1) < 12000){
            
        }
        
        if (ROBUS_IsBumper(0)) {
            SERVO_SetAngle(0,80);
        } 
        else
        {
            SERVO_SetAngle(0,140);
            Depogner();
        }
        
        
        
    }
    

}


#endif