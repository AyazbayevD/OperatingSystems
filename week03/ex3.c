#include <stdio.h>
#include <stdlib.h>

struct LinkedList{
    int value;
    struct LinkedList *next;
};

typedef struct LinkedList *node;

void print_list(node start){
    node run = start;
    while(run != NULL){
        printf("%d ", run->value);
        run = run->next;
    }
}

void insert_node(node where, int new_value){
    node new_node = (node)malloc(sizeof(struct LinkedList));
    new_node->value = new_value;
    new_node->next = where->next;
    where->next = new_node;
}

void delete_node(node some_node){ //deleting node after node "some_node"
    node new_node = (node)malloc(sizeof(struct LinkedList));
    new_node->next = some_node->next;
    some_node->next = some_node->next->next;
    free(new_node); //artificial garbage collection
}

int main() {
    node head = (node)malloc(sizeof(struct LinkedList));
    head->next = NULL;

    //"head" node works as a reference to the first node,
    //so if we want to print content of the list,
    //we should print starting from the next node of "head" node
    print_list(head->next);
    printf("\n");

    //examples of using delete_node() and insert_node()
    insert_node(head, 5);
    print_list(head->next);
    printf("\n");

    insert_node(head, 5);
    print_list(head->next);
    printf("\n");

    insert_node(head->next, 6);
    print_list(head->next);
    printf("\n");

    delete_node(head->next);
    print_list(head->next);
    printf("\n");

    return 0;
}