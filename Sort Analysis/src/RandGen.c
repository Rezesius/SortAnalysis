/*
 * RandGen.c
 *
 *  Created on: 17-Apr-2015
 *      Author: aditya
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Structs.h"

#define lim 1000

void alloc(struct node** head_ref, int new_data)
{
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int* genrandarr(int size)
{
	time_t t;
	srand((unsigned) time(&t));
	int *arr = malloc(sizeof(int)*size);
	if(!arr)
		return NULL;
	for(int i = 0; i < size; ++i)
		*(arr+i) = rand();
	return arr;
}

void genrandlist(struct node *head, int size)
{
	time_t t;
	srand((unsigned) time(&t));
	int data;
	for(int i = 0; i < size; i++)
	{
		data = rand() % lim;
		alloc(&head, data);
	}
}
