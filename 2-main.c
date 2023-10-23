#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 *  * main - Entry point
 *   *
 *    * Return: Always 0
 *     */
int main(void)
{
	int array[]  = {20, 20, 18, 19, 19, 15, 16, 23, 18, 13, 13, 20, 21, 13};
	size_t n = sizeof(array) / sizeof(array[0]);
	
	printf("%ld", n);

/*	array = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
	n = sizeof(array) / sizeof(array[0]);
	print_array(array, n);
	printf("\n");
	bubble_sort(array, n);
	printf("\n");
	print_array(array, n);
	array = NULL;*/

/*	printf("\n..................................................\n");
	print_array(array, n);
	printf("\n");
	bubble_sort(array, n);
	printf("\n");
	print_array(array, n);*/
	
/*	printf("\n..................................................\n");
	print_array(array, n);
	printf("\n");
	bubble_sort(array, n);
	printf("\n");
	print_array(array, n);
	printf("\n..................................................\n");
	*/
/*	print_array(array, n);
	printf("\n");
	bubble_sort(array, n);
	printf("\n");
	print_array(array, n);*/

	printf("\n..................................................\n");
	print_array(array, n);
	printf("\n");
	selection_sort(array, n);
	printf("\n");
	print_array(array, n);
	return (0);
}
