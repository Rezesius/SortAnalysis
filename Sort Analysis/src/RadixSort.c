/*
 * RadixSort.c
 *
 *  Created on: 17-Apr-2015
 *      Author: aditya
 */

#include <stdlib.h>

// A utility function to get maximum value in array
int getMax(int *array, int size)
{
    int mx = *(array + 0);
    for (int i = 1; i < size; i++)
        if (*(array + i) > mx)
            mx = *(array + i);
    return mx;
}

// A function to do counting sort of array according to
// the digit represented by exp.
void countSort(int *array, int size, int exp)
{
    int *output = malloc(sizeof(int) * size); // output array
    int i, *count = malloc(sizeof(int) * 10);

    // Store count of occurrences in count[]
    for (i = 0; i < size; i++)
    	(*(count + (*(array + i) / exp) % 10 ))++;

    // Change count[i] so that count[i] now contains actual position of
    // this digit in output[]
    for (i = 1; i < 10; i++)
        *(count + i) += *(count + i - 1);

    // Build the output array
    for (i = size - 1; i >= 0; i--)
    {
        *(output + *(count + (*(array + i)/exp)%10 ) - 1) = *(array +i);
        (*(count + (*(array + i) / exp) %10 ))--;
    }

    // Copy the output array to array[], so that array[] now
    // contains sorted numbers according to current digit
    for (i = 0; i < size; i++)
    	*(array + i) = *(output + i);
}

// The main function to that sorts array[] of size n using Radix Sort
void RadixSort(int *array, int size)
{
    // Find the maximum number to know number of digits
    int m = getMax(array, size);

    // Do counting sort for every digit. Note that instead of passing digit
    // number, exp is passed. exp is 10^i where i is current digit number
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(array, size, exp);
}
