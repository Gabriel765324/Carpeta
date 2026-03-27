#include "supertrees.h"
#include "bits/stdc++.h"
using namespace std;
bool Final = 0;
int n;
vector<int> Representantes0, Representantes1;
vector< vector<int> > Respuesta, Copia, Grafo, Separaciones, Caminos;
vector< pair<int, int> > Activadores;
bitset<2222> Visitados;
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
void DFS(int Nodo, bool S__vuelve, int Activador_0, int Activador_1, int Inicio){
	Visitados[Nodo] = 1;
	S__vuelve = S__vuelve or Nodo == Activador_0 or Nodo == Activador_1;
	//cerr<<Nodo<<" "<<S__vuelve<<" "<<Activador_0<<" "<<Activador_1<<"\n";
	Caminos[Inicio][Nodo] = 1 + S__vuelve;
	for(auto E: Grafo[Nodo]){
		if(!Visitados[E]){
			DFS(E, S__vuelve, Activador_0, Activador_1, Inicio);
		}
	}
}
bool Verificar(){
	Grafo.assign(n, {});
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(Respuesta[i][j] == 1){
				//cerr<<i<<" >> "<<j<<"\n";
				Grafo[i].push_back(j);
			}
		}
	}
	bitset<2222> Reinicio;
	/*for(auto E: Separaciones){
		for(auto e: E){
			cerr<<e<<" ";
		}
		cerr<<"\n";
	}*/
	for(int i = 0; i < n; i++){
		//cerr<<i<<"\n";
		DFS(i, 0, Activadores[i].first, Activadores[i].second, i);
		/*cerr<<"\n";
		for(auto E: Caminos[i]) cerr<<E<<" ";
		cerr<<"\n\n";*/
		Visitados = Visitados & Reinicio;
		if(Copia[i] != Caminos[i]){
			//cerr<<"No válido.";
			return 0;
		}
	}
	//cerr<<"Válido.";
	return 1;
}
int construct(vector< vector<int> > p){
	n = p.size();
	Caminos.assign(n, vector<int>(n, 0));
	Separaciones.assign(n, {});
	Copia = p;
	Activadores.assign(n, {-2, -2});
	for(int i = 0; i < n; i++) Representantes0.push_back(i);
	Respuesta.assign(n, vector<int>(n, 0));
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
	for(int i = 0; i < m; i++){
		Separaciones[Buscar1(i)].push_back(iMapeo[i]);
	}
	for(auto E: Separaciones){
		if(E.size() <= 1) continue;
		if(E.size() == 2) return 0;
		for(int i = 0; i < int(E.size()); i++){
			int Siguiente = i + 1, Anterior = i - 1;
			if(Siguiente >= int(E.size())) Siguiente = 0;
			if(Anterior < 0) Anterior = int(E.size()) - 1;
			Activadores[E[i]].first = E[Anterior];
			Activadores[E[i]].second = E[Siguiente];
			Respuesta[E[i]][E[Siguiente]] = 1;
			Respuesta[E[Siguiente]][E[i]] = 1;
		}
	}
	for(int i = 0; i < n; i++){
		Activadores[i] = Activadores[Buscar0(i)];
	}
	if(Verificar()) build(Respuesta);
	else return 0;
	return 1;
}