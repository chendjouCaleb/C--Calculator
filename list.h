//
// Created by chendjou on 29/11/2018.
//

#ifndef CALCULATOR_LIST_H
#define CALCULATOR_LIST_H

#endif //CALCULATOR_LIST_H

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
int pop_to_list(List* list);
List* create_list();
