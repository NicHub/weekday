/**
 * weekday
 */

#include <Arduino.h>
#include "ctime_ext.h"

/**
 *
 */
void setup()
{
    Serial.begin(115200);
    Serial.print("\n-- START --\n\n");
    Serial.print("Weekday = ");
    Serial.println(getWeekDay(2019, 6, 15));
    Serial.print("Weekday = ");
    Serial.println(getWeekDay(1900, 3, 1));
    Serial.print("Weekday = ");
    Serial.println(getWeekDay(1901, 1, 1));
    Serial.print("Weekday = ");
    Serial.println(getWeekDay(9999, 1, 1));
    Serial.print("Weekday = ");
    Serial.println(getWeekDay(2019, 6, 16));
}

/**
 *
 */
void loop()
{
}
