//
// Created by chendjou on 02/12/2018.
//

#include <malloc.h>
#include <stdio.h>
#include <mem.h>
#include "map.h"
#include "list.h"


struct KeyValue{
char* key;
void* value;
};

struct Map {
    List* list;
    int size;
};

Map* create_map(){
    List* list = create_list();
    Map* map = malloc(sizeof(Map));

    map -> list = list;
    map -> size = 0;
}

void put_to_map(Map* map, char* key, void* value){
    KeyValue* keyValue = malloc(sizeof(KeyValue));
    keyValue ->value = value;
    keyValue -> key = key;
    map ->size +=1;
    push_to_list(map -> list, keyValue);

}

void print_map(Map* map){
    Node* node = map -> list -> first;
    KeyValue* current = node -> value;
    while (node != NULL){
        current = node -> value;
        printf("%s => %s\n", current -> key, current ->value);
        node = node ->next;

    }
    printf("Print is finish\n");
}
void* get_from_map(Map* map, char* key){
    Node* node = map -> list -> first;
    KeyValue* current;
    while (node != NULL){
        current = node -> value;
        if(strcmp(current ->key, key) == 0){
            return current ->value;
        }

        node = node ->next;
    }
    return NULL;
}


void remove_from_map(Map* map, char* key);
