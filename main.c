#include <stdio.h>
#include <stdint.h>
#include "Linked_Lists.h"

int main() {
    int T[] = {1, 2, 3, 4, 5, 6};
    setList_t* pList = NULL;
    do_create_linked_list(createLinkedList, &pList, 1);
    do_create_linked_list(createLinkedList, &pList, 2);
    return 0;
}