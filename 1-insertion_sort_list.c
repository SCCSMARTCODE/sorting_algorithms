#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       in ascending order using the Insertion sort algorithm.
 *
 * @list: Double pointer to the head of the doubly linked list.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *head, *current;
	int run = 0;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;


	head = *list;

	while (run != 1)
	{
		current = head;
		while (current->next != NULL)
		{
			if (current->n > current->next->n)
			{
			head = swap_list(current, current->next, &head);
			run = check_if_all_sorted(head);
			print_list(head);
			break;
			}
			current = current->next;
		}
	}

	*list = head;
}

/**
 * check_if_all_sorted - Checks if a doubly linked list is sorted.
 *
 * @list: Pointer to the head of the doubly linked list.
 *
 * Return: 1 if the list is sorted, 0 otherwise.
 */
int check_if_all_sorted(listint_t *list)
{
	listint_t *head = list;

	if (list == NULL || list->next == NULL)
		return (1);

	while (head->next != NULL)
	{
		if (head->n > head->next->n)
		{
			return (0);
		}
		head = head->next;
	}

	return (1);
}

/**
 * swap_list - Swaps two nodes in a doubly linked list.
 *
 * @a: First node to swap.
 * @b: Second node to swap.
 * @head: Double pointer to the head of the doubly linked list.
 *
 * Return: Pointer to the new head of the list.
 */
listint_t *swap_list(listint_t *a, listint_t *b, listint_t **head)
{
	if (a->prev != NULL)
	{
		a->prev->next = b;
	}

	if (b->next != NULL)
	{
		b->next->prev = a;
	}

	a->next = b->next;
	b->prev = a->prev;
	a->prev = b;
	b->next = a;

	if (b->prev == NULL)
	{
		return (b);
	}

	return (*head);
}
