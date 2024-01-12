#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

listint_t *insert_node(listint_t **head, int number)
{
    listint_t *new_node;

    if (head == NULL)
        return (NULL);

    new_node = malloc(sizeof(listint_t));
    if (!new_node)
        return (NULL);

    new_node->n = number;
    new_node->next = NULL;

    while (*head != NULL && number > (*head)->n)
    {
        head = &(*head)->next;
    }

    new_node->next = *head;
    *head = new_node;

    return (new_node);
}