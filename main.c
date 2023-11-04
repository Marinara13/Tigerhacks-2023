#include "header.h"
#include "functions.c"

int main (void)
{
    position player = storyIntro();
    while (*(current.age) != 40) {
        printStats();
        mainChoice();
    }
}
