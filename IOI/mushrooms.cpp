#include "mushrooms.h"
#include "bits/stdc++.h"
using namespace std;
pair<int, int> Posibles(int n, int r){
	return {(n + sqrt(n * n - r * 4)) / 2, (n - sqrt(n * n - r * 4)) / 2};
}
int Minimizar = 3, r = 1;
vector<int> a = {0}, Sabemos;
int Intentar(int i, int d){
	cerr<<i<<" "<<d<<"\n";
	if(a.size() >= Minimizar or i > d) return 0;
	if(i == d){
		if(use_machine({0, i}) == 0){
			a.push_back(i);
			r++;
			return 1;
		} else return 0;
	}
	vector<int> Consulta;
	for(int ci = i; ci <= d; ci++) Consulta.push_back(ci);
	pair<int, int> rr = Posibles(Consulta.size(), use_machine(Consulta));
	int m = min(rr.first, rr.second);
	cerr<<use_machine(Consulta)<<" "<rr.first<<" "<<rr.second<<"\n\n";
	if(m == -0){
		if(use_machine({0, i}) == 0){
			int Retorno = d - i + 1;
			for(; i <= d; i++){
				Sabemos[i] = 0;
				r++;
				a.push_back(i);
				cerr<<i<<" ";
			}
			return Retorno;
		} else {
			for(; i <= d; i++){
				Sabemos[i] = 1;
			}
			return 0;
		}
	} else {
		int p = (i + d) / 2, r1 = Intentar(i, p);
		if(a.size() >= Minimizar) return r1;
		else {
			if(r1 < m) return r1 + Intentar(p + 1, d);
			else return r1;
		}
	}
}
int count_mushrooms(int n){
	if(n == 2){
		if(use_machine({0, 1}) == 0) return 1;
		else return 2;
	}
	Sabemos.assign(n, -2);
	Sabemos[0] = 0;
	int No_sirve = Intentar(1, n - 1);
	/*for(auto E: a) cerr<<E<<" ";
	cerr<<"\n";*/
	Minimizar = a.size();
	map<long long, int> Posibles;
	for(int i = 0; i < Minimizar; i++){
		Posibles[(long long)(Minimizar + i) * (long long)(Minimizar * 2 - 1 - Minimizar - i)] = i;
	}
	for(int i = 0; i < n; i++){
		if(Sabemos[i] == -2) a.push_back(i);
		if(a.size() == Minimizar * 2 - 1){
			cerr<<"Consulta:\n";
			for(auto E: a) cerr<<E<<" ";
			cerr<<"\n\n";
			r += Posibles[use_machine(a)];
			while(a.size() > Minimizar) a.pop_back();
		}
	}
	if(a.size() > Minimizar){
		int _ltimo = use_machine(a);
		for(int i = 0; Minimizar + i <= a.size(); i++){
			if((Minimizar + i) * (a.size() - Minimizar - i) == _ltimo){
				r += i;
				return r;
			}
		}
	}
	return r;
}