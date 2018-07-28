#include"ArrayList.h"
#ifndef numeroNatural_H_INCLUDED
#define numeroNatural_H_INCLUDED

typedef struct
{
    char letra;
    char nombre[21];
    int vocal;
    int consonante;
}eLetra;


#endif // numeroNatural_H_INCLUDED
eLetra* constructor();

void set_letra(eLetra* this, char letra);
void set_name(eLetra* this, char name[]);
void set_vocal(eLetra* this, int vocal);
void set_consonante(eLetra* this, int consonante);


int isVocal(eLetra* this);
int isConsonante(eLetra* this);


char get_letra(eLetra* this);
char* get_nombre(eLetra* this);
int get_vocal(eLetra* this);
int get_consonante(eLetra* this);

void printAll(ArrayList* this);
void printOne(eLetra* this);
int  funcionQueFiltra(void* elemento,char* palabra);
int ordenar(void* letraA,void* letraB);



int mostrarLetras(ArrayList* this);
int WriteVocal(ArrayList* this);
