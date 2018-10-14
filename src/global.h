#ifndef GLOBAL_H
#define GLOBAL_H

int32_t roueDroite;
int32_t roueGauche;
float bias;
const float baseSpeed = 0.2;
float topSpeed = 0.4;
float avancerSpeed = 0.4;
float tournerSpeedMax = 0.4;
float tournerSpeedInit = 0;
float diff= 0.05;
const float ticParCM = 3200/(7.7*PI);
float tour = 3930;//3945 //3939 //3925
float tourInverse = 3915;

float tourDroit = 3935; //3940
float tourGauche = 3955; //3930 
float tourDroitInverse = 3925; //3915 //3930
float tourGaucheInverse = 3949; //3945

int test = 3951;//3951 //3960 
float tourDroit2 = 3900;
float tourGauche2 = 3880;
float rightBiasTourner = 0.993;//.994
float rightBias = 0.995;//.994

int errTotGauche = 0;
int errTotDroite = 0;

#endif