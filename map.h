//
// Created by chendjou on 02/12/2018.
//


#ifndef CALCULATOR_MAP_H
#define CALCULATOR_MAP_H

#endif //CALCULATOR_MAP_H

typedef struct KeyValue KeyValue;
struct KeyValue;

typedef struct Map Map;
struct Map;

Map* create_map();

void put_to_map(Map* map, char* key, void* value);
void remove_from_map(Map* map, char* key);
void* get_from_map(Map* map, char* key);
void print_map(Map* map);