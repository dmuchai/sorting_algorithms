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
	listint_t *head;
	int flag = 0;

	if (!list || !*list || !(*list)->next)
		return;

	do {
		for (head = *list; head->next != NULL; head = head->next)
		{
			if (head->n > head->next->n)
			{
				swap_nodes(list, head, head->next);
				print_list(*list);
				flag = 1;
				head = head->prev;
			}
		}
		if (flag == 0)
			break;
		flag = 0;
		for (; head->prev != NULL; head = head->prev)
		{
			if (head->n < head->prev->n)
			{
				swap_nodes(list, head->prev, head);
				print_list(*list);
				flag = 1;
				head = head->next;
			}
		}
	} while (flag == 1);
}
