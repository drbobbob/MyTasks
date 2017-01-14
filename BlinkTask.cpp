/*
 * BlinkTask.cpp
 *
 *  Created on: Sep 5, 2015
 *      Author: DrBobBob
 */

#include "BlinkTask.h"
#include "Arduino.h"
//#include "PinDefinitions.h"

BlinkTask::BlinkTask(const int ledPin, uint32_t interval)
: TimedTask(millis())
, LEDPin(ledPin)
, Interval(interval)
, LEDState(false)
{
	pinMode(LEDPin, OUTPUT);
	// TODO Auto-generated constructor stub
}

BlinkTask::~BlinkTask() {
	// TODO Auto-generated destructor stub
}

void BlinkTask::run(uint32_t now)
{
	if(LEDState)
	{
		digitalWrite(LEDPin, false);
	}
	else
	{
		digitalWrite(LEDPin, true);
	}
	LEDState = !LEDState;
	incRunTime(Interval);
}
