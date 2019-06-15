/**
 * weekday.cpp
 *
 * This programs creates a file that can be run in Scilab to compare the results.
 * Execution is made in Scilab with the following command:
 * exec("~/Documents/PlatformIO/Projects/weekday/g++/scilab-vs-ctime.sci", -1)
 *
 * It also creates a .h file that can be used to check if the desktop and the
 * embedded version of ctime are consistent.
 *
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

#include <ctime>
#include <fstream>
#include "ctime_ext.h"

using namespace std;
ofstream out_file;

/**
 *
 */
int make_scilab_file()
{
    const char fname[20] = "scilab-vs-ctime.sci";
    out_file.open(fname);
    int weekDay;
    for (int year = 2000; year < 3001; year += 1)
    {
        for (int month = 1; month < 13; month += 1)
        {
            for (int day = 1; day < 3; day += 1)
            {
                weekDay = getWeekDay(year, month, day);
                // printf("%d-%d-%d => %d\n", year, month, day, weekDay);
                out_file << "d = datenum(" << year << "," << month << "," << day
                         << ",0,0,0); if(weekday(d) ~= " << (weekDay + 1)
                         << ") then disp(datevec(d)); end\n";
            }
        }
    }
    out_file << "disp('DONE.')\n";
    out_file.close();
    return 0;
}

/**
 *
 */
int make_arduino_file()
{
    const char fname[20] = "../src/tests.h";
    out_file.open(fname);
    int weekDay;
    out_file << "#pragma once\n";
    out_file << "#include \"ctime_ext.h\"\n";
    out_file << "void test1()\n{\nint weekDay;\n";
    for (int year = 2000; year < 2120; year += 1)
    {
        // out_file << "Serial.println(\"YEAR = " << year << "\");\n";
        for (int month = 1; month < 13; month += 1)
        {
            for (int day = 1; day < 7; day += 1)
            {
                weekDay = getWeekDay(year, month, day);
                // printf("%d-%d-%d => %d\n", year, month, day, weekDay);
                out_file << "weekDay = getWeekDay("
                         << year << ", " << month << ", " << day
                         << "); if(weekDay != " << (weekDay)
                         << "){ Serial.println(\"Error on "
                         << year << "-" << month << "-" << day
                         << "\"); }\n";
            }
        }
    }
    out_file << "Serial.println(\"TEST 1 DONE\");\n";
    out_file << "}";
    out_file.close();
    return 0;
}

/**
 *
 */
int main()
{
    make_arduino_file();
    make_scilab_file();
    return 0;
}
