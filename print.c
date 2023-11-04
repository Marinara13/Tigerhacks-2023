#include "header.h"


// creates the starting set up for the player
// -1 means malloc failed (shouldn't happen) 
position createChar(){

    position character;
    option * opts = malloc(sizeof(option));
    int * action = malloc(sizeof(int));
    int * luck = malloc(sizeof(int));
    int * age = malloc(sizeof(int));
    int * networth = malloc(sizeof(int));
    if(opts == NULL || action == NULL || luck == NULL|| age ==NULL){ 
    character.ec=-1;
    return character;
    }

    character.opts = opts;
    character.action = action;
    character.luck = luck;
    character.age = age;
    character.networth = networth;
    
    return character;

}

//give it the posistion and 4 char strings
void setOpt(position current,char*opt1,char*opt2,char*opt3,char*opt4 ){

    current.opts->opt1= opt1;
    current.opts->opt2= opt2;
    current.opts->opt3= opt3;
    current.opts->opt4= opt4;

}
//prints out the users options 
void printOpt(position current){

    printf("Your current options are: \n");
    printf("[1] : %s\n\n",current.opts->opt1);
    printf("[2] : %s\n\n",current.opts->opt2);
    if(current.opts->opt3 != NULL){
        printf("[3] : %s\n\n",current.opts->opt3);
    }
    if(current.opts->opt4 != NULL){
    printf("[4] : %s\n\n",current.opts->opt4);
    }
    

}

//asks the user to make a choice
void choice(position current){

    int buffer;
    char eat;
    printf("What choice will you make?\n");


    while(*(current.action) != 1 && *(current.action) != 2 && *(current.action) != 3 && *(current.action) != 4){
       
       buffer = scanf("%d",current.action);
       if(buffer == 0){
        scanf("%c",&eat);
        continue;
       }
    }

}

//frees the stuff
void freePositon(position current){

    free(current.opts);
    free(current.action);

}