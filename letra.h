#ifndef __LETRA
#define __LETRA
#include "ArrayList.h"

struct S_Letra{
  char letra;
  char nombre[22];
  int vocal;
  int consonante;
};
typedef struct S_Letra Letra;
char toUpper(char);
int orderLetter(Letra*,Letra*);
int listFilter(ArrayList*,ArrayList*);
int mostrarLetra(Letra* eAux);
int parser_Letra(char* fileName, ArrayList* this);
int crear_Letra(char* fileName, ArrayList* this);


#endif
