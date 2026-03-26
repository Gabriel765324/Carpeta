#include "bits/stdc++.h"
using namespace std;
int n;
vector<long long> A;
vector< pair<long long, long long> > PD;
pair<long long, long long> operator+(const pair<long long, long long>& a, const pair<long long, long long>& b){
    return {a.first + b.first + a.second + b.second, a.second + b.second};
}
bool operator<(const pair<long long, long long>& a, const pair<long long, long long>& b){
    if(a.first < b.first) return 1;
    if(a.first > b.first) return 0;
    return a.second < b.second;
}
pair<long long, long long> Resolver(int i, int j){
    if(i == j) return {0, A[i]};
    if(j == i + 1) return {A[i] + A[j], A[i] + A[j]};
    if(PD[i + j * 422].first != -2) return PD[i + j * 422];
    PD[i + j * 422] = Resolver(i, i) + Resolver(i + 1, j);
    for(int k = i + 2; k <= j; k++){
        PD[i + j * 422] = min(PD[i + j * 422], Resolver(i, k - 1) + Resolver(k, j));
    }
    return PD[i + j * 422];
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    PD.assign(n - 1 + (n - 1) * 422 + 22, {-2, -2});
    A.assign(n, 0);
    for(int i = 0; i < n; i++) cin>>A[i];
    cout<<Resolver(0, n - 1).first;
    return 0;
}