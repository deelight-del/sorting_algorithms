#include "sort.h"
#include <stdlib.h>
/**
 * counting_sort - Function to implememt the counting sort algorithm
 * @array: The array to sort.
 * @size: The size of the array to sort.
 *
 * Return: void.
 */
void counting_sort(int *array, size_t size)
{
	int *CountArray, *HoldArray, max, i;

	if (array == NULL || size < 2)
		return;
	max = array[0];
	for (i = 0; (size_t)i < size; i++)
	{
		if (array[i] > max) /*Find maximum*/
			max = array[i];
	}
	CountArray = malloc(sizeof(int) * (max + 1));
	if (CountArray == NULL)
		return;
	for (i = 0; i <= max; i++)
		CountArray[i] = 0; /*Init count array to zero*/
	HoldArray = malloc(sizeof(int) * size);
	if (HoldArray == NULL)
		return;
	for (i = 0; (size_t)i < size; i++)
	{
		CountArray[array[i]]++; /*Assign count values in xount array*/
		HoldArray[i] = array[i]; /*copy arraay to HoldArray*/
	}
	for (i = 1; i <= max; i++) /*Prefix sum*/
		CountArray[i] = CountArray[i] + CountArray[i - 1];
	print_array(CountArray, (size_t)(max + 1));
	for (i = 0; (size_t)i < size; i++)
	{
		/*Update Array order and CountArray*/
		array[CountArray[HoldArray[i]] - 1] = HoldArray[i];
		(CountArray[HoldArray[i]])--;
	}
	free(HoldArray);
	free(CountArray);
}
