#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n, mm;
    cin>>n>>mm;
    vector< vector< pair<long long, long long> > > Grafo(n, vector< pair<long long, long long> >());
    string a, b;
    cin.ignore();
    for(long long i = 0; i < n; i++){
        getline(cin, a);
        getline(cin, b);
        //cout<<a<<"\n"<<b<<"\n";
        long long v, w;
        stringstream c1, c2;
        c1<<a;
        c2<<b;
        while(c1>>v){
            c2>>w;
            Grafo[v - 1].push_back(make_pair(i, w));
            //cout<<"Unir "<<v - 1<<" y "<<i<<"\n";
        }
    }
    cout<<n<<" "<<mm<<"\n";
    for(long long i = 0; i < n; i++){
        bool Algo = 0;
        for(long long j = 0; j < Grafo[i].size(); j++){
            cout<<Grafo[i][j].first + 1;
            if(j < (Grafo[i].size() - 1)) cout<<" ";
            Algo = 1;
        }
        if(!Algo){
            cout<<"0\n0";
        } else {
            cout<<"\n";
            for(long long j = 0; j < Grafo[i].size(); j++){
                cout<<Grafo[i][j].second;
                if(j < (Grafo[i].size() - 1)) cout<<" ";
                Algo = 1;
            }
        }
        if(i < (n - 1)) cout<<"\n";
    }
    return 0;
}