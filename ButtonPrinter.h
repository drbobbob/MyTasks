/*
 * ButtonPrinter.h
 *
 *  Created on: Sep 6, 2015
 *      Author: DrBobBob
 */

#ifndef BUTTONPRINTER_H_
#define BUTTONPRINTER_H_

#include "ButtonDebounceTask.h"

class ButtonPrinter: public ButtonDebounceTask {
public:
	ButtonPrinter(int pin);
	virtual ~ButtonPrinter();

	virtual void ButtonPressed();
	virtual void ButtonReleased();
};

#endif /* BUTTONPRINTER_H_ */
