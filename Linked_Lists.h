//
// Created by El Mehdi Benseddik on 12/2/2019.
//

#ifndef LINKEDLISTS_LINKED_LISTS_H
#define LINKEDLISTS_LINKED_LISTS_H

#include <stdlib.h>

typedef struct setList {
    int data;
    struct setList *next;
} setList_t;

void do_create_linked_list(void (*op) (setList_t**, int),
                           setList_t** pList, int a) {
    op(pList, a);
}

setList_t* newNode(int a) {
    setList_t* temp = malloc(sizeof(setList_t));
    if (temp == NULL)
        return NULL;
    temp->data = a;
    temp->next = NULL;
    return temp;
}
void createLinkedList(setList_t** pList, int a) {
    if ((*pList) == NULL) {
        // Create new node
        setList_t *new_node = newNode(a);
        (*pList) = new_node;
    } else
        createLinkedList(&(*pList)->next, a);
}
setList_t* fillLinkedList(setList_t* pList, int T[], int n) {
    for (int i = 0; i < n; ++i) {
        do_create_linked_list(createLinkedList, &pList, T[i]);
    }
    return pList;
}
void printLinkedList(setList_t* pList) {
    printf("List Number: ");
    while (pList != NULL) {
        printf("%d ", pList->data);
        pList = pList->next;
    }
    printf("\n");
}

setList_t* do_inserting_value(setList_t* (*op) (setList_t*, setList_t*, int),
                              setList_t* pList, setList_t* p, int value) {
    return op(pList, p, value);
}
setList_t* insertingValue(setList_t* pList, setList_t *p ,int value) {
    if (pList != NULL) {
        if (pList->next != NULL) {
            if (value < pList->data) {
                p = newNode(value);
                p->next = pList;
                pList = p;
            } else if (value > pList->data && value < pList->next->data) {
                p = pList->next;
                pList->next = newNode(value);
                pList->next->next = p;
            } else
                insertingValue(pList->next, p, value);
        } else
            pList->next = newNode(value);
    } else
        pList = newNode(value);
    return pList;
}


#endif //LINKEDLISTS_LINKED_LISTS_H
