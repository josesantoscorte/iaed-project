/*
* File: time.c
* Author: Jose Corte
* Description: A time module for c.
* Date: 02-04-2022
*/

#include "time.h"

/* Date Functions */
int date_comp(Date d1, Date d2) 
/* Compares tow dates */
/* Returns 0 if equal, 1 if d1 < d2 and -1 if d2 < d1 */
{
    if(d1.year == d2.year && d1.month == d2.month && d1.day == d2.day) return 0;
    if(d1.day < d2.day && d1.month <= d2.month && d1.year <= d2.year) return 1;
    if(d1.month < d2.month && d1.year <= d2.year) return 1;
    if(d1.year < d2.year) return 1;
    return -1;
}

int date_day(Date d) 
/* Returns the relative day of the year */
/* Dose not work for leap years! */
{
    #define MONTHS 12

    int day = 0;
    int i;
    int month[MONTHS] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    day += d.day;
    if(d.month != 1)
    {
        for(i = 0; i < d.month - 1; i++)
        {
            day += month[i];
        }
    }
    return day;
}

Hour sum_hour(Hour h1, Hour h2) 
/* Caculates the sum of tow hours */
/* If the result hour is bigger than a day, then loops back */
{
    Hour res;

    res.hour = 0;
    res.min = 0;

    if(h1.min + h2.min < 60 && h1.hour + h2.hour < 24)
    {
        res.hour = h1.hour + h2.hour;
        res.min = h1.min + h2.min;
        return res;
    }
    if(h1.min + h2.min >= 60)
    {
        if(h1.hour + h2.hour + 1 < 24)
        {
            res.hour = h1.hour + h2.hour + 1;
            res.min = h1.min + h2.min - 60;
            return res;
        }
        else
        {
            res.hour = h1.hour + h2.hour - 24 + 1;
            res.min = h1.min + h2.min - 60;
            return res;
        }
    }
    if(h1.hour + h2.hour >= 24)
    {
        if(h1.min + h2.min < 60)
        {
            res.hour = h1.hour + h2.hour - 24;
            res.min = h1.min + h2.min; 
            return res;
        }
        else
        {
            res.hour = h1.hour + h2.hour - 24 + 1;
            res.min = h1.min + h2.min - 60; 
            return res;    
        }
    }
    return res;
}