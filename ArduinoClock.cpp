/*
	MIT License

	Copyright (c) 2022 Evgeny Oskolkov (ea dot oskolkov at yandex.ru)
	Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
	The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#include "ArduinoClock.h"
#include <Arduino.h>

static uint64_t TStart = 0;

// Extended millis (64-bit)
static uint64_t exMsCounter = 0;
static unsigned long lastMs = 0;
static constexpr unsigned long millisMax = -1UL;

Time_t getTime()
{
  Time_t ret;

  const auto currentMs = exMillis() + TStart;

  ret.hours = (currentMs / 60 / 60 / 1000) % 24;
  ret.mins = (currentMs / 60 / 1000) % 60;
  ret.sec = (currentMs / 1000) % 60;

  return ret;
}

uint64_t exMillis()
{
  const auto currentMillis = millis();
  if (currentMillis < lastMs)
  {
    // Overflow, increase extended counter
    exMsCounter += millisMax;
  }
  lastMs = currentMillis;

  return (uint64_t)currentMillis + exMsCounter;
}

void setupTime(int h, int m, int s = 0)
{
  TStart = ((uint64_t)h * 60 * 60 * 1000) + ((uint64_t)m * 60 * 1000) + ((uint64_t)s * 1000);
}
