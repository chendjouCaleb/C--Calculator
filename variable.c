//
// Created by chendjou on 02/12/2018.
//

#include <malloc.h>
#include <stdio.h>
#include <mem.h>
#include "variable.h"
#include "map.h"
#include "util.h"
#include "list.h"
#include "HConsole.h"

Map* map;
Map* file_variables;
void init_variable_storage(){
    map = create_map();
    file_variables = create_map();

    create_file_if_not_exist("variable.cal");
    load_default_constant();

    load_file_variables();
}

void load_default_constant() {
    put_to_map(map, "PI", "3.14159265358979");
    put_to_map(map, "E", "2.71828182845905");
    put_to_map(map, "G", "9.8");
}

void load_file_variables(){
    FILE* file = NULL;

    file = fopen("variable.cal", "r");
    if(file != NULL){
        char content[2000]={};
        fgets(content, 2000, file);
        int cursor = 0;
        int i = 0;
        while (is_digit_or_letter(content[cursor])){
            char* name = malloc(sizeof(char)*50);
            char* value = malloc(sizeof(char)*50);
            memset(name, 0, sizeof(name));
            memset(value, 0, sizeof(value));
            while (content[cursor] != '='){
                name[i] = content[cursor];
                i++;
                cursor++;
            }
            cursor++;i=0;
            while (content[cursor] != ';'){
                value[i] = content[cursor];
                cursor++;i++;
            }
            cursor++;i=0;
            put_to_map(map, name, value);
            put_to_map(file_variables, name, value);
        }
        fclose(file);
        //printf("Variables readed form file\n");

    }
}

int add_or_update_variable(char* key, char* value){

    save_or_update_from_map(map, key, value);
}

void save_variable(char* key){
    char* value = get_from_map(map, key);
    if(value == NULL){
        red_text();
        printf("La variable '%s' n'existe pas\n", key);
        white_text();
    } else{
        save_or_update_from_map(file_variables, key, value);
        write_variable_in_file();
    }
}

void remove_variable(char* key){
    remove_from_map(map, key);
    remove_from_map(file_variables, key);
    write_variable_in_file();
}

void remove_all_variable(){
    remove_all_from_map(map);
}

void write_variable_in_file(){
    FILE* file = fopen("variable.cal", "w+");
    if(file !=NULL){
        Node* node = file_variables -> list -> first;
        KeyValue* keyValue;
        while (node != NULL){
            keyValue = node ->value;
            fprintf(file, "%s=%s;", keyValue ->key, keyValue -> value);
            node = node -> next;
        }
        fclose(file);
    }
}

char* get_variable(char* key){
    char* v = get_from_map(map, key);
    if(v != NULL){
        return v;
    }
    return NULL;
}



Map* get_all_variables(){
    return map;
}