#include "agentes.h"
#include "bits/stdc++.h"
using namespace std;
vector<int> encode(vector<string> agents){
    vector<int> r;
    int n = agents.size();
    for(int i = 0; i < n; i++) r.push_back(i + i * 100 + i * 10000);
    return r;
}
string decode(vector<string> agents, int id){
    int a = id % 100, b = (id / 100) % 100, c = (id / 10000);
    if(a == b) return agents[a];
    if(a == c) return agents[a];
    return agents[b];
}