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
    char mainMenuOption;
		int tableTotalValues,i, overwrite;
    sizeData sizeOfTable;
    

    sizeOfTable = readTable();
    header title[sizeOfTable.row];
		readTitle(title,sizeOfTable);
		tableTotalValues = (sizeOfTable.row * sizeOfTable.column)+1;
		tableData content[tableTotalValues];
	
	/*for(i=0;i<sizeOfTable.column;i++)
  {
		printf("hola %s\n",title[i].title);
  }
	*/	


  while(mainMenuOption != 'e')
  {
    mainMenuOption = mainMenu();


      switch (mainMenuOption)
      {
      case 'r':
          system("clear");
          printf("Cantidad de columnas dentro del archivo = %d\nCantidad de Filas en el archivo = %d\n\n", sizeOfTable.column, sizeOfTable.row);
          pause();
          break;

      case 'p':
          system("clear");
          *content = printTable(title,sizeOfTable,content, tableTotalValues);
          pause();
          break;

      case 'a':
          system("clear");
          overwrite = alterTable(sizeOfTable,content,tableTotalValues);
          pause();
          break;
      case 's':
          saveTable(title, sizeOfTable,content,tableTotalValues,overwrite);
          pause();
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