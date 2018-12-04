//
// Created by chendjou on 01/12/2018.
//

#include <stdio.h>
#include <stdlib.h>
#include <mem.h>
#include <stdbool.h>
#include <math.h>
#include "evaluator.h"
#include "variable.h"
#include "function.h"
#include "util.h"


double eval(Operation *operation) {

    double result = term(operation);
    while (has_char(operation) && (get_current(operation) == '-' || get_current(operation) == '+')) {
        //printf("op=%c\n", get_current());
        char op = pop_current(operation);
        if (op == '+') {
            result += term(operation);
        } else if (op == '-') {
            result -= term(operation);
        }
        //printf("cursor=%d, char=%c\n", operation ->cursor, get_current(operation));
    }
    if(has_char(operation) && (get_current(operation) == ')' && operation -> depth == 0)) {
        operation ->hasError = 1;
        printf("Le caractère '%c' à la position %d est inattendu\n", get_current(operation), operation->cursor);
    }

    //printf("%s = %f; len=%d; c=%d", operation->expression, result, operation->length, operation->cursor);
    //printf("%s = %f", operation->expression, result);
    return result;
}


double term(Operation *operation) {
    double result = factor(operation);

    while (has_char(operation) && (get_current(operation) == '*' || get_current(operation) == '/')) {
        //printf("op=%c\n", get_current(operation));
        char op = pop_current(operation);
        if (op == '*') {
            result *= factor(operation);
        } else if (op == '/') {
            result /= factor(operation);
        }
    }
//    if(has_char(operation) && (get_current(operation) != '-' && get_current(operation) != '+')) {
//        printf("Le caractère '%c' à la position %d est inattendu\n", get_current(operation), operation->cursor);
//    }
    //printf("t=%f\n", result);
    return result;
}

double factor(Operation *operation) {
    //printf("cursor=%d, char=%c\n", operation ->cursor, get_current(operation));
    if(!is_factor_begin(get_current(operation))) {
        printf("Le caractère '%c' à la position %d n'est pas un début de facteur\n", get_current(operation), operation->cursor);
    }
    double result = 0;
    if (current_is_digit(operation)) {
        result = value(operation);
    } else if(is_letter(get_current(operation))){
        char* name = get_name(operation);

        if(get_current(operation) == '('){
            operation -> depth +=1;
            pop_current(operation);
            double values[10];
            int i = 0;
            values[0] = eval(operation);

            i++;
            while (get_current(operation) == ','){
                pop_current(operation);
                values[i] = eval(operation);

                i++;
            }
            if(get_current(operation) != ')'){
                printf("La caractère ')' est attendu à la position %d\n", operation ->cursor);
                operation ->hasError++;
            }

            pop_current(operation);
            char* func_expression = interpret_function(name, values);
            Operation* sub_op = init_operation(func_expression);
            result = eval(sub_op);

        } else{
            double value = get_variable(name);
            if(value == 0){
                printf("La variable ou la constant '%s' n'existe pas\n", name);
                operation ->hasError = 1;
            }
            result = value;
        }
    }


    else if (get_current(operation) == '(') {
        printf("parenthèse\n");
        operation -> depth +=1;
        pop_current(operation);
        result = eval(operation);
       // printf("cursor=%d, char=%c\n", operation ->cursor, get_current(operation));
        if (pop_current(operation) != ')') {
            printf("Le caractère ')' est attendu à la position %d\n", operation->cursor);
        }
        operation -> depth-=1;

    } else if (get_current(operation) == '-') {
        pop_current(operation);
        result = -factor(operation);
    } else if (get_current(operation) == '+') {
        pop_current(operation);
        result = factor(operation);
    }
    if(get_current(operation) == '^'){
        pop_current(operation);
        result = pow(result, factor(operation));
    }


    //printf("f=%f\n", result);
    return result;
}

double value(Operation *operation) {

    double decimal = 0;
    double result = pop_current(operation) - '0';
    while (get_current(operation) >= '0' && get_current(operation) <= '9') {
        result = 10 * result + pop_current(operation) - '0';
    }
    if (has_char(operation) && (get_current(operation) == '.') ){
        pop_current(operation);
        double j = 1;
        while (get_current(operation) >= '0' && get_current(operation) <= '9') {
            decimal = 10 * decimal + pop_current(operation) - '0';
            j = j * 10;
        }
        decimal /= j;
    }
    result += decimal;
    //printf("v=%f\n", result);
    return result;
}


Operation *init_operation(char *expression) {
    Operation *operation = malloc(sizeof(Operation));
    operation->expression = expression;
    operation->length = strlen(expression);
    operation->hasError = 0;
    operation->cursor = 0;
    operation -> depth = 0;
}

char pop_current(Operation *operation) {
    char value = operation->expression[operation->cursor];
    operation->cursor = operation->cursor + 1;
    return value;
}

int has_char(Operation *operation) {
    return operation->cursor <= operation->length - 1;
}


int current_is_digit(Operation *operation) {
    return get_current(operation) >= '0' && get_current(operation) <= '9';
}


char get_current(Operation *operation) {
    return operation->expression[operation->cursor];
}

char* get_name(Operation* operation){
    char* name = malloc(sizeof(char) * 20);
    int i=0;
    while (has_char(operation) && is_digit_or_letter(get_current(operation))){
        name[i] = pop_current(operation);
        i++;
    }
    return name;
}