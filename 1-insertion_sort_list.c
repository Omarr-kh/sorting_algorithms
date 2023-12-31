#include "sort.h"

/**
 * _swap - Swap two nodes in a listint_t doubly-linked list.
 * @head: A pointer to the head of the doubly-linked list.
 * @node1: A pointer to the first node to swap.
 * @node2: The second node to swap.
 */
void _swap(listint_t **head, listint_t **node1, listint_t *node2)
{
	(*node1)->next = node2->next;
	if (node2->next != NULL)
	{
		node2->next->prev = *node1;
	}
	node2->prev = (*node1)->prev;
	node2->next = *node1;
	if ((*node1)->prev != NULL)
	{
		(*node1)->prev->next = node2;
	}
	else
	{
		*head = node2;
	}
	(*node1)->prev = node2;
	*node1 = node2->prev;
}

/**
 * insertion_sort_list - insertion sort.
 * @list: A pointer to the head of a doubly-linked list of integers.
 * Description: Prints the list after each swap.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *i, *prev_node, *next_node;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (i = (*list)->next; i != NULL; i = next_node)
	{
		next_node = i->next;
		prev_node = i->prev;
		while (prev_node != NULL && i->n < prev_node->n)
		{
			_swap(list, &prev_node, i);
			print_list((const listint_t *)*list);
		}
	}
}
