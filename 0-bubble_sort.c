#include "sort.h"

/**
 * _swap - swaps two elements in an array
 * @a: first element
 * @b: second element
 */

void _swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * bubble_sort - bubble sort algorithm
 * @array: array to sort
 * @size: size of the array
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, l = size;
	bool sorted = false;

	if (array == NULL || size < 2)
	{
		return;
	}

	while (sorted == false)
	{
		sorted = true;
		for (i = 0; i < l - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				_swap(array + i, array + i + 1);
				print_array(array, size);
				sorted = false;
			}
		}
		l--;
	}
}
