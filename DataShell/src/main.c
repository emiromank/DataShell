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
	
  while(opcionMenu != 'e')
  {
    opcionMenu = menu();

      switch (opcionMenu)
      {
      case 'r':
          system("clear");
         // printf("Ingresa el nombre del archivo que deseas leer: ");
         // scanf(" %[^\n]", file);
          table = readTable(file);
          limpiarEntradaDatos();
          printf("\n\nPresiona la tecla ENTER para continuar\n\n");
          getchar();
          break;

      case 'p':
          system("clear");
          printTable(table);
          limpiarEntradaDatos();
          printf("\nPresiona la tecla ENTER para continuar");
          getchar();
          break;

      case 'a':
          system("clear");
          printf(":)\n\n");
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