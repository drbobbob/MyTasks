/*
 * ButtonDebounceTask.cpp
 *
 *  Created on: Sep 6, 2015
 *      Author: DrBobBob
 */

#include "ButtonDebounceTask.h"
#include "Arduino.h"

const int POLL_MULTIPLIER = 4;

ButtonDebounceTask::ButtonDebounceTask(int pin, bool pullupEnabled, uint32_t settleTime)
:TimedTask(millis())
, Pin(pin)
, PollInterval(settleTime / POLL_MULTIPLIER)
, PrevState(false)
, StableCount(POLL_MULTIPLIER +1)
{
	if(pullupEnabled)
	{
		pinMode(Pin, INPUT_PULLUP);
		PrevState = true;
	}
	else
	{
		pinMode(Pin, INPUT);
	}
}

ButtonDebounceTask::~ButtonDebounceTask() {
	// TODO Auto-generated destructor stub
}

void ButtonDebounceTask::run(uint32_t now)
{
	bool newState = digitalRead(Pin);

	if(newState == PrevState)
	{
		StableCount++;
		if(StableCount == POLL_MULTIPLIER)
		{
			if(newState)
			{
				ButtonReleased();
			}
			else
			{
				ButtonPressed();
			}
		}
		else if(StableCount > POLL_MULTIPLIER)
		{
			StableCount = POLL_MULTIPLIER + 1;
		}
	}
	else
	{
		StableCount = 0;
	}

	PrevState = newState;
	incRunTime(PollInterval);
}

bool ButtonDebounceTask::IsPressed()
{
	return !digitalRead(Pin);
}
