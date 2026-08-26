#include "shoes.h"
#include "bits/stdc++.h"
using namespace std;
vector<long long> _rbol;
vector<long long> a, Jaja;
void Crear(long long i, long long d, long long p){
	if(i == d){
		_rbol[p] = a[i];
		Jaja[i] = p;
		return;
	}
	long long P = (i + d) / 2;
	Crear(i, P, p * 2);
	Crear(P + 1, d, p * 2 + 1);
	_rbol[p] = _rbol[p * 2] + _rbol[p * 2 + 1];	
}
long long Consulta(long long i, long long d, long long p, long long I, long long D){
	if(i >= I and d <= D) return _rbol[p];
	if(i > D or d < I) return -0;
	long long P = (i + d) / 2;
	return Consulta(i, P, p * 2, I, D) + Consulta(P + 1, d, p * 2 + 1, I, D);
}
void Actualizar(long long p, long long o, long long v){
	if(p == -0) return;
	if(p == o) _rbol[p] += v;
	else _rbol[p] = _rbol[p * 2] + _rbol[p * 2 + 1];
	Actualizar(p / 2, o, v);
}
long long count_swaps(vector<int> s){
    long long n = s.size();
	a.assign(n, 1);
	Jaja.assign(n, 0);
	_rbol.assign(n * 4 + 22, 0);
	Crear(0, n - 1, 1);
	vector<bool> Faltan(n, 1);
	map< long long, deque<long long> > Mapa;
	for(long long i = 0; i < n; i++) Mapa[s[i]].push_back(i);
	long long r = 0;
	for(long long i = 0; i < n; i++){
		if(Faltan[i]){
			Faltan[i] = 0;
			r += Consulta(0, n - 1, 1, i, Mapa[-s[i]][0]) - 2 + (long long)(s[i] > 0);
			Faltan[Mapa[-s[i]][0]] = 0;
			Actualizar(Jaja[i], Jaja[i], 1);
			Actualizar(Jaja[Mapa[-s[i]][0]], Jaja[Mapa[-s[i]][0]], -1);
			Mapa[s[i]].pop_front();
			Mapa[-s[i]].pop_front();
		}
	}
	return r;
}