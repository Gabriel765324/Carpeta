#include "traffic.h"
#include "bits/stdc++.h"
using namespace std;
long long Total = 0, Mejor = 0, Costo = 2222222222222222;
vector<long long> Personas, Costos, Otros_costos, El_anterior;
vector< vector<long long> > Grafo;
vector<bool> Visitados;
long long DFS(long long Nodo, long long Anterior){
   long long Suma = 0;
   Visitados[Nodo] = 1;
   El_anterior[Nodo] = Anterior;
   for(auto E: Grafo[Nodo]){
      if(!Visitados[E]) Suma += DFS(E, Nodo);
   }
   //cout<<Nodo<<" ";
   return Otros_costos[Nodo] = Personas[Nodo] + Suma;
}
void DFS1(long long Nodo, long long Llevo, long long Anterior){
   Visitados[Nodo] = 1;
   long long Suma = 0;
   long long Mayor = 0;
   //cout<<Nodo<<" ";
   if(Grafo[Nodo].size() == 1){
      if(Anterior == -1){
         for(auto E: Grafo[Nodo]){
            Mayor = max(Mayor, Otros_costos[E]);
            DFS1(E, Personas[Nodo], Nodo);
         }
      } else {
         Mayor = max(Mayor, Llevo);
      }
   } else {
      for(auto E: Grafo[Nodo]){
         if(E != Anterior){
            Suma += Otros_costos[E];
            Mayor = max(Mayor, Otros_costos[E]);
         } else {
            Mayor = max(Mayor, Llevo);
         }
      }
      Llevo += Personas[Nodo];
      for(auto E: Grafo[Nodo]){
         if(!Visitados[E]){
            DFS1(E, Llevo + Suma - Otros_costos[E], Nodo);
         }
      }
   }
   if(Mayor < Costo){
      Costo = Mayor;
      Mejor = Nodo;
   }
}
int LocateCentre(int N, int pp[], int S[], int D[]) {
   long long n = N;
   if(n == 1) return 0;
   Personas.assign(n, 0);
   Visitados.assign(n, 0);
   El_anterior.assign(n, 0);
   Otros_costos.assign(n, 0);
   Costos.assign(n, -1);
   Grafo.assign(n, vector<long long>());
   for(long long i = 0; i < n; i++){
      Personas[i] = pp[i];
      Total += Personas[i];
   }
   for(long long i = 0; i < (n - 1); i++){
      Grafo[S[i]].push_back(D[i]);
      Grafo[D[i]].push_back(S[i]);
   }
   long long Inicio = 0;
   for(long long i = 0; i < n; i++){
      if(Grafo[i].size() == 1){
         Inicio = i;
         Costos[i] = Personas[i];
         deque<long long> Cola = {i};
         while(!Cola.empty()){
            long long Nodo = Cola[0];
            Cola.pop_front();
            for(auto E: Grafo[Nodo]){
               if(Costos[E] == -1){
                  Costos[E] = Personas[E] + Costos[Nodo];
                  Cola.push_back(E);
               }
            }
         }
         break;
      }
   }
   //cout<<"Penúltimo.\n";
   long long Coscoscoscoscos = DFS(Inicio, -1);
   Visitados.assign(n, 0);
   //cout<<"Último.\n";
   DFS1(Inicio, 0, -1);
   return (int)Mejor;
}