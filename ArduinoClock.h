/*
	MIT License

	Copyright (c) 2022 Evgeny Oskolkov (ea dot oskolkov at yandex.ru)
	Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
	The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#ifndef ArduinoClock_h
#define ArduinoClock_h

#include <inttypes.h>

struct Time_t
{
  uint8_t hours = 0;
  uint8_t mins = 0;
  uint8_t sec = 0;
};

// Build time
#define BUILD_HOUR ((unsigned)((__TIME__[0] - '0') * 10) + (__TIME__[1] - '0'))
#define BUILD_MIN ((unsigned)((__TIME__[3] - '0') * 10) + (__TIME__[4] - '0'))
#define BUILD_SEC ((unsigned)((__TIME__[6] - '0') * 10) + (__TIME__[7] - '0'))

/**
 * Returns the current time in ms. Overflow in 18446744073709551615 ms (584942417.35507 year).
 * No more than (millisMax-1, ~50 days) milliseconds must have elapsed since the last call.
 * 
 */
uint64_t exMillis();

/**
 * Sets the time from which the countdown starts.
 * 
*/
void setupTime(int h, int m, int s = 0);

/**
 * Returns the current time.
 * To avoid overflow every ~50 days, you need to call the function once every ~50 days.
 * 
*/
Time_t getTime();

#endif