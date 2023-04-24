#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * insertion_sort_list - function to sort a doubly linked list
 * @list: doubly linked list
 *
 * Return: Nothing
 */
void insertion_sort_list(listint_t **list)
{
listint_t *current_node = NULL, *tmp = NULL;
if (list == NULL || *list == NULL || (*list)->next == NULL)
return;
current_node = *list;
current_node = current_node->next;
while (current_node)
{
while (current_node->prev && current_node->n < (current_node->prev)->n)
{
tmp = current_node;
if (current_node->next)
(current_node->next)->prev = tmp->prev;
(current_node->prev)->next = tmp->next;
current_node = current_node->prev;
tmp->prev = current_node->prev;
tmp->next = current_node;
if (current_node->prev)
(current_node->prev)->next = tmp;
current_node->prev = tmp;
if (tmp->prev == NULL)
*list = tmp;
print_list(*list);
current_node = current_node->prev;
}
current_node = current_node->next;
}
}
