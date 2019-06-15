#include <ctime>
#include <fstream>
#include "ctime_ext.h"

/**
 * This programs creates a file that can be run in Scilab to compare the results.
 * Execution is made in Scilab with the following command:
 * exec("~/Documents/PlatformIO/Projects/weekday/g++/scilab-vs-ctime.sci", -1)
 */

using namespace std;
ofstream scilab_file;

/**
 *
 */
int main()
{
    const char fname[20] = "scilab-vs-ctime.sci";
    scilab_file.open(fname);
    int weekDay;
    for (int year = 2000; year < 3001; year += 1)
    {
        for (int month = 1; month < 13; month += 1)
        {
            for (int day = 1; day < 3; day += 1)
            {
                weekDay = getWeekDay(year, month, day);
                // printf("%d-%d-%d => %d\n", year, month, day, weekDay);
                scilab_file << "d = datenum(" << year << "," << month << "," << day
                            << ",0,0,0); if(weekday(d) ~= " << (weekDay + 1)
                            << ") then disp(datevec(d)); end\n";
            }
        }
    }
    scilab_file << "disp('DONE.')\n";
    scilab_file.close();
    return 0;
}
