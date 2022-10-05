/*
* File: parsing.c
* Author: Jose Corte
* Description: A costum parsing for comands built in c.
* Date: 04-04-2022
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char* get_input()
/* Reads the input of the user until a '\n' is found */
/* Returns the pointer to an array with the input */
{
    #define BUFFER 256

    char buffer[BUFFER];
    char *input;
    char c;
    int i;

    i = 0;
    do{
        c = getchar();
        buffer[i] = c;
        i++;
    } while(c != '\n');

    buffer[i] = '\0';

    input = (char*) malloc(i * sizeof(char));
    strcpy(input, buffer);
    return input;
}

char* get_par(char* input, int index) 
{
    /* Reads the input of the user until the index of the parameter is found */
    /* If the index is 0 then return only the first character */
    /* Returns the pointer to an array with the parameter */
    #define BUFFER 256

    char buffer[BUFFER];
    char *par;
    int i, k, count, len;

    if(index == 0)
    {
        /* Return the first charecter of the input */
        buffer[0] = input[0];
        buffer[1] = '\0';

        par = (char*) malloc(2 * sizeof(char));
        strcpy(par, buffer);
        return par;
    }
    else
    {
        /* Calculate the index of the desired parameter */
        i = 0;
        count = 0;
        len = strlen(input);  
        while(count < index && input[i] != '\0' && i < len)
        {
            if(input[i] == ' ' || input[i] == '\t')
            {
                count++;
                while (input[i] == ' ' || input[i] == '\t')
                {
                    i++;
                }
            }
            else i++;
        }

        /* Load the buffer */
        k = 0;
        while(input[i] != ' ' && input[i] != '\t' && input[i] != '\0')
        {
            buffer[k] = input[i];
            k++;
            i++; 
        }
        buffer[k] = '\0';

        /* Load and Return the string */
        par = (char*) malloc(k * sizeof(char));
        strcpy(par, buffer);
        return par;
    }
}

char* get_all_par(char* input, int index)
{
/* Reads the input of the user until the index of the parameter is found */
/* Returns the pointer to an array with the all the following parameters */

    #define BUFFER 256

    char buffer[BUFFER];
    char *par;
    int i, k, count, len;

    /* Calculate the index of the desired parameter */
    i = 0;
    count = 0;
    len = strlen(input);
    while(count < index && i < len && input[i] != '\0')
    {
        if(input[i] == ' ' || input[i] == '\t')
        {
            count++;
            while (input[i] == ' ' || input[i] == '\t')
            {
                    i++;
            }
        } else i++;
    }

    /* Load the buffer */
    k = 0;
    while(input[i] != '\0' && input[i] != '\n')
    {
        buffer[k] = input[i];
        i++;
        k++;
    }
    buffer[k] = '\0';

    /* Load and Return the string */
    par = (char*) malloc(k * sizeof(char));
    strcpy(par, buffer);
    return par;
}

