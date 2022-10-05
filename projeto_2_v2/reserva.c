/*
* File: reserva.c
* Author: Jose Corte n-103210
* Description: The module for manipulating "reservas".
* Date: 2021/2022
*/

#include <stdio.h>
#include <string.h>
#include "list.h"
#include "voo.h"
#include "parsing.h"

#define NAO_EXISTE -1		/* Error Code */

#define TRUE 1			/* True */
#define FALSE 0			/* False */

#define MAX_LEN 65535 /* Max Len Buffer */
#define MAX_DIG 4   /* Max Digits */

extern int _numVoos;	/* Number of Flights */
extern Voo _voos[MAX_NUM_VOOS];	/* Flights Array */

int index, i;

int checkVoo(Voo v)
{
    /* Check Date */
    if (validaData(v.data) == FALSE)
    {
		printf("invalid date\n");
        return -1;
    } 

    /* Find Flight */
    index = encontraVoo(v.id, v.data);
    
    /* Check Flight Code */
    if(index == NAO_EXISTE)
    {
        printf("%s: flight does not exist\n", v.id);
        return -1;
    }
    return 0;
} 

void adicionaReserva() /* Adds an entry to the list of "reservas" */
{
    Voo v;
    int i, num, buffer_len;
    char buffer[MAX_LEN];

    /* Parsing*/
    leProximaPalavra(v.id);
    v.data = leData();

    /* Print Reservations */
    if (leProximaPalavra(buffer)) 
    {
        if(checkVoo(v) == -1) return;
        _voos[index].reservas = sort(_voos[index].reservas);
	    print(_voos[index].reservas);
	    return;
    }

    /* Parsing */
    scanf("%d", &num);
    leAteFimDeLinha();

    /* Check Flight */
    if(checkVoo(v) == -1) return;
    
    /* Check Code */
    buffer_len = strlen(buffer);
    if(buffer_len < 10)
    {
        printf("invalid reservation code\n");
        return;
    }
    for(i = 0; i < buffer_len; i++)
    {
        if((buffer[i] < 'A' || buffer[i] > 'Z') 
        && (buffer[i] < '0' || buffer[i] > '9'))
            {
                printf("invalid reservation code\n");
                return;
            }
    }

    /* Check Passagers Number */
    if(num <= 0)
    {
        printf("invalid passager number\n");
        return;
    }

    for(i = 0; i < _numVoos; i++)
        if(lookup(_voos[i].reservas, buffer) != NULL)
        {
            printf("%s: flight reservation already used\n", buffer);
            return;
        }

    /* Check Number of Reservations */
    if(_voos[index].numReservas + num > _voos[index].capacidade)
    {
        printf("too many reservations\n");
        return;
    }

    /* Load Array */

    if(_voos[index].reservas == NULL)
    {
        _voos[index].reservas = list_init(buffer, num);
        if(_voos[index].reservas == NULL)
            return;
    }
    else
    {
        _voos[index].reservas = append(_voos[index].reservas, buffer, num);
        if(_voos[index].reservas == NULL)
            return;
    }
    _voos[index].numReservas = _voos[index].numReservas + num;

    return;
}

void voo_del(int index)
{
    int i;

    for(i = index; i < _numVoos; i++)
        _voos[i] = _voos[i + 1];
    strcpy(_voos[i].id, "");
    _numVoos--;
    return;
}

void eliminaVoos(char code[])
{
    int i, found = 0;
    for (i = 0; i < _numVoos; i++)
		if (!strcmp(code, _voos[i].id))
        {
            found = 1;
            list_del(_voos[i].reservas);
            voo_del(i);
        }
    if(found == 0)
        printf("not found\n");
    return;
}

void eliminaReservas(char code[])
{
    int i, found = 0;

    for(i = 0; i < _numVoos; i++)
        if(lookup(_voos[i].reservas, code) != NULL)
        {
            found = 1;
            delete(_voos[i].reservas, code);
        }
    if(found == 0)
        printf("not found\n");
    return;
}

void elimina() /* Removes an entry from the list of "reservas" or "voos" */
{
    char code[MAX_LEN];

    scanf("%s", code);
    leAteFimDeLinha();
    if(strlen(code) < 10) eliminaVoos(code);
    else eliminaReservas(code);
    return;
}

void clean()
{
    int i;
    for(i = 0; i < _numVoos; i++)
        {
            list_del(_voos[i].reservas);
            voo_del(i);
        }
    return;
}