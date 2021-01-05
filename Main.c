#include "crud.h"
#include "generator.h"

int main () {
    T timeTable;
    G generatedTable;
    
    create(&timeTable);

    read(timeTable);

    update(timeTable);

    generator(&generatedTable, timeTable, 0);
    displayTable(generatedTable);
}