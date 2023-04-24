#include <stdio.h>
#include <stdlib.h>
#include "sort.h"


/**
 * lomuto_partition - Function to partition
 * @array: The array
 * @low: lower pointer
 * @high: higher pointer
 * @size: size of the array
 * Return: i
 *
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
int i = low - 1, j = low;
int pivot = array[high], aux = 0;

for (; j < high; j++)
{
if (array[j] < pivot)
{
i++;
if (array[i] != array[j])
{
aux = array[i];
array[i] = array[j];
array[j] = aux;
print_array(array, size);
}
}
}
if (array[i + 1] != array[high])
{
aux = array[i + 1];
array[i + 1] = array[high];
array[high] = aux;
print_array(array, size);
}
return (i + 1);
}

/**
 * lomuto_sort - lomuto function to sort
 * @array: array
 * @low: lower pointer
 * @high: higher pointer
 * @size: size of the array
 * Return: void
 */
void lomuto_sort(int *array, int low, int high, size_t size)
{
int pivot;

if (low < high)
{
pivot = lomuto_partition(array, low, high, size);
lomuto_sort(array, low, pivot - 1, size);
lomuto_sort(array, pivot + 1, high, size);
}
}

/**
 * quick_sort - function to sort using the lomuto partition scheme
 * @array: array of integers
 * @size: size of the array
 *
 * Return: Nothing
 *
 */
void quick_sort(int *array, size_t size)
{
if (array == NULL || size < 2)
return;

lomuto_sort(array, 0, size - 1, size);

}
