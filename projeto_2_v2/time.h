/*
* File: time.h
* Author: vmm
* Description: Header for the time.c module.
* Date: 2021/2022
*/

#ifndef _TIME_
#define _TIME_

typedef struct {
	int dia;
	int mes;
	int ano;
} Data;

typedef struct {
	int hora;
	int minuto;
} Hora;

Hora leHora();
Data leData();
void mostraData(Data d);
void mostraHora(Hora h);
int converteDataNum(Data d);
int converteHoraNum(Hora h);
int converteDataHoraNum(Data d, Hora h);
Hora converteNumHora(int num);
Data converteNumData(int num);
int validaData(Data d);
int validaHora(Hora h);

#endif

