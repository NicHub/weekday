/**
 * ctime_ext.h
 *
 * Extends ctime
 */

#pragma once

#include <ctime>

/**
 * getWeekDay
 *
 * Returns the day of the week.
 * 0 = Sunday
 * 6 = Saturday
 *
 * Original example:
 * http://www.cplusplus.com/reference/ctime/mktime/
 *
 */
int getWeekDay(int year, int month, int day)
{
    time_t rawtime;
    struct tm *timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    timeinfo->tm_year = year - 1900;
    timeinfo->tm_mon = month - 1;
    timeinfo->tm_mday = day;
    mktime(timeinfo);
    return timeinfo->tm_wday;
}
