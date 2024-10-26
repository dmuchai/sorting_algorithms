#include "sort.h"
#include <stdio.h>

/**
 * bubble_sort - Sorts array of integers in ascending order
 * @array: Pointer to the array to sort
 * @size: Num of elements in the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, d;
	int temp;

	if (size < 2)
		return;
	for (i = 0; i < size - 1; i++)
		for (d = 0; d < size - i - 1; d++)
		{
			if (array[d] > array[d + 1] && array[d + 1])
			{
				temp = array[d];
				array[d] = array[d + 1];
				array[d + 1] = temp;
				print_array(array, size);
			}
		}
}
