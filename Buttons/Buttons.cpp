#include "Arduino.h"
#include "Timer.h"
#include "Buttons.h"

Timer mainT;
Timer dTimer;

Buttons::Buttons(int a, bool kind) {
	buttPin = a;
	if (kind)
	  pinMode (a, INPUT_PULLUP);
	else
	 pinMode (a, INPUT);
}

bool Buttons::Press() {
	buttRead = !digitalRead(buttPin);
	if (buttRead == 0) {
		buttPressed = 0;
		return false;
	}
	if (buttRead == 1 && buttPressed == 0) {
		mainT.resetT();
		mainT.startT();
		buttHold = 0;
		buttPressed = 1;
		return true;
	}
	if (buttPressed == 1) {
		return false;
	}
}

bool Buttons::Release() {
	buttRead = !digitalRead(buttPin);
	if (buttRead == 1) {
		buttState = 1;
		return false;
	}
	if (buttRead == 0 && buttState == 1) {
		buttState = 0;
		return true;
	}
	else
		return false;
}

bool Buttons::click() {
	if (Press())
		return false;

	if ((Release() == true) && (mainT.checkT() < buttDelay)) {
		mainT.resetT();
		return true;
	}
	else
		return false;
}

bool Buttons::Hold() {
	if (Press())
		return false;

	if (Release() == false && buttHold == 0 && mainT.checkT() >= buttDelay) {
		buttHold = 1;
		return true;
	}
	else 
		return false;
}

bool Buttons::Click() {
	doubleClick();
	if (c == true) {
		c = false;
		return true;
	}
	else
		return false;
}

bool Buttons::doubleClick() {
	if (dRun == 0 && click()) {
		dRun = 1;
		dTimer.startT();
		return false;
	}
	if ((click()) && (dTimer.checkT() <= buttDelay) && (dRun == 1)) {
		dRun = 0;
		dTimer.resetT();
		return true;
	}
	else if (dRun == 1 && dTimer.checkT() > buttDelay) {
		dRun = 0;
		dTimer.resetT();
		c = true;
		return false;
	}
	else
		return false;
}

void Buttons::help() {
	
	Serial.println("Buttons (int butt_pin, bool kind(0 - INPUT / 1 - INPUT_PULLUP))\n");
	Serial.println("Press(): returns true when you press down the button\n");
	Serial.println("Release(): returns true when you release the button\n");
	Serial.println("buttDelay: lets you set the delay used in the program - default = 400 mili seconds\n");
	Serial.println("click(): returns true when you click the button(without checking double click) - click = press & release within (buttDelay) mili seconds\n");
	Serial.println("Hold(): returns true when you hold the button for (buttDelay) mili seconds\n");
	Serial.println("doubleClick(): returns true if you click the twice within (buttDelay) mili seconds\n");
	Serial.println("Click(): returns true (buttDelay - mili seconds) after you click the button as long as you don't double click it\n");

}
