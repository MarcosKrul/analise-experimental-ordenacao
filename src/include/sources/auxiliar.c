#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "./../headers/auxiliar.h"


struct stats_t {
    double digital;
    double quicksort;
    double bubblesort;
};


void print_vs(char** v, int n) {
    for(int i = 0; i < n; i++) printf("%s\n", v[i]);
}


void print_vi(long long* v, int n) {
    for(int i = 0; i < n; ++i) printf("%lld\n", v[i]);
}


int randomInteger(int low, int high) {
    double d;
    d = (double) rand () / ((double) RAND_MAX + 1);
    int k = d * (high - low + 1);
    return low + k;
}


void strings_aleatorias(char** v, int n, int m) {  
  int i, j;
  
    for(i = 0; i<n; ++i) {
        for(j = 0; j<m; j++) 
            v[i][j] = randomInteger(48,57);
        v[i][j] = '\0';
    }
}


void gravar_arq_dados(Stats* stats, int tam, int digits) {
    short primeiro = 0;
    char title[20] = ".\\..\\..\\tmp\\log_";
    char* aux = (char*) malloc(2 * sizeof(char));
    if(aux == NULL) return;

    itoa(digits, aux, 10);
    strcat(title, aux);
    strcat(title, ".csv");

    FILE* arq = fopen(title, "r");
    if(arq == NULL) primeiro = 1;
    fclose(arq);
    
    arq = fopen(title, "a");
    if(arq == NULL) {
        printf("Erro ao abrir o arquivo! \n");
        return;
    }

    if(primeiro) fprintf(
        arq, 
        "%s;%s;%s;%s\n", 
        "quantidade",
        "digital",
        "quick",
        "bubble"
    );

    fprintf(
        arq,
        "%d;%lf;%lf;%lf\n",
        tam,
        stats->digital,
        stats->quicksort,
        stats->bubblesort
    );
    fclose(arq);
}