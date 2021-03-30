#ifndef QUICKSORT_H
#define QUICKSORT_H


// funcao que recebe dois ponteiros genericos
// e retorna um inteiro que representa
// a posicao relativa dos elementos no vetor ordenado
// 0: valores iguais
// 1:  no vetor ordenado, o primeiro valor aparece depois
// -1: no vetor ordenado, o primeiro valor aparece antes
int comparador(const void*,const void*);


// procedimento utilizado para realizar a 
// ordenacao com o metodo quicksort;
// utiliza a funcao qsort(), declarada e implementada
// nas biblitecas padroes da linguagem C
// primeiro parametro (long long*): vetor a ser ordenado
// segundo parametro (int): quantidade de elementos
void quicksort(long long*,int);


#endif