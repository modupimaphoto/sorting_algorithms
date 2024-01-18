#include "sort.h"
/**
 * swap_nodes - Swaps two nodes in a doubly linked list.
 *
 * @node1: A pointer to the first node
 * @node2: A pointer to the second node
 * @list: A double pointer to the head of the linked list
 *
 * Return: Nothing.
 */
void swap_nodes(listint_t **node1, listint_t **node2, listint_t **list)
{
	listint_t *temp;

	if (*node1 == NULL || *node2 == NULL)
		return;

	if ((*node1)->prev != NULL)
		(*node1)->prev->next = *node2;
	else
		*list = *node2;

	if ((*node2)->next != NULL)
		(*node2)->next->prev = *node1;

	temp = (*node2)->next;
	(*node2)->next = *node1;
	(*node1)->prev = *node2;
	(*node1)->next = temp;
	(*node2)->prev = (*node1)->prev;
}
/**
 * cocktail_sort_list - sorts a doubly linked list of integers in
 * ascending order using the Cocktail shaker sort algorithm.
 *
 * @list: doubly linked list
 *
 * Return: Nothing.
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped;
	listint_t *temp;

	if (list == NULL || *list == NULL)
		return;
	do {
		swapped = 0;
		for (temp = *list; temp->next != NULL; temp = temp->next)
		{
			if (temp->n > temp->next->n)
			{
				swap_nodes(&(temp->next), &temp, list);
				swapped = 1;
				print_list(*list);
			}
		}
		if (swapped == 0)
			break;
		swapped = 0;
		for (; temp->prev != NULL; temp = temp->prev)
		{
			if (temp->n < temp->prev->n)
			{
				swap_nodes(&(temp->prev), &temp, list);
				swapped = 1;
				print_list(*list);
			}
		}
	} while (swapped);
}
