#include "sort.h"
/**
 * compare_bitonic - helper function for merging bitonic sequences,
 * sorts the contents of the current subarray.
 * @upper: if true, sort in ascending order, false, descending
 * @y: subarray in current frame of recursion
 * @n: number of elements in `y`
 */
void compare_bitonic(int upper, int *y, size_t n)
{
	size_t len, j;
	int tmp;

	len = n / 2;
	for (j = 0; j < len; j++)
	{
		if ((y[j] > y[j + len]) == upper)
		{
			tmp = y[j];
			y[j] = y[j + len];
			y[j + len] = tmp;
			print_array(y, len);
		}
	}
}

/**
 * merge_bitonic - second recursive function for bitonic_sort,
 * sorts subarrays using compare_bitonic, and merges the sorted results.
 * @upper: if true, sort in ascending order, false, descending
 * @sub_arr: subarray in previous frame of recursion
 * @n: number of elements in `sub_arr`
 * @origi_size: number of elements in source array being sorted
 */
void merge_bitonic(int upper, int *sub_arr, size_t n, size_t origi_size)
{
	int *left, *right;

	if (n > 1)
	{
		left = sub_arr;
		right = sub_arr + (n / 2);
		compare_bitonic(upper, sub_arr, n);
		merge_bitonic(upper, left, n / 2, origi_size);
		merge_bitonic(upper, right, n / 2, origi_size);
	}
}

/**
 * sort_bitonic_r - first recursive function of bitonic_sort,
 * divides array into binary tree of subarrays, and assigns sorting order
 * @upper: if true, sort in ascending order, false, descending
 * @sub_arr: subarray in previous recursion frame
 * @n: number of elements in `sub_arr`
 * @origi_size: number of elements in original array being sorted
 */
void sort_bitonic_r(int upper, int *sub_arr, size_t n, size_t origi_size)
{
	int *left, *right;

	if (n <= 1)
		return;
	left = sub_arr;
	right = sub_arr + (n / 2);
	printf("Merging [%lu/%lu] (%s):\n", n, origi_size,
	       (upper ? "UP" : "DOWN"));
	print_array(sub_arr, n);
	sort_bitonic_r(1, left, n / 2, origi_size);
	sort_bitonic_r(0, right, n / 2, origi_size);
	merge_bitonic(upper, left, n, origi_size);
	printf("Result [%lu/%lu] (%s):\n", n, origi_size,
	       (upper ? "UP" : "DOWN"));
	print_array(sub_arr, n);
}

/**
 * bitonic_sort - sorts array of integers in ascending order with bitonic
 * sort alogrithm
 * @array: array of int to be sorted
 * @size: number of elements in array
 */
void bitonic_sort(int *array, size_t size)
{
	if (!array || size == 0)
		return;

	sort_bitonic_r(1, array, size, size);
}
