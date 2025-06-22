#include "rail.h"
#include "bits/stdc++.h"
using namespace std;
void findLocation(int N, int first, int location[], int stype[]){
    int n = N;
    stype[0] = 1;
    location[0] = first;
    vector< vector< pair<int, int> > > Distancias(n, vector< pair<int, int> >(n, {0, 0}));
    for(int i = 0; i < n; i++){
        Distancias[i][i] = {0, i};
        for(int j = i + 1; j < n; j++){
            Distancias[i][j] = {getDistance(i, j), j};
            Distancias[j][i] = {Distancias[i][j].first, i};
        }
    }
    for(int i = 0; i < n; i++) sort(Distancias[i].begin(), Distancias[i].end());
    int Actual = 0, Puesto = 1;
    for(int i = 0; i < n - 1; i++){
        pair<int, int> Nuevo = Distancias[Actual][Puesto];
        if(Puesto % 2 == 1){
            location[Nuevo.second] = location[Actual] + Nuevo.first;
            stype[Nuevo.second] = 2;
        } else {
            location[Nuevo.second] = location[Actual] - Nuevo.first;
            stype[Nuevo.second] = 1;
        }
        Actual = Nuevo.second;
        Puesto++;
    }
    return;
}