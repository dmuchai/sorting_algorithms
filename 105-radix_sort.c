#include "sort.h"
/**
 * get_max - gets max value from array
 * @array: pointer to array
 * @size: size of the array
 * Return: max value from array
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
 * radix_sort - sorts an array of integers is ASC
 * order implementing Radix Sort algorithm
 * @array: pointer to array
 * @size: size of the array
 */
void radix_sort(int *array, size_t size)
{
	int *new_arr;
	int i, max, e = 1;
	int tam = size;

	if (!array || size < 2)
		return;

	max = get_max(array, size);

	new_arr = malloc(sizeof(int) * size);
	while (max / e > 0)
	{
		int brews[20] = {0};

		i = 0;

		while (i < tam)
		{
			brews[(array[i] / e) % 10]++;
			i++;
		}

		if (brews != NULL)
		{
			for (i = 1; i < 10; i++)
				brews[i] += brews[i - 1];

			for (i = tam - 1; i >= 0; i--)
			{
				new_arr[brews[(array[i] / e) % 10] - 1] = array[i];
				brews[(array[i] / e) % 10]--;
			}

			for (i = 0; i < tam; i++)
				array[i] = new_arr[i];
		}
		e *= 10;
		print_array(array, size);
	}
	free(new_arr);
}
