#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers in ascending order using bubble sort.
 * @array: Array to be sorted.
 * @size: Size of the array.
 *
 * Return: void
 */
void bubble_sort(int *array, size_t size)
{
        size_t i, j;
        int temp;

        if (size < 2 || array == NULL)
                return;

        for (j = 0; j < size; j++)
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
        }
}
