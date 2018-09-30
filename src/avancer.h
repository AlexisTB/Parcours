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
float tourDroit = 3970;
float tourGauche = 3980;
int test = 3800;
float tourDroit2 = 3950;
float tourGauche2 = 3900;

void AvancerEnLigneDroite(float cm){
  int distance = cm*ticParCM;
  ENCODER_Reset(0);
  ENCODER_Reset(1);
  avancerSpeed = baseSpeed;
  MOTOR_SetSpeed(0,avancerSpeed);
  MOTOR_SetSpeed(1,avancerSpeed);
  do
  {
    roueGauche = ENCODER_Read(0);
    roueDroite = ENCODER_Read(1);
    
    if(roueGauche > 5*ticParCM) avancerSpeed = topSpeed;

    if(abs(roueGauche-roueDroite)<10) diff = 0.05;
    else if (abs(roueGauche-roueDroite)<100) diff = 0.25;
    else diff = 0.5;

    if (roueGauche > roueDroite) {
      MOTOR_SetSpeed(0,avancerSpeed*(1-diff));
      MOTOR_SetSpeed(1,avancerSpeed*(1+diff));
      //Serial.print("   Droite= ");
      //Serial.print(baseSpeed*(1+diff));
      //Serial.print("  Gauche = ");
      //Serial.print(baseSpeed*(1-diff));

    }
    else if (roueDroite > roueGauche) {
      MOTOR_SetSpeed(0,avancerSpeed*(1+diff));
      MOTOR_SetSpeed(1,avancerSpeed*(1-diff));
      //Serial.print("   Droite= ");
      //Serial.print(baseSpeed*(1-diff));
      //Serial.print("  Gauche = ");
      //Serial.print(baseSpeed*(1+diff));
    } 
    else
    {
      MOTOR_SetSpeed(0,avancerSpeed);
      MOTOR_SetSpeed(1,avancerSpeed);
      //Serial.print("   Droite= ");
      //Serial.print(baseSpeed*(1));
      //Serial.print("  Gauche = ");
      //Serial.print(baseSpeed*(1));
    }
    //Serial.println();
    Serial.println(roueGauche);
  } while (roueGauche < distance && roueDroite < distance);
  Serial.print("FINI avancer");
  MOTOR_SetSpeed(0,0);
  MOTOR_SetSpeed(1,0);
   
}

void Calibration(){
    MOTOR_SetSpeed(0,0.095);
    MOTOR_SetSpeed(1,0.1);

    ENCODER_Reset(0);
    ENCODER_Reset(1);
    
    do
    {
        roueDroite = ENCODER_Read(1);
        roueGauche = ENCODER_Read(0);
    } while (roueDroite < 1000);

    Serial.print("roueGauche = ");
    //bias = roueDroite/roueGauche;
    Serial.println(roueGauche);
    Serial.print("roueDroite = ");
    Serial.print(roueDroite);
    MOTOR_SetSpeed(0,0);
    MOTOR_SetSpeed(1,0);
}

void AvancerEnLigneDroiteInt(float cm){
  int distance = cm*ticParCM;
  float erreur;
  float sum=0;
  float erreurRatio = 1000;
  float sumRatio = 3900;
  ENCODER_Reset(0);
  ENCODER_Reset(1);
  avancerSpeed = 0.1;
  MOTOR_SetSpeed(0,0.095*avancerSpeed);
  MOTOR_SetSpeed(1,avancerSpeed);
  do
  {
    roueGauche = ENCODER_Read(0);
    roueDroite = ENCODER_Read(1);
    erreur = roueGauche - roueDroite;
    sum += erreur;
    
    if (roueGauche > distance - 1000){
     if ( avancerSpeed > 0.2) avancerSpeed -= 0.05 ;
    }
    else if (avancerSpeed < .6) avancerSpeed += 0.04;//.02
    
    MOTOR_SetSpeed(0, avancerSpeed*(1-erreur/erreurRatio -sum/sumRatio));
    MOTOR_SetSpeed(1, avancerSpeed*(1+erreur/erreurRatio + sum/sumRatio));

    // Serial.print("erreur = ");
    // Serial.print(erreur);
    // Serial.print("sum = ");
    // Serial.print(sum);
    // Serial.println("");
    delay(200);
    if (roueGauche > distance) MOTOR_SetSpeed(0,0);
    if (roueDroite > distance) MOTOR_SetSpeed(1,0);

  } while (roueGauche < distance && roueDroite < distance);
  Serial.print("FINI avancer");
  Serial.print("Gauche = ");
  Serial.println(roueGauche);
  Serial.print("Droite = ");
  Serial.println(roueDroite);

  MOTOR_SetSpeed(0,0);
  MOTOR_SetSpeed(1,0);
  delay(100);

}

void AllerFuckingVite(int cm){
  int distance = cm*ticParCM;
  float erreur;
  float sum=0;
  float erreurRatio = 500;
  float sumRatio = 1000000;
  ENCODER_Reset(0);
  ENCODER_Reset(1);
  avancerSpeed = 0.1;
  MOTOR_SetSpeed(0,0.095*avancerSpeed);
  MOTOR_SetSpeed(1,avancerSpeed);
  do
  {
    roueGauche = ENCODER_Read(0);
    roueDroite = ENCODER_Read(1);
    erreur = roueGauche - roueDroite;
    sum += erreur;
  
    if (avancerSpeed < 1) avancerSpeed += 0.1;//.02
    MOTOR_SetSpeed(0, avancerSpeed*(1-erreur/erreurRatio -sum/sumRatio));
    MOTOR_SetSpeed(1, avancerSpeed*(1+erreur/erreurRatio + sum/sumRatio));
    delay(100);
    if (roueGauche > distance) MOTOR_SetSpeed(0,0);
    if (roueDroite > distance) MOTOR_SetSpeed(1,0);

  } while (roueGauche < distance && roueDroite < distance);
}

#endif