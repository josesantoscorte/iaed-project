/*
* File: aeroporto.h
* Author: vmm
* Description: Header for the aeroporto.c module.
* Date: 2021/2022
*/

#ifndef _AEROPORTO_
#define _AEROPORTO_

#define MAX_NUM_AEROPORTOS 40	/* número máximo de areoportos */

#define MAX_CODIGO_AEROPORTO 4	/* dimensão do código do aeroporto */
#define MAX_NOME_PAIS 31	/* dimensão do nome do pais */
#define MAX_NOME_CIDADE 51	/* dimensão do nome da cidade */

typedef struct {
	char id[MAX_CODIGO_AEROPORTO];
	char pais[MAX_NOME_PAIS];
	char cidade[MAX_NOME_CIDADE];
	int numVoos;
} Aeroporto;

int aeroportoInvalido(char id[]);
int encontraAeroporto(char id[]);
void adicionaAeroporto();
void mostraAeroporto(int index);
int cmpAeroportos(int a, int b);
void listaTodosAeroportos();
void listaAeroportos();

#endif