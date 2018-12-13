//
// Created by chendjou on 29/11/2018.
//

#ifndef CALCULATOR_LIST_H
#define CALCULATOR_LIST_H



typedef struct Node Node;
struct Node {
    void *value;
    Node *next;
};

typedef struct List List;

struct List {
    Node *first;
    int size;
};

void print_list(List* list);
void push_to_list(List* list, void *value);
void* pop_to_list(List* list);
void* get_last_from_list(List* list);
int remove_last_from_list(List* list);
void remove_all_from_list(List* list);

int remove_from_list(List* list, void *value);
List* create_list();

#endif //CALCULATOR_LIST_H