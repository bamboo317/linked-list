/*
 * linked_list.h
 */

typedef struct node {
    struct node * next;
    int val;
} node;


typedef struct linked_list {
    node *head;
    node *tail;
} linked_list;

linked_list * linked_list_init (void);
void linked_list_destroy(linked_list ** ll);
void linked_list_remove(linked_list **ll, int val);
int linked_list_add(linked_list **ll, int val);
void linked_list_print(linked_list *ll);
