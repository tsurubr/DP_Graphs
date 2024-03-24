#include <stdio.h> 

static int separa(int v[], int p, int r){
  int c = v[r]; //pivo
  int t, j = p;
  for(int k = p; k<r; k++){
    if(v[k] <= c) {
      t = v[j], v[j] = v[k], v[k] = t;
      j++;
    }
  }
  t = v[j], v[j] = v[r], v[r] = t;
  return j;
}

void quicksort(int v[], int p, int r){
  if(p<r){
    int j = separa(v, p, r);
    quicksort(v, p, j-1);
    quicksort(v, j+1, r);
  }
}

void psort (int v[], int p, int r) {
   if (p >= r) return;
   if (v[p] > v[r]) {
      int t = v[p]; v[p] = v[r]; v[r] = t; 
   }
   psort (v, p, r-1);
   psort (v, p+1, r); 
}


// pilha de execucao muito alta
void 
quickSort (int v[], int p, int r)
{
   while (p < r) {      
      int j = separa (v, p, r);    
      if (j - p < r - j) {     
         quickSort (v, p, j-1);
         p = j + 1;            
      } else {                 
         quickSort (v, j+1, r);
         r = j - 1;
      }
   }
}


int main(){
  int v[10] = {8,4,3,2,5,7,6,9,0,1};
  psort(v, 0, 9);
  for(int i = 0; i < 10; i++){
    printf("%d ", v[i]);
  }
}
