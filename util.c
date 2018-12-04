//
// Created by chendjou on 03/12/2018.
//

#include <stdio.h>
#include "util.h"

int is_digit(char op) {
    return op >= '0' && op <= '9';
}

int is_letter(char character) {
    return (character <= 'z' && character >= 'a') || (character <= 'Z' && character >= 'A');
}

int is_digit_or_letter(char character) {
    return is_letter(character) || is_letter(character);
}

int is_factor_begin(char op) {
    return op == '+' || op == '-' || op == '(' || is_digit(op) || is_letter(op);
}

void create_file_if_not_exist(char *name) {

    FILE *file = fopen(name, "a+");
    if (file != NULL) {
        printf("Le fichier %s a été crée\n", name);
        fclose(file);
    } else {
        printf("Impossible de créer le fichier %s\n", name);
    }
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