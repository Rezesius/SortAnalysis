/*
 * HeapSort.c
 *
 *  Created on: 17-Apr-2015
 *      Author: aditya
 */

void HeapSort(int *array, int size)
{
	int i, j, c, root, temp;
	for (i = 1; i < size; i++)
	{
		c = i;
	    do
	    {
	    	root = (c - 1) / 2;
	        if (*(array + root) < *(array + c))   /* to create MAX heap array */
	        {
	        	temp = *(array + root);
	        	*(array + root) = *(array + c);
	        	*(array + c) = temp;
	        }
	        c = root;
	    } while (c != 0);
	}
	for (j = size - 1; j >= 0; j--)
	{
		temp = *(array + 0);
		*(array + 0) = *(array + j);    /* swap max element with rightmost leaf element */
		*(array + j) = temp;
	    root = 0;
	    do
	    {
	    	c = 2 * root + 1;    /* left node of root element */
	        if ((*(array + c) < *(array + c + 1)) && c < j - 1)
	        	c++;
	        if (*(array + root) < *(array + c) && c < j)    /* again rearrange to max heap array */
	        {
	        	temp = *(array + root);
	        	*(array + root) = *(array + c);
	        	*(array + c) = temp;
	        }
	        root = c;
	    } while (c < j);
	}
}

