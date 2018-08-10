#ifndef SetGetBool_H_INCLUDED
#define SetGetBool_H_INCLUDED
#include "letra.h"

//SETTERS
int char_setVocal(Letra* this, int vocal);
int char_setConsonante(Letra* this, int consonante);
int char_setNombre(Letra* this, char* nombre);
int char_setLetra(Letra* this, char letra);
int setVocalOConsonante(Letra* this);

//GETTERS
char* getString(int,char*);
int char_getVocal(Letra* this);
int char_getConsonante(Letra* this);
char* char_getNombre(Letra* this);
char char_getLetra(Letra* this);

//BOOLEAN
int trueOrFalse();
int isLetra(char);


#endif // SetGetBool_H_INCLUDED
