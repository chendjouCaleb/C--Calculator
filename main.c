#include <stdio.h>
#include <locale.h>
#include "evaluator.h"
#include "map.h"
#include "variable.h"
#include "function.h"
#include <wchar.h>

int main(void) {
    setlocale(LC_ALL, "");
    //init_function_storage();
    init_variable_storage();
    add_or_update_variable("xy", "15.963");
    print_map(get_all_variables());
    save_variable("xy");
    remove_variable("xy");
    remove_variable("xyz");
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

void op(char* operation){
    printf("%s=%f\n\n", operation, eval(init_operation(operation)));
}