#ifndef RUN_H
#define RUN_H
#include <LibRobus.h> // Essentielle pour utiliser RobUS
#include "global.h"
#include "avancer.h"
#include "tournerdroite.h"
#include "tournergauche.h"
#include "tournersurlui.h"
#include "fonctions.h"

void Run(){
   //DÉBUT PARCOURS
  //A
  Serial.println("A");
  AvancerEnLigneDroite(210);  
  //B
  Serial.println("B");
  TournerGauche(90);
  AvancerEnLigneDroite(35); 
  //C
  Serial.println("C");
  TournerDroite(90);   
  AvancerEnLigneDroite(20);
  //D
  Serial.println("D");
  TournerDroite(90);
  AvancerEnLigneDroite(25); 
  //E
  Serial.println("E");
  TournerGauche(90);
  AvancerEnLigneDroite(15);//8
  //F
  Serial.println("F");
  TournerDroite(45);
  AvancerEnLigneDroite(40);
  //G
  Serial.println("G");
  TournerGauche(90);
  AvancerEnLigneDroite(60); //50
  //H
  Serial.println("H");
  TournerDroite(45);
  AvancerEnLigneDroite(110);
  //I
  Serial.println("I");
  //J 
  Serial.println("J");
  
  //FINIALLER
  //delay(20);
  //TournerSurLui(180);
  TournerGauche(270);
  TournerDroite(90);
  //TEST
  // errTotDroite = 0;
  // errTotGauche = 0;
  delay(200);
  AvancerEnLigneDroite(110);//76
  // I
  Serial.println("I");
  //AvancerEnLigneDroiteInt(31);
  //H
  Serial.println("H");
  TournerGauche(45);//50
  AvancerEnLigneDroite(50);
  //G
  Serial.println("G");
  TournerDroite(90);
  AvancerEnLigneDroite(37);
  //F
  Serial.println("F");
  TournerGauche(45);
  AvancerEnLigneDroite(12);
  //E
  Serial.println("E");
  TournerDroite(90);
  AvancerEnLigneDroite(25);
  //D
  Serial.println("D");
  TournerGauche(90);
  AvancerEnLigneDroite(20);
  //C
  Serial.println("C");
  TournerGauche(90);
  AvancerEnLigneDroite(25);
  //B
  Serial.println("B");
  TournerDroite(90);
  //A
  AllerFuckingVite(200);

}

#endif