/*
 * Swap.c
 *
 *  Created on: 17-Apr-2015
 *      Author: aditya
 */

void swap ( int *a, int *b )
{
    int t = *a;
    *a = *b;
    *b = t;
}
