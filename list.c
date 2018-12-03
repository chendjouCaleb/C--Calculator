#include <stdio.h>
#include <malloc.h>
#include "list.h"




List *create_list(){
    List* list = malloc(sizeof(List));

    if(list == NULL){
        exit(EXIT_FAILURE);
    }
    list -> first = NULL;
    list->size = 0;

    return list;
}

void push_to_list(List* list, void* value){
    Node* node = malloc(sizeof(Node));

    node -> value = value;

    if(list->first == NULL){
        node -> next = NULL;
        list -> first = node;
    }else{
        node -> next = list -> first;
        list -> first = node;
    }

    list->size++;
}

int pop_to_list(List* list){
    if(list -> first == NULL){
        exit(EXIT_FAILURE);
    }

    //if(list -> first != NULL){
        Node* to_pop = list -> first;
        int value = to_pop -> value;
        list -> first = list -> first -> next;
        free(to_pop);
    //}
    list->size--;
    return value;
}

void print_list(List* list){
    if(list -> first == NULL){
        exit(EXIT_FAILURE);
    }

    Node* actual = list->first;

    while(actual != NULL){
        printf("%d ->", actual->value);
        actual = actual -> next;
    }
    printf("NULL\n");
    printf("size: %d", list -> size);
}