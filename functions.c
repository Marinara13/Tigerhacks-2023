#include "header.h"


void audition(position current){
    char opt1[]=" Indie";
    char opt2[]=" Low Budget";
    char opt3[]=" High Budget";


    setOpt(current, opt1, opt2, opt3, NULL);
    printOpt(current);
    choice3( current);
    
    switch (*(current.action)) {
        case 1: //No fame required
            char indieMovies[22][30] = {"movie", "movie", "movie", "movie", "movie", "movie", "movie", "movie", "movie"};
            printf("Congratulations! You are now starring in %s", indieMovies[(int)rand()%22]);
            *(current.fame) += rand() % 1000;
            *(current.networth) += rand() % 50000;
            break;
        case 2: //Some fame required unless lucky enough
            if (*(current.luck) >= 50 || *(current.fame) >= 4000) {
                char lowMovies[22][30] = {"movie", "movie", "movie", "movie", "movie", "movie", "movie", "movie", "movie", "movie"};
                printf("Hooray! yabada bing bong %s", lowMovies[(int)rand()%22]);
                *(current.fame) += rand() % 2000 + 250;
                if (*(current.luck) >= 90) {
                    *(current.networth) += 10000 * (rand() % 10) + 50000; //More money if you're really lucky
                }
                else *(current.networth) += 20000 * (rand() % 10) + 50000;
            }
            else printf("You were unable to secure a role for the film\n");
            break;
        case 3: //Lots of fame required unless really lucky
            if (*(current.luck) >= 90 || *(current.fame) >= 7000) {
                char highMovies[22][30] = {"movie", "movie", "movie", "movie", "movie", "movie", "movie", "movie", "movie", "movie"};
                printf("Hooray! yabada bing bong %s", highMovies[(int)rand()%22]);
                *(current.fame) += rand() % 2000 + 250;
                if (*(current.luck) >= 90) {
                    *(current.networth) += 7400000 * (rand() % 10) + 1000000; //More money if you're really lucky
                }
                else *(current.networth) += 500000 * (rand() % 10) + 250000;
            }
            else printf("You were unable to secure a role for the film\n");
            break;
    }

    
}

void mainChoice(position current) {
    char opt1[]=" Audition for a roll";
    char opt2[]=" Go out and network ";
    char opt3[]=" Go to improv club to practice";


    setOpt(current, opt1, opt2, opt3, NULL);
    printOpt(current);
    choice3( current);
    switch (*(current.action)) {
        case 1:
            audition(current);
            break;
        case 2:
            network(current);
            break;
        case 3:
            *(current.luck) += 10;
            printf("Hopefully someone will see you efforts\n");
            break;
    }
    int updateAge = *(current.age);
    *(current.age) = updateAge + 1;
}

