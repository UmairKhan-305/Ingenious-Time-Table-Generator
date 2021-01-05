#include <string.h>
#include <time.h>
#include "declaration.h"

#define RANDOM(num) ({int randInt = rand() % num; randInt;})

int IsTaken[ROOMS][PERIODS][DAYS] = {0};
int rand_period, rand_room, rand_day;
char content[SLOTLENGTH];

void generator(G *generatedTable, T timeTable, C classRooms, int sec) {
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
                strcat(content, "; ");
                strcat(content, timeTable.subjectName[i]);
                strcat(content, "; ");
                strcat(content, timeTable.teachers[i][sec]);

                for(int j = 0; j < sec; j++) {
                    if(!strcmp(content, generatedTable->table[j][rand_period][rand_day])) goto again;
                }

                strcat(content, "; ");
                strcat(content, classRooms.class[rand_room]);
                strcpy(generatedTable->table[sec][rand_period][rand_day], content);
                strcpy(generatedTable->table[sec][rand_period+1][rand_day], content);
                IsTaken[rand_room][rand_period][rand_day] = 1;
                IsTaken[rand_room][rand_period+1][rand_day] = 1;
            }
            
        }
        generator(generatedTable, timeTable, classRooms, sec+1);
    }
}

void displayTable(G table) {
    FILE *infile;
    char *inname = "Time Table.txt";
    
    infile = fopen(inname, "w");

    for (int i = 0; i < SECNO; i++) {
        fprintf(infile, "\nSection: %d\n", i);
        fprintf(infile, "---------------------------------\n");
        for (int j = 0; j < DAYS; j++) {
            fprintf(infile, "\nDay: %d\n", j);
            fprintf(infile, "---------------------------------\n");
            for (int k = 0; k < PERIODS; k++) {
                fprintf(infile, "Slot: %d\t|\t%s\n", k, table.table[i][k][j]);
            }
        }
    }
    fclose(infile);
}