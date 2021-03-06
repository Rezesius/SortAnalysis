/*
 * QuickSort.c
 *
 *  Created on: 17-Apr-2015
 *      Author: aditya
 */

#include <stdio.h>
#include <stdlib.h>
#include "Swap.h"

/* This function is same in both iterative and recursive*/
int partition (int *array, int l, int h)
{
    int x = *(array + h);
    int i = (l - 1);

    for (int j = l; j <= h - 1; j++)
    {
        if (*(array + j) <= x)
        {
            i++;
            swap ((array + i), (array + j));
        }
    }
    swap ((array + i + 1), (array + h));
    return (i + 1);
}

void QuickSort(int *array, int l, int h)
{
	// Create an auxiliary stack
	int *stack = malloc(sizeof(int) * (h - l + 1));

	// initialize top of stack
	int top = -1;

	// push initial values of l and h to stack
	*(stack + ++top) = l;
	*(stack + ++top) = h;

	// Keep popping from stack while is not empty
	while ( top >= 0 )
	{
		// Pop h and l
	    h = *(stack + top--);
	    l = *(stack + top--);

	    // Set pivot element at its correct position in sorted array
	    int p = partition( array, l, h );

	    /* If there are elements on left side of pivot, then push left
	     side to stack */
	    if ( p - 1 > l )
	    {
	    	*(stack + ++top) = l;
	    	*(stack + ++top) = p - 1;
	    }

	    /* If there are elements on right side of pivot, then push right
	     side to stack */
	    if ( p + 1 < h )
	    {
	    	*(stack + ++top) = p + 1;
	    	*(stack + ++top) = h;
	    }
	}
}
