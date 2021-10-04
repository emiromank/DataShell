/**
 * @file functions.c
 * @authors: Jose Pablo Montero
 *					Irving Alejandro Vega Lagunas
 *					Emilio Roman
 * @date 27/09/2021
 */


#include "../libs/def.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//___________________________________________________________________________//
//------------------------------TAMAÑO DE TABLA------------------------------//
//___________________________________________________________________________//


struct dimensions
{
    int column;
    int row;
}; 


//___________________________________________________________________________//
//-----------------------------DATOS DE LA TABLA-----------------------------//
//___________________________________________________________________________//


struct table
{
	 float values;
};


//___________________________________________________________________________//
//------------------------LIMPIA EL BUFFER DE MEMORIA------------------------//
//___________________________________________________________________________//


extern void cleanBuffer(void)
  {
    int clean;

        while((clean = getchar()) != '\n' && clean != EOF) { }

    return;
  }


//___________________________________________________________________________//
//-----------------------CREA UNA PAUSA EN EL PROGRAMA-----------------------//
//___________________________________________________________________________//


extern void pause(void)
{
  cleanBuffer();
  printf("\n\nPresiona la tecla ENTER para continuar\n\n");
  getchar();
}


//___________________________________________________________________________//
//------------------------------MENU DE PROGRAMA-----------------------------//
//___________________________________________________________________________//


char mainMenu(void)
{
  char mainMenuOption;

    system("clear");
    printf("SELECCIONA UNA OPCION:\n\n\t\t[r]Read Table\n\t\t[p]Print Table\n\t\t[a]Alter table\n\t\t[s]Save Table\n\n\t\t[e]Exit\n\nOpcion: ");
    scanf(" %c", &mainMenuOption);

  return mainMenuOption;
}


//___________________________________________________________________________//
//----------------------LEE ARCHIVO CSV Y GUARDA TAMAÑO----------------------//
//___________________________________________________________________________//


sizeData readTable(void)
{
    FILE *fp;
    char row[512];
    int rowNum = 0, columnNum = 0, i;
    sizeData sizeOfTable;

    fp = fopen("table_data.db", "r");

    if(fp == NULL){
        printf("File not found");
        exit(1);
    }
    
    while(fscanf(fp," %[^\n]",row)==1)
    {
      rowNum++;
    }
    
  for(i = 0; i < strlen(row); i++)
    {
      if(row[i] == ',')
      {
        columnNum++;
      }
    }

	  fclose(fp);
  
    sizeOfTable.column = columnNum+1;
    sizeOfTable.row = rowNum;
	
    
    return sizeOfTable;
}


//___________________________________________________________________________//
//---------------------IMPRIME TABLA Y GUARDA EN ARREGLO---------------------//
//___________________________________________________________________________//


tableData printTable(sizeData sizeOfTable,tableData *content, int tableTotalValues)
{
  
  float biDimTable[sizeOfTable.row][sizeOfTable.column];
  int i,j,k;
	int cont=0, cont2 = 0,cont3 = 0;

	FILE *fp;

  fp = fopen("table_data.db", "r");

  if(fp == NULL){
        printf("File not found");
        exit(1);
  }

  printf("EN PRINT filas %d columnas %d\n\n", sizeOfTable.row, sizeOfTable.column);

  for(i = 0; i < sizeOfTable.row; i++)
  {
    for(j = 0; j < sizeOfTable.column; j++)
    {
      while(fscanf(fp,"%f,", &biDimTable[i][j])==0)
			{
        k++;
				if(k == sizeOfTable.column)break;
			}
      printf("|%f\t|", biDimTable[i][j]);
			content[cont].values = biDimTable[i][j];
			cont++;
      k = 0;
    }
    printf("\n");
  }

  return *content;

}


//___________________________________________________________________________//
//---------------------------PERMITE EDITAR TABLA----------------------------//
//___________________________________________________________________________//


void alterTable(sizeData sizeOfTable, tableData *content, int tableTotalValues)
{
  int i, cont2=0;
	
  printf("Table:\n");

 	for(i = 0; i < tableTotalValues; i++ )
	{
		cont2++;
		printf("|%f\t|", content[i].values);
	  if(cont2 == sizeOfTable.column)
	  {
    	printf("\n");
	  	cont2=0;
	  }
	}

  return;
}


//___________________________________________________________________________//
//---------------------GUARDA DATOS DE TABLA EN ARCHIVO----------------------//
//___________________________________________________________________________//


//FORMULA: sizeOfTable.columna*(y-1)+x
