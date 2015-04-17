/*
 * BubbleSort.c
 *
 *  Created on: 17-Apr-2015
 *      Author: aditya
 */

#include "Swap.h"

void BubbleSort(int *array, int n)
{
   int i, j;
   for (i = 0; i < n; i++)
       for (j = 0; j < n-i-1; j++) //Last i elements are already in place
           if (*(array + j) > *(array + j + 1))
              swap((array + j), *(array + j + 1));
}
