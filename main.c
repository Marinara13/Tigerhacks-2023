#include "header.h"
#include "functions.c"

int main (void)
{
    position player = storyIntro();
    if(player.ec ==0){
        printf("cool\n");
    }

    while (*(player.age) != 22) {
        mainChoice(player);
        printStats(player);

    }
}

