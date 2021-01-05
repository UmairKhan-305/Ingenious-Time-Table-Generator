#include <string.h>
#include "declaration.h"

#define RANDOM(num) ({int randInt = rand() % num; randInt;})

int IsTaken[ROOMS][PERIODS][DAYS] = {0};
int rand_period, rand_room, rand_day;
char content[80];

void generator (G *, T, int);
void displayTable (G);

void generator(G *generatedTable, T timeTable, int sec) {
    if (sec == SECNO) {
        printf("End\n");
        return;
    }
    else {
        for(int i = 0; i < 8; i++) {
            again:
            rand_period = RANDOM(PERIODS);
            rand_room = RANDOM(ROOMS);
            rand_day = RANDOM(DAYS);
            if (IsTaken[ROOMS][PERIODS][DAYS] || IsTaken[ROOMS][PERIODS+1][DAYS]) goto again;
            else
            {
                strcpy(content, timeTable.courseCode[i]);
                strcat(content, " ");
                strcat(content, timeTable.subjectName[i]);
                strcat(content, " ");
                strcat(content, timeTable.teachers[i][sec]);
                // strcat(content, " ");

                for(int j = 0; j < sec; j++) {
                    if(!strcmp(content, generatedTable->table[j][rand_period][rand_day])) goto again;
                }

                strcpy(generatedTable->table[sec][rand_period][rand_day], content);
                IsTaken[rand_room][rand_period][rand_day] = 1;
            }
            
        }
        generator(generatedTable, timeTable, sec+1);
    }
    
}

void displayTable(G table) {
    for (int i = 0; i < SECNO; i++) {
        for (int j = 0; j < PERIODS; j++) {
            for (int k = 0; k < DAYS; k++) {
                printf(table.table[i][j][k]);
            }
        }
    }
}