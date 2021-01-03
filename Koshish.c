#include<stdio.h>
#define SIZE 500

struct TimeTables
{
    char courseCode[7][8];
    char subjectName[7][50];
    char teachers[7][6][20];
} timeTable;


int main()
{
    char line[SIZE];

    FILE *infile;
    char *inname = "Teachers and Subjects.txt";

    int i = 0;

    infile = fopen(inname, "r");
    if (!infile) {
        printf("Couldn't open %s for reading\n");
        return 0;
    }
    while(fgets(line, sizeof(line), infile) != NULL) {
        sscanf(line, "%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\n]", 
        timeTable.courseCode[i], timeTable.subjectName[i], timeTable.teachers[i][0], timeTable.teachers[i][1], timeTable.teachers[i][2], timeTable.teachers[i][3], timeTable.teachers[i][4], timeTable.teachers[i][5], timeTable.teachers[i][6]);
        printf("%s\n", timeTable.courseCode[i]);
        printf("%s\n", timeTable.subjectName[i]);
        printf("%s\n", timeTable.teachers[i][0]);
        i++; 
    }
}