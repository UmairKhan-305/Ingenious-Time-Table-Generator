#include <conio.h>
#include "crud.h"
#include "generator.h"

void create (T *, C *);
void read (T, C,int);
void update (T);
void generator (G *, T, C, int);
void displayTable (G);
void garbageCollector (G *);
void cleanIsTaken ();

int main () {
    T timeTable;
    G generatedTable;
    C classes;
    char cont;
    int choice;
    
    create(&timeTable, &classes);
    system("cls");
    printf("\nFile processing successful...\n");

    do
    {
        printf("\n1. View allocations\n");
        printf("2. View class rooms\n");
        printf("3. Update allocations\n");
        printf("4. Generate time table\n");
        printf("0. Exit program\n");
        printf("\nPlease enter your choice: ");
        scanf(" %d", &choice);

        switch (choice)
        {
            case 0:
                printf("\nExiting program gracefully...\n");
                break;
            case 1:
            case 2:
                read(timeTable, classes, choice);
                break;

            case 3:
                update(timeTable);
                break;

            case 4:
                srand(time(0));
                garbageCollector(&generatedTable);
                generator(&generatedTable, timeTable, classes, 0);
                displayTable(generatedTable);
                printf("\nTime Table generated...");
                printf("\nView timetable (Y/N)? ");
                cont = getche();
                if (cont == 'y' || cont == 'Y') system("notepad '.\\Time Table.txt'");
                cleanIsTaken();
                break;
            
            default:
                printf("\nInvalid choice please verify again...\n");
                break;
        }
    } while (choice != 0);
}