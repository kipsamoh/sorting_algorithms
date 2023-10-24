#include "sort.h"
/**
 * radix_sort - sorts an array of _integers in ascending
 * order using the _Radix sort algorithm
 *
 * @array: input _array
 * @size: size of the array
 */
void radix_sort(int *array, size_t size)
{
	int _flag = 1, n = 10;
	size_t i, f;

	if (!array || size == 1)
		return;
	while (_flag)
	{
		_flag = 0;
		for (i = 1, f = 1; i <  size; i++, f++)
		{
			if ((array[i - 1] % (n * 10)) / ((n * 10) / 10) > 0)
				_flag = 1;
			if (((array[i - 1] % n) / (n / 10)) > ((array[i] % n) / (n / 10)))
			{
				array[i - 1] = array[i - 1] + array[i];
				array[i] = array[i - 1] - array[i];
				array[i - 1] = array[i - 1] - array[i];
				if ((i - 1) > 0)
					i = i - 2;
			}
		}
		print_array(array, size);
		n = n * 10;
	}
}
