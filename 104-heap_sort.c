#include "sort.h"
/**
 * sift_down - Ensures max-heap property for a subtree rooted at an index
 * @array: pointer to the array
 * @size: current size of the heap
 * @size_init: original size of the array
 * @i: index as a root of the tree
 *
**/
void sift_down(int *array, size_t size_init, size_t size, size_t i)
{

	int temp, branch1, branch2;
	size_t left, right;

	left = i * 2 + 1;
	right = left + 1;
	branch1 = array[left];
	branch2 = array[right];
	if (((left < size) && (right < size) &&
		(branch1 >= branch2 && branch1 > array[i]))
		|| ((left == size - 1) && branch1 > array[i]))
	{
		temp = array[i];
		array[i] = branch1;
		array[left] = temp;
		print_array(array, size_init);
	}
	else if ((left < size) && (right < size) &&
		(branch2 > branch1 && branch2 > array[i]))
	{
		temp = array[i];
		array[i] = branch2;
		array[right] = temp;
		print_array(array, size_init);
	}
	if (left < size - 1)
		sift_down(array, size_init, size, left);
	if (right < size - 1)
		sift_down(array, size_init, size, right);
}
/**
 * heap_sort - Sorts an array of integers in ascending order using heap sort
 * @array: pointer to array to sort
 * @size: number of elements in array
 *
**/
void heap_sort(int *array, size_t size)
{
	size_t i, size_init = size;
	int temp;

	if (!array)
		return;
	for (i = 0; i < size / 2 ; i++)
	{
		sift_down(array, size_init, size, size / 2 - 1 - i);
	}
	for (i = 0; i < size_init - 1; i++)
	{
		temp = array[0];
		array[0] = array[size - 1 - i];
		array[size - 1 - i] = temp;
		print_array(array, size_init);
		sift_down(array, size_init, size - i - 1, 0);
	}

}
