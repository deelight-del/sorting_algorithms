#ifndef SORT_H
#define SORT_H
#include <stddef.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_list(const listint_t *list);
void print_array(const int *array, size_t size);
void bubble_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void selection_sort(int *array, size_t size);
void insert_node(listint_t **head_ptr, listint_t *node);
void insertion_sort_list(listint_t **list);
void quick_sort(int *array, size_t size);
void sort(int *array, int start_idx, int end_idx, int size);
int partition(int *array, int start_idx, int end_idx, int size);
void swap(int *array, int *first, int *second, int size);
#endif
