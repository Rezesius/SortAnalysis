/*
 * GnomeSort.c
 *
 *  Created on: 17-Apr-2015
 *      Author: aditya
 */

void GnomeSort(int *array, int size)
{
	int i = 0, temp;
	while (i < size)
	{
		if (i == 0 || *(array + i - 1) <= *(array + i))
			i++;
		else
		{
			temp = *(array + i - 1);
			*(array + i - 1) = *(array + i);
			*(array + i) = temp;
			i--;
		}
	}
}
