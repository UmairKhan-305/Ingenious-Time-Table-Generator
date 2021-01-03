#include<stdio.h>
#include <stdlib.h>
#include <time.h>

#define PERIODS 8
#define SIZE 500
<<<<<<< HEAD
#define RANDOM() ({int randInt = rand() % PERIODS; randInt;})
=======
#define SECNO 7
>>>>>>> 044ef6c70015ba8402fbd08034487e7cef0c91a6

struct TimeTables {
    char courseCode[7][8];
    char subjectName[7][50];
    char teachers[7][SECNO][20];
} timeTable;

int main()
{
    char line[SIZE];
<<<<<<< HEAD
    int i = 0, randInt;
=======
    char sec[SECNO] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
>>>>>>> 044ef6c70015ba8402fbd08034487e7cef0c91a6

    FILE *infile;
    char *inname = "Teachers and Subjects.txt";

    srand(time(0));

    infile = fopen(inname, "r");
    if (!infile) {
        printf("Couldn't open %s for reading\n");
        return 0;
    }

    printf("Semester Details:\n");

    while(fgets(line, sizeof(line), infile) != NULL) {
        sscanf(line, "%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\n]", 
        timeTable.courseCode[i], timeTable.subjectName[i], timeTable.teachers[i][0], timeTable.teachers[i][1], timeTable.teachers[i][2], timeTable.teachers[i][3], timeTable.teachers[i][4], timeTable.teachers[i][5], timeTable.teachers[i][6]);
        
        printf("\n");
        printf("%s\t | ", timeTable.courseCode[i]);
        printf("%s\t | ", timeTable.subjectName[i]);
        
        for(int j = 0; j < SECNO; j++){
            printf("%c. %s | ", sec[j], timeTable.teachers[i][j]);
        }

        printf("\n");
        printf("__________________________________________________________\n");

        i++; 
    }

    randInt = RANDOM();
}