//
// Created by chendjou on 02/12/2018.
//

#include <malloc.h>
#include <stdio.h>
#include "variable.h"
#include "map.h"

Map* map;

void init_variable_storage(){
    map = create_map();

    put_to_map(map, "pi", "3.14");
}

double get_variable(char* key){
    char* v = get_from_map(map, key);
    if(v != NULL){
        double value = to_double(v);
        return value;
    }
    return 0;
}

double to_double(char* string){
    int i = 0;
    double decimal = 0;
    double result = string[i] - '0';
    i++;
    while (string[i] >= '0' && string[i] <= '9') {
        result = 10 * result + string[i] - '0';
        i++;
    }
    if (string[i] == '.') {
        i++;
        double j = 1;
        while (string[i] >= '0' && string[i] <= '9') {
            decimal = 10 * decimal + string[i] - '0';
            i++;
            j = j * 10;
        }
        decimal /= j;
    }
    result += decimal;
    //printf("v=%f\n", result);
    return result;
}