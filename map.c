//
// Created by chendjou on 02/12/2018.
//

#include <malloc.h>
#include <stdio.h>
#include <mem.h>
#include "map.h"
#include "list.h"




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
    keyValue ->next = map ->list ->first;
    map ->size +=1;
    push_to_list(map -> list, keyValue);
}

void save_or_update_from_map(Map* map, char* key, void* value){
    KeyValue* current = get_key_value_from_map(map, key);

    if(current != NULL){
        current -> value = value;
    } else{
        put_to_map(map, key, value);
    }
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

void* get_key_value_from_map(Map* map, char* key){
    Node* node = map -> list -> first;
    KeyValue* current;
    while (node != NULL){
        current = node -> value;
        if(strcmp(current ->key, key) == 0){
            return current;
        }

        node = node ->next;
    }
    return NULL;
}


void remove_from_map(Map* map, char* key){
    KeyValue* current = get_key_value_from_map(map, key);

    if(current != NULL){
        remove_from_list(map ->list, current);
        free(current);
    } else{
        printf("La variable %s n'existe pas\n");
    }
}
