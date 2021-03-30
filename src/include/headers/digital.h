#ifndef DIGITAL_H
#define DIGITAL_H


// Rearranja em ordem lexicografica um vetor v[0..n-1] 
// de strings. Cada v[i] e uma string v[i][0..W-1]
// cujos elementos pertencem ao conjunto 0..9.
// Fonte: Prof. Paulo Feofiloff
// https://www.ime.usp.br/~pf/algoritmos/aulas/radix.html
// primeiro parametro (char**): vetor a ser ordenado
// segundo parametro (int): quantidade de elementos
// terceiro parametro (int): quantidade de digitos
void ordenacaoDigital(char**,int,int);


#endif