#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "letra.h"
#include "SetGetBool.h"
#include "ArrayList.h"
#define ESC 27

Letra* char_new(void){
    Letra* this = (Letra*) malloc(sizeof(Letra));
    return this;
}

int menu(){
    int seguir=0;
        system("cls");
        printf("________________________________________________________________________________\n");
        printf("  1-Listar todo\n");
        printf("  2-Listar A\n");
        printf("  3-Listar B\n");
        printf("  4-Generar Archivo\n");
        printf("________________________________________________________________________________\n");
        printf(" >");
        do{
            fflush(stdin);
            seguir=getch();
        }while(seguir!=ESC&&!(seguir>='1'&&seguir<='4'));
    return seguir;
}

int mostrarLetra(Letra* eAux){
    printf("|  %c  |",char_getLetra(eAux));
    printf("%9s|",char_getNombre(eAux));
    printf("  %d  |",char_getVocal(eAux));
    printf("     %d    |\n",char_getConsonante(eAux));
    return 1;
}

char toUpper(char aux){
    if(aux>='a'&&aux<='z')
        {aux=aux-32;}
    return aux;
}

int orderLetter(Letra*aux1,Letra*aux2){
    int L1=toUpper(char_getLetra(aux1));
    int L2=toUpper(char_getLetra(aux2));
    return (L1-L2);
}

int listFilter(ArrayList* this,ArrayList* auxArray){
    char *String=(char*)malloc(sizeof(char)*100);
    char *pAux;
    getString(100,String);
    int arrayList=0;
    int contIndex=0,index=0;
    int isRepeat=0;
    char letraAux;
    for(int i=0;i<=strlen(String);i++){
        pAux=String+i;
        letraAux=*pAux;
        if(!isLetra(letraAux))
            {continue;}
        for(int j=i-1;j>=0;j--){
            if(letraAux==*(String+j))
                {isRepeat=1;break;}
        }
        if(isRepeat)
            {isRepeat=0;continue;}
        index=this->indexInt(this,char_getLetra,letraAux,index,this->len(this));
        while(index>=0){
            if(contIndex==0){
                printf("\n  | id|letra|   nombre|vocal|consonante|\n");
            }contIndex++;
            printf("%2d)%3d",contIndex,index);mostrarLetra(this->get(this,index));
            auxArray->add(auxArray,this->get(this,index));
            index=this->indexInt(this,char_getLetra,letraAux,index+1,this->len(this));
        }index=this->indexInt(this,char_getLetra,letraAux,0,this->len(this));
    }free(String);
    auxArray->sort(auxArray,orderLetter,1);
    system("pause");
    printf("\n Lista A:\n");
    printf("\n|id|letra|   nombre|vocal|consonante|\n");
    auxArray->map(auxArray,mostrarLetra,1);
    system("pause");
    return arrayList;
}

int parser_Letra(char* fileName, ArrayList* this)
{
  char letra[2];
  char nombre[22];
  char vocal[2];
  char consonante[2];
    int ok=1,cant;
    FILE* pFile;
    pFile= fopen(fileName, "r");
    if((pFile)==NULL){
        printf("No se pudo abrir el archivo.\n");
        system("pause");
        ok=0;
    }fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", letra, nombre, vocal, consonante);
    while(!feof(pFile)){
        cant=fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", letra, nombre, vocal, consonante);
        if(cant!=4){
            if(feof(pFile))
                {break;}
            else{
                printf("Error.\n");
                system("pause");
                ok=0;break;
            }
        }
        Letra* eAux=char_new();
        char_setVocal(eAux,atoi(vocal));
        char_setConsonante(eAux,atoi(consonante));
        char_setNombre(eAux,nombre);
        char_setLetra(eAux,letra[0]);
        this->add(this,eAux);
    }fclose(pFile);
    return ok; // OK
}

int crear_Letra(char* fileName, ArrayList* this)
{
    FILE* f;
    Letra* eAux=char_new();
    int returnAux = 0;
    int i;
    if(this != NULL){
        f = fopen(fileName, "w");
        if(f != NULL){
            fprintf(f,"letra,nombre,vocal,consonante\n");
            for(i=0; i<this->len(this); i++){
                eAux = this->get(this,i);
                fprintf(f,"%c,%s,%d,%d\n",char_getLetra(eAux),char_getNombre(eAux),char_getVocal(eAux),char_getConsonante(eAux));
            }fclose(f);

        }returnAux = 1;
    }free(eAux);

    return returnAux; // OK
}
