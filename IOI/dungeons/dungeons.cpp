#include "dungeons.h"
#include <bits/stdc++.h>
using namespace std;
struct Mazmorra{
	long long Fuerza, Fuerza_al_perder, Ir_al_ganar, Ir_al_perder;
};
struct Ancestro{
	long long Suma, Ir;
};
vector<Mazmorra> Mazmorras;
vector<long long> Para_ganar;
vector< vector<Ancestro> > Ancestros;
long long n;
bool _3 = 1;
vector< vector<long long> > Grafo;
long long La_fuerza_com_n;
void init(int N, vector<int> s, vector<int> p, vector<int> w, vector<int> l){
	n = N;
	Grafo.assign(n + 1, {});
	Para_ganar.assign(n + 1, 2222222222222222);
	Ancestros.assign(n + 1, {});
	long long Hola = -2;
	for(long long i = 0; i <= n; i++){
		Mazmorra Nueva;
		if(i == n){
			Nueva.Fuerza = 0;
			Nueva.Fuerza_al_perder = 0;
			Nueva.Ir_al_ganar = n;
			Nueva.Ir_al_perder = n;
			Mazmorras.push_back(Nueva);
			Ancestro Nuevo;
			Nuevo.Ir = n;
			Nuevo.Suma = 0;
			Ancestros[i].push_back(Nuevo);
			break;
		}
		La_fuerza_com_n = s[i];
		Nueva.Fuerza = s[i];
		Nueva.Fuerza_al_perder = p[i];
		Nueva.Ir_al_ganar = w[i];
		Nueva.Ir_al_perder = l[i];
		Ancestro Nuevo;
		Nuevo.Ir = l[i];
		Nuevo.Suma = p[i];
		Ancestros[i].push_back(Nuevo);
		Mazmorras.push_back(Nueva);
		Grafo[w[i]].push_back(i);
		if(Hola == -2) Hola = s[i];
		else if(Hola != s[i]) _3 = 0;
	}
	Para_ganar[n] = 0;
	set< pair<long long, long long> > Cola;
	Cola.insert({0, n});
	while(!Cola.empty()){
		long long Nodo = (*Cola.begin()).second;
		long long Llegar = (*Cola.begin()).first;
		Cola.erase(Cola.begin());
		if(Llegar > Para_ganar[Nodo]) continue;
		for(auto E: Grafo[Nodo]){
			if(Para_ganar[E] > Para_ganar[Nodo] + Mazmorras[E].Fuerza){
				Para_ganar[E] = Para_ganar[Nodo] + Mazmorras[E].Fuerza;
				Cola.insert({Para_ganar[E], E});
			}
		}
	}
	for(long long Saltitos = 0; Saltitos < 44; Saltitos++){
		for(long long i = 0; i <= n; i++){
			Ancestro Nuevo;
			Nuevo.Ir = Ancestros[Ancestros[i][Saltitos].Ir][Saltitos].Ir;
			Nuevo.Suma = Ancestros[Ancestros[i][Saltitos].Ir][Saltitos].Suma + Ancestros[i][Saltitos].Suma;
			Ancestros[i].push_back(Nuevo);
		}
	}
}
long long simulate(int x, int z){
	if(_3){
		if(x == n) return z;
		if(z >= La_fuerza_com_n) return Para_ganar[x] + z;
		if(Ancestros[x][0].Suma + z >= La_fuerza_com_n) return simulate(Ancestros[x][0].Ir, Ancestros[x][0].Suma + z);
		/*for(long long i = 1; i < Ancestros[x].size(); i++){
			if(Ancestros[x][i].Suma + z >= La_fuerza_com_n) return simulate(Ancestros[x][i - 1].Ir, Ancestros[x][i - 1].Suma + z);
		}*/
		long long i = 0, d = Ancestros[x].size() - 1, Mejor = 0;
		while(1){
			long long p = (i + d) / 2;
			if(Ancestros[x][p].Suma + z >= La_fuerza_com_n) d = p - 1;
			else {
				i = p + 1;
				Mejor = p;
			}
			if(i >= d + 1) break;
		}
		return simulate(Ancestros[x][Mejor].Ir, Ancestros[x][Mejor].Suma + z);
	}
	if(x == n) return z;
	if(z < Mazmorras[x].Fuerza) return simulate(Mazmorras[x].Ir_al_perder, z + Mazmorras[x].Fuerza_al_perder);
	else return simulate(Mazmorras[x].Ir_al_ganar, z + Mazmorras[x].Fuerza);
}