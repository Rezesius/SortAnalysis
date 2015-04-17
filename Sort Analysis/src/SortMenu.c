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
#include "HeapSort.h"
#include "RandGen.h"
#include "Structs.h"

#define out stdout
#define lim 100

void callsort()
{
	time_t t;
	clock_t start[100], end[100];
	double cpu_time_used[100];
	srand((unsigned) time(&t));
	int *qs, size, *hs;
	size = rand() % lim;
	qs = genrandarr(size);
	hs = genrandarr(size);
	start[0] = clock();
	QuickSort(qs, 0, size);
	end[0] = clock();
	cpu_time_used[0] = ((double) (end[0] - start[0])) / CLOCKS_PER_SEC;
	struct node *head = NULL;
	genrandlist(head, size);
	start[1] = clock();
	cpu_time_used[1] = ((double) (end[1] - start[1])) / CLOCKS_PER_SEC;
	MergeSort(head);
	end[1] = clock();
	start[2] = clock();
	HeapSort(hs, size);
	end[2] = clock();
	cpu_time_used[2] = ((double) (end[2] - start[2])) / CLOCKS_PER_SEC;

}
