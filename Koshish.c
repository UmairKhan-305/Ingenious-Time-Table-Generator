#include<stdio.h>

struct TimeTables
{
    char courceCode[7][8];
    char subjectName[7][50];
    char teachers[7][6][20];
} timeTable;


int main()
{
    FILE *fp; // declaration of file pointer
    char con[1000]; // variable to read the content
    int i  = 0;
    fp = fopen("Teachers and Subjects.txt","r");// opening of file
    
    if (!fp) { // checking for error
        printf("File could not be read.");
        return 101; // file not found error
    }

    while(!feof(fp)) {
      fscanf(fp, "%[^\t]\t%[^\t]\t%[^\t]\t", timeTable.courceCode[i], timeTable.subjectName[i], timeTable.teachers[i][0]);
      fscanf(fp, "%[^\t]\t",timeTable.teachers[i][1]);
      fscanf(fp, "%[^\t]\t",timeTable.teachers[i][2]);
      fscanf(fp, "%[^\t]\t",timeTable.teachers[i][3]);
      fscanf(fp, "%[^\t]\t",timeTable.teachers[i][4]);
      fscanf(fp, "%[^\t]\t",timeTable.teachers[i][5]);
      fscanf(fp, "%[^\n]\n",timeTable.teachers[i][6]);
      i++;
    //   printf( "%s\t%s\t%s\n",                    string1, string2, string3 );
    }

    // printf("%s", timeTable.courceCode[1]);
    // printf("%s", timeTable.subjectName[1]);
    // printf("%s", timeTable.teachers[0][1]);

    for(int j=0; j<i; j++) {
        printf("%s\t%s\t", timeTable.courceCode[i], timeTable.subjectName[i]);
        for(int k=0; k<7; k++) {
            printf("%s\t", timeTable.teachers[i][k]);
        }printf("%s", timeTable.courceCode[1]);
        printf("\n");
    }

    // while (fgets(con,1000, fp)!=NULL) { // reading file content
    //     printf("%s",con);
    // }
    fclose(fp); // closing file
    return 0;
}