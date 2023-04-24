#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sort.h"

/**
 * swap - function to implement bubble sort
 * @xp: integer to be swapped
 * @yp: second integer to be swapped
 *
 * Return: Always 0.
 */
void swap(int *xp, int* yp)
{
int temp = *xp;
*xp = *yp;
*yp = temp;
}

/**
 * bubble_sort - function to sort array
 *@array: pointer to array
 *@size: size of the array
 *
 * Return: Always 0.
 *
 */
void bubble_sort(int *array, size_t size)
{
size_t i = 0, j = 0;
int temp = 0;
if (array == NULL || size == 0)
return;
for (; i < size - 1; i++)
{
for (j = 0; j < size - i - 1; j++)
{
if (array[j] > array[j + 1])
{
temp = array[j + 1];
array[j + 1] = array[j];
array[j] = temp;
print_array(array, size);
}
}
}
}
