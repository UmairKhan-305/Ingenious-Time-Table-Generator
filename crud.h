#include <stdio.h>
#include "declaration.h"

char sec[SECNO] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
char flag = 'N', flag1 = 'N';
int k, l, check;

void create(T *timeTable, C *classRooms) {
    char line[SIZE];
    int i = 0;

    FILE *infile;
    char *inname = "Teachers and Subjects.txt";

    infile = fopen(inname, "r");
    if (!infile) {
        printf("Couldn't open %s for reading\n", inname);
        exit(1);
    }

    while(fgets(line, sizeof(line), infile) != NULL) {
        sscanf(line, "%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\n]", 
        timeTable->courseCode[i], timeTable->subjectName[i], timeTable->teachers[i][0], timeTable->teachers[i][1], timeTable->teachers[i][2], timeTable->teachers[i][3], timeTable->teachers[i][4], timeTable->teachers[i][5], timeTable->teachers[i][6]);

        i++; 
    }
    fclose(infile);

    inname = "ClassRooms.txt";
    infile = fopen(inname, "r");
    if (!infile) {
        printf("Couldn't open %s for reading\n", inname);
        exit(1);
    }

    i = 0;
    while(fgets(line, sizeof(line), infile) != NULL) {
        sscanf(line, "%[^\n]", classRooms->class[i]);
        
        i++;
    }
    fclose(infile);
}

void read(T timeTable, C classRooms) {
    printf("Semester Details:\n");
    for(int i = 0; i < COURSE; i++) {
        printf("\n");
        printf("%s\t | ", timeTable.courseCode[i]);
        printf("%s\t | ", timeTable.subjectName[i]);
        
        for(int j = 0; j < SECNO; j++){
            printf("%c. %s |\t", sec[j], timeTable.teachers[i][j]);
        }

        printf("\n");
        printf("__________________________________________________________\n");
    }

    printf("Class Rooms: (Room) | (Campus) \n");
    for (int i = 0; i < ROOMS; i++)
    {
        printf("%s\n", classRooms.class[i]);
    }
}

void update(T timeTable){
    printf("Do you wish to change Instructors? (Y/N): ");
        scanf(" %c", &flag);

    switch (flag)
    {
    case 'Y':
    case 'y':

        do{
            printf("Select section you wish to make changes for: \n");
        
            for(int i = 0; i < SECNO; i++){
                printf("%i. %c | ", i+1, sec[i]);
            }

            printf("\n");
                scanf(" %i", &k);

            printf("Select subject: \n");
            
            for(int i = 0; i < PERIODS; i++){
                printf("%i. %s\n", i+1, timeTable.subjectName[i]);
            }

            printf("\n");
                scanf(" %i", &l);

            printf("Current Instructor: %s\n", timeTable.teachers[l-1][k-1]);
            printf("Enter substitute Instructor: ");
                scanf(" %s", timeTable.teachers[l-1][k-1]);
            printf("Instructor has been successfully updated.\n");
            printf("Updated Instructor: %s\n", timeTable.teachers[l-1][k-1]);

            printf("Anymore changes? (Y/N): ");
                scanf(" %c", &flag1);

        }while(flag1 == 'y' || flag1 == 'Y');       

        FILE * infile;
        char *inname = "Teachers and Subjects.txt";
        
        infile = fopen(inname, "w");

        for(int i = 0; i < COURSE; i++){
            fprintf(infile, "%s\t%s\t", timeTable.courseCode[i], timeTable.subjectName[i]);

            for(int j = 0; j < SECNO; j++){
                fprintf(infile, "%s\t", timeTable.teachers[i][j]);
            }

            fprintf(infile, "\t\n");
        }
        break;
    
    default:
        break;
    }
}