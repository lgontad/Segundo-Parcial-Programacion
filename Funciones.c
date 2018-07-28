#include "Funciones.h"
#include<stdio.h>

eLetra* constructor()
{
    eLetra* aux;
    aux=(eLetra*)malloc(sizeof(eLetra));
    return aux;
}

void set_letra(eLetra* this, char letra)
{
    this->letra=letra;
}

void set_name(eLetra* this, char name[])
{
    strcpy(this->nombre,name);
}

void set_vocal(eLetra* this, int vocal)
{
    this->vocal=vocal;
}

void set_consonante(eLetra* this, int consonante)
{
    this->consonante=consonante;
}


char get_letra(eLetra* this)
{
    return this->letra;
}

char* get_nombre(eLetra* this)
{
    return this->nombre;
}

int get_vocal(eLetra* this)
{
    return this->vocal;
}

int get_consonante(eLetra* this)
{
    return this->consonante;
}

void printAll(ArrayList* this)
{
   /* int i, len;
    int contador = 0;
    eLetra* g;
    if(lista!=NULL)
    {
        len=lista->len(lista);
        printf("\nLetra\t| Nombre\t| Vocal\t| Consonante\n");
        for(i=0; i<len; i++)
        {
            g=lista->get(lista,i);
            if(let_getEstado(g)!=0)
            {
                printf("\n%c\t| %s\t| %d\t| %d",let_getLetra(g),let_getNombre(g),let_getVocal(g),let_getConsonante(g));
            }
            contador++;
            if(contador == 50 || contador == 100)
            {
                printf("\n");
                system("pause");
            }
        }
        printf("\n");
    }
}*/


    int i;
    int len=this->len(this);
    eLetra* aux;
    printf("\nid\tletra\tNombre\t\t\tvocal\tconsonante\t");
    for(i=0;i<len;i++)
    {


        aux=this->get(this,i);
        if(aux!=NULL)
        {
            printf("\n%d\t",i);
            printOne(aux);
        }
    }

}
void printOne(eLetra* this)
{
    printf("%c\t%s",get_letra(this),get_nombre(this));
    if(strlen(get_nombre(this))<16)
    {
        printf("\t");
    }
    if(strlen(get_nombre(this))<8)
    {
        printf("\t");
    }
    if(get_vocal(this)==0)
    {
        printf("\t0");
    }
    else if(get_vocal(this)==1)
    {
        printf("\t1");
    }

    if(get_consonante(this)==0)
    {
        printf("\t0");
    }
    else if(get_consonante(this)==1)
    {
        printf("\t1");
    }

}

int isVocal(eLetra* this)
{
    int auxReturn=0;
    char letra=get_letra(this);
    if((letra < 'a' || letra > 'z') || (letra < 'A' || letra > 'Z'))
    {
        if(letra=='a'||letra=='e'||letra=='i'||letra=='o'||letra=='u'||letra=='A'||letra=='E'||letra=='I'||letra=='O'||letra=='U')
        {
            auxReturn=1;
        }
    }

    return auxReturn;
}

int isConsonante(eLetra* this)
{
    int auxReturn=0;
    char letra=get_letra(this);

    if((letra < 'a' || letra > 'z') || (letra < 'A' || letra > 'Z'))
    {
        if(letra!='a'&&letra!='e'&&letra!='i'&&letra!='o'&&letra!='u'&&letra!='A'&&letra!='E'&&letra!='I'&&letra!='O'&&letra!='U')
        {
            auxReturn=1;
        }
    }

    return auxReturn;
}

int ordenar(void* letraA,void* letraB)
{
    int returnAux=0;
    if(((eLetra*)letraA)->letra < ((eLetra*)letraB)->letra)
    {
        returnAux=1;
    }
    if(((eLetra*)letraA)->letra > ((eLetra*)letraB)->letra)
    {
        returnAux=-1;
    }
    return returnAux;
}




int mostrarLetras(ArrayList* this)
{
    char letra[5];
    char nombre[21];
    int vocal[2];
    int consonante[2];
    char vocalAux[2], consAux[2];


    int auxVocal,auxConsonante;

    eLetra* aux;
    int leidos;
    if(this!=NULL)
    {
        FILE* pFile;
        pFile=fopen("datos.csv","r");
        if(pFile!=NULL)
        {
            do
            {
                leidos=fscanf(pFile,"%[^,],%[^,],%[^,],%[^,\n]\n",letra,nombre,vocalAux,consAux);

                if(leidos==4)
                {
                    aux=constructor();
                    if(aux!=NULL)
                    {
                        set_letra(aux,letra[0]);
                        set_name(aux,nombre);

                        auxVocal=isVocal(aux);
                        auxConsonante=isConsonante(aux);

                        set_vocal (aux,auxVocal);
                        set_consonante (aux,auxConsonante);
                        this->add(this,aux);
                    }
                }
            }
            while(!feof(pFile));
            printf("\nArchivo leido con exito\n");
            system("cls");
        }
        else
        {
            printf("\nArchivo no encontrado\n");
            system("cls");
        }
        fclose(pFile);
    }
}

int WriteVocal(ArrayList* this)
{
    int i;
    eLetra* aux;
    FILE* pFile;
    pFile=fopen("info.csv","w");
    if(pFile!=NULL&&this!=NULL)
    {
        for(i=0; i<al_len(this); i++)
        {
            aux=this->get(this,i);
            if(aux!=NULL)
            {
                fprintf(pFile,"%c,%s,%d,%d\n",get_letra(aux),get_nombre(aux),get_vocal(aux),get_consonante(aux));
            }
        }
        printf("\nArchivo guardado con exito\n ");
    }
    fclose(pFile);
}

char comparaLetras(void* letraA, void* letraB)
{
    int retorno;
    if(get_letra((eLetra*)letraA)>get_letra((eLetra*)letraB))
    {
        retorno=1;
    }
    else if(get_letra((eLetra*)letraA)<get_letra((eLetra*)letraB))
    {
        retorno=-1;
    }
    else
    {
        retorno=0;
    }
    return retorno;
}


char buscarLetraRepetida(ArrayList* this, ArrayList* repetidos, ArrayList* depurado)
{
    int retorno=-1;
    int i;
    int j;
    int flag=0;
    eLetra* letra;
    eLetra* aux;
    if(this!=NULL&&repetidos!=NULL&&depurado!=NULL)
    {
        for(i=0; i<this->len(this)-1; i++)
        {
            aux=this->get(this,i);
            if((comprobarSiLetraEsRepetida,aux)==0)
            {
                flag=0;
                for(j=i+1; j<this->len(this); j++)
                {
                    letra=this->get(this,j);
                    if(get_letra(aux)==get_letra(letra))
                    {
                        repetidos->add(repetidos,letra);
                    }
                    if(flag==0)
                    {
                        depurado->remove(depurado,i);
                        flag==1;
                    }
                }
            }
        }
        /*repetidos->sort(repetidos,comparaLetras,0);
        printf("\nletras repetidas\n");
        printAll(repetidos);
        system("pause");
        system("cls");
        depurado->sort(depurado,comparaLetras,1);
        printf("\nNumeros que no se repitieron\n");
        printAll(depurado);*/
    }
}

char comprobarSiLetraEsRepetida(ArrayList* repetido, eLetra* aux)
{
    int retorno=0;
    eLetra* auxiliar;
    int i;
    for(i=0;i<repetido->len(repetido);i++)
    {
        auxiliar=repetido->get(repetido,i);
        if(get_letra(auxiliar)==get_letra(aux))
        {
            retorno=-1;
            break;
        }
    }
    return retorno;
}


/*ArrayList* nuevaCadena(ArrayList* this)
{
    eLetra* auxStruct;
    ArrayList* auxAL;
    auxAL=al_newArrayList();
    char auxCadena[20];
    int auxVocal;
    int auxConsonante;

    if(!getStringLetras("\nIngrese una cadena de caracteres: ",auxCadena))
    {
        printf("La cadena contenia elementos que no eran letras");
    }

    printf("\nCadena: %s\n",auxCadena);
    system("pause");
    for(int i=0;i<strlen(auxCadena);i++)
    {
        char letra;
        letra = auxCadena[i];

        auxStruct=constructor();

        set_letra(auxStruct,letra);
        set_name(auxStruct,"NULL");

        auxVocal=isVocal(auxStruct);
        auxConsonante=isConsonante(auxStruct);

        set_vocal(auxStruct,auxVocal);
        set_consonante(auxStruct,auxConsonante);

        for(int i=0;i<al_len(this);i++)
        {

            if(this->(pElements+i)->letra==auxStruct->letra)
            {
                al_add(auxStruct);
            }
        }


    }
}
*/
