#ifndef DEPLACEMENTOCTOGONE_H
#define DEPLACEMENTOCTOGONE_H

#include <LibRobus.h>
#include "global.h"
#include "deplacementoctogone.h"

float vitesseNormale = .5;
float vitesseVite = .9;


void AvancerTemps(int temps){
    MOTOR_SetSpeed(0, vitesseNormale);
    MOTOR_SetSpeed(1, vitesseNormale);
    delay(temps);
}

void ReculerTemps(int temps){
    MOTOR_SetSpeed(0, -vitesseNormale);
    MOTOR_SetSpeed(1, -vitesseNormale);
    delay(temps);
}

void TournerDroiteTemps(int temps){
    MOTOR_SetSpeed(0, vitesseNormale);
    MOTOR_SetSpeed(1, -vitesseNormale);
    delay(temps);
}

void TournerGaucheTemps(int temps){
    MOTOR_SetSpeed(0, -vitesseNormale);
    MOTOR_SetSpeed(1, vitesseNormale);
    delay(temps);
}


void AttendreTemps(int temps){
    MOTOR_SetSpeed(0,0);
    MOTOR_SetSpeed(1,0);
    delay(1000);
}

void BaisserFourchette(){
    SERVO_SetAngle(FOURCHETTE, LO_POS);
}

void LeverFourchette(){
    SERVO_SetAngle(FOURCHETTE, HI_POS);
}

void Depogner(){
    AttendreTemps(1000);
    AX_BuzzerON(1000,100);
    delay(200);
    AX_BuzzerON(1000,100);
    delay(200);
    ReculerTemps(1000);
    TournerGaucheTemps(800);
    flipFlop = 0;
}

void DepognerAvecBalle(){
    AttendreTemps(1000);
    AX_BuzzerON(1000,100);
    delay(200);
    AX_BuzzerON(1000,100);
    delay(200);
    TournerDroiteTemps(800);
    flipFlop = 0;
}

#endif