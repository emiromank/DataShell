#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct parameters param;
typedef struct tabla data;

void limpiarEntradaDatos(void);
param readTable(char file[]);
char menu(void);
void printTable(param table);
//int alterTable(nodo *pt);
//void saveTable(nodo *pt);