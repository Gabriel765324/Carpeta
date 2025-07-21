#include "books.h"
#include "bits/stdc++.h"
using namespace std;
int n;
struct No_repetir{
	vector<int> p;
	int Inicio, Posici_n, Mano;
	long long Profundidad;
};
bool operator<(const No_repetir& a, const No_repetir& b){
	if(a.p < b.p) return 1;
	if(a.p > b.p) return 0;
	if(a.Inicio < b.Inicio) return 1;
	if(a.Inicio > b.Inicio) return 0;
	if(a.Posici_n < b.Posici_n) return 1;
	if(a.Posici_n > b.Posici_n) return 0;
	if(a.Mano < b.Mano) return 1;
	if(a.Mano > b.Mano) return 0;
	return a.Profundidad < b.Profundidad;
}
map<No_repetir, long long> Programaci_n_din_mica_que_parece_recursi_n;
long long Resolver(vector<int> p, int Inicio, int Posici_n, int Mano, long long Profundidad){
	bool Bien = 1;
	if(Profundidad >= 22) return 2222222222222222;
	for(int i = 0; i < n and Bien; i++) if(p[i] != i) Bien = 0;
	if(Bien){
		cerr<<abs(Posici_n - Inicio)<<"\n";
		for(auto E: p) cerr<<E<<" ";
		cerr<<"\n"<<Inicio<<" "<<Posici_n<<" "<<Mano<<"\n";
		return abs(Posici_n - Inicio);
	}
	No_repetir Estado;
	Estado.Inicio = Inicio;
	Estado.Mano = Mano;
	Estado.p = p;
	Estado.Posici_n = Posici_n;
	Estado.Profundidad = Profundidad;
	if(Programaci_n_din_mica_que_parece_recursi_n.count(Estado) == 1) return Programaci_n_din_mica_que_parece_recursi_n.count(Estado);
	long long r = 2222222222222222;
	for(int i = 0; i < n; i++){
		if(p[i] != i){
			swap(Mano, p[i]);
			r = min(r, Resolver(p, Inicio, i, Mano, Profundidad + 1) + abs(i - Posici_n));
			swap(Mano, p[i]);
		}
	}
	cerr<<r<<"\n";
	for(auto E: p) cerr<<E<<" ";
	cerr<<"\n"<<Inicio<<" "<<Posici_n<<" "<<Mano<<"\n";
	return Programaci_n_din_mica_que_parece_recursi_n[Estado] = r;
}
long long minimum_walk(vector<int> p, int s){
	n = p.size();
	return Resolver(p, s, 0, -2, 0);
}