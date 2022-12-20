# Overview
A library for Arduino that implements a volatile clock. Accuracy to seconds.
Millis overflow protection implemented.
Implemented in C++.

# Interface
``` C
struct Time_t
{
  uint8_t hours = 0;
  uint8_t mins = 0;
  uint8_t sec = 0;
};

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
```

# Example

``` C
setTime(BUILD_HOUR, BUILD_MIN, BUILD_SEC);

const Time_t& tm = getTime(); // Use exMillis()

Serial.println(tm.hours); // Out hours
Serial.println(tm.mins);  // Out minutes
Serial.println(tm.sec);   // Out seconds
```

 # LICENSE

This software is distributed under [MIT](https://opensource.org/licenses/MIT) license.
