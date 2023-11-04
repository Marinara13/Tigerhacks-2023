#include <time.h>
#include <stdio.h>
#include <stdlib.h>

// returns a random integer between 0 and 100
// DON'T CALL MULTIPLE TIMES SIMULTANEOUSLY
int setLuck()
{
    time_t t;
    
    srand((unsigned) time(&t));
    int luck = (rand())%101;
    return luck;
}
