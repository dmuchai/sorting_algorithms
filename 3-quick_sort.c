#include "sort.h"
/**
*swap_elements - swaps the values of two positions in an array
*@array: array containing elements
*@pos1: the first element's index
*@pos2: the second element's index
*/
void swap_elements(int *array, ssize_t pos1, ssize_t pos2)
{
	int temp;

	temp = array[pos1];
	array[pos1] = array[pos2];
	array[pos2] = temp;
}
/**
 *partition_lomuto - partitions the array following Lomuto scheme
 *@array: array to partition
 *@low: starting index of the partition
 *@high: ending index of the partition
 *@size: total size of the array
 *Return: index of the pivot after partition
 */
int partition_lomuto(int *array, ssize_t low, ssize_t high, size_t size)
{
	int pivot = array[high];
	ssize_t left = low, right;

	for (right = low; right < high; right++)
	{
		if (array[right] < pivot)
		{
			if (left != right)
			{
				swap_elements(array, left, right);
				print_array(array, size);
			}
			left++;
		}
	}
	if (array[left] != array[high])
	{
		swap_elements(array, left, high);
		print_array(array, size);
	}
	return (left);
}
/**
 *quicksort_recursive - recursive Quick Sort function
 *@array: array to sort
 *@low: the starting index of the current partition
 *@high: the ending index of the current partition
 *@size: size of the array
 */
void quicksort_recursive(int *array, ssize_t low, ssize_t high, int size)
{
	if (low < high)
	{

		ssize_t pivot_index = partition_lomuto(array, low, high, size);

		quicksort_recursive(array, low, pivot_index - 1, size);
		quicksort_recursive(array, pivot_index + 1, high, size);
	}
}
/**
 *quick_sort - initializes Quick Sort algorithm on an array
 *@array: array to sort
 *@size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	quicksort_recursive(array, 0, size - 1, size);
}
