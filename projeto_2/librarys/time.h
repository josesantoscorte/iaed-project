/*
* File: time.h
* Author: Jose Corte
* Description: The headder for the time.c module.
* Date: 02-04-2022
*/

/* Date Declaration */
typedef struct Date {
    int day;
    int month;
    int year;
} Date;

/* Hour Declaration */
typedef struct Hour {
    int hour;
    int min;
} Hour;

int date_comp(Date d1, Date d2);
int date_day(Date d);
Hour sum_hour(Hour h1, Hour h2);