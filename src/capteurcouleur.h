#ifndef CAPTEURCOULEUR_H
#define CAPTEURCOULEUR_H

#include <ADJDS311.h>
#include <Wire.h>
#include "RGBTOHSL.h"

int sensorLed_pin = 2; //LED on the ADJDS-311
ADJDS311 colorSensor(sensorLed_pin);

void BruitCouleur(){
    AX_BuzzerON(3000,200);
    AX_BuzzerON(1000,200);
}

void InitCapteurCouleur(){
  colorSensor.init();
  colorSensor.ledOn(); //turn LED on
  
  //Calibrate white 
  //Need to hold white card in front (1-3mm) of it to calibrate from
  colorSensor.calibrate(); 
  //Serial.println("yooo");
}
//if using an RGB LED (Needs PWM Pins)
// int redPin = 3;
// int greenPin = 5;
// int bluePin = 6;

// void loop(){

  
//   lightLED(color); //send color to the LED
  
//   delay(200); //just here to slow down the serial output
  
// }

// void lightLED(RGBC color){
//   //RGBC is an array of red/green/blue/clear readings 
//   //Take a RGBC, and try to reproduce it on an RGB LED
//   //This does not work very well as is because of how colors/our eyes work
  
//   analogWrite(redPin, map(color.red, 0, 1024, 0, 255));
//   analogWrite(greenPin, map(color.green, 0, 1024, 0, 255));
//   analogWrite(bluePin, map(color.blue, 0, 1024, 0, 255));
// }

void DetecterCouleur(){

  colorSensor.ledOn();
  RGBC color = colorSensor.read(); //read the color
  // RGB color2(color.red, color.green, color.blue);
  // HSL color3 = RGBToHSL(color2);

  // Serial.print("H = ");
  // Serial.print(color3.H);
  // Serial.print("  | S = ");
  // Serial.print(color3.S);
  // Serial.print("  |  L = ");
  // Serial.println(color3.L);

  // if (color3.H > 200 && color3.H < 250){
  //   Serial.print("rouge : ");
  //   BruitCouleur();
  // } else if (color3.H > 200 && color3.H < 250){
  //   Serial.print("vert : ");
  //   BruitCouleur();
  // } else if (color3.H > 200 && color3.H < 250){
  //   Serial.print("bleu : ");
  //   BruitCouleur();
  // } else if (color3.H > 200 && color3.H < 250){
  //   Serial.print("jaune : ");
  //   BruitCouleur();
  // } else if (color3.H > 200 && color3.H < 250){
  //   Serial.print("blanc : ");
  //   BruitCouleur();
  // } else if (color3.H > 200 && color3.H < 250){
  //   Serial.print("noir : ");
  //   BruitCouleur();
  // }

  if (color.red > 1000 && color.green > 1000 && color.blue > 1000 && color.clear > 800) {
      //Serial.print("blanc : ");
      //BruitCouleur();
  }else if (color.red > 700 && color.green < 800 && color.blue < 400) {
      // Serial.print("rouge : ");
      BruitCouleur();
  }else if (color.red > 1000 && color.green > 1000 && color.blue < 800 && color.clear > 500) {
      // Serial.print("jaune : ");
      BruitCouleur();
  }else if (color.red < 400 && color.green < 400 && color.blue < 300 && color.clear > 150) {
      //Serial.print("vert : ");
      BruitCouleur();
  }else if (color.red < 400 && color.green < 400 && color.blue > 400 && color.clear > 200) {
      //Serial.print("bleu : ");
      BruitCouleur();
  }else if (color.red < 200 && color.green < 200 && color.blue < 200 && color.clear < 200) {
      //Serial.print("noir : ");
      //BruitCouleur();
  }


  // Serial.print(color.red);
  // Serial.print(" | ");
  // Serial.print(color.green);
  // Serial.print(" | ");
  // Serial.print(color.blue);
  // Serial.print(" | ");
  // Serial.println(color.clear);
}

#endif