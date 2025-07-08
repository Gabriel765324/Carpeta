#include "quality.h"
#include "bits/stdc++.h"
using namespace std;
vector<int> _rbol, Jaja;
void Crear(int i, int d, int p){
	if(i == d){
		Jaja[i] = p;
		return;
	}
	int P = (i + d) / 2;
	Crear(i, P, p * 2);
	Crear(P + 1, d, p * 2 + 1);
}
void Actualizar(int p, int o){
	if(p == -0) return;
	if(p == o) _rbol[p] = 1 - _rbol[p];
	else _rbol[p] = _rbol[p * 2] + _rbol[p * 2 + 1];
	Actualizar(p / 2, o);
}
int Consulta(int i, int d, int p, int v){
	if(i == d) return i + 1;
	int P = (i + d) / 2;
	if(_rbol[p * 2] >= v) return Consulta(i, P, p * 2, v);
	else return Consulta(P + 1, d, p * 2 + 1, v - _rbol[p * 2]);
}
int rectangle(int R, int C, int H, int W, int Q[3001][3001]){
	int n = R * C, r = n, i = 0, j = 0, k = H - 1, l = W - 1;
	_rbol.assign(n * 4 + 22, 0);
	Jaja.assign(n, 0);
	Crear(0, n - 1, 1);
	bool Derecha = 1;
	for(int m = 0; m < H; m++){
		for(int o = 0; o < W; o++){
			Actualizar(Jaja[Q[m][o] - 1], Jaja[Q[m][o] - 1]);
		}
	}
	int Mediana = (H * W + 1) / 2;
	r = min(Consulta(0, n - 1, 1, Mediana), r);
	while(1){
		//cerr<<i<<" "<<j<<"\n";
		if(Derecha) l++;
		else l--;
		bool Bajar = 0;
		if(l - W + 1 == -1 or l == C){
			Bajar = 1;
			if(Derecha) l--;
			else l++;
			k++;
			if(k == R) break;
		}
		if(Bajar){
			for(int cj = j; cj <= l; cj++){
				Actualizar(Jaja[Q[i][cj] - 1], Jaja[Q[i][cj] - 1]);
				Actualizar(Jaja[Q[k][cj] - 1], Jaja[Q[k][cj] - 1]);
			}
			i++;
			Derecha = !Derecha;
		} else {
			if(Derecha){
				for(int ci = i; ci <= k; ci++){
					Actualizar(Jaja[Q[ci][j] - 1], Jaja[Q[ci][j] - 1]);
					Actualizar(Jaja[Q[ci][l] - 1], Jaja[Q[ci][l] - 1]);
				}
				j++;
			}
			else {
				for(int ci = i; ci <= k; ci++){
					Actualizar(Jaja[Q[ci][j - 1] - 1], Jaja[Q[ci][j - 1] - 1]);
					Actualizar(Jaja[Q[ci][l + 1] - 1], Jaja[Q[ci][l + 1] - 1]);
				}
				j--;
			}
		}
		r = min(Consulta(0, n - 1, 1, Mediana), r);
	}
	return r;
}