#include "sort.h"
/**
 * selection_sort - Using the selection sorting algorithm:
 * This swaps the minimum value with the first value in the array on a
 * single pass, and updates the lower boundary subsequently.
 * @array: An array of size @size.
 * @size: Size of the @array.
 *
 * Return: void.
 */

void selection_sort(int *array, size_t size)
{
	size_t boundary = 0, i, smallest_val_idx;
	int smallest_value, temp;

	if (array == NULL || size < 2) /*Handle empty/singlet array*/
		return;
	/*
	 * setup outer loop that runs `size` times. setting subsequent
	 * least values to the boundary on each loop. Such that on each
	 * loop pass, The first `boundary+1` values in the array
	 * are rightly ordered.
	 */
	while (boundary < size)
	{
		smallest_value = array[boundary]; /*init smallest_value*/
		smallest_val_idx = boundary;
		/*
		 * Inner loop that runs from respective boundary to the end
		 * of the array, and swaps the smallest value with the value
		 * at the boundary, iff array[boundary] is not the least value
		 */
		for (i = boundary + 1; i < size; i++)
		{
			/*Update smallest value if element @i is < smallest*/
			if (array[i] < smallest_value)
			{
				smallest_value = array[i];
				smallest_val_idx = i;
			}
		}
		if (smallest_value != array[boundary]) /*Swap values*/
		{
			temp = array[smallest_val_idx];
			array[smallest_val_idx] = array[boundary];
			array[boundary] = temp;
			print_array(array, size);
		}
		boundary++; /*Incease boundary on outer loop*/
	}
}
