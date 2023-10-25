#include "sort.h"
#include <stdio.h>
/**
 * cocktail_sort - Implementation of the cocktail_sort
 * algorithm (a variant of bubble sort)
 * @list: double linked list.
 *
 * Return: void.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *head, *tail, *previous, *current;
	int swap = 1;

	if (list == NULL || (*list) == NULL || (*list)->next == NULL)
		return;
	head = (*list);
	tail = NULL;
	while (swap)
	{
		swap = 0;
		current = (*list);
		while (current != tail)
		{
			if (current->prev != NULL)
			{
				if (current->n < current->prev->n)
				{
					previous = current->prev;
					current->prev->next = current->next;
					current->prev = current->prev->prev;
					previous->prev = current;
					if (current->next)
						current->next->prev = previous;
					current->next = previous;
					if (current->prev)
						current->prev->next = current;
					else
						(*list) = current;
					current = previous;
					swap = 1;
					print_list((*list));
				}
			}
			current = current->next;
		}
		if (previous->prev)
			tail = previous->prev;
		swap = 0;
		current = tail;

		while (current != head && head != NULL)
		{
			if (current->prev != NULL)
			{
				if (current->n < current->prev->n)
				{
					previous = current->prev;
					current->prev->next = current->next;
					current->prev = current->prev->prev;
					previous->prev = current;
					if (current->next)
						current->next->prev = previous;
					current->next = previous;
					if (current->prev)
						current->prev->next = current;
					else
						(*list) = current;
					swap = 1;
					print_list((*list));
					printf("Here011\n");
				}
				printf("Here1\n");
			}
			current = current->prev;
		}
		head = current->next;

	}
}
