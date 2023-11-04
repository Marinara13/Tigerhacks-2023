#include "header.h"


// creates the starting set up for the player
// -1 means malloc failed (shouldn't happen) 
position createPlayer(){

    position player;
    option * opts = malloc(sizeof(option));
    int * action = malloc(sizeof(int));
    int * luck = malloc(sizeof(int));
    int * age = malloc(sizeof(int));
    int * fame = malloc(sizeof(int));
    int * networth = malloc(sizeof(int));
    int * luckCounter = malloc(sizeof(int));
    if(opts == NULL || action == NULL || luck == NULL|| age ==NULL ||fame ==NULL||networth==NULL||luckCounter == NULL){ 
    player.ec=-1;
    return player;
    }

    *age = 18;
    *luckCounter = 1;
    player.luckCounter = luckCounter;

    *luck = setLuck(player);
    *network = 500 * (*luck);
    player.opts = opts;
    player.action = action;
    player.luck = luck;
    player.age = age;
    player.fame = fame;
    player.networth = networth;
    printf("What will you superstar name be?\n");
    scanf("%s",player.name);
    
    return player;

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

//asks the user to make a choice of 2 options
void choice2(position current){

    int buffer;
    char eat;
    printf("What choice will you make?\n");

    scanf("%d",current.action);

    while(*(current.action) != 1 && *(current.action) != 2 ){
       
       buffer = scanf("%d",current.action);
       printf("That is not an option try again: \n");
       if(buffer == 0){
        scanf("%c",&eat);
        continue;
       }
    }

}

//asks the user to make a choice of 3 options
void choice3(position current){

    int buffer;
    char eat;
    printf("What choice will you make?\n");

    scanf("%d",current.action);

    while(*(current.action) != 1 && *(current.action) != 2 && *(current.action) != 3){
       
       buffer = scanf("%d",current.action);
       printf("That is not an option try again: \n");
       if(buffer == 0){
        scanf("%c",&eat);
        continue;
       }
    }

}


//asks the user to make a choice of 4 options
void choice4(position current){

    int buffer;
    char eat;
    printf("What choice will you make?\n");

    scanf("%d",current.action);

    while(*(current.action) != 1 && *(current.action) != 2 && *(current.action) != 3 && *(current.action) != 4){
       
       buffer = scanf("%d",current.action);
       printf("That is not an option try again: \n");
       if(buffer == 0){
        scanf("%c",&eat);
        continue;
       }
    }

}

//frees the stuff
void freePositon(position current){

    free(current.opts);
    free(current.age);
    free(current.fame);
    free(current.luck);
    free(current.luckCounter);
    free(current.networth);
    free(current.action);

}


//prints the current player stats
void printStats(position current) {
    
    printf("Age: %d\n", *(current.age));
    printf("Fame: %d\n", *(current.fame));
    printf("Net Worth: %d\n", *(current.networth));
    
}

// returns a random integer between 0 and 100
int setLuck(position current)
{
    time_t t;
    int counter = *(current.luckCounter);
    srand((unsigned) time(&t)*counter);
    int luck = (rand())%101;
    counter++;
    *(current.luckCounter) = counter;
    return luck;
}

void audition(position current) {

}

void mainChoice(position current) {
    char opt1[]=" Audition for a roll";
    char opt2[]=" Go out and network ";
    char opt3[]=" Go to improve to practice";


    setOpt(current, opt1, opt2, opt3, NULL);
    printOpt(current);
    choice3( current);
    /*switch (current.action) {
        case 1:
            audition(position current);
            break;
        case 2:
            *(current.fame) += 10;
            break;
        case 3:
            *(current.luck) += 10;
            break;
    }
    */
}

