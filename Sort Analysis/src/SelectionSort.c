/*
 * SelectionSort.c
 *
 *  Created on: 17-Apr-2015
 *      Author: aditya
 */

#include "Swap.h"

void SelectionSort(int *array, int size)
{
    int i, j, min_idx;

    // One by one move boundary of unsorted sub array
    for (i = 0; i < size - 1; i++)
    {
        // Find the minimum element in unsorted array
    	min_idx = i;
        for (j = i + 1; j < size; j++)
        	if (*(array + j) < *(array + min_idx))
        		min_idx = j;

        // Swap the found minimum element with the first element
        swap((array + min_idx), (array + i));
    }
}
