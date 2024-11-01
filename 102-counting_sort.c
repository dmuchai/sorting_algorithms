#include "sort.h"
#include <stdlib.h>

/**
 * counting_sort - sorts an array of integers in ascending order
 * using the Counting sort algorithm
 * @array: Array to be sorted
 * @size: size of the array
 *
 * Return: void
 */
void counting_sort(int *array, size_t size)
{
	int *count_array, c;
	size_t a, b, arr_size;

	if (array == NULL || size <= 1)
		return;
	arr_size = array[0];
	for (a = 0; array[a]; a++)
	{
		if (array[a] > (int)arr_size)
			arr_size = array[a];
	}

	arr_size += 1;

	count_array = malloc(arr_size * sizeof(int *));
	if (count_array == NULL)
		return;

	for (a = 0; a < arr_size; a++)
		count_array[a] = 0;

	for (a = 0; a < size; a++)
		count_array[array[a]] += 1;

	for (a = 0; a <= arr_size; a++)
		count_array[a] += count_array[a - 1];

	print_array(count_array, arr_size);

	for (a = 1, b = 0; a <= arr_size; a++)
		if (count_array[a] != count_array[a - 1])
		{
			for (c = 0; c < count_array[a] - count_array[a - 1]; c++)
				array[b++] = a;
		}
	free(count_array);
}
