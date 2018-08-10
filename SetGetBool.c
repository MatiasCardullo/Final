#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "SetGetBool.h"
#include "letra.h"

int char_setVocal(Letra* this, int vocal){
    int ok=0;
    if(vocal==0||vocal==1)
        {this->vocal = vocal;ok=1;}
    return ok;
}
int char_setConsonante(Letra* this, int consonante){
    int ok=0;
    if(consonante==0||consonante==1)
        {this->consonante = consonante;ok=1;}
    return ok;
}
int char_setNombre(Letra* this, char* nombre){
    int ok=0;
    if(strlen(nombre)<22)
        {strcpy(this->nombre, nombre);ok=1;}
    return ok;
}
int char_setLetra(Letra* this, char letra){
    int ok=0;
    if(isLetra(letra))
        {this->letra=letra;ok=1;}
    return ok;
}

char* getString(int large,char* aux){
    fflush(stdin);
    fgets(aux,large,stdin);
      if (aux[strlen(aux)-1] == '\n')
      {aux[strlen(aux)-1] = '\0';}
    return aux;
}

int char_getVocal(Letra* this){
    return this->vocal;
}
int char_getConsonante(Letra* this){
    return this->consonante;
}
char* char_getNombre(Letra* this){
    return this->nombre;
}
char char_getLetra(Letra* this){
    return this->letra;
}

int trueOrFalse(){
    int aux;
    while(1){
        aux=getch();
        if(aux=='T'||aux=='t'||aux=='V'||aux=='v'||aux=='S'||aux=='s')
            {aux=1;break;}
        else if(aux=='F'||aux=='f'||aux=='N'||aux=='n')
            {aux=0;break;}
        else
            {printf("%c",7);}
    }
    return aux;
}
int setVocalOConsonante(Letra* this){
    char letra=char_getLetra(this);
    if(letra=='a'||letra=='A'||letra=='e'||letra=='E'||letra=='i'||letra=='I'||letra=='o'||letra=='O'||letra=='u'||letra=='U'){
        char_setVocal(this,1);
        char_setConsonante(this,0);
    }else{
        char_setVocal(this,0);
        char_setConsonante(this,1);
    }
    return 0;
}
int isLetra(char letra){
    int aux=0;
    if((letra>='a'&&letra<='z')||(letra>='A'&&letra<='Z'))
        {aux=1;}
    return aux;
}
