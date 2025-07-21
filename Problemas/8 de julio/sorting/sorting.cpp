#include "sorting.h"
#include "bits/stdc++.h"
using namespace std;
int findSwapPairs(int N, int S[], int M, int X[], int Y[], int P[], int Q[]){
	int r = 0;
	set<int> Cola;
	bool Cero_uno = 1;
	for(int i = 0; i < M; i++) if(X[i] != 0 or Y[i] != 1) Cero_uno = 0;
	for(int i = 0; i < N; i++){
		Cola.insert(S[i]);
	}
	if(Cero_uno){
		Cola.erase(Cola.begin());
		Cola.erase(Cola.begin());
		for(int i = 2; i < N; i++){
			int Deber_a_ser = *Cola.begin();
			Cola.erase(Cola.begin());
			if(S[i] != Deber_a_ser){
				swap(S[0], S[1]);
				int j;
				for(j = 0; j < N; j++){
					if(S[j] == Deber_a_ser) break;
				}
				P[r] = i;
				Q[r] = j;
				r++;
				swap(S[i], S[j]);
			}
			/*for(int i = 0; i < N; i++) cerr<<S[i]<<" ";
			cerr<<"\n";*/
		}
		if(S[0] < S[1]) return r;
		P[r] = 0;
		Q[r] = 0;
		r++;
		return r;
	}
	for(int i = 0; i < N; i++){
		int Deber_a_ser = *Cola.begin();
		Cola.erase(Deber_a_ser);
		if(S[i] != Deber_a_ser){
			int j;
			for(j = 0; j < N; j++){
				if(S[j] == Deber_a_ser) break;
			}
			P[r] = i;
			Q[r] = j;
			r++;
			swap(S[i], S[j]);
		}
		/*for(int i = 0; i < N; i++) cerr<<S[i]<<" ";
		cerr<<"\n";*/
	}
	//for(int i = 0; i < N; i++) cerr<<S[i]<<" ";
	return r;
}