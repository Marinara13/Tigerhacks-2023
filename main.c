#include "header.h"
#include "functions.c"

int main (void)
{
    createPlayer();
    storyIntro();
    while (*(current.age) != 40) {
        printStats();
        mainChoice();
    }
}
