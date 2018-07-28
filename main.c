#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "Parser.h"

int getInt(char mensaje[], int enteroIngresado, int maximo, int minimo);
void getString(char mensaje[],char input[]);
int getStringLetras(char mensaje[],char input[]);
int esSoloLetras(char str[]);
int menu();

/*ArrayList* nuevaCadena(ArrayList*this);*/

int main()
{
    ArrayList* letras;
    ArrayList* depurado;
    ArrayList* repetidos;

    letras=al_newArrayList();
    repetidos=al_newArrayList();
    depurado = al_newArrayList();
    int opcion;
    char respuesta='s';
    int opcion1=0;


    while(respuesta=='s')
    {
    opcion=menu();

    switch(opcion)
    {
    case 1:
        printf("\n---Lista de Letras---\n");
        parserRead(letras);
        printf("Archivo Caragado Correctamente");

        printf("\n\n---Presione una tecla para salir---\n");
        system("pause > nul");
        break;

   case 2:
        printf("\n---Lista de Letras---\n");
        printAll(letras);
        printf("\n\n---Presione una tecla para salir---\n");
        system("pause > nul");
        break;

    case 4:
        printf("1)Ordenar repetidos orden descendente\n");
        printf("2)Ordenar sin repeticion orden ascendente\n");
        printf("INDIQUE OPCION: ");
        scanf("%d",&opcion1);
            switch(opcion1)
            {
            case 1:
                repetidos=al_clone(letras);
                buscarLetraRepetida(letras,repetidos,depurado);
                repetidos->sort(repetidos,comparaLetras,0);
                printf("\nletras repetidas\n");
                printAll(repetidos);
                system("pause");
                break;
            /*case 2:*/
               /* clonada= letras->clone(letras);
                clonada->sort(clonada,ordenar,0);
                printAll(clonada);
                system("pause");
                break;*/
            }
    default:
    break;
    }
        system("cls");
    }//cierre while

    return 0;
}


int getInt(char mensaje[], int enteroIngresado, int maximo, int minimo)
{
    do
    {
        printf("%s",mensaje);
        scanf("%d",&enteroIngresado);
    }
    while(enteroIngresado>maximo||enteroIngresado<minimo);
    return enteroIngresado;
}


int menu()
{
    int opcion;
    printf("\n1-Carga de Archivo\n");
    printf("\n2-Completar\n");
    printf("\n3-Comprobar\n");
    printf("\n4-Listar");
    printf("\nIngrese una opcion: ");
    scanf("%d",&opcion);

    return opcion;
}

void getString(char mensaje[],char input[])
{
    printf("%s",mensaje);
    fflush(stdin);
    gets(input);
}

int getStringLetras(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esSoloLetras(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

int esSoloLetras(char str[])
{
    int i=0;
    while(str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
            return 0;
        i++;
    }
    return 1;
}
