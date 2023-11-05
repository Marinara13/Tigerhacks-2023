#include "header.h"

int main (void)
{
    position player = storyIntro();
    printStats(player);
    location(player);
    while (*(player.age) != 22) {
        mainChoice(player);
        printStats(player);
        randomEvent(player);
        if(*(player.fail) == 1){
            break;
        }

    }
    ending(player);
    freePosition(player);
}
