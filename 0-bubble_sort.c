#include "sort.h"

/**
 * bubble_sort - algorithm that sorts our array in ascending
 * order by swapping two adjacent elements if they are misplaced.
 * @array: array of integers that require sorting
 * @size: number of elements in the array
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j, temp;
	int flag;

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - 1 - i; j++)
		{
			flag = 0;
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				flag = 1;
			}
			if (flag == 1)
				print_array(array, size);
		}
		if (flag == 0)
			break;
	}
}
