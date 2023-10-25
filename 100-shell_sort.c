#include "sort.h"
/**
 * shell_sort - Function to implement the shell sort algorithm
 * @array: Array of integers to sort.
 * @size: The size of the array.
 * description: It works just like the insertion sort\
 * but uses gaps / seqences to swap/insert elements. Starting out
 * with a high number in the respective sequence, and gradually descending.
 * Return: Void.
 */

void shell_sort(int *array, size_t size)
{
	size_t sequence = 1, i, j, k;
	int temp;

	if (array == NULL || size < 2)
		return;
	while (size > sequence && ((sequence * 3) + 1) < size)
		sequence = (sequence * 3) + 1; /*Calc highes possible seq no.*/
	while (sequence != 0) /*Loop from highest seq no. to zero*/
	{
		/*Loop that cuts array into sub-sequences, and do insetion*/
		for (i = sequence; i < size; i += sequence)
		{
			/*
			 * For each element in a subsequence, compare element
			 * with corresponding elemnt in a previous sub-seq.
			 */
			for (k = i; k < size && k < (i + sequence); k++)
			{
				j = k;
				/*Swap element in a corresponding position*/
				/*of a sub-seq to a preceding sub-seq*/
				while (array[j] < array[j - sequence] &&
						j >= sequence)
				{
					temp = array[j];
					array[j] = array[j - sequence];
					array[j - sequence] = temp;
					j -= sequence;
				}
			}
		}
		if (sequence == 1) /*size_t will underflow without this*/
			sequence = 0;
		else
			sequence = (sequence - 1) / 3;
		print_array(array, size);
	}
}
