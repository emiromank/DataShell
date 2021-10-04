/**
 * @file functions.c
 * @author Jose Pablo Montero, Irving Vega, Emilio Roman
 * @date 27/09/2021
 */

#include "../libs/def.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//
//___________________________________________________________________________//


struct parameters
{
    int columna;
    int fila;
}; 

//___________________________________________________________________________//
struct element 
{
  char columna[50];
  float number1[101];
};

//___________________________________________________________________________//


char menu(void)
{
    char opcionMenu;

    system("clear");
    printf("SELECCIONA UNA OPCION:\n\n\t\t[r]Read Table\n\t\t[p]Print Table\n\t\t[a]Alter table\n\t\t[s]Save Table\n\n\t\t[e]Exit\n\nOpcion: ");
    scanf(" %c", &opcionMenu);

    return opcionMenu;
}


//___________________________________________________________________________//


param readTable(char file[])
{
    FILE *fp;
    char dato[512],juan;
    int contadorf = 0, contadorc = 0, i;
    param table;

    fp = fopen("table_data.db", "r");

    if(fp == NULL){
        printf("File not found");
        exit(1);
    }
    
    while(fscanf(fp," %[^\n]",dato)==1)
    {
      contadorf++;
      //printf("%s\n\n", dato);
    }
    
  for(i = 0; i < strlen(dato); i++)
    {
      if(dato[i] == ',')
      {
        contadorc++;
      }
    }

	  fclose(fp);
  
    table.columna = contadorc+1;
    table.fila = contadorf;
		printf("ContadorColumna = %d\nContadorFila = %d\n\n", table.columna, table.fila);
    printf("\n\nPresiona cualquier letra para continuar");
	  scanf(" %c", &juan);
    

    return table;
}


//___________________________________________________________________________//

void printTable(param table)
{
  float tablita[table.fila][table.columna];
  int i,j,k;
  char juan;
  FILE *fp;

  fp = fopen("table_data.db", "r");

  if(fp == NULL){
        printf("File not found");
        exit(1);
  }

  printf("EN PRINT filas %d columnas %d\n\n", table.fila, table.columna);

  for(i = 0; i < table.fila; i++)
  {
    for(j = 0; j < table.columna; j++)
    {
      while(fscanf(fp,"%f,", &tablita[i][j])==0)
			{
        k++;
				if(k == table.columna)break;
			}
      printf("%f\t", tablita[i][j]);
      k = 0;
    }
    printf("\n");
  }

  scanf(" %c", &juan);
  return;

}

//___________________________________________________________________________//

