#ifndef RUN3_H
#define RUN3_H
#include <LibRobus.h> // Essentielle pour utiliser RobUS
#include "global.h"
#include "avancer.h"
#include "tournerdroite.h"
#include "tournergauche.h"
#include "tournersurlui.h"
#include "fonctions.h"

void Run3(){
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
  AvancerEnLigneDroite(27); //24
  //F
  Serial.println("F");
  TournerDroite(44.8);
  AvancerEnLigneDroite(36);//****
  //G
  Serial.println("G");
  TournerGauche(90);
  AvancerEnLigneDroite(70); //60
  //H
  Serial.println("H");
  TournerDroite(44.8);//55
  AvancerEnLigneDroite(32);//32

  //I
  Serial.println("I");
  TournerDroite(10); //12.5
  AvancerEnLigneDroite(90);

  //J 
  Serial.println("J");
  
  //FINIALLER
  delay(100);
  // TournerGauche(270);//180 homemade
  // TournerDroite(90);
  AvancerEnLigneDroite(-90);

  //I
  Serial.println("I");
  TournerDroite(-9.5);//12.3
  AvancerEnLigneDroite(-32);//-32

  //H
  Serial.println("H");
  TournerDroite(-44.4);
  AvancerEnLigneDroite(-70); //-60
  //G
  Serial.println("G");
  TournerGauche(-90);
  AvancerEnLigneDroite(-36);
  //F
  Serial.println("F");
  TournerDroite(-44.4);
  AllerFuckingVite(-23); //-20
  //E
  Serial.println("E");
  TournerGauche(-90);
  AllerFuckingVite(-28);//-28
  //D
  Serial.println("D");
  TournerDroite(-90);
  AllerFuckingVite(-24);
  //C
  Serial.println("C");
  TournerDroite(-90);
  AllerFuckingVite(-36); //-28
  //B
  Serial.println("B");
  TournerGauche(-90);
  //A
  AllerFuckingVite(-212);

}

#endif