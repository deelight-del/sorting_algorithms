#include "sort.h"

/**
 * quick_sort - sorts an array using quick sort
 * @array: array of integers
 * @size: size of array
 * description: sorts an array using the quick sort algorithm
 * with lomuto partition scheme
 * Return: Nothing
*/
void quick_sort(int *array, size_t size)
{

	if (array == NULL || size < 2)
		return;
	sort(array, 0, size - 1, size);

}
/**
 * sort - sorts an array
 * @array: array of integers
 * @start_idx: start index of the array
 * @end_idx: end index of the array
 * @size: size of original array
 * description: sorts an array using the quick sort algorithm
 * Return Nothing
*/
void sort(int *array, int start_idx, int end_idx, int size)
{
	int pidx;

	if (start_idx < end_idx)
	{
		pidx = partition(array, start_idx, end_idx, size);
		sort(array, start_idx, pidx - 1, size);
		sort(array, pidx + 1, end_idx, size);
	}
}


/**
 * partition - partitions an array into two parts
 * @array: array of integers
 * @start_idx: start index of the array
 * @size: size of original array
 * @end_idx: end index of the array
 * description: partitions an array using lomuto partition scheme
 * Return: partition index
*/

int partition(int *array, int start_idx, int end_idx, int size)
{
	int pidx, i, pivot;

	pivot = array[end_idx];
	pidx = start_idx;
	for (i = start_idx; i < end_idx; i++)
	{
		if (array[i] <= pivot)
		{
			swap(array, &array[i], &array[pidx], size);
			pidx++;
		}
	}
	swap(array, &array[pidx], &array[end_idx], size);
	return (pidx);
}

/**
 * swap - swaps two integer
 * @first: pointer to first integer
 * @size: size of original array
 * @array: array of integers
 * @second: pointer to second intger
 * description: swaps two integers
 * Return: Nothing
*/
void swap(int *array, int *first, int *second, int size)
{
	int temp;

	temp = (*first);
	*first = *second;
	*second = temp;
	if (*first != *second)
		print_array(array, size);
}
