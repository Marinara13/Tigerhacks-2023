#include "header.h"


// creates the starting set up for the player
// -1 means malloc failed (shouldn't happen) 
position storyIntro(){

    printf("\nLights. Camera. Action. You are an aspiring young actor, hoping one day to see your name in lights:\n\n");
    position player = createPlayer();
    printf("\nMaking it in showbiz ain’t easy, but with the right combination of luck and determination, \"%s\" might just be the next big thing.\n\n", player.name);

    return player;
}
position createPlayer(){


    position player;
    option * opts = malloc(sizeof(option));
    int * action = malloc(sizeof(int));
    int * luck = malloc(sizeof(int));
    int * age = malloc(sizeof(int));
    int * fame = malloc(sizeof(int));
    int * networth = malloc(sizeof(int));
    int * luckCounter = malloc(sizeof(int));
    int * fail = malloc(sizeof(int));
    if(opts == NULL || action == NULL || luck == NULL|| age ==NULL ||fame ==NULL||networth==NULL||luckCounter == NULL){ 
    player.ec=-1;
    return player;
    }

    *fail = 0; 
    *age = 18;
    *luckCounter = 1;
    player.luckCounter = luckCounter;

    *luck = setLuck(player);
    *networth = 500 * (*luck);
    player.opts = opts;
    player.action = action;
    player.luck = luck;
    player.age = age;
    player.fame = fame;
    player.networth = networth;
    player.fail = fail;
    printf("What will your superstar name be?\n");
    scanf("%s",player.name);
    player.ec = 0;
    
    return player;

}

void location(position current)
{
    printf("First things first. Where does your journey to fame begin?\n\n");
    
    int holly = 10, boone = 1, ny = 7, como = 3;
    
    setOpt(current, "Hollywood", "Booneville, MO", "New York", "Como, baby!");
    printOpt(current);
    choice4(current);

    switch (*(current.action))
    {
        case 1: // Hollywood
            printf("What better place to start your acting career than the heart of glitz and glam, ");
            printf("\nHollywood? The sheer amount of talent here intimidates you a bit, ");
            printf("\nbut your’re confident in your ability to shine the brightest.\n\n");

            *(current.fame) = (*(current.luck))*holly;
            break;
        case 2: // Booneville
            printf("Why did you pick Booneville? This podunk town doesn’t even have a population ");
            printf("\nof 8,000. Ah, well. It’s the hometown of Jimr, so maybe anything is possible.\n\n");

            *(current.fame) = (*(current.luck))*boone;
            break;
        case 3: // New York
            printf("Ah, the Big Apple! You’ve been surrounded by the hustle and bustle of ");
            printf("\ncity life since you were young, and now you’re ready to rise above the crowd ");
            printf("\n(hopefully in a penthouse).\n\n");
            
            *(current.fame) = (*(current.luck))*ny;
            break;
        case 4: // Como
            printf("You grew up in Columbia, Missouri, home to the best, most spectacular and ");
            printf("\namazing college, Mizzou! It might not be the biggest city to get your foot ");
            printf("\nin the door, but Como’s strong sense of community may help you achieve new heights.\n\n");
            
            *(current.fame) = (*(current.luck))*como;
            break;
    }
}

void setOpt(position current,char*opt1,char*opt2,char*opt3,char*opt4 ){

    current.opts->opt1= opt1;
    current.opts->opt2= opt2;
    current.opts->opt3= opt3;
    current.opts->opt4= opt4;

}
void printOpt(position current){

    // printf("Your current options are: \n\n");
    printf(GREEN "[1] : %s\n\n" OFF,current.opts->opt1);
    printf(GREEN "[2] : %s\n\n" OFF,current.opts->opt2);
    if(current.opts->opt3 != NULL){
        printf(GREEN "[3] : %s\n\n" OFF,current.opts->opt3);
    }
    if(current.opts->opt4 != NULL){
    printf(GREEN "[4] : %s\n\n" OFF,current.opts->opt4);
    }
    

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
//asks the user to make a choice of 2 options
void choice2(position current){

    int buffer;
    char eat;
    // printf("What choice will you make?\n");

    scanf("%d",current.action);

    while(*(current.action) != 1 && *(current.action) != 2 ){
       
       buffer = scanf("%d",current.action);
       printf("That is not an option try again: \n");
       if(buffer == 0){
        scanf("%c",&eat);
        continue;
       }
    }

    printf(BLUE "\n******************************************************************************************\n\n" OFF);

}

//asks the user to make a choice of 3 options
void choice3(position current){

    int buffer;
    char eat;
    // printf("What choice will you make?\n");

    scanf("%d",current.action);

    while(*(current.action) != 1 && *(current.action) != 2 && *(current.action) != 3){
       
       buffer = scanf("%d",current.action);
       printf("That is not an option try again: \n");
       if(buffer == 0){
        scanf("%c",&eat);
        continue;
       }
    }

    printf(BLUE "\n******************************************************************************************\n\n" OFF);

}


//asks the user to make a choice of 4 options
void choice4(position current){

    int buffer;
    char eat;
    // printf("What choice will you make?\n");

    scanf("%d",current.action);

    while(*(current.action) != 1 && *(current.action) != 2 && *(current.action) != 3 && *(current.action) != 4){
       
       buffer = scanf("%d",current.action);
       printf("That is not an option try again: \n");
       if(buffer == 0){
        scanf("%c",&eat);
        continue;
       }
    }

    printf(BLUE "\n******************************************************************************************\n\n" OFF);

}

//frees the stuff
void freePosition(position current){

    free(current.opts);
    free(current.age);
    free(current.fame);
    free(current.luck);
    free(current.luckCounter);
    free(current.networth);
    free(current.action);
    free(current.fail);

}
//prints the current player stats
void printStats(position current) {
    
    printf(RED "\nAge: %d\n" OFF, *(current.age));
    printf(RED "Fame: %d\n" OFF, *(current.fame));
    printf(RED "Net Worth: $%d\n" OFF, *(current.networth));
    printf(RED "Your Luck is %d\n\n" OFF,*(current.luck));
    
}
