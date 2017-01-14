/*
 * ButtonPrinter.cpp
 *
 *  Created on: Sep 6, 2015
 *      Author: DrBobBob
 */

#include "ButtonPrinter.h"
#include "Arduino.h"

ButtonPrinter::ButtonPrinter(int pin)
: ButtonDebounceTask(pin, true)
{
	// TODO Auto-generated constructor stub

}

ButtonPrinter::~ButtonPrinter() {
	// TODO Auto-generated destructor stub
}

void ButtonPrinter::ButtonPressed()
{
	Serial.write("Button Pressed ");
	Serial.print(Pin);
	Serial.write('\n');
}

void ButtonPrinter::ButtonReleased()
{
	Serial.write("Button Released ");
	Serial.print(Pin);
	Serial.write('\n');
}
