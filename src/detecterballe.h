#ifndef DETECTERBALLE_H
#define DETECTERBALLE_H

#include <LibRobus.h>

#define PINHAUT 6
#define PINBAS 7

#define ARRAY_SIZE 5
int filtre1[ARRAY_SIZE];
int filtre2[ARRAY_SIZE];


const int REP = 2;
int distanceirhaut;
int distanceirhautMAX;
int distanceirbas;
int distanceirbasMAX;


int DistanceIR(int capteurIR){
  return (int)(9325.1 * pow(capteurIR,-1.263));
}

void getDistance(){

  distanceirhautMAX = 0;
  distanceirbasMAX = 0;
  for(int i = 0; i < REP; i++)
  {
    distanceirhaut = DistanceIR(analogRead(PINHAUT));
    if(distanceirhaut > distanceirhautMAX) distanceirhautMAX = distanceirhaut;
    distanceirbas = DistanceIR(analogRead(PINBAS));
    if(distanceirbas > distanceirbasMAX) distanceirbasMAX = distanceirbas;
    //delay(5);
  }

  
  
}


int DetecterBalleAlexis(){

  distanceirhaut = 0;
  distanceirbas = 0;


  //Ring buffer pour filter les IRS
  for (int j = ARRAY_SIZE - 1 ; j > 0 ; j--)
  {
    // Serial.println(j);
    // for(int i = 0; i < ARRAY_SIZE; i++)
    // {
    //   Serial.print(i);
    //   Serial.print(" = ");
    //   Serial.println(filtre1[i]);
    // }
    filtre1[j] = filtre1[j - 1];
    filtre2[j] = filtre2[j - 1];

  }
  
  filtre1[0] =  (int)(9325.1 * pow(analogRead(PINHAUT),-1.263));
  filtre2[0] =  (int)(9325.1 * pow(analogRead(PINBAS),-1.263));

  for(int i = 0; i < ARRAY_SIZE; i++)
  {
    //Serial.print(i);
    //Serial.print(" = ");
    //Serial.println(filtre1[i]);
    distanceirhaut += filtre1[i];
    distanceirbas += filtre2[i];
  }
  
  distanceirhaut = distanceirhaut/ARRAY_SIZE;
  distanceirbas = distanceirbas/ARRAY_SIZE;

  // Serial.print("distanceirhaut : ");
  // Serial.print(distanceirhaut);

  // Serial.print("  ||  distanceirbas : ");
  // Serial.println(distanceirbas);
  

  if (distanceirhaut > distanceirbas + 6  && distanceirbas < 15 && distanceirhaut > 5) return 1;
  else return 0;
}

void MonitorInfrarouge(){
  
  getDistance();

  Serial.print("distanceirhaut : ");
  Serial.print(distanceirhautMAX);

  Serial.print("  ||  distanceirbas : ");
  Serial.println(distanceirbasMAX);
} 



#endif