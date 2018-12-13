//
// Created by chendjou on 02/12/2018.
//

#ifndef CALCULATOR_VARIABLE_H
#define CALCULATOR_VARIABLE_H


#include "map.h"

void init_variable_storage();
void load_default_constant();
char* get_variable(char* key);
double to_double(char* string);

void load_file_variables();
int add_or_update_variable(char* key, char* value);
void save_variable(char* key);
Map* get_all_variables();
void remove_all_variable();

void remove_variable(char* key);

void write_variable_in_file();

#endif //CALCULATOR_VARIABLE_H