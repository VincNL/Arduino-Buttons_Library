/*
 * Example that prints the library's functions to the serial montior
 * 
 * You don't have to use button for this program to work
 * 
 * For further explanations about the library read the README file
 * 
 * Library written by VincNL
 * GitHub: https://github.com/VincNL
 */
 
#include <Buttons.h>

Buttons b1(7, 0); //Sets pin no. 7 as INPUT

void setup() {

  Serial.begin(9600);
  b1.help(); // Prints the library's functions to the serial montior with short explanations
  
}

void loop() {
  
}
