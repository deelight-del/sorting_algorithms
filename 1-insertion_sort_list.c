#include "sort.h"

/**
 * insertion_sort_list - sorts a linked list
 * @list: pointer to head of list
 * description: sorts a list using insertion sort
 * Return: Nothing
*/


void insertion_sort_list(listint_t **list)
{
	listint_t *curr_node, *insert_loc, *curr_prev;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	/*start checking from the second*/
	curr_node = (*list)->next;
	while (curr_node != NULL)
	{
		insert_loc = curr_node;
		curr_prev = curr_node->prev;
		while (curr_prev != NULL && curr_node->n < curr_prev->n)
		{
			/*swap the curr_node and curr_prev*/
			if (curr_node->next != NULL)
				curr_node->next->prev = curr_prev;
			curr_prev->next = curr_node->next;
			curr_node->prev = curr_prev->prev;
			curr_prev->prev = curr_node;

			if (curr_node->prev != NULL)
				curr_node->prev->next = curr_node;
			else
				*list = curr_node;

			curr_node->next = curr_prev;
			print_list(*list);
			curr_prev = curr_node->prev;
		}
		curr_node = insert_loc->next;
	}
}
