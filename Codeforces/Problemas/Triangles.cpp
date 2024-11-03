#include "bits/stdc++.h"
using namespace std;
bool Sirve(long long a, long long b, long long c){
    vector<long long> s = {a, b, c};
    sort(s.begin(), s.end());
    if(s[2] < (s[0] + s[1])) return 1;
    else return 0;
}
vector<long long> a1, Jaja;
vector< vector<long long> > _rbol;
map<long long, long long> Dos, iDos;
long long d = 0;
void Crear(long long i, long long f, long long p){
    //cout<<p<<"\n";
    if(i == f){
        _rbol[iDos[a1[i]]][p] = 1;
        Jaja[i] = p;
    } else {
        long long P = (i + f) / 2;
        Crear(i, P, p * 2);
        Crear(P + 1, f, p * 2 + 1);
        for(i = 0; i < d; i++){
            _rbol[i][p] = _rbol[i][p * 2] + _rbol[i][p * 2 + 1];
        }
    }
}
vector<long long> Consulta(long long Inicio, long long Final, long long Posici_n, long long Rango1, long long Rango2){
    vector<long long> Fusi_n(d, 0);
    if(Inicio >= Rango1 and Final <= Rango2){
        for(long long i = 0; i < d; i++){
            Fusi_n[i] = _rbol[i][Posici_n];
        }
        return Fusi_n;
    }
    if(Inicio > Rango2 or Final < Rango1) return Fusi_n;
    long long P = (Inicio + Final) / 2;
    vector<long long> _1 = Consulta(Inicio, P, Posici_n * 2, Rango1, Rango2);
    vector<long long> _2 = Consulta(P + 1, Final, Posici_n * 2 + 1, Rango1, Rango2);
    for(long long i = 0; i < d; i++){
        Fusi_n[i] = _1[i] + _2[i];
    }
    return Fusi_n;
}
void Actualizar(long long Afectado, long long Nuevo, long long Posici_n, long long Original){
    if(Posici_n == 0) return;
    if(Posici_n == Original){
        _rbol[Afectado][Posici_n] = 0;
        _rbol[Nuevo][Posici_n] = 1;
    } else {
        _rbol[Afectado][Posici_n] = _rbol[Afectado][Posici_n * 2] + _rbol[Afectado][Posici_n * 2 + 1];
        _rbol[Nuevo][Posici_n] = _rbol[Nuevo][Posici_n * 2] + _rbol[Nuevo][Posici_n * 2 + 1];
    }
    Actualizar(Afectado, Nuevo, Posici_n / 2, Original);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n, q;
    cin>>n>>q;
    vector<long long> a(n);
    bool Dos2 = 1;
    for(long long i = 0; i < n; i++){
        cin>>a[i];
        long long aa = a[i];
        while((aa % 2) == 0) aa /= 2;
        if(aa != 1) Dos2 = 0;
    }
    if(n <= 3022){
        while(q--){
            long long t, l, r;
            cin>>t>>l>>r;
            if(t == 0) a[l] = r;
            else {
                vector<long long> s;
                for(long long i = l; i <= r; i++){
                    s.push_back(a[i]);
                }
                sort(s.begin(), s.end());
                long long Mejor = 0;
                for(long long i = 2; i < s.size(); i++){
                    if((s[i - 2] + s[i - 1]) > s[i]) Mejor = max(Mejor, s[i - 2] + s[i] + s[i - 1]);
                }
                cout<<Mejor<<"\n";
            }
        }
    } else if(Dos2){
        for(long long i = 1; i <= 500000000; i *= 2){
            Dos[d] = i;
            iDos[i] = d;
            d++;
        }
        a1 = a;
        _rbol.assign(d, vector<long long>(n * 4, 0));
        Jaja.assign(n, 0);
        n--;
        //cout<<"Seguro falló aquí.\n";
        Crear(0, n, 1);
        /*for(auto E: _rbol){
            for(auto i: E){
                cout<<i<<" ";
            }
            cout<<"\n";
        }*/
        while(q--){
            long long t, l, r;
            cin>>t>>l>>r;
            if(t == 0){
                Actualizar(iDos[a[l]], iDos[r], Jaja[l], Jaja[l]);
                a[l] = r;
            } else {
                vector<long long> Valorcitos = Consulta(0, n, 1, l, r);
                /*vector<long long> Procesito(d, 0);
                for(long long i = d - 1; i > -1; i--){
                    Procesito[i] = (long long)(Valorcitos[i] > 0);
                    if(i < (d - 1)) Procesito[i] += Procesito[i + 1];
                }*/
                /*for(long long i = 0; i < d; i++){
                    cout<<i<<" "<<Dos[i]<<" "<<Valorcitos[i]<<"\n";
                }*/
                long long Insano = -2;
                bool Joya = 0;
                for(long long i = d - 1; i > -1; i--){
                    if(Insano != -2 and Valorcitos[i] > 0){
                        cout<<2 * Insano + Dos[i]<<"\n";
                        Joya = 1;
                        break;
                    }
                    if(Valorcitos[i] >= 3){
                        cout<<3 * Dos[i]<<"\n";
                        Joya = 1;
                        break;
                    }
                    if(Valorcitos[i] == 2){
                        Insano = max(Dos[i], Insano);
                    }
                }
                if(!Joya) cout<<"0\n";
            }
        }
    }/* else {
        while(q--){
            long long t, l, r;
            cin>>t>>l>>r;
            if(t == 0){
                a[l] = r;
            } else {
                long long Mejor = 0;
                vector<long long> s;
                for(long long i = l; i <= r; i++) s.push_back(a[i]);
                sort(s.begin(), s.end());
                for(long long i = l; i < r; i++){
                    for(long long j = i + 1; j <= r; j++){
                        long long Valor = a[i] + a[j];
                        long long ii = 0, d = s.size() - 1, Bueno = s.size();
                        while(1){
                            long long p = (ii + d) / 2;
                            if(s[p] < Valor){
                                ii = p + 1;
                                Bueno = p;
                            } else d = p - 1;
                            if(ii >= (d + 1)) break;
                        }
                        long long No_usar1 = 1, No_usar2 = 1;
                        if(Bueno < s.size()){
                            if(a[i] != a[j]){
                                while(Bueno > -1){
                                    if(s[Bueno] == a[i]){
                                        if(No_usar1 > 0){
                                            No_usar1 = 0;
                                        } else {
                                            if(Sirve(a[i], a[j], s[Bueno])) Mejor = max(Mejor, Valor + s[Bueno]);
                                            //cout<<a[i]<<" "<<a[j]<<" "<<s[Bueno]<<" t\n";
                                            break;
                                        }
                                    } else if(s[Bueno] == a[j]){
                                        if(No_usar2 > 0){
                                            No_usar2 = 0;
                                        } else {
                                            if(Sirve(a[i], a[j], s[Bueno])) Mejor = max(Mejor, Valor + s[Bueno]);
                                            //cout<<a[i]<<" "<<a[j]<<" "<<s[Bueno]<<" t\n";
                                            break;
                                        }
                                    } else {
                                        if(Sirve(a[i], a[j], s[Bueno])) Mejor = max(Mejor, Valor + s[Bueno]);
                                        //cout<<a[i]<<" "<<a[j]<<" "<<s[Bueno]<<" t\n";
                                        break;
                                    }
                                    Bueno--;
                                }
                            } else {
                                No_usar1 = 2;
                                while(Bueno > -1){
                                    if(s[Bueno] == a[i]){
                                        if(No_usar1 > 0){
                                            No_usar1--;
                                        } else {
                                            if(Sirve(a[i], a[j], s[Bueno])) Mejor = max(Mejor, Valor + s[Bueno]);
                                            //cout<<a[i]<<" "<<a[j]<<" "<<s[Bueno]<<" t\n";
                                            break;
                                        }
                                    } else {
                                        if(Sirve(a[i], a[j], s[Bueno])) Mejor = max(Mejor, Valor + s[Bueno]);
                                        //cout<<a[i]<<" "<<a[j]<<" "<<s[Bueno]<<" t\n";
                                        break;
                                    }
                                    Bueno--;
                                }
                            }
                        }
                    }
                }
                cout<<Mejor<<"\n";
            }
        }
    }*/
    return 0;
}