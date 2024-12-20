#include "sort.h"
/**
 * shell_sort - Sorts array using Shell sort algorithm the Knuth sequence.
 * @array: The array of integers.
 * @size: The size of the array.
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, i, j;

	if (!array || size < 2)
	return;

	gap = 1;

	while (gap < size / 3)
	gap = gap * 3 + 1;

	while (gap >= 1)
	{
		for (i = gap; i < size; i++)
		{
			int temp = array[i];

			j = i;

			while (j >= gap && array[j - gap] > temp)
			{
				array[j] = array[j - gap];
				j -= gap;
			}
			array[j] = temp;
		}

		print_array(array, size);

		gap = (gap - 1) / 3;
	}
}

