#include "header.h"

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
