#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

int check_cycle(listint_t *list) {
    if (list == NULL || list->next == NULL)
        return 0;
    
    listint_t *before = list;
    listint_t *after = list->next;

    while (after != NULL && after->next != NULL) {
        if (before == after)
            return 1;
        before = before->next;
        after = after->next->next;
    }
    
    return 0;
}
