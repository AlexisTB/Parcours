#ifndef DETECTERBALLE_H
#define DETECTERBALLE_H

#include <LibRobus.h>

#define PINHAUT 6
#define PINBAS 5

#define ARRAY_SIZE_INFRAROUGE 5

int filtre1[ARRAY_SIZE_INFRAROUGE];
int filtre2[ARRAY_SIZE_INFRAROUGE];

// int distanceHautTemp[ARRAY_SIZE_INFRAROUGE];
// int distanceBasTemp[ARRAY_SIZE_INFRAROUGE];


const int REP = 5;
int distanceirhaut;
int distanceirhautMAX;
int distanceirbas;
int distanceirbasMAX;

int indexInfrarouge = 0;


int DistanceIR(int pin){
  return (int)(9325.1 * pow(analogRead(pin),-1.263));
}

void getDistance(){

  distanceirhautMAX = 0;
  distanceirbasMAX = 0;
  for(int i = 0; i < REP; i++)
  {
    distanceirhaut = DistanceIR(PINHAUT);
    if(distanceirhaut > distanceirhautMAX) distanceirhautMAX = distanceirhaut;
    distanceirbas = DistanceIR(PINBAS);
    if(distanceirbas > distanceirbasMAX) distanceirbasMAX = distanceirbas;
    //delay(5);
  }

  
  
}

int DetecterBalleRQ(){
  getDistance();
  if (distanceirhaut > distanceirbas + 6  && distanceirbas < 15 && distanceirhaut > 5) return 1; //SI balle est visible
  return 0;
}

int DetecterBalleAlexis(){

  //Ring buffer pour filter les IRS
  for (int j = ARRAY_SIZE_INFRAROUGE - 1 ; j > 0 ; j--)
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
  
  filtre1[0] =  DistanceIR(PINHAUT);
  filtre2[0] =  DistanceIR(PINBAS);

  //moyenne du ring buffer
  distanceirhaut = 0;
  distanceirbas = 0;
  for(int i = 0; i < ARRAY_SIZE_INFRAROUGE; i++)
  {
    //Serial.print(i);
    //Serial.print(" = ");
    //Serial.println(filtre1[i]);
    distanceirhaut += filtre1[i];
    distanceirbas += filtre2[i];
  }

  distanceirhaut = distanceirhaut/ARRAY_SIZE_INFRAROUGE;
  distanceirbas = distanceirbas/ARRAY_SIZE_INFRAROUGE;


  // Serial.print("distanceirhaut : ");
  // Serial.print(distanceirhaut);

  // Serial.print("  ||  distanceirbas : ");
  // Serial.println(distanceirbas);

  if (distanceirhaut < 10) return -1; //SI mur
  else if (distanceirhaut > distanceirbas + 6  && distanceirbas < 7 && distanceirhaut > 5) return 2; //SI balle proche en état de se faire attraper
  else if (distanceirhaut > distanceirbas + 6  && distanceirbas < 15 && distanceirhaut > 5) return 1; //SI balle est visible
  else return 0;
}

void MonitorInfrarouge(){
  
  int etatBalle = DetecterBalleAlexis();

  Serial.print("distanceirhaut : ");
  Serial.print(distanceirhaut);

  Serial.print("  ||  distanceirbas : ");
  Serial.print(distanceirbas);

  Serial.print("  ||  état balle : ");
  Serial.println(etatBalle);
} 

// void AnalyserInfrarouge(){


//     distanceBasTemp[indexInfrarouge] = DistanceIR(PINBAS);
//     distanceBasTemp[indexInfrarouge] = DistanceIR(PINBAS);

    
//     couleur = couleurTemp[indexInfrarouge];
//     for(int i = 1; i < ARRAY_SIZE_INFRAROUGE; i++)
//     {
//         if(couleurTemp[i] != couleurTemp[i-1]) {
//             couleur = 0;
//             break;
//         }
//     }
//     if(indexInfrarouge < 9) indexInfrarouge++;
//     else indexInfrarouge = 0;
    
// }

#endif