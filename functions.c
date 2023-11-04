#include "header.h"




void mainChoice(position current) {
    char opt1[]=" Audition for a roll";
    char opt2[]=" Go out and network ";
    char opt3[]=" Go to improve to practice";


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

