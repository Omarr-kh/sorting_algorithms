#include "sort.h"

void _swap(int *a, int *b);
int _partition(int *array, size_t size, int start, int end);
void _sort(int *array, size_t size, int start, int end);
void quick_sort(int *array, size_t size);

/**
 * _swap - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void _swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * _partition - Order an array (last element as pivot).
 * @array: The array of integers.
 * @size: The size of the array.
 * @start: The starting index of the subset to order.
 * @end: The ending index of the subset to order.
 *
 * Return: The final partition index.
 */
int _partition(int *array, size_t size, int start, int end)
{
	int *pivot, r, l;

	pivot = array + end;
	for (r = l = start; l < end; l++)
	{
		if (array[l] < *pivot)
		{
			if (r < l)
			{
				_swap(array + l, array + r);
				print_array(array, size);
			}
			r++;
		}
	}

	if (array[r] > *pivot)
	{
		_swap(array + r, pivot);
		print_array(array, size);
	}

	return (r);
}

/**
 * _sort - quicksort algorithm through recursion.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @start: The starting index of the array partition to order.
 * @end: The ending index of the array partition to order.
 */
void _sort(int *array, size_t size, int start, int end)
{
	int part;

	if (end - start > 0)
	{
		part = _partition(array, size, start, end);
		_sort(array, size, start, part - 1);
		_sort(array, size, part + 1, end);
	}
}

/**
 * quick_sort - Sort an array using quicksort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	_sort(array, size, 0, size - 1);
}
