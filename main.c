#include <stdio.h>
#include <stdlib.h>
#include "letra.h"
#include "SetGetBool.h"
#include "ArrayList.h"
#define ESC 27

int main()
{
    ArrayList *auxArray=al_newArrayList();
    ArrayList *auxArrayA=NULL;
    ArrayList *auxArrayB=NULL;
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
                    if(auxArrayA!=NULL){
                        al_deleteArrayList(auxArrayA);
                    }auxArrayA=al_newArrayList();
                    listFilter(auxArray,auxArrayA);
                    if(auxArrayA->isEmpty(auxArrayA)){
                        printf("\n No se encontraron coincidencias\n");
                    }else{
                        auxArrayA->sort(auxArrayA,orderLetter,0);
                        printf("\n Lista A:\n");
                        printf("\n|id|letra|   nombre|vocal|consonante|\n");
                        auxArrayA->map(auxArrayA,mostrarLetra,1);
                    }
                    printf("\n ");system("pause");
                    break;
                case '3':
                    if(auxArrayB!=NULL){
                        al_deleteArrayList(auxArrayB);
                    }auxArrayB=al_newArrayList();
                    auxArrayB=al_clone(auxArray);
                    listPurger(auxArray,auxArrayB);
                    if(auxArrayB->isEmpty(auxArrayB)){
                        printf("\n No se encontraron diferencias\n");
                    }else{
                        removeRepeated(auxArrayB);
                        auxArrayB->sort(auxArrayB,orderLetter,1);
                        printf("\n Lista B:\n");
                        printf("\n|id|letra|   nombre|vocal|consonante|\n");
                        auxArrayB->map(auxArrayB,mostrarLetra,1);
                    }
                    printf("\n ");system("pause");
                    break;
                case '4':
                    printf(" Generando Archivos...\n\n ");
                    if(crear_Letra("completo.csv",auxArray))
                        {printf(" -Lista completa\n ");}
                    if(crear_Letra("repetido.csv",auxArrayA))
                        {printf(" -Lista con repetidos\n ");}
                    if(crear_Letra("depurado.csv",auxArrayB))
                        {printf(" -Lista depurada\n ");}
                    printf("\n ");system("pause");
                    break;
                case ESC:
                    seguir=ESC;
                    al_deleteArrayList(auxArray);
                    if(auxArrayA!=NULL)
                        {al_deleteArrayList(auxArrayA);}
                    if(auxArrayB!=NULL)
                        {al_deleteArrayList(auxArrayB);}
                    break;
            }
        }
    }else
        {printf("Error leyendo datos.csv\n");system("pause");}
    return 0;
}
