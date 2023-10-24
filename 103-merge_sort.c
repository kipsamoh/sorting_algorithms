#include "sort.h"
/**
 * print_data - _print data
 * @msg: message
 * @a: array
 * @from: from
 * @to: to
 * Return: no return
 */
void print_data(char *msg, int *a, int from, int to)
{
	char *sep;
	int x;

	printf("[%s]: ", msg);
	sep = "";

	for (x = from; x <= to; x++)
	{
		printf("%s%d", sep, a[x]);
		sep = ", ";
	}
	printf("\n");
}

/**
 * merge - _Auxiliar function for
 * Merge _sort algorithm
 * @a: array
 * @low: low index
 * @middle: middle
 * @high: high index
 * @buff: buffer
 * Return: no return
 */
void merge(int *a, int low, int middle, int high, int *buff)
{
	int lo, lm, x;

	lo = x = low;
	lm = middle + 1;

	printf("Merging...\n");
	print_data("left", a, low, middle);
	print_data("right", a, middle + 1, high);

	while (lo <= middle && lm <= high)
	{
		if (a[lo] < a[lm])
			buff[x++] = a[lo++];
		else
			buff[x++] = a[lm++];
	}

	while (lo <= middle)
		buff[x++] = a[lo++];

	while (lm <= high)
		buff[x++] = a[lm++];

	for (x = low; x <= high; x++)
		a[x] = buff[x];

	print_data("Done", a, low, high);
}
/**
 * msort -Auxiliar _function for
 * Merge sort algorithm
 * @array: array
 * @low: low index
 * @high: high index
 * @buffer: buffer
 * Return: no return
 */
void msort(int *array, int low, int high, int *buffer)
{
	int middle;

	if (low < high)
	{
		middle = (low + high - 1) / 2;
		msort(array, low, middle, buffer);
		msort(array, middle + 1, high, buffer);
		merge(array, low, middle, high, buffer);
	}
}
/**
 * merge_sort -Sorts an _arrayof integers
 * in _ascending order using the
 * Merge sort algorithm
 * @array: array
 * @size: size
 * Return: no return
 */
void merge_sort(int *array, size_t size)
{
	int *buffer;

	buffer = malloc(sizeof(int) * size);
	if (!buffer)
		return;
	msort(array, 0, size - 1, buffer);
	free(buffer);
}
