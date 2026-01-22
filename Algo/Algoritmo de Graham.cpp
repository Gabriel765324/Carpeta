#include "bits/stdc++.h"
using namespace std;
struct Punto{
    double x, y;
};
Punto a;
double Distancia(Punto _1, Punto _2){
    return (_1.x - _2.x) * (_1.x - _2.x) + (_1.y - _2.y) * (_1.y - _2.y);
}
int Orientaci_n(Punto _1, Punto _2, Punto _3){
    double r = _1.x * (_2.y - _3.y) + _2.x * (_3.y - _1.y) + _3.x * (_1.y - _2.y);
    cerr<<r<<" ";
    if(r == 0) return 0;
    if(r < 0) return -1;
    return 1;
}
bool operator<(const Punto& b, const Punto& c){
    int o = Orientaci_n(a, b, c);
    cerr<<b.x<<" "<<b.y<<" "<<c.x<<" "<<c.y<<"\n";
    if(o == 0){
        cerr<<((Distancia(a, b) < Distancia(a, c)) ? "<" : ">")<<"\n";
        return Distancia(a, b) < Distancia(a, c);
    }
    cerr<<((o < 0) ? "<" : ">")<<"\n";
    return o < 0;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    vector<Punto> Lista(n);
    for(int i = 0; i < n; i++) cin>>Lista[i].x>>Lista[i].y;
    int Menor = 0;
    for(int i = 1; i < n; i++){
        if(Lista[Menor].y > Lista[i].y or (Lista[Menor].y == Lista[i].y and Lista[Menor].x > Lista[i].x)){
            Menor = i;
        }
    }
    a = Lista[Menor];
    Lista.erase(Lista.begin() + Menor);
    sort(Lista.begin(), Lista.end());
    Lista.push_back(a);
    vector<Punto> Pol_gono_convexo = {a, Lista[0]};
    cerr<<"\n";
    for(auto E: Lista) cerr<<E.x<<" "<<E.y<<"\n";
    cerr<<"\n";
    for(int i = 1; i < n; i++){
        while(Pol_gono_convexo.size() > 2 and Orientaci_n(Pol_gono_convexo[Pol_gono_convexo.size() - 2], Pol_gono_convexo.back(), Lista[i]) > 0) Pol_gono_convexo.pop_back();
        Pol_gono_convexo.push_back(Lista[i]);
    }
    Pol_gono_convexo.pop_back();
    for(auto E: Pol_gono_convexo) cout<<E.x<<" "<<E.y<<"\n";
    return 0;
}