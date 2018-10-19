#include <LibRobus.h>

int distanceirhaut;
int distanceirbas;

bool DetecterBalle(){

    distanceirhaut = 0;
    distanceirhaut = 0;

    for(int i = 0; i < 4; i++)
    {
    /* code */

    distanceirhaut += (int)(9325.1 * pow(ROBUS_ReadIR(0),-1.263));
    distanceirbas += (int)(9325.1 * pow(ROBUS_ReadIR(3),-1.263));
    delay(10);
    }

    distanceirhaut = distanceirhaut/4;
    distanceirbas = distanceirbas/4;

    Serial.print("distanceirhaut : ");
    Serial.print(distanceirhaut);

    Serial.print("  ||  distanceirbas : ");
    Serial.println(distanceirbas);





    //mode trouver et avancer sur la balle
    if (distanceirhaut > distanceirbas + 6  && distanceirbas < 15 && distanceirbas > 5 && distanceirhaut > 5) {
     // Avancervite et ralentir vers la balle.
    //   MOTOR_SetSpeed(0,.2);
    //   MOTOR_SetSpeed(1,.2);
      return true;
    } 
    else
    {
      return false;
    }
    
}

  