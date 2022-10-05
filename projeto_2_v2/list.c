/*
* File: list.c
* Author: Jose Corte n-103210
* Description: A list module to manipulate strings.
* Date: 2021/2022
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "list.h"

#define TRUE 1			/* True */
#define FALSE 0			/* False */

link list_init(char* string, int value)
{
    link head = (link) malloc(sizeof(struct node));
    if(head == NULL)
    {
        printf("No memory\n");
        return NULL;
    }
    head->next = NULL;
    head->string = (char*) malloc(sizeof(char) * (strlen(string) + 1));
    if(head->string == NULL)
    {
        printf("No memory\n");
        return NULL;
    }
    strcpy(head->string, string);
    head->value = value;
    return head;
}

void list_del(link head)
{
    link next;
    if(head == NULL) 
        return;
    for(next = head->next; next != NULL; head = next, next = next->next)
        {
            free(head->string);
            free(head);
        }
}

link append(link head, char* buffer, int value)
{
    link new = (link) malloc(sizeof(struct node));
    if(new == NULL)
    {
        printf("No memory\n");
        return NULL;
    }
    new->string = (char*) malloc(sizeof(char)*(strlen(buffer)+1));
    if(new->string == NULL)
    {
        printf("No memory\n");
        return NULL;
    }
    strcpy(new->string, buffer);
    new->value = value;
    new->next = head; 
    return new;
}

link lookup(link head, char* string)
{
    link temp;

    if(head == NULL)
        return NULL;
    for(temp = head; temp != NULL; temp = temp->next)
        if(!strcmp(temp->string, string))
            return temp;
    return NULL;
}

void print(link head)
{
    link temp;
    for(temp = head; temp != NULL; temp = temp->next)
        if(temp->value <= 100 && temp->value >= 0)
            printf("%s %d\n",temp->string, temp->value);
}

link delete(link head, char* string)
{
    link temp, prev;
    if(head == NULL) 
        return head;
    if(head->next == NULL)
        list_del(head);
    for(temp = head, prev = NULL; temp != NULL; prev = temp, temp = temp->next) 
    {
        if(strcmp(temp->string, string) == 0) 
        {
            if(temp == head)
                head = temp->next;
            else
                prev->next = temp->next; 
            free(temp->string);
            free(temp);
            break;
        }
    }
    return head;
}

int cmpCode(char code1[], char code2[])
/* Comperes tow strings, return 0 if equal, 
1 if code1 < code2 and -1 otherwise */ 
{
    int len1, len2, max, i;

    len1 = strlen(code1);
    len2 = strlen(code2);
    
    if(len1 < len2)
        max = len1;
    else
        max = len1;
    
    for(i = 0; i <= max; i++)
    {
        if(code1[i] > 'A' && code2[i] > 'A')
            {
                if(code1[i] < code2[i])
                    return 1;
                if(code1[i] > code2[i])
                    return -1;
            }
        if(code1[i] > 'A' && code2[i] < 'A')
            return -1;
        if(code1 [i] < 'A' && code2[i] > 'A')
            return 1;
        if(code1[i] < 'A' && code2[i] < 'A')
        {
            if(code1[i] < code2[i])
                return 1;
            if(code1[i] > code2[i])
                return -1;
        }
    }
    return 0;
}

link sort(link head)
{
    link now, prev, prev_prev;
    int swap = TRUE;

    while(swap == TRUE)
    {
        swap = FALSE;
        for(now = head, prev = NULL, prev_prev = NULL; 
        now != NULL; prev_prev = prev, prev = now, now = now->next)
        {
            if(prev == head && cmpCode(prev->string, now->string) == -1)
            {
                prev->next = now->next;
                now->next = prev;
                head = now;
                swap = TRUE;
            }
            if(prev_prev != NULL && cmpCode(prev->string, now->string) == -1)
                {
                    prev->next = now->next;
                    now->next = prev;
                    prev_prev->next = now;
                    swap = TRUE;
                }
        }
    }
    return head;
}