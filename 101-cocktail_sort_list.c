#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * swap_node_forward - swaps a node in listint doubly linked
 *                     list
 * @list: A pointer that points to the head of doubly linked list
 * @tail: A pointer that ponts to the tail of the doubly linked list
 * @shaker: A pointer to the current swapping node of the cocktail shaker
 *
 *
 */
void swap_node_forward(listint_t **list, listint_t **tail, listint_t **shaker)
{
listint_t *tmp = (*shsker)->next;

if ((*shaker)->prev != NULL)
(*shaker)->prev->next = tmp;
else
*list = tmp;
tmp->prev = (*shaker)->prev;
(*shaker)->next = tmp->next;
if (tmp->next != NULL)
tmp->next->prev = *shaker;
else
*tail = *shaker;
(*shaker)->prev = tmp;
tmp->next = *shaker;
*shaker = tmp;

}

/**
 * swap_node_backward - swaps a node in doubly linked list
 *
 * @list: A pointerthat points to the head of the doubly linked list
 * @tail: A pointer that points to the tail of the doubly linked list
 * @shaker: A pointer to the current swapping node of the coctail shaker
 *
 */
void swap_node_backward(listint_t **list, listint_t **tail, listint_t **shaker)
{
listint_t *tmp = (*shaker)->prev;

if ((*shaker)->next != NULL)
(*shaker)->next->prev = tmp;

else
*tail = tmp;
tmp->next = (*shaker)->next;
(*shaker)->prev = tmp->prev;
if (tmp->prev != NULL)
tmp->prev->next = *shaker;
else
*list = *shaker;
(*shaker)->next = tmp;
tmp->prev = *shaker;
*shaker = tmp;
}

/**
 * cocktail_sort_list - function to sort using the cocktail
 *                      shaker sort algorithm
 *
 * @list: double linked list of integers
 *
 * Return: Nothing.
 *
 */
void cocktail_sort_list(listint_t **list)
{
listint_t *tail, *shaker;
bool shaken_not_stirred = false;

if (list == NULL || *list == NULL || (*list)->next == NULL)
return;

for (tail = *list; tail->next != NULL;)
tail = tail->next;

while (shaken_not_stirred == false)
{
shaken_not_stirred = true;
for (shaker = *list; shaker != tail; shaker = shaker->next)
{
if (shaker->n > shaker->next->n)
{
swap_node_forward(list, &tail, &shaker);
print_list((const listint_t *)*list);
shaken_not_stirred = false;

}
}
for (shaker = shaker->prev; shaker != *list;
shaker = shaker->prev)
{
if (shaker->n < shaker->prev->n)
{
swap_node_backward(list, &tail, &shaker);
print_list((const listint_t *)*list);
shaken_not_stirred = false;
}
}
}
}
