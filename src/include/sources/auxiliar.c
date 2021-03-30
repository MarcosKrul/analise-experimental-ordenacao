#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "./../headers/auxiliar.h"



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