/*
* File: main.c
* Author: Jose Corte n-103210
* Description: The main for the second project of IAED of IST.
* Date: 2021/2022
*/

#include <stdio.h>
#include <stdlib.h>

#include "time.h"
#include "parsing.h"
#include "aeroporto.h"
#include "voo.h"
#include "reserva.h"
#include "list.h"

int main() {
	int c;

	while ((c = getchar()) != EOF) {
		switch (c) {
		case 'q': 
			return 0;
		case 'a': 
			adicionaAeroporto();
			break;
		case 'l': 
			listaAeroportos();
			break;
		case 'v': 
			adicionaListaVoos();
			break;
		case 'p': 
			listaVoosPartida();
			break;
		case 'c': 
			listaVoosChegada();
			break;
		case 't': 
			alteraData();
			break;
		case 'r':
			adicionaReserva();
			break;
		case 'e':
			elimina();
			break;
		default: 
			printf("Invalid comand: %c\n", c);
		}
	}
	clean();
	return 0;
}
