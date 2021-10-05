#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct dimensions sizeData;
typedef struct table tableData;

void cleanBuffer(void);
void pause(void);
sizeData readTable(void);
char mainMenu(void);
tableData printTable(sizeData sizeOfTable, tableData *content, int tableTotalValues);
int alterTable(sizeData sizeOfTable, tableData *content, int tableTotalValues);
void saveTable(sizeData sizeOfTable, tableData *content, int tableTotalValues, int overwrite);