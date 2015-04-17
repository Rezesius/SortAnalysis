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
#include "InsertionSort.h"
#include "SelectionSort.h"
#include "BubbleSort.h"
#include "BucketSort.h"
#include "CombSort.h"
#include "RandGen.h"
#include "Structs.h"

#define out stdout
#define lim 100

void callsort()
{
	time_t t;
	clock_t start[100], end[100]; //Needs to be changed. Reduce 100 to number of sorting techniques
	double cpu_time_used[100];    //used in the program
	srand((unsigned) time(&t));
	int *qs, size, *hs, *is, *ss, *bs, *bucs, *cs;
	size = rand() % lim;
	qs = genrandarr(size);
	hs = genrandarr(size);
	is = genrandarr(size);
	ss = genrandarr(size);
	bs = genrandarr(size);
	bucs = genrandarr(size);
	cs = genrandarr(size);
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
	start[3] = clock();
	InsertionSort(is, size);
	end[3] = clock();
	cpu_time_used[3] = ((double) (end[3] - start[3])) / CLOCKS_PER_SEC;
	start[4] = clock();
	SelectionSort(ss, size);
	end[4] = clock();
	cpu_time_used[4] = ((double) (end[4] - start[4])) / CLOCKS_PER_SEC;
	start[5] = clock();
	BubbleSort(bs, size);
	end[5] = clock();
	cpu_time_used[5] = ((double) (end[5] - start[5])) / CLOCKS_PER_SEC;
	start[6] = clock();
	BucketSort(bucs, size);
	end[6] = clock();
	cpu_time_used[6] = ((double) (end[7] - start[7])) / CLOCKS_PER_SEC;
	start[7] = clock();
	CombSort(cs, size);
	end[7] = clock();
	cpu_time_used[7] = ((double) (end[7] - start[7])) / CLOCKS_PER_SEC;
}
