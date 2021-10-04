 /**
 * @file main.c
 * @author Jose Pablo Montero, Irving Vega, Emilio Roman
 * @date 27/09/2021
 */

#include "../libs/def.h"
#include "../src/functions.c"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    char opcionMenu;
		int suma,i ;
    param table;

    table = readTable();
		suma = table.fila * table.columna;
		datos tabla[suma];
	
  while(opcionMenu != 'e')
  {
    opcionMenu = menu();


      switch (opcionMenu)
      {
      case 'r':
          system("clear");
          printf("Cantidad de columnas dentro del archivo = %d\nCantidad de Filas en el archivo = %d\n\n", table.columna, table.fila);
          pause();
          break;

      case 'p':
          system("clear");
          *tabla = printTable(table,tabla, suma);
          pause();
          break;

      case 'a':
          system("clear");
          alterTable(table,tabla,suma);
          pause();
          break;
      case 's':
        printf("Jeje buenas\n\n");
        break;

      case 'e':
          system("clear");
          printf("Hasta pronto! (._.)/\n\n");
          break;
      
      default:
          printf("Opcion invalida...\n\n");
          break;
      }
  }
    return 0;
}