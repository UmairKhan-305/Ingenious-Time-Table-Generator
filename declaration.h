#include<stdio.h>

#define PERIODS 8
#define SIZE 500
#define RANDOM() ({int randInt = rand() % PERIODS; randInt;})
#define SECNO 7
#define COURSE 8

typedef struct TimeTables T;

struct TimeTables {
    char courseCode[COURSE][10];
    char subjectName[COURSE][50];
    char teachers[COURSE][SECNO][20];
};

char sec[SECNO] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};

char flag = 'N';
char flag1 = 'N';
int k, l;
int check;
