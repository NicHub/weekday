/**
 * weekday
 *
 * Copyright (C) 2019  Nicolas Jeanmonod, ouilogique.com
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 */

#include <Arduino.h>
#include "ctime_ext.h"
#include "tests.h"

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
    test1();
}

/**
 *
 */
void loop()
{
}
