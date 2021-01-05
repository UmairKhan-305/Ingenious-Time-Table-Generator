#pragma once
#include<stdio.h>

#define PERIODS 8
#define SIZE 500
#define SECNO 7
#define COURSE 8
#define DAYS 6
#define ROOMS 25
#define SLOTLENGTH 100

typedef struct TimeTables T;
typedef struct GeneratedTable G;

struct TimeTables {
    char courseCode[COURSE][10];
    char subjectName[COURSE][50];
    char teachers[COURSE][SECNO][20];
};

struct GeneratedTable {
    char table[SECNO][PERIODS][DAYS][SLOTLENGTH];
};