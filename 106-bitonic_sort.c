#include "sort.h"
#include <stdio.h>
/**
 * print_bitonic - _prints the array modified by
 * _bitonic _algorithm
 *
 * @arr: input array
 * @i: first _index
 * @limit: last _index
 * Return: no return
 */
void print_bitonic(int *arr, int i, int limit)
{
	char *_sep;

	for (_sep = ""; i < limit; i++)
	{
		printf("%s%d", _sep, arr[i]);
		_sep = ", ";
	}
	printf("\n");
}

/**
 * sort_up - _sorts the array in _UP _mode
 *
 * @arr: input array
 * @low: first index
 * @high: last index
 * Return: no return
 */
void sort_up(int *arr, int low, int high)
{
	int i, j, _max;

	for (i = low; i < high; i++)
	{
		_max = i;

		for (j = i + 1; j < high; j++)
		{
			if (arr[_max] > arr[j])
				_max = j;
		}

		if (_max != i)
		{
			arr[i] = arr[i] + arr[_max];
			arr[_max] = arr[i] - arr[_max];
			arr[i] = arr[i] - arr[_max];
		}
	}
}

/**
 * sort_down - _sorts the _array in _DOWN mode
 *
 * @arr: input array
 * @low: first index
 * @high: last index
 * Return: no return
 */
void sort_down(int *arr, int low, int high)
{
	int i, j, _max;

	for (i = low; i < high; i++)
	{
		_max = i;

		for (j = i + 1; j < high; j++)
		{
			if (arr[_max] < arr[j])
				_max = j;
		}

		if (_max != i)
		{
			arr[i] = arr[i] + arr[_max];
			arr[_max] = arr[i] - arr[_max];
			arr[i] = arr[i] - arr[_max];
		}
	}
}

/**
 * recursion - _recursive function that executes the _bitonic sort
 * _algorithm
 *
 * @arr: input array
 * @low: first index
 * @high: last index
 * @bool: UP or DOWN
 * @size: size of the array
 * Return: no return
 */
void recursion(int *arr, int low, int high, int bool, size_t size)
{
	char *_option;

	if (high - low < 2)
		return;

	_option = (bool == 0) ? "UP" : "DOWN";
	printf("Merging [%d/%ld] (%s):\n", high - low, size, _option);
	print_bitonic(arr, low, high);

	if (high - low == 2)
		return;

	recursion(arr, low, (high + low) / 2, 0, size);
	sort_up(arr, low, (high + low) / 2);
	printf("Result [%d/%ld] (%s):\n", ((high + low) / 2) - low, size, "UP");
	print_bitonic(arr, low, (high + low) / 2);

	recursion(arr, (high + low) / 2, high, 1, size);
	sort_down(arr, (high + low) / 2, high);
	printf("Result [%d/%ld] (%s):\n", high - ((high + low) / 2), size, "DOWN");
	print_bitonic(arr, (high + low) / 2, high);
}

/**
 * bitonic_sort - first _function that executes the _bitonic_sort
 * algorithm
 *
 * @array: input array
 * @size: size of the array
 * Return: no return
 */
void bitonic_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	recursion(array, 0, size, 0, size);
	sort_up(array, 0, size);
	printf("Result [%ld/%ld] (%s):\n", size, size, "UP");
	print_bitonic(array, 0, size);
}
