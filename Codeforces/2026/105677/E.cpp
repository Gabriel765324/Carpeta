/*#include "bits/stdc++.h"
using namespace std;
struct Punto{
    long long x, y;
    Punto(){}
    Punto(long long a, long long b){
        x = a;
        y = b;
    }
    Punto(int a, int b){
        x = a;
        y = b;
    }
    Punto operator-(const Punto& a){
        return Punto(this->x - a.x, this->y - a.y);
    }
    void Izquierda(){
        swap(x, y);
        x /= -1;
    }
    void Derecha(){
        swap(x, y);
        y /= -1;
    }
    int operator*(const Punto& a){
        long long r = this->x * a.y - this->y * a.x;
        if(r > 0LL) return 1;
        if(r == 0LL) return 0;
        return -1;
    }
    Punto operator*(const int& a){
        return Punto(this->x * (long long)a, this->y * (long long)a);
    }
    bool operator==(const Punto& a){
        return this->x == a.x and this->y == a.y;
    }
    long long M_dulo(){
        return this->x * this->x + this->y * this->y;
    }
};
Punto Origen = Punto(-2222222222222222, -2222222222222222);
bool Primera_pasada = 1;
bool operator<(const Punto &a, const Punto& b){
    if(Origen == Punto(-2222222222222222, -2222222222222222)){
        return make_pair(a.x, a.y) < make_pair(b.x, b.y);
    }
    if(Primera_pasada){
        if(Origen == a) return 1;
        if(Origen == b) return 0;
        Punto a0 = (Origen - a) * -1, b0 = (Origen - b) * -1;
        if(a0 * b0 == -1) return 1;
        if(a0 * b0 == 1) return 0;
        return a0.M_dulo() < b0.M_dulo();
    }
    if(a.x > b.x) return 1;
    if(a.x < b.x) return 0;
    return a.y < b.y;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    bool x = 1, y = 1;
    long long mx = 1000000022, my = 1000000022;
    vector<Punto> a(n);
    for(int i = 0; i < n; i++){
        cin>>a[i].x>>a[i].y;
        mx = min(mx, a[i].x);
        my = min(my, a[i].y);
        if(i > 0){
            x = x and a[i].x == a[i - 1].x;
            y = y and a[i].y == a[i - 1].y;
        }
    }
    if(x or y){
        sort(a.begin(), a.end());
        cout<<n + 1<<"\n";
        for(auto E: a){
            cout<<E.x<<" "<<E.y<<"\n";
        }
        cout<<a[0].x + int(y)<<" "<<a[0].y + int(x)<<"\n";
        return 0;
    }
    int p = 0;
    for(int i = 1; i < n; i++){
        if((a[i].x == a[p].x and a[i].y > a[p].y) or a[i].x < a[p].x) p = i;
    }
    for(int i = 0; i < n; i++) a[i].Izquierda();
    Origen = a[p];
    sort(a.begin(), a.end());
    Primera_pasada = 0;
    int Ayudita = n - 2;
    for(; Ayudita > -1; Ayudita--){
        if((a[n - 1] - a[0]) * (a[Ayudita] - a[0]) != 0) break;
    }
    Ayudita++;
    reverse(a.begin() + Ayudita, a.end());
    vector<Punto> Pol_gono = {a[0], a[1]};
    for(int i = 2; i < n; i++){
        while(Pol_gono.size() > 1){
            if((a[i] - Pol_gono[int(Pol_gono.size()) - 2]) * (Pol_gono.back() - Pol_gono[int(Pol_gono.size()) - 2]) == 1){
                Pol_gono.pop_back();
            } else {
                Pol_gono.push_back(a[i]);
                break;
            }
        }
    }
    my = LLONG_MAX;
    for(auto E: Pol_gono){
        my = max(my, E.y);
    }
    while(Pol_gono.back().y != my) Pol_gono.pop_back();
    Origen = Punto(-2222222222222222, -2222222222222222);
    set<Punto> Tenemos;
    for(auto E: Pol_gono) Tenemos.insert(E);
    vector<Punto> Sobrantes;
    for(auto E: a){
        if(Tenemos.find(E) == Tenemos.end()){
            Sobrantes.push_back(E);
        }
    }
    Origen.x--;
    vector<Punto> Respuesta;
    int n = int(Pol_gono.size());
    for(int i = 0; i < n; i++){
        Pol_gono[i].Derecha();
        Respuesta.push_back(Pol_gono[i]);
    }
    n = int(Sobrantes.size());
    for(int i = 0; i < n; i++){
        Sobrantes[i].Derecha();
    }
    sort(Sobrantes.begin(), Sobrantes.end());
    Sobrantes.push_back(Pol_gono[0]);
    Punto Anterior = Pol_gono.back();
    n++;
    for(int i = 0; i < n; i++){
        if(Sobrantes[i].x == Anterior.x){
            Anterior = Sobrantes[i];
            Respuesta.push_back(Anterior);
            continue;
        }
        //Aquí se hacía la construcción de la parte de abajo del polígono, pero la lógica falló.
        long long xa = Sobrantes[i].x - 1LL;
        long long 
    }
    Respuesta.pop_back();
    cout<<Respuesta.size()<<"\n";
    for(auto E: Respuesta) cout<<E.x<<" "<<E.y<<"\n";
    return 0;
}*/
#include "bits/stdc++.h"
using namespace std;
struct Punto{
    long long x, y;
    Punto(){}
    Punto(long long a, long long b){
        x = a;
        y = b;
    }
    bool operator<(const Punto& a){
        if(this->y > a.y) return 1;
        if(this->y < a.y) return 0;
        return this->x < a.x;
    }
    bool operator==(const Punto& a){
        return this->x == a.x and this->y == a.y;
    }
    bool operator!=(const Punto& a){
        return !(*this == a);
    }
};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    bool x = 1, y = 1;
    long long mx = 1000000022, my = 1000000022, My = -2;
    vector<Punto> a(n);
    for(int i = 0; i < n; i++){
        cin>>a[i].x>>a[i].y;
        mx = min(mx, a[i].x);
        my = min(my, a[i].y);
        My = max(My, a[i].y);
        if(i > 0){
            x = x and a[i].x == a[i - 1].x;
            y = y and a[i].y == a[i - 1].y;
        }
    }
    sort(a.begin(), a.end());
    if(x or y){
        cout<<n + 1<<"\n";
        for(auto E: a){
            cout<<E.x<<" "<<E.y<<"\n";
        }
        cout<<(a[0].x + int(y) <= 1000000000 ? a[0].x + int(y) : a[0].x - int(y))<<" "<<(a[0].y + int(x) <= 1000000000 ? a[0].y + int(x) : a[0].y - int(x))<<"\n";
        return 0;
    }
    vector<Punto> Respuesta;
    Punto Anterior = Punto(mx, My);
    Respuesta.push_back(Anterior);
    int i = 0;
    if(a[0] == Anterior) i++;
    if(a[i].y == Anterior.y){
        Respuesta.push_back(a[i]);
        Anterior = a[i];
        i++;
    } else {
        Anterior.x++;
        Respuesta.push_back(Anterior);
    }
    vector<Punto> Borde;
    for(; i < n; i++){
        if(a[i].x == mx){
            Borde.push_back(a[i]);
            continue;
        }
        if(a[i].y == my) break;
        if(a[i].y == Anterior.y){
            Respuesta.push_back(a[i]);
            Anterior = Respuesta.back();
            continue;
        }
        if(a[i].x == Anterior.x and a[i].x == mx + 1){
            Respuesta.push_back(a[i]);
            Anterior = Respuesta.back();
            continue;
        }
        Anterior.y--;
        Anterior.x = mx + 1;
        Respuesta.push_back(Anterior);
        if(a[i] == Anterior) continue;
        Respuesta.push_back(a[i]);
        Anterior = Respuesta.back();
    }
    reverse(a.begin() + i, a.end());
    for(; i < n; i++){
        if(a[i].y == Anterior.y){
            Respuesta.push_back(a[i]);
            Anterior = Respuesta.back();
            continue;
        }
        if(a[i].y == Anterior.y - 1){
            Respuesta.push_back(a[i]);
            Anterior = Respuesta.back();
            continue;
        }
        Anterior.x = mx + 1;
        Anterior.y--;
        Respuesta.push_back(Anterior);
        Anterior.y = a[i].y + 1;
        if(!(Anterior == Respuesta.back())){
            Respuesta.push_back(Anterior);
        }
        Respuesta.push_back(a[i]);
        Anterior = Respuesta.back();
    }
    reverse(Borde.begin(), Borde.end());
    for(auto E: Borde){
        if(Anterior.y == E.y){
            Respuesta.push_back(E);
            Anterior = E;
            continue;
        }
        if(Anterior.x == E.x){
            Respuesta.push_back(E);
            Anterior = E;
            continue;
        }
        Anterior.x = mx;
        Respuesta.push_back(Anterior);
        if(Anterior != E){
            Respuesta.push_back(E);
            Anterior = Respuesta.back();
        }
    }
    cout<<int(Respuesta.size())<<"\n";
    for(auto E: Respuesta){
        cout<<E.x<<" "<<E.y<<"\n";
    }
    return 0;
}