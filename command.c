//
// Created by chendjou on 04/12/2018.
//

#include <stdio.h>
#include <mem.h>
#include "command.h"

int console_read(char* entry, int length){
    char* entryCursor=NULL;

    if(fgets(entry, length, stdin) != NULL){
        entryCursor = strchr(entry, '\n');

        if(entryCursor != NULL){
            *entryCursor = '\0';
        } else{
            clearBuffer();
        }
        return 1;
    }
    clearBuffer();
    return 0;
}

void clearBuffer()
{
    int c = 0;
    while (c != '\n' && c != EOF)
    {
        c = getchar();
    }
}

void split_command(char* string, char* command, char* desc){
    memset(command, 0, sizeof(strlen(command)));
    memset(desc, 0, sizeof(strlen(desc)));

    int i=0;
    while (string[i] == ' '){
        i++;
    }

    int j = 0;
    while (string[i] != ' ' && string[i] != '\0'){
        command[j] = string[i];
        i++;
        j++;
    }
    command[j] = '\0';
    i++;

    j = 0;
    while (string[i] != '\0'){
        if(string[i] != ' '){
            desc[j] = string[i];
            j++;
        }
        i++;
    }
    desc[j] = '\0';
}