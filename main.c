
#include <stdio.h>
#include <stdlib.h>
#define SOUBOR1 "cisla.txt"
#define SOUBOR2 "vysledky.txt"

int main(int argc, char** argv) {
    int draha;
    int cas;
    float rychlost;  
   
    FILE *fp;
    fp = fopen(SOUBOR1,"r");
    if(fp == NULL){
        printf("%s Read/Open error",SOUBOR1);
        return EXIT_FAILURE;
    }
    FILE *fp2;
    fp2 = fopen(SOUBOR2,"w");
    if(fp2 == NULL){
        printf("%s Write/Open error",SOUBOR2);
        return EXIT_FAILURE;
    }
    while(fscanf(fp,"%d %d",&draha,&cas)==2){
        rychlost = (float)draha/cas;
        printf("%d metru\t%d sekund\t%.2f m/s\n",draha,cas,rychlost);
    }

    if(fclose(SOUBOR1) == EOF){
        printf("%s Close/read error",SOUBOR1);
    }
    if(fclose(SOUBOR2) == EOF){
        printf("%s Close/write error",SOUBOR2);
    }
    return (EXIT_SUCCESS);
}

