//
// Created by chendjou on 05/12/2018.
//
#include <windows.h>
#include "HConsole.h"

HANDLE hConsole;
void init_HConsole(){
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
}

void red_text(){
    SetConsoleTextAttribute(hConsole, 12);
}

void white_text(){
    SetConsoleTextAttribute(hConsole, 15);
}

void green_text(){
    SetConsoleTextAttribute(hConsole, 10);
}

void bleu_text(){
    SetConsoleTextAttribute(hConsole, 9);
}