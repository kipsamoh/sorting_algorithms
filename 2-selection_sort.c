#include "sort.h"

/**
 * selection_sort - _sorts an array of _integers in
 * _ascending order using the _Selection sort
 * algorithm
 *
 * @array: input _array of _integers
 * @size: size of the _array
 * Return: no return
 */
void selection_sort(int *array, size_t size)
{
	int temp;
	size_t i, j, m;

	for (i = 0; i < size; i++)
	{
		m = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[m] > array[j])
				m = j;
		}

		if (i != m)
		{
			temp = array[i];
			array[i] = array[m];
			array[m] = temp;
			print_array(array, size);
		}
	}
}
