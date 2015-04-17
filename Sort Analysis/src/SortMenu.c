/*
 * SortMenu.c
 *
 *  Created on: 17-Apr-2015
 *      Author: aditya
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "QuickSort.h"
#include "MergeSort.h"
#include "RandGen.h"
#include "Structs.h"

#define out stdout
#define lim 100

void callsort()
{
	time_t t;
	clock_t start[], end[];
	double cpu_time_used[];
	srand((unsigned) time(&t));
	int *qs, size;
	size = rand() % lim;
	qs = genrandarr(size);
	start[0] = clock();
	QuickSort(qs, 0, size);
	end[0] = clock();
	cpu_time_used[0] = ((double) (end[0] - start[0])) / CLOCKS_PER_SEC;
	struct node *head = NULL;
	randgenlist(head, size);
	start[1] = clock();
	MergeSort(&head);
	end[1] = clock();
}
