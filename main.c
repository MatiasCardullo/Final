#include <stdio.h>
#include <stdlib.h>
#include "letra.h"
#include "SetGetBool.h"
#include "ArrayList.h"
#define ESC 27

int main()
{
    int subArrayListA=0,subArrayListB=0;
    ArrayList* auxArray=al_newArrayList();
    ArrayList *auxArrayA,*auxArrayB;
    if(parser_Letra("datos.csv",auxArray)){
        int seguir=0;
        auxArray->map(auxArray,setVocalOConsonante,0);
        while(seguir!=ESC){
            switch(menu()){
                case '1':
                    printf("\n|id|letra|   nombre|vocal|consonante|\n");
                    auxArray->map(auxArray,mostrarLetra,1);
                    system("pause");
                    break;
                case '2':
                    if(subArrayListA==0){
                        auxArrayA=al_newArrayList();
                        subArrayListA=1;
                    }
                    listFilter(auxArray,auxArrayA);
                    system("pause");
                    /*auxArrayA->sort(auxArrayA,orderLetter,1);
                    system("pause");
                    printf("\n|id|letra|   nombre|vocal|consonante|\n");
                    auxArrayA->map(auxArrayA,mostrarLetra,1);
                    system("pause");*/
                    break;
                case '3':
                    if(subArrayListB==0){
                        auxArrayB=al_newArrayList();
                        subArrayListB=1;
                    }
                    break;
                case '4':
                    crear_Letra("prueba.csv",auxArray);
                    break;
                case ESC:
                    seguir=ESC;
                    auxArray->deleteArrayList(auxArray);
                    if(subArrayListA)
                        {auxArrayA->deleteArrayList(auxArrayA);}
                    if(subArrayListB)
                        {auxArrayB->deleteArrayList(auxArrayB);}
                    break;
            }
        }
    }else
        {printf("Error leyendo datos.csv\n");system("pause");}
    return 0;
}
