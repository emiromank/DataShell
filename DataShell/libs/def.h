#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct parameters param;
typedef struct tabla datos;

void limpiarEntradaDatos(void);
void pause(void);
param readTable(void);
char menu(void);
datos printTable(param table, datos *tabla, int suma);
void alterTable(param table, datos *tabla, int suma);
//void saveTable(nodo *pt);