//
// Created by El Mehdi Benseddik on 12/2/2019.
//

#ifndef LINKEDLISTS_SINGLE_LINKED_LISTS_H
#define LINKEDLISTS_SINGLE_LINKED_LISTS_H

/*********************************/
/****** Single Linked List *******/
/*********************************/
typedef struct p_node {
    uint32_t data;
    struct p_node* next;
} node_t;

void do_create_node(void (*op) (node_t**, uint32_t),
                    node_t** pNode, uint32_t value) {
    op(pNode, value);
}

node_t* new_node(int value) {
    node_t* node = malloc(sizeof(node_t));
    if (node == NULL) {
        printf("Memory not Allocated !\n");
        return NULL;
    }
    node->data = value;
    node->next = NULL;
    return node;
}

void create_node(node_t** pNode, uint32_t value) {
    node_t* prev = NULL, *curr = *pNode;
    if (curr != NULL) {
        while (curr != NULL) {
            prev = curr;
            curr = curr->next;
        }
        prev->next = new_node(value);
    } else
        (*pNode) = new_node(value);
}

void printData(node_t* p_node) {
    uint32_t i = 0;
    while (p_node != NULL) {
        printf("data:= %d\n", p_node->data);
        p_node = p_node->next;
        i++;
    }
}

uint32_t findData(node_t* p_node, uint32_t data) {
    while (p_node != NULL) {
        if (p_node->data == data)
            return p_node->data;
        p_node = p_node->next;
    }
    return 0;
}

#endif //LINKEDLISTS_SINGLE_LINKED_LISTS_H
