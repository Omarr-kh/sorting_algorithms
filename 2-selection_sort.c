#include "sort.h"

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
 * selection_sort - selection sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 */
void selection_sort(int *array, size_t size)
{
	int *minim;
	size_t i, j;

	if (size < 2 || array == NULL)
	{
		return;
	}

	for (i = 0; i < size - 1; i++)
	{
		minim = array + i;
		for (j = i + 1; j < size; j++)
			minim = (array[j] < *minim) ? (array + j) : minim;

		if ((array + i) != minim)
		{
			_swap(array + i, minim);
			print_array(array, size);
		}
	}
}
