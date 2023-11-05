#include "header.h"

int main (void)
{
    position player = storyIntro();
    sleep(3);
    printStats(player);
    sleep(3);
    location(player);
    while (*(player.age) != 22) {
        mainChoice(player);
        printStats(player);
        sleep(3);
        randomEvent(player);
        if(*(player.fail) == 1){
            break;
        }

    }
    ending(player);
    freePosition(player);
}
