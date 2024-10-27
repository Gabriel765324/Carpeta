#include "traffic.h"
#include "bits/stdc++.h"
using namespace std;
int LocateCentre(int N, int pp[], int S[], int D[]) {
   long long n = N;
   if(n == 1) return 0;
   vector<long long> a(n), b(n);
   for(long long i = 0; i < n; i++){
      a[i] = (long long)pp[i];
      if(i > 0) a[i] += a[i - 1];
   }
   for(long long i = n - 1; i > -1; i--){
      b[i] = (long long)pp[i];
      if(i < (n - 1)) b[i] += b[i + 1];
   }
   long long r = 222222222222222222;
   long long c = 0;
   for(long long i = 0; i < n; i++){
      long long G = -2, g = G;
      if(i > 0) G = a[i - 1];
      if(i < (n - 1)) g = b[i + 1];
      if(G != -2 and g != -2){
         if(max(G, g) < r){
            r = max(G, g);
            c = i;
         }
      } else if(G == -2){
         if(g < r){
            r = g;
            c = i;
         }
      } else if(g == -2){
         if(G < r){
            r = G;
            c = i;
         }
      }
   }
   return (int)c;
}