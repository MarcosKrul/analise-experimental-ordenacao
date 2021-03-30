#include <stdlib.h>
#include "./../headers/digital.h"


void ordenacaoDigital(char **v, int n, int W) {
   int *fp = malloc ((11) * sizeof (int));
   if(fp == NULL) return;

   char **aux = malloc (n * sizeof (char *));
   if(aux == NULL) return;

   for(int d = W-1; d >= 0; --d) {
        int r;

        for(r = 0; r <= 10; ++r) fp[r] = 0;

        for(int i = 0; i < n; ++i) {
            r = v[i][d]-'0';
            fp[r+1] += 1; 
        }

        for(r = 1; r <= 10; ++r)  fp[r] += fp[r-1]; 
        
        for(int i = 0; i < n; ++i) {
            r = v[i][d]-'0';
            aux[fp[r]] = v[i]; 
            fp[r]++; 
        }

        for(int i = 0; i < n; ++i) v[i] = aux[i];
   }
   free(fp);
   free(aux);
}