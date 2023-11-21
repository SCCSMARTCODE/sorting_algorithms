#include "sort.h"

/**
 * bubble_sort -  function that sorts an array of integers in ascending order
 *
 * @array: first arg
 * @size: second arg
 * Return: 0
 */

int bubble_sort(int *array, int size)
{
	int i, j = 0, temp;

	if (size < 2)
	{
		return (0);
	}

	while (j < size)
	{
		for (i = 0; i < size - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
				print_array(array, size);
			}
		}

		j++;
	}


	return (0);
}
