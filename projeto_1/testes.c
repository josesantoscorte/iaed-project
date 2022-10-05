#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct Hour {
    int hour;
    int min;
} Hour;

Hour hour_add(Hour h1, Hour h2) /* Cacula a soma de duas horas */
{
    Hour hres;

    hres.hour = 0;
    hres.min = 0;

    if(h1.min + h2.min < 60 && h1.hour + h2.hour < 24)
    {
        hres.hour = h1.hour + h2.hour;
        hres.min = h1.min + h2.min;
        return hres;
    }
    if(h1.min + h2.min >= 60)
    {
        if(h1.hour + h2.hour + 1 < 24)
        {
            hres.hour = h1.hour + h2.hour + 1;
            hres.min = h1.min + h2.min - 60;
            return hres;
        }
        else
        {
            hres.hour = h1.hour + h2.hour - 24 + 1;
            hres.min = h1.min + h2.min - 60;
            return hres;
        }
    }
    if(h1.hour + h2.hour >= 24)
    {
        if(h1.min + h2.min < 60)
        {
            hres.hour = h1.hour + h2.hour - 24;
            hres.min = h1.min + h2.min; 
            return hres;
        }
        else
        {
            hres.hour = h1.hour + h2.hour - 24 + 1;
            hres.min = h1.min + h2.min - 60; 
            return hres;    
        }
    }
    return hres;
}

int main()
{
    Hour h1, h2, hres;

    scanf("%d:%d", &h1.hour, &h1.min);
    scanf("%d:%d", &h2.hour, &h2.min);

    hres = hour_add(h1, h2);

    printf("Hora Soma: %02d:%02d\n", hres.hour, hres.min);

    return 0;
}