#include "sort.h"

/**
 * swap_nodes - swaps two adjacent nodes in a doubly linked list
 * @head_ref: pointer to the list's head pointer
 * @node_1: the first node in the pair
 * @node_2: second node  in the pair
 */
void swap_nodes(listint_t **head_ref, listint_t *node_1, listint_t *node_2)
{
	listint_t *prev, *next;

	prev = node_1->prev;
	next = node_2->next;

	if (prev != NULL)
		prev->next = node_2;
	else
		*head_ref = node_2;
	node_1->prev = node_2;
	node_1->next = next;
	node_2->prev = prev;
	node_2->next = node_1;
	if (next)
		next->prev = node_1;
}
/**
 * cocktail_sort_list - sorts a list using the cocktail sort algorithm
 * @list: list to sort
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *head_ref;
	int flag = 0;

	if (!list || !*list || !(*list)->next)
		return;

	do {
		for (head_ref = *list; head_ref->next != NULL; head_ref = head_ref->next)
		{
			if (head_ref->n > head_ref->next->n)
			{
				swap_nodes(list, head_ref, head_ref->next);
				print_list(*list);
				flag = 1;
				head_ref = head_ref->prev;
			}
		}
		if (flag == 0)
			break;
		flag = 0;
		for (; head_ref->prev != NULL; head_ref = head_ref->prev)
		{
			if (head_ref->n < head_ref->prev->n)
			{
				swap_nodes(list, head_ref->prev, head_ref);
				print_list(*list);
				flag = 1;
				head_ref = head_ref->next;
			}
		}
	} while (flag == 1);
}
