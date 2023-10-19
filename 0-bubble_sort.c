#include "sort.h"
/**
 * bubble_sort - Sorting, using the bubble sort algorithm
 * @array: The array to be sorted.
 * @size: The size of the array  @array
 *
 * Return: void.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j, swap_bool;
	int temp;

	/*Do nothig if array size is < 2*/
	if (size < 2)
		return;
	/*Outer loop that loops size times on the worst ocassion*/
	for (i = 0; i < size; i++)
	{
		/*
		 * Set up inner loop that will compare and swap values if need
		 * ed. loop goes from 0 to n - 2 - i; since we know that every
		 * successful inner loop pass will put highest values at the
		 * coreesponding rightmost position.
		 */
		swap_bool = 0;
		for (j = 0; j < size - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				swap_bool++;
				print_array(array, size);
			}
		}
		/*Break; if no swap occurred. array already sorted*/
		if (swap_bool == 0)
			break;
	}
}
