#ifndef ARENEUN_H
#define ARENEUN_H

#include <LibRobus.h>
#include "detecterballe.h"
#include "suivreligne.h"
#include "avancer.h"
#include "suivreballe.h"

int suivreLigne = 1;



int ScanBalle(){
  ENCODER_Reset(1);
  int tempsTemp = tempsGlobal;
  MOTOR_SetSpeed(0,.4);
  MOTOR_SetSpeed(1,-.4);
  
  while(ENCODER_Read(1) > -7700){
    if(DetecterBalleRQ() == 1){
      AX_BuzzerON(1000,100);
      Serial.println("BALLE");
      return 1;
    }
    SOFT_TIMER_Update();
    if (tempsGlobal > tempsTemp + 3) {
      Serial.println("TEMPSMAX");
      return 0;
    }
    
    
  }
  Serial.println("ENCODERMAX");



  return 0;
  
 
  
    
    // Serial.println("YOO la balle");
    // MOTOR_SetSpeed(0,.4);
    // MOTOR_SetSpeed(1,.4);
    // delay(500);
    // TournerSurLui(10);
    // MOTOR_SetSpeed(0,-.2);
    // MOTOR_SetSpeed(1,.2);
    // MOTOR_SetSpeed(0,0);
    // MOTOR_SetSpeed(1,0);
  }

void AreneUn(){
  
     //code test déplacement parcours
  if (DetecterBalleAlexis() == 1) {
    suivreLigne = 0;
    MOTOR_SetSpeed(0,.4);
    MOTOR_SetSpeed(1,.4);

    //  Buzzer on for ball detection.

    AX_BuzzerON(10000,25);
    delay(100);
    AX_BuzzerON(5000,25);
    delay(100);
    AX_BuzzerON(7000,25);
    delay(100);
    AX_BuzzerON(3000,250);
    delay(300);
    AX_BuzzerON(3000,250);
    delay(300);
    AX_BuzzerON(3000,250);
    delay(300);
    AX_BuzzerON(10000,25);
    delay(100);
    AX_BuzzerON(5000,25);
    delay(100);
    AX_BuzzerON(7000,25);
    delay(100);
    AX_BuzzerON(3000,250);
    delay(300);
    Serial.println("YOO la balle");

    //delay(1000);
    // TournerSurLui(10);
    // MOTOR_SetSpeed(0,-.2);
    // MOTOR_SetSpeed(1,.2);
    Depogner();
    suivreLigne = 1;
    // delay(10000);
    // flipFlop = 0;
  } 
  else if (suivreLigne == 1)
  {
    SuivreLigne();

    // MOTOR_SetSpeed(0,.05);
    // MOTOR_SetSpeed(1,.2);
  }

}

#endif