#include <iostream>
#include <algorithm>

using namespace std;

/* indices 0, 1, 2, ..., n-1
          0
       1     2
     3  4  5   6
   7

left(i) = 2*i + 1  (?)   
right(i) = 2*i + 2  (?)

parent(i) = (i-1)/2

Dizemos que um vetor v[0:n) é um heap se
     v[parent(i)] >= v[i]
para cada i em [1:n)

Exemplo    
          7
    4           6
1      3      5    2

*/

/* Problema 1: Dado um vetor v[0:n) rearranjá-lo de tal forma
que seja um heap 

     i
2i+1   2i+2

Suponha que sub(2i+1) e sub(2i+2) são heaps.
Vamos mostrar como transformar sub(i) em um heap
         6
    4           3  i
1      3     5    2

1) determinar o indice k de maior chave dentre 2i+1 e 2i+2 (se existir)
   v[k] é o max(v[2i+1], v[2i+2])
2) se v[i] >= v[k], então sub(i) é heap
3) suponha que v[i] < v[k]  
4) swap(v[i], v[k])
5) submeta reursivamente a função para k
   ou iterativamente faça i = k
*/

int inline left(int i) { return 2*i + 1; }
int inline parent(int i) { return (i-1)/2; }


/* receve v[0:n) e i em [0:n) tal que sub(left(i)) e sub(right(i)) 
   são heaps e rearranja v de tal forma que sub(i) seja um heap */
void sift_down(int *v, int n, int i) {
    int k = left(i);
    if (k >= n) return;
    if (k + 1 < n && v[k+1] > v[k]) ++k;
    if (v[i] >= v[k]) return;
    swap(v[i], v[k]);
    sift_down(v, n, k);
}


/* 
         1 
      |3   |4        
    |5   |6  |7  |8 

*/

/* recebe v[0:n) e rearranja v[0:n) de tal forma
que v[0:n) seja um heap */
void build_heap(int *v, int n) {
    for (int i = parent(n-1); i >= 0; i--)
        sift_down(v, n, i);
}

void heap_sort(int *v, int n) {
    build_heap(v, n);
    while (n > 0) {
        --n;
        swap(v[n], v[0]);
        sift_down(v, n, 0);
    }
}


int main() {
    int v[] {6, 7, 1, 2, 8, 9, 3, 4, 5, 10};
    heap_sort(v, 10);
    for (int x: v) cout << x << ' ';
}