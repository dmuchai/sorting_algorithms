#include "sort.h"
/**
 * counting_sort - sorts an array of integers in ascending
 * order using the Counting sort algorithm
 * @array: pointer to the array to be sorted
 * @size: number of elements in the array
 **/
void counting_sort(int *array, size_t size)
{
	int max, i, *count_array, *sorted_arr;
	size_t index;

	if (!array || size < 2)
		return;
	max = array[0];
	for (index = 0; index < size; index++)
	{
		if (array[index] > max)
			max = array[index];
	}
	count_array = calloc((max + 1), sizeof(int));
	for (index = 0; index < size; index++)
	{
		count_array[array[index]]++;
	}
	for (i = 1; i < max; i++)
	{
		count_array[i + 1] += count_array[i];
	}
	print_array(count_array, max + 1);
	sorted_arr = malloc(sizeof(int) * size);
	for (index = 0; index < size; index++)
	{
		count_array[array[index]]--;
		sorted_arr[count_array[array[index]]] = array[index];
	}
	for (index = 0; index < size; index++)
	{
		array[index] = sorted_arr[index];
	}
	free(sorted_arr);
	free(count_array);
}
