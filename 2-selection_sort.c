#include "sort.h"
/**
 * selection_sort - Sorts an array of integers in ascending order
 * using the Selection sort algorithm
 * @array: Array of integers to sort
 * @size_arr: Size of the array
 */
void selection_sort(int *array, size_t size_arr)
{
	size_t i, j, min_idx;
	int tmp;

	if (array == NULL || size_arr < 2)
		return;

	for (i = 0; i < size_arr - 1; i++)
	{
		min_idx = i;

		for (j = i + 1; j < size_arr; j++)
		{
			if (array[j] < array[min_idx])
			min_idx = j;
		}

		if (min_idx != i)
		{
			tmp = array[i];
			array[i] = array[min_idx];
			array[min_idx] = tmp;
			print_array(array, size_arr);
		}
	}
}
