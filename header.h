#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h> 
#include <time.h>

typedef struct{
    char *opt1;
    char *opt2;
    char *opt3;
    char *opt4;
}option;

typedef struct{
    option* opts;
    int *action;
    int *luck;
    int *age;
    int *fame;
    int *networth;
    int ec;
}position;

position createChar();
void setOpt(position current,char*opt1,char*opt2,char*opt3,char*opt4 );
void printOpt(position current);
void choice(position current);
void freePositon(position current);