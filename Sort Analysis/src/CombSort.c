/*
 * CombSort.c
 *
 *  Created on: 17-Apr-2015
 *      Author: aditya
 */

int newgap(int gap)
{
    gap = (gap * 10) / 13;
    if (gap == 9 || gap == 10)
        gap = 11;
    if (gap < 1)
        gap = 1;
    return gap;
}

/*Function to implement the combsort*/
void CombSort(int *array, int size)
{
    int gap = size;
    int temp, i;
    for ( ; ; )
    {
        gap = newgap(gap);
        int swapped = 0;
        for (i = 0; i < size - gap; i++)
        {
            int j = i + gap;
            if (*(array + i) > *(array + j))
            {
                temp = *(array + i);
                *(array + i) = *(array + j);
                *(array + j) = temp;
                swapped  =  1;
            }
        }
        if (gap  ==  1 && !swapped)
        	break;
    }
}
