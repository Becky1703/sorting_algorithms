#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * selection_sort - function to sort an array
 * @array: array to sort
 * @size: size of the array
 *
 * Return: Nothing.
 */
void selection_sort(int *array, size_t size)
{
int aux_i = 0;
size_t i = 0, j = 0, loc = 0;

if (array == NULL || size == 0)
return;
for (; i < size -1; i++)
{
loc = i;
for (j = i + 1; j < size; j++)
{
if (array[j] < array[loc])
loc = j;
}
if (loc != i)
{
aux_i = array[i];
array[i] = array[loc];
array[loc] = aux_i;
print_array(array, size);
}
}
}
