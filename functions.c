#include "header.h"


void audition(position current){
    char opt1[]=" prompt 1";
    char opt2[]=" prompt 2 ";
    char opt3[]=" prompt 3";


    setOpt(current, opt1, opt2, opt3, NULL);
    printOpt(current);
    choice3( current)
    
    switch (*(current.action)) {
        case 1:
            //option 1
            break;
        case 2:
            //option 2
            break;
        case 3:
            //option 3
            break;
    }

    
}

void mainChoice(position current) {
    char opt1[]=" Audition for a roll";
    char opt2[]=" Go out and network ";
    char opt3[]=" Go to improv club to practice";


    setOpt(current, opt1, opt2, opt3, NULL);
    printOpt(current);
    choice3( current);
    switch (*(current.action)) {
        case 1:
            audition(current);
            break;
        case 2:
            *(current.fame) += 10;
            printf("you have gained some fame\n");
            break;
        case 3:
            *(current.luck) += 10;
            printf("Hopefully someone will see you efforts\n");
            break;
    }
    int updateAge = *(current.age);
    *(current.age) = updateAge + 1;
}

