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
void save_operation(char* operation, double op_result);
void print_last_operations();
HANDLE hConsole;

List* last_operations;
int main2(void){
    add_function("tan(xdd,y,ze1)=sin(x)/cos(x)");

    return 0;
}

int main(void) {
    init_HConsole();
    last_operations = create_list();
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    //init_evaluator_hConsole();
    setlocale(LC_ALL, "");

    init_variable_storage();
    char command[1000];
    char instruction[100];
    char* description = malloc(sizeof(char) * 20);
    do{
        console_read(command, 1000);

        split_command(command, instruction, description);

        if(strcmp("var", instruction) == 0){
            if(strchr(description, '=') == NULL){
                red_text();
                printf("Mauvaise déclaration de variable\n");
                white_text();
                continue;
            }
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
        }
        else if(strcmp("remove", instruction) == 0){
            remove_variable(description);
        }
        else if(strcmp("clear", instruction) == 0){
            system("cls");
        }
        else if(strcmp("vars", instruction) == 0){
            print_map(get_all_variables());
        }
        else if(strcmp("operations", instruction) == 0){
            print_last_operations();
        }
        else if(strcmp("reset", instruction) == 0){
            remove_all_from_list(last_operations);
            remove_all_variable();
            load_default_constant();
        }

        else if(instruction[0] == '\0'){
            red_text();
            printf("Instruction ignorée\n");
            white_text();
        }
        else{
            op(instruction);
        }

    }while (strcmp("exit", instruction));

    return 0;
}

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
        save_operation(expression, result);
    }

}

void save_operation(char* operation, double op_result){
    char* result_str = double_to_string(op_result);
    char* result = malloc(sizeof(operation) + sizeof(result_str ) +5);
    result[0] = '\0';
    strcat(result, operation);
    strcat(result, " = ");
    strcat(result, result_str);
    push_to_list(last_operations, result);

    if(last_operations -> size == 4){
        remove_last_from_list(last_operations);
    }
}

void print_last_operations(){
    Node* node = last_operations ->first;
    while (node != NULL){
        printf("%s\n", node -> value);
        node = node -> next;
    }
}