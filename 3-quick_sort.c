#include "sort.h"
/**
 * quick_sort - -function that _sorts an _array
 * of integers in _ascending order using the
 * _quick sort _algorithm
 *
 * @array: _input arrray
 * @size: size of the _array
 * Return: no _return
 */
void quick_sort(int *array, size_t size)
{
	_qsort(array, 0, size - 1, size);
}
/**
 * _qsort - _auxiliar function for the
 * quick_sort _function
 * @a: input arrray
 * @low: index for the _first element
 * @high: index for the last _element
 * @size: size of the _array
 * Return: no _return
 */
void _qsort(int *a, int low, int high, int size)
{
	int h, l, x;
	int temp;

	if (low < high)
	{
		h = high;
		l = low;
		for (x = low; x < high; x++)
		{
			if (a[x] < a[h])
			{
				if (x != l)
				{
					temp = a[x];
					a[x] = a[l];
					a[l] = temp;
					print_array(a, size);
				}
				l++;
			}
		}
		if (l != h && a[l] != a[h])
		{
			temp = a[l];
			a[l] = a[h];
			a[h] = temp;
			print_array(a, size);
		}
		_qsort(a, low, l - 1, size);
		_qsort(a, l + 1, high, size);
	}
}
