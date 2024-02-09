#include "lists.h"
#include <stdio.h>
#include <stdlib.h>
/**
*
*
*
**/

int is_palindrome(listint_t **head) {


    listint_t *tmp;

    tmp = *head;

    if (*head == NULL) {
        return 1;
    }

    int length_list = 1;

    while((*head)->next != NULL) {
        *head = (*head)->next;
        length_list++;
    }

    *head = tmp;

    int *First_part = (int*)malloc((length_list / 2) * sizeof(int));
    int *Second_part = (int*)malloc((length_list / 2) * sizeof(int));

    for(int i = 0; i < (length_list / 2); i++) {
        First_part[i] = (*head)->n;
        *head = (*head)->next;
    }

    for(int j = 0; j < (length_list / 2); j++) {
        Second_part[j] = (*head)->n;
        *head = (*head)->next;
    }

    /*
    for(int fi = 0; fi < (length_list / 2); fi++) {
        printf("+++++++++++%i++++++++++", First_part[fi]);
        for(int si = (length_list / 2 - 1); si > 0; si--) {
            printf("---s--%i--s-------", Second_part[si]);
            if(First_part[fi] == Second_part[si]) {
                break;
            } else {
                printf("caca");
                return 0;
            }
        }
    }
    */
    
    int fi = 0;
    int si = (length_list / 2 - 1);

    while(fi < (length_list / 2)) {
        if(First_part[fi] == Second_part[si]) {
        } else {
            printf("caca");
            return 0;
        }
        fi++;
        si--;
    }
    return 1;
}
