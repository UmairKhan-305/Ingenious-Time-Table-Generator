#include <conio.h>
#include "crud.h"
#include "generator.h"

void create (T *, C *);
void read (T, C);
void update (T);
void generator (G *, T, C, int);
void displayTable (G);
void garbageCollector (G *);

int main () {
    T timeTable;
    G generatedTable;
    C classes;
    char cont;
    // char classRooms[ROOMS][14] = {0};
    
    create(&timeTable, &classes);

    read(timeTable, classes);

    update(timeTable);

    printf("Generate Time Table? ");
    cont = getche();
       
    if(cont != 'y' || cont != 'Y') {
        garbageCollector(&generatedTable);
        generator(&generatedTable, timeTable, classes, 0);
        displayTable(generatedTable);
        printf("\nTime Table generated\n");
    }
}