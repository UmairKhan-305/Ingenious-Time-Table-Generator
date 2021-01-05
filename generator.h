#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "declaration.h"

#define RANDOM(num) ({int randInt = rand() % num; randInt;})

int IsTaken[ROOMS][PERIODS][DAYS] = {0};
int rand_period, rand_room, rand_day;
char content[SLOTLENGTH];

void generator (G *, T, int);
void displayTable (G);

void generator(G *generatedTable, T timeTable, int sec) {
    srand(time(0));
    if (sec == SECNO) {
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
                memset(content, '\0', SLOTLENGTH);
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
                strcpy(generatedTable->table[sec][rand_period+1][rand_day], content);
                IsTaken[rand_room][rand_period][rand_day] = 1;
                IsTaken[rand_room][rand_period+1][rand_day] = 1;
            }
            
        }
        generator(generatedTable, timeTable, sec+1);
    }
    
}

void displayTable(G table) {
    FILE *infile;
    char *inname = "Time Table.txt";
    
    infile = fopen(inname, "w");

    for (int i = 0; i < SECNO; i++) {
        fprintf(infile, "Section: %d\n", i);
        printf("---------------------------------\n");
        for (int j = 0; j < DAYS; j++) {
            fprintf(infile, "Day: %d\n", j);
            fprintf(infile, "---------------------------------\n");
            for (int k = 0; k < PERIODS; k++) {
                // printf("Day: %d\n", k);
                // printf("------------------------------------\n");
                fprintf(infile, "%s\n", table.table[i][k][j]);
                // fprintf(infile, "\n");
            }
        }
    }
    fclose(infile);
}