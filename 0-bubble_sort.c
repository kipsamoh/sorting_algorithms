#include "sort.h"

/**
 * bubble_sort - _function that _sorts an array
 * of integers in _ascending order using the
 * _Bubble sort _algorithm
 *
 * @array: input arrray
 * @size: size of the array
 * Return: no return
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, n;
	int temp, swap;

	for (n = size, swap = 1; n > 0 && swap; n--)
	{
		swap = 0;
		for (i = 0; (i + 1) < n; i++)
		{
			if (array[i] > array[i + 1])
			{
				temp = array[i + 1];
				array[i + 1] = array[i];
				array[i] = temp;
				print_array(array, size);
				swap = 1;
			}
		}
	}
}
