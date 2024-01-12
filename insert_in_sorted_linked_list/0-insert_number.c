#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

listint_t *insert_node(listint_t **head, int number) {
    
    listint_t *new_node;

    new_node = (listint_t *) malloc(sizeof(listint_t));

    if (new_node == NULL) {
        return NULL;
    }

    new_node->n = number;
    new_node->next = *head;

    while(new_node->next != NULL) {
        if(new_node->next->n < new_node->n) {
            new_node = new_node->next;
        };
    };

    return (new_node);
}