#include<stdio.h>

#define PERIODS 8
#define SIZE 500
#define RANDOM() ({int randInt = rand() % PERIODS; randInt;})
#define SECNO 7
#define COURSE 9

typedef struct TimeTables T;

struct TimeTables {
    char courseCode[COURSE][10];
    char subjectName[COURSE][50];
    char teachers[COURSE][SECNO][20];
};
