#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

int check_cycle(listint_t *list) {
    listint_t *current_node = list;
    listint_t *tmp = list;
    int length_list = 0;

    if (list == NULL || list->next == NULL){
        return 1;
    }

    while (current_node != NULL) {
        current_node = current_node->next;
        length_list++;
    }

    current_node = tmp;

    int *Linked_List = (int *)malloc(length_list * sizeof(int));

    int i = 0;
    while (current_node != NULL) {
        Linked_List[i] = current_node->n;
        current_node = current_node->next;
        i++;
    }

    for (int i = 0; i < length_list; i++) {
        for (int j = i + 1; j < length_list; j++) {
            if (Linked_List[i] == Linked_List[j]) {
                free(Linked_List);
                return 1;
            }
        }
    }

    free(Linked_List);
    return 0;
}
