#include "dna.h"
#include "bits/stdc++.h"
using namespace std;
long long n;
unordered_map<string, long long> Cambiar;
unordered_map<long long, string> iCambiar;
vector< vector<long long> > Pares, Letrasa, Letrasb;
void init(string a, string b){
	n = a.size();
	Pares.assign(9, vector<long long>(n, 0));
	Letrasa.assign(3, vector<long long>(n, 0));
	Letrasb.assign(3, vector<long long>(n, 0));
	for(long long i = 0; i < 3; i++){
		for(long long j = 0; j < 3; j++){
			string c = "  ";
			if(i == 0) c[0] = 'A';
			if(i == 1) c[0] = 'C';
			if(i == 2) c[0] = 'T';
			if(j == 0) c[1] = 'A';
			if(j == 1) c[1] = 'C';
			if(j == 2) c[1] = 'T';
			Cambiar[c] = i * 3 + j;
			iCambiar[i * 3 + j] = c;
		}
		string c = " ";
		if(i == 0) c[0] = 'A';
		if(i == 1) c[0] = 'C';
		if(i == 2) c[0] = 'T';
		Cambiar[c] = i;
		iCambiar[i] = c;
	}
	for(long long i = 0; i < n; i++){
		string c = "", cc = "", ccc = "";
		c += a[i];
		c += b[i];
		cc += a[i];
		ccc += b[i];
		Pares[Cambiar[c]][i]++;
		Letrasa[Cambiar[cc]][i]++;
		Letrasb[Cambiar[ccc]][i]++;
		if(i > 0){
			for(long long j = 0; j < 9; j++) Pares[j][i] += Pares[j][i - 1];
			for(long long j = 0; j < 3; j++) Letrasa[j][i] += Letrasa[j][i - 1];
			for(long long j = 0; j < 3; j++) Letrasb[j][i] += Letrasb[j][i - 1];
		}
	}
	/*cout<<a<<"\n"<<b<<"\n";
	for(long long i = 0; i < 9; i++){
		cout<<iCambiar[i]<<" ";
		for(long long j = 0; j < n; j++) cout<<Pares[i][j]<<" ";
		cout<<"\n";
	}*/
}
int get_distance(int x, int y){
	x--;
	vector<long long> c(9);
	for(long long i = 0; i < 9; i++) c[i] = Pares[i][y];
	for(long long i = 0; i < 9 and x > -1; i++) c[i] -= Pares[i][x];
	for(long long i = 0; i < 3; i++){
		long long ka = Letrasa[i][y], kb = Letrasb[i][y];
		if(x > -1){
			ka -= Letrasa[i][x];
			kb -= Letrasb[i][x];
		}
		if(ka != kb) return -1;
	}
	int r = 0, m, Extra = 0;
	m = min(c[Cambiar["AC"]], c[Cambiar["CA"]]);
	r += m;
	c[Cambiar["AC"]] -= m;
	c[Cambiar["CA"]] -= m;
	Extra += c[Cambiar["AC"]];
	Extra += c[Cambiar["CA"]];
	m = min(c[Cambiar["AT"]], c[Cambiar["TA"]]);
	r += m;
	c[Cambiar["AT"]] -= m;
	c[Cambiar["TA"]] -= m;
	Extra += c[Cambiar["AT"]];
	Extra += c[Cambiar["TA"]];
	m = min(c[Cambiar["TC"]], c[Cambiar["CT"]]);
	r += m;
	c[Cambiar["TC"]] -= m;
	c[Cambiar["CT"]] -= m;
	Extra += c[Cambiar["TC"]];
	Extra += c[Cambiar["CT"]];
	r += Extra * 2 / 3;
	return r;
}