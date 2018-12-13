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

void* pop_to_list(List* list){
    if(list -> first == NULL){
        exit(EXIT_FAILURE);
    }

    //if(list -> first != NULL){
        Node* to_pop = list -> first;
        void* value = to_pop -> value;
        list -> first = list -> first -> next;
        free(to_pop);
    //}
    list->size--;
    return value;
}

int remove_from_list(List* list, void* value){
    Node* node = list -> first;
    if(node ->value == value){
        pop_to_list(list);
        return 1;
    }
    Node* prev;
    while (node != NULL){
        if(node ->next -> value == value){
            prev = node;
            Node* toDelete = node ->next;
            prev -> next = toDelete -> next;
            free(toDelete);
            return 1;
        }
        node = node ->next;
    }
    printf("Aucune valeur %s n'a été trouvée", value);
    return 0;
}

void* get_last_from_list(List* list){
    Node* node = list ->first;
    while (node ->next != NULL){
        node = node -> next;
    }
    return node ->value;
}
int remove_last_from_list(List* list){
    Node* node = list ->first;
    if(node == NULL){
        return 0;
    }
    if(node ->next == NULL){
        list ->first = NULL;
        list -> size--;
        free(node);
        return 1;
    }
    while (node ->next ->next != NULL){
        node = node -> next;
    }
    free(node ->next);
    node ->next = NULL;
    list -> size--;
    return 1;
}


void remove_all_from_list(List* list){
    while (list ->first != NULL){
        remove_last_from_list(list);
    }
}

void print_list(List* list){

    Node* actual = list->first;

    while(actual != NULL){
        printf("%d ->", actual->value);
        actual = actual -> next;
    }
    printf("NULL\n");
    printf("size: %d\n", list -> size);
}