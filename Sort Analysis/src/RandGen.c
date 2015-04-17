/*
 * RandGen.c
 *
 *  Created on: 17-Apr-2015
 *      Author: aditya
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int genrandarr(int size)
{
	time_t t;
	srand((unsigned) time(&t));
	int *arr = malloc(sizeof(int)*size);
	if(!arr)
		return NULL;
	for(int i = 0; i < size; ++i)
		*(arr+i) = i;
	return arr;
}
