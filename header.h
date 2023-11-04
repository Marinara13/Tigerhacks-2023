#ifndef _HEADER_H
#define _HEADER_H

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
    int *luckCounter;
    int *fail;
    char name[20];
    int ec;
}position;

//story code
position storyIntro();
void location(position current);
void audition(position current);
void mainChoice(position current);
void ending(position current);


//all set up code
position createPlayer();
void setOpt(position current,char*opt1,char*opt2,char*opt3,char*opt4 );
void printOpt(position current);
void choice2(position current);
void choice3(position current);
void choice4(position current);
void freePositon(position current);
void printStats(position current);
int setLuck(position current);
#endif
