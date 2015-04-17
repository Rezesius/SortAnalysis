/*
 * BucketSort.c
 *
 *  Created on: 17-Apr-2015
 *      Author: aditya
 */

void BucketSort(int *array, int size)
{
    int i, j;
    int *count = malloc(sizeof(int) * size);
    for (i = 0; i < size; i++)
        *(count + i) = 0;

    for (i = 0; i < size; i++)
        (*(count + *(array + i)))++;

    for (i = 0, j = 0; i < size; i++)
        for(; *(count + i) > 0; (*(count + i))--)
            *(array + j++) = i;
}
