#include<stdio.h>
#include <stdlib.h>
#include <time.h>

#define PERIODS 8
#define SIZE 500
#define RANDOM() ({int randInt = rand() % PERIODS; randInt;})
#define SECNO 7

struct TimeTables {
    char courseCode[9][8];
    char subjectName[8][50];
    char teachers[7][SECNO][20];
} timeTable;

int main()
{
    char line[SIZE];
    int i = 0, randInt;
    char sec[SECNO] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};

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
            printf("%c. %s |\t", sec[j], timeTable.teachers[i][j]);
        }

        printf("\n");
        printf("__________________________________________________________\n");

        i++; 
    }

    randInt = RANDOM();

    char flag = 'N';
    int k, l;

    printf("Do you wish to change Instructors? (Y/N): ");
        scanf(" %c", &flag);

    switch (flag)
    {
    case 'Y':
    case 'y':

        printf("Select section you wish to make changes for: \n");
        
        for(i = 0; i < SECNO; i++){
            printf("~%i. %c | ", i+1, sec[i]);
        }

        printf("\n");
            scanf(" %i", &k);

        printf("Select subject: \n");
        
        for(i = 0; i < PERIODS; i++){
            printf("%i. %s\n", i+1, timeTable.subjectName[i]);
        }

        printf("\n");
            scanf(" %i", &l);

        printf("Current Instructor: %s\n", timeTable.teachers[l-1][k-1]);
        printf("%s", timeTable.teachers[0][1]);

        break;
    
    default:
        break;
    }
}