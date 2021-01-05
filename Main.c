#include <stdlib.h>
#include <time.h>
#include "crud.h"
#include "generator.h"

int main () {
    T timeTable;
    G generatedTable;
    
    create(&timeTable);

    read(timeTable);

    update(timeTable);

    srand(time(0));
    generator(&generatedTable, timeTable, 0);
    displayTable(generatedTable);
}