#pragma once
#include <stdio.h>
#include <stdlib.h>

#define PERIODS 8
#define SIZE 500
#define SECNO 7
#define COURSE 8
#define DAYS 6
#define ROOMS 25
#define SLOTLENGTH 100
#define LABS 5

typedef struct TimeTables T;
typedef struct GeneratedTable G;
typedef struct ClassRooms C;

struct TimeTables {
    char courseType[COURSE][5];
    char courseCode[COURSE][5];
    char subjectName[COURSE][50];
    char teachers[COURSE][SECNO][20];
};

struct GeneratedTable {
    char table[SECNO][PERIODS][DAYS][SLOTLENGTH];
};

struct ClassRooms {
    char class[ROOMS][14];
};

char sec[SECNO] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
char day[DAYS][10] = {{"Monday"}, {"Tuesday"}, {"Wednesday"}, {"Thursday"}, {"Friday"}, {"Saturday"}};