#include "supertrees.h"
#include "bits/stdc++.h"
using namespace std;
bool Final = 0;
vector<int> Representantes0, Representantes1;
int Buscar0(int a){
	if(Representantes0[a] == a) return a;
	return Representantes0[a] = Buscar0(Representantes0[a]);
}
bool Unir0(int A, int B){
	int a = Buscar0(A), b = Buscar0(B);
	if(Representantes0[a] != Representantes0[b]){
		Representantes0[b] = a;
		return 1;
	}
	return 0;
}
int Buscar1(int a){
	if(Representantes1[a] == a) return a;
	return Representantes1[a] = Buscar1(Representantes1[a]);
}
void Unir1(int A, int B){
	int a = Buscar1(A), b = Buscar1(B);
	Representantes1[b] = a;
}
int construct(vector< vector<int> > p){
	int n = p.size();
	for(int i = 0; i < n; i++) Representantes0.push_back(i);
	vector< vector<int> > Respuesta(n, vector<int>(n, 0));
	for(int i = 0; i < n; i++){
		for(int j = i + 1; j < n; j++){
			if(p[i][j] == 3) return 0;
			if(p[i][j] != 1) continue;
			if(Unir0(i, j)){
				Respuesta[i][j] = 1;
				Respuesta[j][i] = 1;
			}
			if(Final) return 0;
		}
	}
	set<int> Nuevos;
	for(int i = 0; i < n; i++){
		Nuevos.insert(Buscar0(i));
	}
	map<int, int> Mapeo, iMapeo;
	int m = Nuevos.size();
	auto E = Nuevos.begin();
	for(int i = 0; i < m; i++){
		Representantes1.push_back(i);
		Mapeo[*E] = i;
		iMapeo[i] = *E;
		E++;
	}
	for(int i = 0; i < n; i++){
		for(int j = i + 1; j < n; j++){
			if(p[i][j] != 2) continue;
			Unir1(Mapeo[Representantes0[i]], Mapeo[Representantes0[j]]);
		}
	}
	vector< vector<int> > Separaciones(n);
	for(int i = 0; i < m; i++){
		Separaciones[Buscar1(i)].push_back(i);
	}
	for(auto E: Separaciones){
		if(E.size() <= 1) continue;
		if(E.size() == 2) return 0;
		for(int i = 0; i < int(E.size()); i++){
			int Siguiente = i + 1;
			if(Siguiente >= int(E.size())) Siguiente = 0;
			Respuesta[iMapeo[E[i]]][iMapeo[E[Siguiente]]] = 1;
			Respuesta[iMapeo[E[Siguiente]]][iMapeo[E[i]]] = 1;
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = i + 1; j < n; j++){
			if(p[i][j] == 0 and (Buscar0(i) == Buscar0(j) or (Buscar1(Mapeo[i]) == Buscar1(Mapeo[j]) and Mapeo[i] != Mapeo[j]))) return 0;
			/*if(p[i][j] == 2){

			}*/
		}
	}
	build(Respuesta);
	return 1;
}