#include "sort.h"
#include <stdio.h>
/**
 * swap_nums - _swaps numbers
 *
 * @arr: input array
 * @a: first index
 * @b: second index
 * Return: no return
 */
void swap_nums(int *arr, int a, int b)
{
	arr[a] = arr[a] + arr[b];
	arr[b] = arr[a] - arr[b];
	arr[a] = arr[a] - arr[b];
}

/**
 * recursion_heap - _recursion that builds the _max heap tree
 *
 * @arr: input array
 * @i: index number
 * @size: size of the array
 * @limit: limit of the array
 * Return: no return
 */
void recursion_heap(int *arr, int i, size_t size, int limit)
{
	int _bigger;
	int i2;

	i2 = i * 2;

	if (i2 + 2 < limit)
	{
		recursion_heap(arr, i2 + 1, size, limit);
		recursion_heap(arr, i2 + 2, size, limit);
	}

	if (i2 + 1 >= limit)
		return;

	if (i2 + 2 < limit)
		_bigger = (arr[i2 + 1] > arr[i2 + 2]) ? (i2 + 1) : (i2 + 2);
	else
		_bigger = i2 + 1;

	if (arr[i] < arr[_bigger])
	{
		swap_nums(arr, i, _bigger);
		print_array(arr, size);
		recursion_heap(arr, _bigger, size, limit);
	}
}

/**
 * heap_sort - _sorts an array of integers in _ascending
 * order using the _Heap sort algorithm
 *
 * @array: input array
 * @size: size of the array
 */
void heap_sort(int *array, size_t size)
{
	int i;
	size_t _limit;

	if (!array || size == 0)
		return;

	i = 0;
	_limit = size;

	while (_limit > 1)
	{
		recursion_heap(array, i, size, _limit);
		if (array[i] >= array[_limit - 1])
		{
			swap_nums(array, i, _limit - 1);
			print_array(array, size);
		}
		_limit--;
	}
}
