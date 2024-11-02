#include "sort.h"
/**
 * merge - Merges two halves into the main array in sorted order
 * @array: The main array to merge into
 * @size: size of the array
 * @left: pointer to left subarray
 * @right: pointer to right subarray
 **/
void merge(int *array, int *left, int *right, size_t size)
{
	int index = 0, i = 0, c = 0;
	int size_left, size_right;

	size_left = size / 2;
	size_right = size - size_left;
	printf("Merging...\n");
	printf("[left]: ");
	print_array(left, size_left);
	printf("[right]: ");
	print_array(right, size_right);

	while (index < size_left && i < size_right)
	{
		if (left[index] < right[i])
			array[c++] = left[index++];
		else
			array[c++] = right[i++];
	}

	while (index < size_left)
		array[c++] = left[index++];

	while (i < size_right)
		array[c++] = right[i++];
	printf("[Done]: ");
	print_array(array, size);
}
/**
 * merge_sort - Sorts an array using the Merge Sort algorithm
 * @array: the array to sort
 * @size: The number of elements in the array
 **/
void merge_sort(int *array, size_t size)
{
	size_t middle = 0, index;
	int left[1000];
	int right[1000];

	if (!array)
		return;

	if (size < 2)
		return;

	middle = size / 2;

	for (index = 0; index < middle; index++)
		left[index] = array[index];

	for (index = middle; index < size; index++)
		right[index - middle] = array[index];

	merge_sort(left, middle);
	merge_sort(right, size - middle);
	merge(array, left, right, size);
}
