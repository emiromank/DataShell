/**
 * @file functions.c
 * @author Jose Pablo Montero, Irving Vega, Emilio Roman
 * @date 27/09/2021
 */

#include "../libs/def.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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
    printf("SELECCIONA UNA OPCION:\n\n\t\t[r]Read Table\n\t\t[p]Print Table\n\t\t[a]Alter table\n\t\t[g]Save Table\n\n\t\t[s]Exit\n\nOpcion: ");
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

    fp = fopen(file, "r");

    if(fp == NULL){
        printf("File not found");
        exit(1);
    }
    
    while(fscanf(fp," %[^,]",dato)==1)
    {
      contadorf++;
      printf("%s\n\n", dato);
        
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

void printTable2(param table)
{
	float tablita[table.columna][table.fila];
  int i,j;
  char juan;
  for(i = 0; i < table.columna; i++)
  {
    for(j = 0; j<table.fila; j++)
    {
    printf("%f", tablita[i][j]);
    }
  }
  scanf(" %c", &juan);
  return;

}

//___________________________________________________________________________//



void printTable(param table)
{

int i,j;
char juan;

tabla = (struct element *)malloc(sizeof(struct element) * table.columna);


  printf("\tAncho %d\n", table.fila);
  printf("\tLargo %d\n", table.columna);


for (i = 0; i < table.fila; i++) 
{
  for(j = 0; j < table.columna; j++)
  {
  tabla[i].number1[j] = 44;
  }
}


for (i = 0; i < table.fila; i++) 
{
  
  for(j = 0; j < table.columna; j++)
  {
    
    printf("|\t%.2f\t|",tabla[i].number1[j]);
  }
printf("\n------------------------------------------\n");

}

	    scanf(" %c", &juan);

}


//___________________________________________________________________________//
