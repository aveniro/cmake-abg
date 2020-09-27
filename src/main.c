// src/main.c

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <openssl/rand.h>

#include "config.h"

int crypto_rnd()
{

}

int main()
{
    // Seed random number generator
    time_t t;
    srand((unsigned) time(&t));

    printf("GTN v%s\n", VERSION);
    printf("Guess a number between 1-10 (inclusive)\n\n");

    int the_number = (rand() % 10) + 1;
    int guess;
    for(int i = 0; i < MAX_TRIES; i++)
    {
        printf("-> ");
        scanf("%d", &guess);

        if(guess == the_number)
        {
            printf("\nYou won!\n");
            return 0;
        }
        else
        {
            printf("\nNope, that's not it! %d tries remaining.\n", MAX_TRIES - i - 1);
        }
    }

    printf("You lost!\n");

    return 0;
}