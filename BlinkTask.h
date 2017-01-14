/*
 * BlinkTask.h
 *
 *  Created on: Sep 5, 2015
 *      Author: DrBobBob
 */

#ifndef BLINKTASK_H_
#define BLINKTASK_H_

#include <Task.h>

class BlinkTask: public TimedTask {
public:
	BlinkTask(const int ledPin, uint32_t interval);
	virtual ~BlinkTask();

	virtual void run(uint32_t now);

private:
	const int LEDPin;
	const uint32_t Interval;
	bool LEDState;
};

#endif /* BLINKTASK_H_ */
