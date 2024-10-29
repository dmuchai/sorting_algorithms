#include "sort.h"

/**
 * selection_sort - Sorts array of integers using Selection sort algorithm
 * @array: Array of integers to sort
 * @size: Size of the array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_x;
	int tmp;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min_x = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_x])
			{
				min_x = j;
			}
		}

		if (min_x != i)
		{
			tmp = array[i];
			array[i] = array[min_x];
			array[min_x] = tmp;
			print_array(array, size);
		}
	}
}
