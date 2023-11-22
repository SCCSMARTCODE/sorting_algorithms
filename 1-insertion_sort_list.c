#include "sort.h"

/**
 * swap_list - Swaps two elements in a doubly linked list.
 * @a: First node to be swapped.
 * @b: Second node to be swapped.
 * @head: Pointer to the head of the list.
 */
void swap_list(listint_t *a, listint_t *b, listint_t **head)
{
	listint_t *border1 = NULL, *border2 = NULL;

	if (a == NULL || b == NULL)
		return;

	border1 = a->prev;
	border2 = b->next;

	if (border1)
		border1->next = b;

	if (border2)
		border2->prev = a;

	a->next = border2;
	a->prev = b;
	b->next = a;
	b->prev = border1;

	if (border1 == NULL)
		*head = b;
}

/**
 * insertion_sort_list - Sorts a doubly linked list using insertion sort.
 * @list: Pointer to the head of the doubly linked list.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *head, *prev;
	int value;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	head = *list;
	while (head)
	{
		prev = head->prev;
		value = head->n;

		while (prev && prev->n > value)
		{
			swap_list(prev, head, list);
			print_list(*list);
			prev = head->prev;
		}
		head = head->next;
	}
}
