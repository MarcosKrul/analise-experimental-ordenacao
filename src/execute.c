#include <time.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "./include/sources/digital.c"
#include "./include/sources/auxiliar.c"
#include "./include/sources/quicksort.c"
#include "./include/sources/bubblesort.c"


void execute(int tam, int digits, unsigned int seed) {
    int i;
    clock_t aux;
    srand(seed);

    Stats stats = (Stats) {
        .digital = -1,
        .quicksort = -1,
        .bubblesort = -1
    };

    char** v_strings = (char**) malloc(tam * sizeof(char *));
    if(v_strings == NULL) return;
    for(i=0 ; i<tam ; i++) {
        v_strings[i] = (char *) malloc((digits+1) * sizeof(char));
        if(v_strings[i] == NULL) return;
    }

    long long* v_numeros = (long long *) malloc(tam * sizeof(long long)); 
    if(v_numeros == NULL) return;
    long long* v_numeros_copia = (long long *) malloc(tam * sizeof(long long)); 
    if(v_numeros_copia == NULL) return;

    strings_aleatorias(v_strings, tam, digits);

    for(i=0 ; i<tam ; i++) {
        v_numeros[i] = atoll(v_strings[i]);
        v_numeros_copia[i] = v_numeros[i];
    }


    // printf("\n\nVetor de long long desordenado\n");
    // print_vi(v_numeros, tam);
    aux = clock();
    quicksort(v_numeros, tam);
    aux = clock() - aux;
    stats.quicksort = ((double) aux) / CLOCKS_PER_SEC;
    // printf("\n\nVetor de long long ordenado pelo quicksort\n");
    // print_vi(v_numeros, tam);
    
    // printf("\n\nVetor de char desordenado\n");
    // print_vs(v_strings, tam);
    aux = clock();
    ordenacaoDigital(v_strings, tam, digits);
    aux = clock() - aux;
    stats.digital = ((double) aux) / CLOCKS_PER_SEC;
    // printf("\n\nVetor de char ordenado\n");
    // print_vs(v_strings, tam);
    
    // printf("\n\nVetor de long long desordenado\n");
    // print_vi(v_numeros_copia, tam);
    aux = clock();
    bubblesort(v_numeros_copia, tam);
    aux = clock() - aux;
    stats.bubblesort = ((double) aux) / CLOCKS_PER_SEC;
    // printf("\n\nVetor de long long ordenado pelo bubblesort\n");
    // print_vi(v_numeros_copia, tam);


    free(v_strings);
    free(v_numeros);
    free(v_numeros_copia);

    gravar_arq_dados(&stats, tam, digits);
}