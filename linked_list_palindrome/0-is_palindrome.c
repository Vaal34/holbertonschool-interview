#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * is_palindrome - checks if a singly linked list is a palindrome.
 * @head: head of list
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
 * An empty list is considered a palindrome
**/

int is_palindrome(listint_t **head) {
    int length_list = 1;
    listint_t *temp;
    int *First_part, *Second_part;
    int i, j, fi, si;

    temp = *head;

    if (*head == NULL) {
        return 1;
    }

    while ((*head)->next != NULL) {
        *head = (*head)->next;
        length_list++;
    }

    *head = temp;

    if (length_list % 2 != 0) {
        return 0;
    } else if (length_list == 1) {
        return 1;
    }

    First_part = (int *)malloc((length_list / 2) * sizeof(int));
    Second_part = (int *)malloc((length_list / 2) * sizeof(int));

    for (i = 0; i < (length_list / 2); i++) {
        First_part[i] = (*head)->n;
        *head = (*head)->next;
    }

    for (j = 0; j < (length_list / 2); j++) {
        Second_part[j] = (*head)->n;
        *head = (*head)->next;
    }

    fi = 0;
    si = (length_list / 2 - 1);

    while (fi < (length_list / 2)) {
        if (First_part[fi] == Second_part[si]) {
        } else {
            free(First_part);
            free(Second_part);
            return 0;
        }
        fi++;
        si--;
    }

    free(First_part);
    free(Second_part);
    return 1;
}