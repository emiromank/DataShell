/**
 * @file functions.c
 * @author Jose Pablo Montero, Irving Vega, Emilio Roman
 * @date 27/09/2021
 */

#include "../libs/def.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct parameters
{
    int columna;
    int fila;
}; 

struct tabla{
 float values;
};


extern void limpiarEntradaDatos(void)
  {
    int limpiar;

        while((limpiar = getchar()) != '\n' && limpiar != EOF) { }

        return;
  }

extern void pause(void)
{
  limpiarEntradaDatos();
  printf("\n\nPresiona la tecla ENTER para continuar\n\n");
  getchar();
}

char menu(void)
{
    char opcionMenu;

    system("clear");
    printf("SELECCIONA UNA OPCION:\n\n\t\t[r]Read Table\n\t\t[p]Print Table\n\t\t[a]Alter table\n\t\t[s]Save Table\n\n\t\t[e]Exit\n\nOpcion: ");
    scanf(" %c", &opcionMenu);

    return opcionMenu;
}


//___________________________________________________________________________//


param readTable(void)
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
	
    
    return table;
}


//___________________________________________________________________________//


datos printTable(param table,datos *tabla, int suma)
{
  
  float tablita[table.fila][table.columna];
  int i,j,k;
	int cont=0, cont2 = 0,cont3 = 0;

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
      printf("|%f\t|", tablita[i][j]);
			tabla[cont].values = tablita[i][j];
			cont++;
      k = 0;
    }
    printf("\n");
  }

  return *tabla;

}

//FORMULA: tabla.columna*(y-1)+x

void alterTable(param table, datos *tabla, int suma)
{
  int i, cont2=0;
	
  printf("Aqui inicia\n\n");

 	for(i = 0; i < suma; i++ )
	{
		cont2++;
		printf("|%f\t|", tabla[i].values);
	  if(cont2 == table.columna)
	  {
    	printf("\n");
	  	cont2=0;
	  }
	}

  printf("Aqui termina\n\n");


  return;
}