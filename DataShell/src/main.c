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
    char file[40];
    param table;
	
  while(opcionMenu != 's')
  {
    opcionMenu = menu();

      switch (opcionMenu)
      {
      case 'r':
          system("clear");
         // printf("Ingresa el nombre del archivo que deseas leer: ");
         // scanf(" %[^\n]", file);
          table = readTable(file);
          break;

      case 'p':
          system("clear");
          printTable(table);
          break;

      case 'a':
          printf(":)");
          break;


      case 's':
          system("clear");
          printf("Hasta pronto! (._.)/");
          break;
      
      default:
          printf("Opcion invalida...\n\n");
          break;
      }
  }
    return 0;
}