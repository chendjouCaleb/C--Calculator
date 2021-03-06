//
// Created by chendjou on 01/12/2018.
//

#ifndef CALCULATOR_EVALUATOR_H
#define CALCULATOR_EVALUATOR_H



typedef struct Operation Operation;

struct Operation{
    char* expression;
    int length;
    int hasError;
    int cursor;
    int depth;
};

double eval(Operation* operation);
char get_current(Operation* operation);
char pop_current(Operation* operation);
double value(Operation* operation);
int current_is_digit(Operation* operation);
double term(Operation* operation);
int has_char(Operation* operation);
double factor(Operation* operation);
Operation* init_operation(char* expression);
char* get_name(Operation* operation);
//void init_evaluator_hConsole();

#endif //CALCULATOR_EVALUATOR_H