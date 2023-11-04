#include "header.h"

void ending(position current) {
    if (current.fame >= 9000 && current.networth >= 100000000) {
        printf("You made it big! You are well renowned, and are able to retire with a well padded savings account. You have become the main star of many peoples’ favorite movies, and there is not a television screen in the world that has not aired your beautiful wealthy face.\n");
    }
    else if (current.fame >= 2500 && current.networth >= 100000000) {
        printf("Congratulations, Mr. Moneybags! You have earned enough in your career to sustain you through the rest of your life. While you didn’t make the biggest splash in the cinemas, you will certainly be content in your gold-plated private jet.\n");
    }
    else if (current.fame >= 9000 && current.networth >= 1000000) {
        printf("Hooray! You are now the biggest name on the face of the earth. You now have your own show called “Keeping up with %s”. You can’t even step outside before being blinded by the flashing lights of a few dozen paparazzi.\n", current.name);
    }
    else if (current.fame >= 2500 && current.networth >= 1000000) {
        printf("You fought tooth and nail to reach your dreams of becoming a superstar. However, you fell just short of anything more than a side character. You are still able to make a decent living though, and will be comfortable for the rest of your life.\n");
    }
    else printf("You are worthless. Your attempts at stardom have led you nowhere. Now, you are but a husk of an actor. An empty promise. You work the rest of your life in a pizza place, and you get barely any sleep at night because your head is full of regret.\n");
}

void audition(position current){
    char opt1[]=" Indie";
    char opt2[]=" Low Budget";
    char opt3[]=" High Budget";

    printf("What type of role would you like to audition for?\n");
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

