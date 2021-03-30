#include <time.h>
#include <stdlib.h>
#include "./../headers/quicksort.h"


int comparador(const void* a, const void* b){
  long long d =  *(long long *)a - *(long long *)b;
  if(d == 0) return 0;
  return (d > 0? 1 : -1);
}


void quicksort(long long* v, int n) { qsort(v, n, sizeof(long long), comparador); }