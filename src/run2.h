#ifndef RUN2_H
#define RUN2_H
#include <LibRobus.h> // Essentielle pour utiliser RobUS
#include "global.h"
#include "avancer.h"
#include "tournerdroite.h"
#include "tournergauche.h"
#include "tournersurlui.h"
#include "fonctions.h"

void Run2(){
   //DÉBUT PARCOURS
  //A
  Serial.println("A");
  AvancerEnLigneDroite(212);  
  //B
  Serial.println("B");
  TournerGauche(90);
  AvancerEnLigneDroite(28); //24
  //C
  Serial.println("C");
  TournerDroite(90);   
  AvancerEnLigneDroite(24);
  //D
  Serial.println("D");
  TournerDroite(90);
  AvancerEnLigneDroite(28); //24
  //E
  Serial.println("E");
  TournerGauche(90);
  AvancerEnLigneDroite(24);
  //F
  Serial.println("F");
  TournerDroite(45);
  AvancerEnLigneDroite(36);//****
  //G
  Serial.println("G");
  TournerGauche(90);
  AvancerEnLigneDroite(50); //60
  //H
  Serial.println("H");
  TournerDroite(45);//55
  AvancerEnLigneDroite(32);

  //I
  Serial.println("I");
  TournerDroite(12.5);
  AvancerEnLigneDroite(80);

  //J 
  Serial.println("J");
  
  //FINIALLER

  // TournerGauche(270);//180 homemade
  // TournerDroite(90);
  TournerSurLui(180);
  AvancerEnLigneDroite(80);

  //I
  Serial.println("I");
  TournerGauche(12.5);
  AvancerEnLigneDroite(32);

  //H
  Serial.println("H");
  TournerGauche(45);//55
  AvancerEnLigneDroite(50);
  //G
  Serial.println("G");
  TournerDroite(90);
  AvancerEnLigneDroite(36);
  //F
  Serial.println("F");
  TournerGauche(45);
  AvancerEnLigneDroite(24);
  //E
  Serial.println("E");
  TournerDroite(90);
  AvancerEnLigneDroite(28);
  //D
  Serial.println("D");
  TournerGauche(90);
  AvancerEnLigneDroite(24);
  //C
  Serial.println("C");
  TournerGauche(90);
  AvancerEnLigneDroite(28);
  //B
  Serial.println("B");
  TournerDroite(90);
  //A
  AllerFuckingVite(212);

}

#endif