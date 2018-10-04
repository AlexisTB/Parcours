#ifndef AVANCER_H
#define AVANCER_H
#include <LibRobus.h> // Essentielle pour utiliser RobUS

int32_t roueDroite;
int32_t roueGauche;
float bias;
const float baseSpeed = 0.2;
float topSpeed = 0.4;
float avancerSpeed = 0.4;
float tournerSpeed = 0.4;
float diff= 0.05;
const float ticParCM = 3200/(7.7*PI);
float tour = 3965;
float tourDroit = 3940;
float tourGauche = 3960;
int test = 3800;
float tourDroit2 = 3930;
float tourGauche2 = 3880;

int errTotGauche = 0;
int errTotDroite = 0;

void AvancerEnLigneDroiteInt(float cm){
  int distance = cm*ticParCM;
  int distanceGauche = distance; //- errTotGauche;
  int distanceDroite = distance; //- errTotDroite;

  float erreur;
  float sum=0;
  float erreurRatio = 10000;
  float sumRatio = 100000;
  ENCODER_Reset(0);
  ENCODER_Reset(1);
  avancerSpeed = 0.05;
  MOTOR_SetSpeed(0,avancerSpeed);
  MOTOR_SetSpeed(1,avancerSpeed);
  do
  {
    roueGauche = ENCODER_Read(0);
    roueDroite = ENCODER_Read(1)*.999;
    erreur = roueGauche - roueDroite;
    sum += erreur;
    
    if (roueGauche > distanceGauche - 1000){
     if ( avancerSpeed > 0.11) avancerSpeed -= 0.05 ;
    }
    else if (avancerSpeed < .6) avancerSpeed += 0.005;
    
    MOTOR_SetSpeed(0, avancerSpeed*(1-erreur/erreurRatio -sum/sumRatio));
    MOTOR_SetSpeed(1, avancerSpeed*(1+erreur/erreurRatio + sum/sumRatio));

    // Serial.print("erreur = ");
    // Serial.print(erreur);
    // Serial.print("sum = ");
    // Serial.print(sum);
    // Serial.println("");
    delay(10);
    if (roueGauche > distanceGauche) MOTOR_SetSpeed(0,0);
    if (roueDroite > distanceDroite) MOTOR_SetSpeed(1,0);

  } while (roueGauche < distanceGauche || roueDroite < distanceDroite);
  errTotGauche = roueGauche - distanceGauche;
  errTotDroite = roueDroite - distanceDroite;
  Serial.println("FINI avancer, spped finale = ");
  Serial.println(avancerSpeed);
  Serial.print("théorique = ");
  Serial.println(distance);
  Serial.print("Gauche = ");
  Serial.println(roueGauche);
  Serial.print("Droite = ");
  Serial.println(roueDroite);
  Serial.print("ERREUR TOT = gauche:");
  Serial.print(errTotGauche);
  Serial.print(" droite:");
  Serial.println(errTotDroite);
  MOTOR_SetSpeed(0,0);
  MOTOR_SetSpeed(1,0);
  delay(100);
}

void AvancerEnLigneDroite(float cm){
  int distance = cm*ticParCM;
  int distanceGauche = distance; //- errTotGauche;
  int distanceDroite = distance; //- errTotDroite;

  int erreur;
  ENCODER_Reset(0);
  ENCODER_Reset(1);
  avancerSpeed = 0.05;
  MOTOR_SetSpeed(0,avancerSpeed);
  MOTOR_SetSpeed(1,avancerSpeed);
  do
  {
    roueGauche = ENCODER_Read(0);
    roueDroite = ENCODER_Read(1)*.999;
    erreur = roueGauche - roueDroite;

    if (roueGauche > distanceGauche - 1000){
     if ( avancerSpeed > 0.11) avancerSpeed -= 0.05 ;
    }
    else if (avancerSpeed < .2) avancerSpeed += 0.005;
    
    if (erreur<0) {
      MOTOR_SetSpeed(0, avancerSpeed*1.05);
      MOTOR_SetSpeed(1, avancerSpeed*0.95);
    } 
    else if (erreur>0)
    {
      MOTOR_SetSpeed(0, avancerSpeed*0.95);
      MOTOR_SetSpeed(1, avancerSpeed*1.05);
    } 
    else
    {
      MOTOR_SetSpeed(0, avancerSpeed*1);
      MOTOR_SetSpeed(1, avancerSpeed*1);
    }
    
    delay(10);
    if (roueGauche > distanceGauche) MOTOR_SetSpeed(0,0);
    if (roueDroite > distanceDroite) MOTOR_SetSpeed(1,0);

  } while (roueGauche < distanceGauche || roueDroite < distanceDroite);
  errTotGauche = roueGauche - distanceGauche;
  errTotDroite = roueDroite - distanceDroite;
  Serial.println("FINI avancer, spped finale = ");
  Serial.println(avancerSpeed);
  Serial.print("théorique = ");
  Serial.println(distance);
  Serial.print("Gauche = ");
  Serial.println(roueGauche);
  Serial.print("Droite = ");
  Serial.println(roueDroite);
  Serial.print("ERREUR TOT = gauche:");
  Serial.print(errTotGauche);
  Serial.print(" droite:");
  Serial.println(errTotDroite);
  MOTOR_SetSpeed(0,0);
  MOTOR_SetSpeed(1,0);
  delay(100);
}



#endif