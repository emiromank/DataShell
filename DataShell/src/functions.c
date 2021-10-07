
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
//----------------------------DATOS DE LOS TITULOS---------------------------//
//___________________________________________________________________________//

struct tableHeader
{
	 char title[20];
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

//    system("clear");
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
    sizeOfTable.row = rowNum-1;
	
    
    return sizeOfTable;
}

//___________________________________________________________________________//
//----------------------LEE ARCHIVO CSV Y GUARDA TAMAÑO----------------------//
//___________________________________________________________________________//

void readTitle(header *title,sizeData sizeOfTable)
{
  FILE *fp;
  char buffer[512],juan;
	char palabra[sizeOfTable.column][512];
  int rowNum = 0, columnNum = 0, i = 0, j=0,k=0;


  fp = fopen("table_data.db", "r");

  if(fp == NULL){
    printf("File not found");
    exit(1);
  }

  fscanf(fp," %[^\n]", buffer);


  for(i = 0; i <strlen(buffer);i++)
  {
	  if(buffer[i] != ',')
	  {
		  palabra[j][k] = buffer[i];
		  k++;
	  }
	  if (buffer[i] == ',')
    {
	    k=0;
      j++;
    }
 }

 for(i = 0; i <sizeOfTable.column;i++)
  {
    strcpy(title[i].title, palabra[i]);
  }

  fclose(fp);
  
return ;
}

//___________________________________________________________________________//
//---------------------IMPRIME TABLA Y GUARDA EN ARREGLO---------------------//
//___________________________________________________________________________//

tableData printTable(header *title,sizeData sizeOfTable,tableData *content, int tableTotalValues)
{
  char buffer[512];
  float biDimTable[sizeOfTable.row][sizeOfTable.column];
  int i=0,j,k;
	int cont=1, cont2 = 0,cont3 = 0;

	FILE *fp;
	FILE *fp1;
	FILE *fp2;
	  fp1 = fopen("table_data.db", "r");
	  fp2 = fopen("table_data2.db", "w");
		  if(fp1 == NULL)
			{
        printf("File not found");
        exit(1);
 			}
			     while(fscanf(fp1," %[^\n]",buffer)==1)
					{
						if(i!=0)
						{
						fprintf(fp2,"%s\n",buffer);
						}
						i++;
					}
  fclose(fp1);
  fclose(fp2);

  fp = fopen("table_data2.db", "r");



  printf("EN PRINT filas %d columnas %d\n\n", sizeOfTable.row, sizeOfTable.column);

		for(i=0;i<sizeOfTable.column;i++)
  {
		printf("|\t%s\t|",title[i].title);
  }	
	    printf("\n");



  for(i = 0; i < sizeOfTable.row; i++)
  {
    for(j = 0; j < sizeOfTable.column; j++)
    {
      while(fscanf(fp,"%f,", &biDimTable[i][j])==0)
			{
        k++;
				if(k == sizeOfTable.column)break;
			}
      printf("|\t%f\t|", biDimTable[i][j]);
			content[cont].values = biDimTable[i][j];
			cont++;
      k = 0;
    }
    printf("\n");
  }

	  fclose(fp);

  return *content;

}

//___________________________________________________________________________//
//---------------------------PERMITE EDITAR TABLA----------------------------//
//___________________________________________________________________________//

int alterTable(sizeData sizeOfTable, tableData *content, int tableTotalValues)
{
  int i, cont2=0,j, pointer = 1,edit=0;
	int x,y, celda=0;
  char tecla;

do
{
  printf("\nUtiliza [w] [a] [s]	[d] para desplazarte por la tabla:\nPresione [e] para editar el valor de la celda:\nPresione [f] busqueda de celda por cordenada:\nPresione [n] para agregar nueva fila:\n\nPresione [q] para salir:\n\n");
  
 	for(i = 1; i < tableTotalValues + (edit*sizeOfTable.column); i++ )
	{
		cont2++;
		if(i < tableTotalValues)
		{
		printf("|%f\t|", content[i].values);
		}
		if(i > tableTotalValues-1)
	  {
    	printf("|0.000000\t|");
	  }

	  if(cont2 == sizeOfTable.column)
	  {
    	printf("\n");
	  	cont2=0;
	  }
	}

			printf("edit %d", edit);

    printf("\nValor de la celda actual: %f \t:", content[pointer].values);
    scanf(" %c", &tecla);

  switch(tecla) 
  {
    case 'w': 

      printf("\nUp row");
			pointer = pointer - sizeOfTable.column;
      printf("\nValor de %d celda actual: %f",pointer, content[pointer].values);
      system("clear");

    break;

    case 'a': 

      printf("\nLeft column ");
      pointer = pointer-1;
      printf("\nValor de %d celda actual: %f",pointer, content[pointer-1].values);
      system("clear");

    break;

    case 's': 

      printf("\nDown row");
			pointer = pointer + sizeOfTable.column;
      printf("\nValor de %d celda actual: %f",pointer, content[pointer].values);
      system("clear");

    break;

    case 'd': 

      printf("\nRight column");
			pointer=pointer+1;
      printf("\nValor de %d celda actual: %f",pointer, content[pointer].values);
      system("clear");

    break;

    case 'e': 

      printf("\nEdit cell");		  
      printf("\nValor de %d celda actual: %f",pointer, content[pointer].values);
      printf("\nIngrese el nuevo valor para esta celda: ");
      scanf(" %f", &content[pointer].values);
      printf("\nNuevo valor de %d celda actual: %f",pointer, content[pointer].values);
      system("clear");

    break;

    case 'f': 

      printf("\nFind cell");
      printf("\nIngrese el valor de [x & y]: ");
      scanf(" %d %d", &x, &y);
      pointer = sizeOfTable.column*(y-1)+x;
      printf("\nValor de %d celda actual: %f",pointer, content[pointer].values);
      system("clear");

    break;

    case 'n': 

      printf("\nNew row ");
			printf("\nIngrese cuantas filas desea agregar: ");
      scanf(" %d", &edit);
      system("clear");

    break;

    case 'q':

    system("clear");
    printf("Saliendo...\n\n");

      break;

    default: 
      printf("\nInvalid value");
      break;
  }
    
}while(tecla != 'q');

  return edit;
}
//FORMULA: sizeOfTable.column*(y-1)+x

//___________________________________________________________________________//
//---------------------GUARDA DATOS DE TABLA EN ARCHIVO----------------------//
//___________________________________________________________________________//
void saveTable(header *title,sizeData sizeOfTable, tableData *content, int tableTotalValues, int overwrite)
{
  int i, cont2=0,cont=0;

	FILE *fp;

	fp = fopen("table_data.db", "w");

    if(fp == NULL){
        printf("File not found");
        exit(1);
    }

		for(i=0;i<sizeOfTable.column;i++)
  {
		  if(i == sizeOfTable.column-1)
      {
				printf("|\t%s\t|",title[i].title);
				fprintf(fp,"%s\n", title[i].title);
			}
      else if(i != sizeOfTable.column-1)
      {
				printf("|\t%s\t|",title[i].title);
				fprintf(fp,"%s,", title[i].title);
			}
		cont++;
  }	
	    printf("\n");



 	for(i = 1; i < tableTotalValues + (overwrite*sizeOfTable.column); i++ )
	{
		cont2++;
  
    if(i < tableTotalValues)
	  {
      if(cont2 == sizeOfTable.column)
      {
      	printf("|%f\t|", content[i].values);
        fprintf(fp,"%f", content[i].values);
      }
      else if(cont2 != sizeOfTable.column)
      {
  		printf("|%f\t|", content[i].values);
      fprintf(fp,"%f,", content[i].values);      
      }
	  }

		if(i > tableTotalValues-1)
	  {
      if(cont2 == sizeOfTable.column)
      {
    	printf("|0.000000\t|");
      fprintf(fp,"0.000000");
      }
      else if(cont2 != sizeOfTable.column)
      {
        printf("|0.000000\t|");
        fprintf(fp,"0.000000,");
      }
    }

	  if(cont2 == sizeOfTable.column)
	  {
    	printf("\n");
      fprintf(fp,"\n");
	  	cont2=0;
	  }
	}

fclose(fp);

  return;
}



