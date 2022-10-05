/*
* File: coo.h
* Author: vmm
* Description: Header for the voo.c module.
* Date: 2021/2022
*/

#ifndef _VOO_
#define _VOO_

#include "time.h"
#include "list.h"

#define MAX_NUM_AEROPORTOS 40	/* número máximo de areoportos */
#define MAX_NUM_VOOS 30000	/* número máximo de voos */

#define MAX_CODIGO_AEROPORTO 4	/* dimensão do código do aeroporto */
#define MAX_NOME_PAIS 31	/* dimensão do nome do pais */
#define MAX_NOME_CIDADE 51	/* dimensão do nome da cidade */

#define MAX_CODIGO_VOO 7	/* dimensão do código do voo */
#define MAX_DATA 11		/* dimensão da data */
#define MAX_HORA 6		/* dimensão da hora */

typedef struct {
	char id[MAX_CODIGO_VOO];
	char partida[MAX_CODIGO_AEROPORTO];
	char chegada[MAX_CODIGO_AEROPORTO];
	Data data;
	Hora hora;
	Hora duracao;
	int capacidade;
	int horaPartida;
	int horaChegada;
	link reservas;
	int numReservas;
} Voo;

void mostraVoo(int index);
void mostraVooPartida(int index);
void mostraVooChegada(int index);
int encontraVoo(char id[], Data d);
int validaIDVoo(char id[]);
void criaVoo(Voo v);
void adicionaListaVoos();
int cmpVoosPartida(int a, int b);
int cmpVoosChegada(int a, int b);
void listaVoosPartida();
void listaVoosChegada();
void alteraData();

#endif