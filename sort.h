#ifndef SORT_H
#define SORT_H

#include <stdlib.h>
#include <stdio.h>


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

/**given printing functions**/
void print_list(const listint_t *list);
void print_array(const int *array, size_t size);

/**sorting functions**/
int bubble_sort(int *array, int size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);

/**sorting-function functions**/
void sorting(int *array, int low, int high, size_t size);
int partition(int *array, int low, int high, size_t size);
void swap(int *a, int *b);
listint_t *swap_list(listint_t *a, listint_t *b, listint_t **head);
int check_if_all_sorted(listint_t *list);
int *get_list(int *list, int max);


#endif
