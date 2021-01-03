#include <stdlib.h>
#include <time.h>
#include "declaration.h"

void create(T *timeTable) {
    char line[SIZE];
    int i = 0;

    FILE *infile;
    char *inname = "Teachers and Subjects.txt";

    srand(time(0));

    infile = fopen(inname, "r");
    if (!infile) {
        printf("Couldn't open %s for reading\n");
        exit(1);
    }

    printf("Semester Details:\n");

    while(fgets(line, sizeof(line), infile) != NULL) {
        sscanf(line, "%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\n]", 
        timeTable->courseCode[i], timeTable->subjectName[i], timeTable->teachers[i][0], timeTable->teachers[i][1], timeTable->teachers[i][2], timeTable->teachers[i][3], timeTable->teachers[i][4], timeTable->teachers[i][5], timeTable->teachers[i][6]);

        i++; 
    }
}

void read(T timeTable) {
    char sec[SECNO] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};

    for(int i = 0; i < 8; i++) {
        printf("\n");
        printf("%s\t | ", timeTable.courseCode[i]);
        printf("%s\t | ", timeTable.subjectName[i]);
        
        for(int j = 0; j < SECNO; j++){
            printf("%c. %s | ", sec[j], timeTable.teachers[i][j]);
        }

        printf("\n");
        printf("__________________________________________________________\n");
    }
}