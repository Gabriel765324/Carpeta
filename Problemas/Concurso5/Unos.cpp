#include "bits/stdc++.h"
using namespace std;
int Potencia(int b, int e){
    if(e == 0) return 1;
    if(e == 1) return b;
    int a = Potencia(b, e / 2);
    a *= a * Potencia(b, e % 2);
    return a;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int> Respuesta(1e5 + 2, 2222);
    Respuesta[0] = 2222;
    Respuesta[1] = 1;
    for(int i = 2; i <= n; i++){
        //cerr<<i<<"\n";
        Respuesta[i] = i;
        for(int j = 1; j <= i / 2; j++){
            Respuesta[i] = min(Respuesta[i - j] + Respuesta[j], Respuesta[i]);
        }
        for(int j = 1; j * j <= i; j++){
            if(i % j == 0) Respuesta[i] = min(Respuesta[i], Respuesta[i / j] + Respuesta[j]);
        }
        int ci = i;
        string ii;
        stringstream Copiador;
        Copiador<<ci;
        Copiador>>ii;
        //cerr<<ii<<" ii\n";
        for(int j = 0; j < ii.size() - 1; j++){
            string Izquierda = "", Derecha = "";
            for(int aaaa = 0; aaaa <= j; aaaa++) Izquierda += ii[aaaa];
            for(int aaaa = j + 1; aaaa < ii.size(); aaaa++) Derecha += ii[aaaa];
            //cerr<<j<<" "<<Izquierda<<" "<<Derecha<<"\n";
            if(Derecha[0] != '0'){
                int iiii, dddd;
                stringstream Nuevo;
                Nuevo<<Izquierda;
                Nuevo>>iiii;
                stringstream Nuevo1;
                Nuevo1<<Derecha;
                Nuevo1>>dddd;
                //cerr<<iiii<<" "<<dddd<<" ¿Hola?\n";
                Respuesta[i] = min(Respuesta[i], Respuesta[iiii] + Respuesta[dddd]);
            }
        }
    }
    cout<<Respuesta[n];
    return 0;
}