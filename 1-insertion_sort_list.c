#include "sort.h"
/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order
 * @list: pointer to the doubly linked list head
 * Return: no return
 **/
void insertion_sort_list(listint_t **list)
{
	listint_t *head_temp1, *head_temp2, *auxi1, *auxi2;
	int swapped;

	if (list)
	{
		head_temp1 = *list;
		head_temp2 = *list;
		while (list && head_temp1->next)
		{
			if (head_temp1->next)
			{
				swapped = 0;
				head_temp2 = head_temp1;
				while (head_temp2 && head_temp2->n > head_temp2->next->n)
				{
					auxi1 = head_temp2;
					auxi2 = head_temp2->next;
					auxi1->next = auxi2->next;
					if (auxi2->next)
						auxi2->next->prev = auxi1;
					if (auxi2)
					{
						auxi2->prev = auxi1->prev;
						auxi2->next = auxi1;
					}
					if (auxi1)
						auxi1->prev = auxi2;
					if (auxi2->prev)
						auxi2->prev->next = auxi2;
					head_temp2 = auxi2->prev;
					if (!auxi2->prev)
						*list = auxi2;
					print_list(*list);
					swapped = 1;
				}
			}
			if (swapped == 0)
				head_temp1 = head_temp1->next;
		}
	}
}
