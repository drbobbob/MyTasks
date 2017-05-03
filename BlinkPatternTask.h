
#ifndef LEDBLINKCODE_H_
#define LEDBLINKCODE_H_

#include "Task.h"
#include "Arduino.h"

class BlinkPatternTask: public TimedTask
{
  public:
  
  BlinkPatternTask(int _pin, int _defaultValue=LOW, int _blinkDuration = 125, int _betweenBlinkDuration = 500, int _resetBlinkDuration = 1500);
  virtual ~BlinkPatternTask();

  virtual void run(uint32_t now);

  void setBlinkCounts(int first, int second);

  private:
    const int pin;
    const int defaultValue;
    const int blinkDuration;
    const int betweenBlinkDuration;
    const int resetBlinkDuration;

    int firstBlinkCount;
    int secondBlinkCount;

    int currentBlinkCount;
    bool blinkMode;    
};

#endif
