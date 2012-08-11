/*
 * linked_list.c
 */
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "linked_list.h"

linked_list * linked_list_init (void) {
    linked_list * ll = NULL;

    ll = malloc(sizeof(linked_list));

    if (!ll) return NULL;

    memset(ll, 0, sizeof(linked_list));

    return ll;
}

void linked_list_destroy (linked_list **ll) {
    node *tmp = NULL;

    if (!ll || !*ll) return;

    while ((*ll)->head) {
        tmp = (*ll)->head;
        (*ll)->head = (*ll)->head->next;
        free(tmp);
    }
    free(*ll);
    *ll = NULL;
}

int linked_list_add (linked_list **ll, int val) {
    node * tmp = NULL;

    if (!*ll || !ll) return -1;

    tmp = malloc(sizeof(node));
    tmp->val = val;
    tmp->next = (*ll)->head;
    (*ll)->head = tmp;
    if (!(*ll)->tail) {
        (*ll)->tail = tmp;
    }

    return 0;
}

void linked_list_remove (linked_list **ll, int val) {
    node * tmp = NULL;
    node * prev = NULL;

    if (!*ll || !ll) return;

    while ((*ll)->head && (*ll)->head->val == val) {
        tmp = (*ll)->head;
        if ((*ll)->tail == tmp) {
            (*ll)->tail = NULL;
        }
        (*ll)->head = (*ll)->head->next;
        free(tmp);
    }

    if (!(*ll)->head) return;

    prev = (*ll)->head;
    tmp = prev->next;

    while (tmp) {
        if (tmp->val == val) {
            prev->next = tmp->next;
            if (tmp == (*ll)->tail) {
                (*ll)->tail = prev;
            }
            free(tmp);
            tmp = prev->next;
        } else {
            prev = tmp;
            tmp = tmp->next;
        }
    }
}

void linked_list_print (linked_list *ll) {
    node * tmp = NULL;
    if (!ll) return;

    tmp = ll->head;
    while (tmp) {
        printf("%d ", tmp->val);
        tmp = tmp->next;
    }
    printf("\n");
}
