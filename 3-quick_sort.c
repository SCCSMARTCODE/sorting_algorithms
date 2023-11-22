#include "sort.h"

/**
 * swap - Swaps two integers.
 * @a: Pointer to the first integer.
 * @b: Pointer to the second integer.
 *
 * Return: void
 */
void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * partition - Partitions an array using a pivot.
 * @array: Array to be partitioned.
 * @low: Lowest index of the partition range.
 * @high: Highest index of the partition range.
 * @size: Size of the array.
 *
 * Return: Index of the pivot.
 */
int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int x = low - 1;
	int y;

	for (y = low; y <= high; y++)
	{
		if (array[y] <= pivot)
		{
			x++;
			if (x != y)
			{
				swap(&array[x], &array[y]);
				print_array(array, size);
			}
		}
	}
	return (x);
}

/**
 * sorting - Recursively sorts an array using Quick Sort.
 * @array: Array to be sorted.
 * @low: Lowest index of the array.
 * @high: Highest index of the array.
 * @size: Size of the array.
 *
 * Return: void
 */
void sorting(int *array, int low, int high, size_t size)
{
	int i;

	if (low < high)
	{
		i = partition(array, low, high, size);
		sorting(array, low, i - 1, size);
		sorting(array, i + 1, high, size);
	}
}

/**
 * quick_sort - Sorts an array using the Quick Sort algorithm.
 * @array: Array to be sorted.
 * @size: Size of the array.
 *
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	sorting(array, 0, size - 1, size);
}
