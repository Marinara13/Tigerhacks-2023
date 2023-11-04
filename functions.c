#include "header.h"

void ending(position current) {
    if (*(current.fail) == 1) {
        printf("You are worthless. Your attempts at stardom have led you nowhere. Now, you are but a husk of an actor. An empty promise. You work the rest of your life in a pizza place, and you get barely any sleep at night because your head is full of regret.\n");
    }
    else{
        if (*(current.fame) >= 9000 && *(current.networth) >= 100000000) {
            printf("You made it big! You are well renowned, and are able to retire with a well padded savings account. You have become the main star of many peoples’ favorite movies, and there is not a television screen in the world that has not aired your beautiful wealthy face.\n");
        }
        else if (*(current.fame) >= 2500 && *(current.networth) >= 100000000) {
            printf("Congratulations, Mr. Moneybags! You have earned enough in your career to sustain you through the rest of your life. While you didn’t make the biggest splash in the cinemas, you will certainly be content in your gold-plated private jet.\n");
        }
        else if (*(current.fame) >= 9000 && *(current.networth) >= 1000000) {
            printf("Hooray! You are now the biggest name on the face of the earth. You now have your own show called “Keeping up with %s”. You can’t even step outside before being blinded by the flashing lights of a few dozen paparazzi.\n", current.name);
        }
        else if (*(current.fame) >= 2500 && *(current.networth) >= 1000000) {
            printf("You fought tooth and nail to reach your dreams of becoming a superstar. However, you fell just short of anything more than a side character. You are still able to make a decent living though, and will be comfortable for the rest of your life.\n");
        }
        else printf("You are worthless. Your attempts at stardom have led you nowhere. Now, you are but a husk of an actor. An empty promise. You work the rest of your life in a pizza place, and you get barely any sleep at night because your head is full of regret.\n");
        }
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

void network(position current){
    char opt1[]=" You can spend 2000 traveling arround and prompoting yourself";
    char opt2[]=" You get a gig to perform at a kids birthday party";
    char opt3[]=" You apply to be on hotones but you might end up wasting your time";
    char opt4[]=" You go with your grandma to the seinor activity center bingo night to meet some new people";


    setOpt(current, opt1, opt2, opt3, opt4);
    printOpt(current);
    choice4( current);

    int luck = setLuck(current);

    switch (*(current.action)) {
        case 1:
            if(luck >= 60){
                printf(" When you get home after traveling you find out the New York Times has made an article about you. With the title being \"Keep your eyes on this new and upcomming star %s\"\n",current.name);
                *(current.fame) = *(current.fame) + *(current.fame);
            }else if(luck >= 40){
                printf("You catch so much attraction you hear you name mentioned on a radio talk show and about how snazzy you are\n");
                *(current.fame) = *(current.fame) + (10 * ( setLuck(current) + 1));
            }else if(luck <=10){
                printf(" After all your traveling you realize you missed your mom's birthday\n -1 follower \n");
                *(current.fame) = *(current.fame) - 1;
            }else{
                printf(" Because of inflation 2000 bucks only allowed you to stay locally but you get to meet some of your fans and add some more\n");
                *(current.fame) = *(current.fame) + (5 * (setLuck(current)+1));
            }
            *(current.networth) = *(current.networth) - 2000;
            break;
        case 2:
            if(luck >= 75){
                printf("When you picked up the flyer for this gig you didn't realise you would be preforming as a clown for Kim k\n you get a healthy check but nobody could tell it was you in that red wig\n");
                *(current.networth) = *(current.networth) + 3000;
            }else if(luck <= 10){
                printf("You read the wrong adrress off the flyer and when you show up it's a funeral home that has a ceremony going on, they probably don't need your services\n");
                *(current.networth) = *(current.networth) - 30;
            }else{
                printf("You show up to the party and dress up as elsa. The kids are loving you and will always be a fan of yours\n");
                *(current.networth) = *(current.networth) + 500;
                *(current.fame) = *(current.fame) + 100;
            }
            
            break;
        case 3:
            if(*(current.fame) > 7000){
                if(luck >=40){
                    printf("You're famous enough to get on hotones and they ask you plenty of spicy questions. However you crush past the ghost pepper sauce without any problems. The episode aires and it's a hit");
                    *(current.fame) += *(current.fame)*0.3 ;
                }else{
                    printf("You're famous enough to get on hoteones but that can only take you so far. The first sauce it tabasco which you thought you were ready for. After one bite your face it beet red and you're hospitalized. The epsiode was never aired but the medical bills remain\n")
                    *(current.networth) = *(current.networth) - 5000;
                }
            }else if(luck >= 80){
                printf("Today is your lucky day, the next episode was supposed to feature tom holland but he got food poising and they to take your application. You crush it as you aplied after years of practacing, the epsiode doesn't get a crazy amount of attention but you'll know you were able to get on the show\n");
                *(current.fame) += *(current.fame)*0.5 ;
            }else{
                printf("Your application didn't even make it to anyones desk and you waste your time waiting for a year and no response\n");
            }
            break;
        case 4;
            if(luck >= 70){

                printf("You go with you grandma to bingo night and you're enjoying yourself even though your grandma is destroying you. You look off to your side and see it's the one and only Nicolas Cage! You rizz him up and get some of his contacts \n");
                *(current.fame) += *(current.fame)*0.75 ;

            }else{
                printf("You go to bingo with your grandma every day that year, sadly nothing out of the ordinary besides winning once but maybe someone interesting might show up next year\n"){
                *(current.fame) += *(current.fame)* 0.1 ;
                }
            }
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

