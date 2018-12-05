//
// Created by chendjou on 02/12/2018.
//




#ifndef CALCULATOR_MAP_H
#define CALCULATOR_MAP_H

#include "list.h"



typedef struct KeyValue KeyValue;
typedef struct Map Map;

struct KeyValue{
    char* key;
    void* value;
};

struct Map {
    List* list;
    int size;
};



Map* create_map();

void put_to_map(Map* map, char* key, void* value);
void remove_from_map(Map* map, char* key);
void* get_from_map(Map* map, char* key);
void print_map(Map* map);
void* get_key_value_from_map(Map* map, char* key);
void save_or_update_from_map(Map* map, char* key, void* value);
#endif //CALCULATOR_MAP_H