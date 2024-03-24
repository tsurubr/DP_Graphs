#include <bits/stdc++.h>
using namespace std; 
typedef long long ll;
#define endl "\n"
typedef unsigned char byte;

void countingsort(int v[], int n, int R){
  int r;
  int fp[R+1], aux[n];
  int *fp, *aux;
  fp = malloc ((R+1) * sizeof (int));
  aux = malloc (n * sizeof (int));

  for(r = 0; r <= R; r++){ // sendo R o elemento de maior valor no vetor
    fp[r] = 0; // inicializa todos os elementos do vetor acumulado sendo 0
  }
  
  for(int i = 0; i < n; i++){
    r = v[i]; // valor de determinado elemento no vetor principal para incrementar sua frequencia
    fp[r+1]++;
  }
  // agora fp[r] é a frequência de r-1
   for (r = 1; r <= R; ++r) 
      fp[r] += fp[r-1]; 
   // agora fp[r] é a freq dos predecessores
   // de r; logo, a carreira de elementos
   // iguais a r deve começar no índice fp[r]
   for (int i = 0; i < n; ++i) {
      r = v[i];
      aux[fp[r]] = v[i]; 
      fp[r]++;  // *
   }
   // aux[0..n-1] está em ordem crescente
   for (int i = 0; i < n; ++i) 
      v[i] = aux[i];

   free (fp);
   free (aux);
} 


//typedef unsigned char byte;
// Rearranja em ordem lexicográfica um vetor v[0..n-1] 
// de strings. Cada v[i] é uma string v[i][0..W-1]
// cujos elementos pertencem ao conjunto 0..R-1.
void ordenacaoDigital (byte **v, int n, int W, int R) 
{
   int *fp;
   byte **aux;
   fp = malloc ((R+1) * sizeof (int));
   aux = malloc (n * sizeof (byte *));

   for (int d = W-1; d >= 0; --d) {
      int r;
      for (r = 0; r <= R; ++r) 
         fp[r] = 0;
      for (int i = 0; i < n; ++i) {
         r = v[i][d];
         fp[r+1] += 1; 
      }
      for (r = 1; r <= R; ++r) 
         fp[r] += fp[r-1]; 
      for (int i = 0; i < n; ++i) {
         r = v[i][d];
         aux[fp[r]] = v[i]; 
         fp[r]++; 
      }
      for (int i = 0; i < n; ++i) 
         v[i] = aux[i];
   }
   free (fp);
   free (aux);
}

void solve(){
  
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    //ll t; cin >> t; while(t--)
    solve();

    return 0;
}

