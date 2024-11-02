#include "sort.h"
/**
 * get_max - gets max value from array
 * @arr: pointer to array of integers
 * @n: size of the array
 * Return: max value in the array array
 */
int get_max(int *arr, size_t n)
{
	int mx = arr[0];
	size_t i;

	for (i = 0; i < n; i++)
	{
		if (arr[i] > mx)
			mx = arr[i];
	}
	return (mx);
}
/**
 * radix_sort - sorts an array of integers using Radix sort algorithm.
 * @array: pointer to array to sort
 * @size: size of the array
 */
void radix_sort(int *array, size_t size)
{
	int *new_arr;
	int i, max, e = 1;
	int t = size;

	if (!array || size < 2)
		return;

	max = get_max(array, size);

	new_arr = malloc(sizeof(int) * size);
	while (max / e > 0)
	{
		int count[20] = {0};

		i = 0;

		while (i < t)
		{
			count[(array[i] / e) % 10]++;
			i++;
		}

		if (count != NULL)
		{
			for (i = 1; i < 10; i++)
				count[i] += count[i - 1];

			for (i = t - 1; i >= 0; i--)
			{
				new_arr[count[(array[i] / e) % 10] - 1] = array[i];
				count[(array[i] / e) % 10]--;
			}

			for (i = 0; i < t; i++)
				array[i] = new_arr[i];
		}
		e *= 10;
		print_array(array, size);
	}
	free(new_arr);
}
