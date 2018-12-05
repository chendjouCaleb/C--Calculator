#include <stdio.h>
#include <locale.h>
#include "evaluator.h"
#include "map.h"
#include "variable.h"
#include "function.h"
#include "command.h"
#include "util.h"
#include "HConsole.h"
#include <wchar.h>
#include <malloc.h>
#include <windows.h>

void op(char* operation);
HANDLE hConsole;
int main(void) {
    init_HConsole();
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    //init_evaluator_hConsole();
    setlocale(LC_ALL, "");

    init_variable_storage();
    char command[1000];
    char instruction[100];
    char* description = malloc(sizeof(char) * 20);
    do{
        memset(command, 0, sizeof(*command));
        memset(instruction, 0, sizeof(*instruction));
        memset(description, 0, sizeof(*description));
        console_read(command, 1000);

        split_command(command, instruction, description);

        //printf("Instruction: %s\n", instruction);
        if(strcmp("var", instruction) == 0){
            char *name = strtok(description, "=");
            char *expression = strtok(NULL, "=");

            Operation* operation = init_operation(expression);
            double r = eval(operation);
            char* result = double_to_string(r);
            if (!operation ->hasError){
                strcat(name, "");
                add_or_update_variable(name, result);
                SetConsoleTextAttribute(hConsole, 9);
                printf("%s = %s\n\n", name, result);
                SetConsoleTextAttribute(hConsole, 15);
            }


        } else if(strcmp("save", instruction) == 0){

            save_variable(description);
        } else if(strcmp("remove", instruction) == 0){
            remove_variable(description);
        } else if(strcmp("clear", instruction) == 0){
            system("cls");
        } else if(strcmp("vars", instruction) == 0){
            print_map(get_all_variables());
        }

        else if(instruction[0] == '\0'){

        }
        else{
            op(instruction);
        }

    }while (strcmp("exit", instruction));

    return 0;
}

double operation_count = 1;
void op(char* expression){
    char* operation_count_str;
    char* var_name = malloc(sizeof(char) * 100);
    Operation* operation = init_operation(expression);
    double result = eval(operation);
    if (!operation ->hasError){
        SetConsoleTextAttribute(hConsole, 10);
        printf("%s\n\n", double_to_string(result));
        SetConsoleTextAttribute(hConsole, 15);

        add_or_update_variable("ans", double_to_string(result));

        operation_count_str = double_to_string(operation_count);

        var_name[0] = 'a';
        var_name[1] = 'n';
        var_name[2] = 's';
        var_name[3] = '\0';
        char* r = strcat(var_name, operation_count_str);


        add_or_update_variable(var_name, double_to_string(result));
        operation_count++;
    }

}