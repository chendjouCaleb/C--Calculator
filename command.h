//
// Created by chendjou on 04/12/2018.
//

#ifndef CALCULATOR_COMMAND_H
#define CALCULATOR_COMMAND_H

void clearBuffer();
int console_read(char* entry, int length);
void split_command(char* string, char* command, char* desc);
#endif //CALCULATOR_COMMAND_H
