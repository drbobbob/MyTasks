/*
 * ButtonDebounceTask.h
 *
 *  Created on: Sep 6, 2015
 *      Author: DrBobBob
 */

#ifndef BUTTONDEBOUNCETASK_H_
#define BUTTONDEBOUNCETASK_H_

#include <Task.h>

class ButtonDebounceTask: public TimedTask {
public:
	ButtonDebounceTask(int pin, bool pullupEnabled = false, uint32_t settleTime = 40);
	virtual ~ButtonDebounceTask();

	virtual void ButtonPressed() = 0;
	virtual void ButtonReleased() = 0;

	virtual void run(uint32_t now);

protected:
	const int Pin;
private:
	const uint32_t PollInterval;
	bool PrevState;
	int StableCount;

};

#endif /* BUTTONDEBOUNCETASK_H_ */
