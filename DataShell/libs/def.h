#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct dimensions sizeData;
typedef struct table tableData;
typedef struct tableHeader header;

void cleanBuffer(void);
void pause(void);
sizeData readTable(void);
void readTitle(header *title,sizeData sizeOfTable);
char mainMenu(void);
tableData printTable(header *title,sizeData sizeOfTable, tableData *content, int tableTotalValues);
int alterTable(sizeData sizeOfTable, tableData *content, int tableTotalValues);
void saveTable(header *title, sizeData sizeOfTable, tableData *content, int tableTotalValues, int overwrite);