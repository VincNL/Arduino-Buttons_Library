/*
 * Example that shows basic identifying of the button's actions
 * 
 * Connect a button to pin no. 8 and open the serial monitor
 * 
 * For further explanations about the library read the README file
 * Library written by VincNL
 */


#include <Buttons.h>
#include <Timer.h>

Timer t1; //Sets new Timer called t1 - used to delay the button's functions without delaying the whole loop.
Buttons button(8, 1); //Sets pin no. 8 as 1 (INPUT_PULLUP)
//Buttons button(8, 0); //uncomment this line and remove the one above if you use a resistor with your button

void setup() {
  Serial.begin(9600);
}

void loop() {
  if (t1.stopClock(20)) { //Every 20 mili seconds - it checks if the button did any of the actions below
    if (button.doubleClick())  //Checks if you double clicked the button
      Serial.println("double click\n");
    if (button.Click()) //Checks if you clicked the button once
      Serial.println("click\n");
    if (button.Hold()) //Checks if you hold the button
      Serial.println("hold\n");
  }
}
