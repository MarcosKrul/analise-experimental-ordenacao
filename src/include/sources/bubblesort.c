#include "./../headers/bubblesort.h"


void bubblesort(long long* v, int n) {
    int aux;
    
    for(int i=0 ; i<n-1 ; i++) 
        for(int j=0 ; j<n-i-1 ; j++)
            if(v[j] > v[j+1]) {
                aux = v[j];
                v[j] = v[j+1];
                v[j+1] = aux;
            }
}