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
#include "CombSort.h"
#include "ShellSort.h"
#include "GnomeSort.h"
#include "RadixSort.h"
#include "RandGen.h"

#define out stdout

void callsort()
{
	FILE *fp;
	fp=fopen("./Time.dat", "ab+");
	time_t t;
	clock_t *start = malloc(sizeof(clock_t) * 10), *end = malloc(sizeof(clock_t) * 10);
	double *cpu_time_used = malloc(sizeof(double) * 10);
	srand((unsigned) time(&t));
	int *qs, *hs, *is, *ss, *bs, *cs, *shs, *gs, *rs;

	for(int i = 10000; i < 100000; i += 10000)
	{
		qs = genrandarr(i);
		*(start + 0) = clock();
		QuickSort(qs, 0, i);
		*(end + 0) = clock();
		*(cpu_time_used + 0) += ((double) (*(end + 0) - *(start + 0))) / CLOCKS_PER_SEC;
		fprintf(fp, "%lf ", *(cpu_time_used + 0));
	}
	fprintf(fp, "\n");

	for(int i = 10000; i < 100000; i += 10000)
	{
		struct node *head = (struct node*) malloc(sizeof(struct node));
		genrandlist(head, i);
		*(start + 1) = clock();
		MergeSort(head);
		*(end + 1) = clock();
		*(cpu_time_used + 1) = ((double) (*(end + 1) - *(start + 1))) / CLOCKS_PER_SEC;
		fprintf(fp, "%lf ", *(cpu_time_used + 1));
	}
	fprintf(fp, "\n");


	for(int i = 10000; i < 100000; i += 10000)
	{
		hs = genrandarr(i);
		*(start + 2) = clock();
		HeapSort(hs, i);
		*(end + 2) = clock();
		*(cpu_time_used + 2) = ((double) (*(end + 2) - *(start + 2))) / CLOCKS_PER_SEC;
		fprintf(fp, "%lf ", *(cpu_time_used + 2));
	}
	fprintf(fp, "\n");


	for(int i = 10000; i < 100000; i += 10000)
	{
		is = genrandarr(i);
		*(start + 3) = clock();
		InsertionSort(is, i);
		*(end + 3) = clock();
		*(cpu_time_used + 3) = ((double) (*(end + 3) - *(start + 3))) / CLOCKS_PER_SEC;
		fprintf(fp, "%lf ", *(cpu_time_used + 3));
	}
	fprintf(fp, "\n");

	for(int i = 10000; i < 100000; i += 10000)
	{
		ss = genrandarr(i);
		*(start + 4) = clock();
		SelectionSort(ss, i);
		*(end + 4) = clock();
		*(cpu_time_used + 4) = ((double) (*(end + 4) - *(start + 4))) / CLOCKS_PER_SEC;
		fprintf(fp, "%lf ", *(cpu_time_used + 4));
	}
	fprintf(fp, "\n");

	for(int i = 10000; i < 100000; i += 10000)
	{
		bs = genrandarr(i);
		*(start + 5) = clock();
		BubbleSort(bs, i);
		*(end + 5) = clock();
		*(cpu_time_used + 5) = ((double) (*(end + 5) - *(start + 5))) / CLOCKS_PER_SEC;
		fprintf(fp, "%lf ", *(cpu_time_used + 5));
	}
	fprintf(fp, "\n");

	for(int i = 10000; i < 100000; i += 10000)
	{
		cs = genrandarr(i);
		*(start + 6) = clock();
		CombSort(cs, i);
		*(end + 6) = clock();
		*(cpu_time_used + 6) = ((double) (*(end + 6) - *(start + 6))) / CLOCKS_PER_SEC;
		fprintf(fp, "%lf ", *(cpu_time_used + 6));
	}
	fprintf(fp, "\n");

	for(int i = 10000; i < 100000; i += 10000)
	{
		shs = genrandarr(i);
		*(start + 7) = clock();
		ShellSort(shs, i);
		*(end + 7) = clock();
		*(cpu_time_used + 7) = ((double) (*(end + 7) - *(start + 7))) / CLOCKS_PER_SEC;
		fprintf(fp, "%lf ", *(cpu_time_used + 7));
	}
	fprintf(fp, "\n");

	for(int i = 10000; i < 100000; i += 10000)
	{
		gs = genrandarr(i);
		*(start + 8) = clock();
		GnomeSort(gs, i);
		*(end + 8) = clock();
		*(cpu_time_used + 8) = ((double) (*(end + 8) - *(start + 8))) / CLOCKS_PER_SEC;
		fprintf(fp, "%lf ", *(cpu_time_used + 8));
	}
	fprintf(fp, "\n");

	for(int i = 10000; i < 100000; i += 10000)
	{
		rs = genrandarr(i);
		*(start + 9) = clock();
		RadixSort(rs, i);
		*(end + 9) = clock();
		*(cpu_time_used + 9) = ((double) (*(end + 9) - *(start + 9))) / CLOCKS_PER_SEC;
		fprintf(fp, "%lf ", *(cpu_time_used + 9));
	}
	fprintf(fp, "\n");
	int fclose(FILE *fp);
}
