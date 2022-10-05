/*
* File: main.c
* Author: Jose Corte n-103210
* Description: Segundo projeto da cadeira de IAED do IST.
* Date: 2021/2022
*/

/* Standard Library's */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Costum library's */ 
#include "parsing.h"
#include "aeroportos.h"

/* Main */
int main()
{
    int exit;

    char *par;
    char *input;

    exit = -1;
    while(exit != 0)
    {
        input = get_input();
        par = get_par(input, 0);

        switch(par[0])
        {
            case 'q':
                exit = 0;
                break;    
            case 'a':
                adicionaAeroporto(input);
                break;   
            case 'v':
                printf("Por implementar\n");
                break;    
            case 'l':
                printf("Por implementar\n");
                break;    
            case 't':
                printf("Por implementar\n");
                break;   
            case 'p':
                printf("Por implementar\n");
                break;    
            case 'c':
                printf("Por implementar\n");
                break;    
            default:
                printf("Command not found\n");
        }

    free(input);
    free(par);
    }

    return 0;
}