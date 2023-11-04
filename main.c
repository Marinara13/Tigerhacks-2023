#include "header.h"
#include "print.c"

int main (void)
{
    createPlayer();
    storyIntro();
    while (*(current.age) != 40) {
        printStats();
        mainChoice();
    }
}
