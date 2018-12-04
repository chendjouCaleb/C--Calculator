#include <stdio.h>
#include <locale.h>
#include "evaluator.h"
#include "map.h"
#include "variable.h"
#include "function.h"
#include "command.h"
#include "util.h"
#include <wchar.h>
#include <malloc.h>

void op(char* operation);
int main(void) {
    setlocale(LC_ALL, "");
    //init_function_storage();
    init_variable_storage();
//    add_or_update_variable("xy", "15.963");
//    print_map(get_all_variables());
//    save_variable("xy");

    char command[1000] = {};
    char instruction[100] = {};
    char description[500] = {};

    do{
        console_read(command, 1000);

        split_command(command, instruction, description);

        if(strcmp("var", instruction) == 0){
            char *name = strtok(description, "=");
            char *expression = strtok(NULL, "=");

            Operation* operation = init_operation(expression);
            double r = eval(operation);
            char* result = double_to_string(r);
            if (!operation ->hasError){
                add_or_update_variable(name, result);
                printf("%s = %s\n", name, result);
            }


        } else if(strcmp("save", instruction) == 0){

            save_variable(description);
        } else if(strcmp("remove", instruction) == 0){
            remove_variable(description);
        }

        else if(instruction[0] == ' '){

        }
        else{
            op(instruction);
        }

    }while (strcmp("exit", instruction));


    //add_function("root(x,y)=cos(x)+sin(y)");




    //printf("PI = %f\n", get_variable("pi"));
//    op("303.11+2+4-1+4+9+6");
//    op("30.11+2+4-1+4+9+6");
//    op("-21+4+9+6");
//    op("+21+4+9+6");
//    op("*21+4+9+6");
//    op("30.11*2+4/1");
//    op("21+(4+9+6");
//    op("30*2+4*1+(4+9)*6");
//    op("30.11*2+4*1+(4+9)*6");
//    op("2+4+9*6^2");
//    op("2+4+9+6^(2))");
//    op("2+4+9+6^(2+1)");
//    op("pi+4");
//    op("pi");
//    op("sqrt(100)");
//    op("sqrt(100,)+1");
//    op("pow(10,sqrt(4))");
//    op("e+4");

    return 0;
}

int main1(){

    Map* map = create_map();
    put_to_map(map, "name", "chendjou");
    put_to_map(map, "surname", "deGrasse");
    put_to_map(map, "tel", "chendjou");
    print_map(map);

    printf("ddd");
    char* name = get_from_map(map, "name");
    printf("name = %s", name);
    return 0;
}

void op(char* expression){
    Operation* operation = init_operation(expression);
    double result = eval(operation);
    if (!operation ->hasError){
        printf("%s\n", double_to_string(result));
        //printf("%f", result);
    }
}