/*
* File: list.h
* Author: Jose Corte n-103210
* Description: Header for the list.c module.
* Date: 2021/2022
*/

#include <stdlib.h>

#ifndef _LIST_
#define _LIST_

typedef struct node{
    char *string;
    int value;
    struct node *next;
} *link;

link list_init(char* string, int value);
void list_del(link head);
link append(link head, char* string, int value);
link lookup(link head, char* string);
void print(link head);
link delete(link head, char* string);
int cmpCode(char code1[], char code2[]);
link sort(link head);

#endif

