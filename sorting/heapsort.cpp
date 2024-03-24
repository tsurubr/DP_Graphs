#include <bits/stdc++.h>
using namespace std; 
typedef long long ll;
#define endl "\n"

// building the heap
static void heapbuild(int m, int v[]){// v[1...m]
  for(int k = 1; k < m; k++){
    //v[1...k] é um heap
    int f = k+1;
    while(f>1 && v[f/1] < v[f]){
      swap(v[f/2], v[f]);
      f /= 2;
    }
  }
} 

static void peneira(int m, int v[]){
  int p = 1, f = 2, x = v[1];
  while(f<=m){
    if(f<m && v[f] < v[f+1]) f++;
    // f é o filho mais valioso de f/2
    if(x>=v[f]) break;
    v[p] = v[f];
    p = f, f = 2*p;
  }
  v[p] = x;
}

void
heapsort (int n, int v[])
{
   heapbuild(n, v);
   for (int m = n; m >= 2; --m) {
      swap(v[1], v[m]);
      peneira (m-1, v);
   }
}

// insert an element in a sorted array
void inserte(int x, int n, int a[]){
  a[n] = x;
  n++;
  int i = n-1;
  while (i>0 && a[i] > a[i-1]){
    swap(a[i], a[i-1]);
    i--;
  }
}

int remove_min(int n, int h[]){
  swap(h[0], h[n-1]);
  n--;
  int i = 0;
  // left child = 2*i+1 right child = 2*i+2
  while(2* i + 1 < n){ // >= has at least one child (2*i+1 == left child) 
    int j = 2*i+1;
    if((2*i+2<n) && h[2*i+2] < h[j]) j = j + 1;
    if(h[j] >= h[i]) break;
    else {swap(h[i], h[j]); i = j;}
  }
  return h[n];
}

//A&DS HeapSort
void itmoHeap(int x, int n, int v[]){
  for(int i = 0; i < n; i++){
    inserte(v[i], n, v);
  }
  for(int i =0; i<n; i++){
      v[i] = remove_min(n, v);  
  }
}

void itmoheap2(int x, int n, int v[]){
  for(int i = 0; i < n; i++){
    //sift_up(i);
  }
  for(int i = 0; i<n;i++){
    swap(v[0], v[i]);
    //sift_down(0);
  }
}
