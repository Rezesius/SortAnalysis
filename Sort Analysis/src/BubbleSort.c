/*
 * BubbleSort.c
 *
 *  Created on: 17-Apr-2015
 *      Author: aditya
 */

#include "Swap.h"

void BubbleSort(int *array, int size)
{
   int i, j;
   for (i = 0; i < size; i++)
       for (j = 0; j < size-i-1; j++) //Last i elements are already in place
           if (*(array + j) > *(array + j + 1))
              swap((array + j), (array + j + 1));
}
