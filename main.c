
#include <stdio.h>
#include <stdlib.h>
#define SOUBOR1 "cisla.txt"
#define SOUBOR2 "vysledky.txt"

int poradi(int z){
    
}


int main(int argc, char** argv) {
    int draha;
    int cas;
    int poradi=1;
    int celkovadraha=0;
    int prumdraha;
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
        printf("%d. %d metru\t%d sekund\t%.2f m/s\n",poradi,draha,cas,rychlost);
        fprintf(fp2,"%d. %d metru\t%d sekund\t%.2f m/s\n",poradi,draha,cas,rychlost);
        celkovadraha += draha;
        poradi++;
    }
    printf("\n");
    prumdraha = celkovadraha/(poradi-1);
    printf("prumerna draha je %d metru\n",prumdraha);
    printf("ze souboru %s bylo precteno %d dvojic cisel\n",SOUBOR1,poradi-1);

    if(fclose(fp) == EOF){
        printf("%s Close/read error",SOUBOR1);
    }
    if(fclose(fp2) == EOF){
        printf("%s Close/write error",SOUBOR2);
    }
    return (EXIT_SUCCESS);
}

