#include "sort.h"
#include <stdio.h>

/**
 * bitonic_swap - Swap two integers in the array and print the array
 * @array: The array of integers
 * @i: The first index
 * @j: The second index
 */
void bitonic_swap(int *array, size_t i, size_t j)
{
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
    print_array(array, i + 1); /* Print the array after each swap */
}

/**
 * bitonic_compare - Compare and swap elements in the bitonic sequence
 * @array: The array of integers
 * @low: Starting index of the sequence
 * @count: Number of elements in the sequence
 * @dir: Direction of sorting (1 for ascending, 0 for descending)
 */
void bitonic_compare(int *array, size_t low, size_t count, int dir)
{
    if (count > 1)
    {
        size_t k = count / 2;
	size_t i;

        for (i = low; i < low + k; i++)
        {
            if ((dir == 1 && array[i] > array[i + k]) ||
                (dir == 0 && array[i] < array[i + k]))
                bitonic_swap(array, i, i + k);
        }
        bitonic_compare(array, low, k, dir);
        bitonic_compare(array, low + k, k, dir);
    }
}

/**
 * bitonic_merge - Recursively merge and sort the bitonic sequence
 * @array: The array of integers
 * @low: Starting index of the sequence
 * @count: Number of elements in the sequence
 * @dir: Direction of sorting (1 for ascending, 0 for descending)
 */
void bitonic_merge(int *array, size_t low, size_t count, int dir)
{
    if (count > 1)
    {
        size_t k = count / 2;
        printf("Merging [%lu] (%s):\n", count, dir ? "UP" : "DOWN");
        print_array(array + low, count);
        bitonic_compare(array, low, count, dir);
        bitonic_merge(array, low, k, dir);
        bitonic_merge(array, low + k, k, dir);
        printf("Result [%lu] (%s):\n", count, dir ? "UP" : "DOWN");
        print_array(array + low, count);
    }
}

/**
 * bitonic_sort_rec - Recursively builds and sorts the bitonic sequence
 * @array: The array of integers
 * @low: Starting index of the sequence
 * @count: Number of elements in the sequence
 * @dir: Direction of sorting (1 for ascending, 0 for descending)
 */
void bitonic_sort_rec(int *array, size_t low, size_t count, int dir)
{
    if (count > 1)
    {
        size_t k = count / 2;
        bitonic_sort_rec(array, low, k, 1);      /* Ascending order */
        bitonic_sort_rec(array, low + k, k, 0);  /* Descending order */
        bitonic_merge(array, low, count, dir);
    }
}

/**
 * bitonic_sort - Sorts an array of integers in ascending order using Bitonic sort
 * @array: The array of integers
 * @size: Number of elements in the array
 */
void bitonic_sort(int *array, size_t size)
{
    if (!array || size < 2)
        return;
    bitonic_sort_rec(array, 0, size, 1);
}

