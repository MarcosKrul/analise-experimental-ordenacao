#ifndef AUXILIAR_H
#define AUXILIAR_H


typedef struct stats_t Stats;


// procedimento que imprime um vetor v de tamanho n de strings
// primeiro parametro (char**): vetor para imprimir
// segundo parametro (int): quantidade de elementos
void print_vs(char**,int);


// procedimento que imprime um vetor v de tamanho n de inteiros
// primeiro parametro (long long**): vetor para imprimir
// segundo parametro (int): quantidade de elementos
void print_vi(long long*,int);


// A funcao randomInteger devolve um inteiro 
// aleatorio entre low e high inclusive,
// Vamos supor que low <= high e que
// high - low <= RAND_MAX. (O codigo foi copiado
// da biblioteca random de Eric Roberts.)
int randomInteger(int,int);


// procedimento que gera n strings aleatorias 
void strings_aleatorias(char**,int,int);



#endif