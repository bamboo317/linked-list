#include "linked_list.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
    linked_list *ll = linked_list_init();
    int arr[] = {1, 2, 1, 3, 1, 4, 1, 5, 1, 6, 1, -1};
    int i = 0;

    while (arr[i] != -1) {
        linked_list_add(&ll, arr[i++]);
	}

    if (!ll) {
        printf("ll is NULL\n");
        return -1;
    } 

    linked_list_print(ll);
    linked_list_remove(&ll, 1);
    linked_list_print(ll);

    return 0;
}
