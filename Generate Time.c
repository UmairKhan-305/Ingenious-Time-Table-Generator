#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PERIODS 8
#define RANDOM() ({int randInt = rand() % PERIODS; randInt;})

int main () {
    srand(time(0));
    int randInt = RANDOM();
    printf("%d", randInt);
}