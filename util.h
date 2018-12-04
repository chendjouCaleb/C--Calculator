//
// Created by chendjou on 03/12/2018.
//

#ifndef CALCULATOR_UTIL_H
#define CALCULATOR_UTIL_H



int is_digit(char op);
int is_letter(char character);
int is_factor_begin(char op);
int is_digit_or_letter(char character);


void create_file_if_not_exist(char* name);
double to_double(char* string);
void replace_char(char* string, char find, char replacement);
char* double_to_string(double value);

#endif //CALCULATOR_UTIL_H