
#include "BlinkPatternTask.h"
#include <Arduino.h>

BlinkPatternTask::BlinkPatternTask(int _pin, int _defaultValue, int _blinkDuration, int _betweenBlinkDuration, int _resetBlinkDuration)
: TimedTask(1)
, pin(_pin)
, defaultValue(_defaultValue)
, blinkDuration(_blinkDuration)
, betweenBlinkDuration(_betweenBlinkDuration)
, resetBlinkDuration(_resetBlinkDuration)
, firstBlinkCount(2)
, secondBlinkCount(2)
, currentBlinkCount(2)
, blinkMode(false)
{
  pinMode(pin, OUTPUT);
  digitalWrite(pin, defaultValue);
}

BlinkPatternTask::~BlinkPatternTask()
{

  
}

void BlinkPatternTask::run(uint32_t now)
{
  digitalWrite(pin, !digitalRead(pin));
  currentBlinkCount--;
  if(currentBlinkCount == 0)
  {
    //need to switch blink mode
    if(blinkMode)
    {
      incRunTime(resetBlinkDuration);
      blinkMode = false;
      currentBlinkCount = firstBlinkCount;
    }
    else
    {
      incRunTime(betweenBlinkDuration);
      blinkMode = true;
      currentBlinkCount = secondBlinkCount;
    }
  }
  else
  {
    incRunTime(blinkDuration);
  }
}

void BlinkPatternTask::setBlinkCounts(int first, int second)
{
  digitalWrite(pin, defaultValue);
  firstBlinkCount = 2 * first;
  secondBlinkCount = 2 * second;
  blinkMode = false;
  setRunTime(millis());
}

