/*
 * ShellSort.c
 *
 *  Created on: 17-Apr-2015
 *      Author: aditya
 */

void ShellSort(int *array, int size)
{
	int i = 0, j = 0, k = 0, mid = 0;
	for (k = size / 2; k > 0; k /= 2)
	{
		for (j = k; j < size ; j++)
		{
			for (i = j - k;i >= 0;i -= k)
			{
				if (*(array + i + k) >= *(array + i))
				{
	   					break;
				}
	   			else
	   			{
	   				mid = *(array + i);
	   				*(array + i) = *(array + i + k);
	   				*(array + i + k) = mid;
	   			}
	   		}
		}
	}
}
