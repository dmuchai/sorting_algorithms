#include "sort.h"
/**
 * selection_sort - Sorts an array of integers in ascending order
 * using the Selection sort algorithm
 * @array: Array of integers to sort
 * @size: Size of the array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int min, tmp, idx;

	for (i = 0; i < size; i++)
	{
		min = array[i];
		for (j = i + 1; j < size; j++)
		{
			if (min > array[j])
			{
				min = array[j];
				idx = j;
			}
		}
		if (min != array[i])
		{
			tmp = array[i];
			array[i] = min;
			array[idx] = tmp;
			print_array(array, size);
		}
	}
}

