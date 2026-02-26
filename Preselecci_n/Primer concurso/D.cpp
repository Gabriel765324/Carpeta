//No se compliquen la vida con coordenadas polares.
#include "bits/stdc++.h"
using namespace std;
struct Punto{
    long long x, y, z;
};
Punto Resta(Punto a, Punto b){
    Punto c;
    c.x = b.x - a.x;
    c.y = b.y - a.y;
    c.z = b.z - a.z;
    return c;
}
Punto Suma(Punto a, Punto b){
    Punto c;
    c.x = b.x + a.x;
    c.y = b.y + a.y;
    c.z = b.z + a.z;
    return c;
}
Punto Operar(Punto a, string o){
    if(o == "+z") a.z++;
    if(o == "+y") a.y++;
    if(o == "-z") a.z--;
    if(o == "-y") a.y--;
    if(o != "No") a.x--;
    return a;
}
Punto Rotar(Punto a, string o){
    if(o == "No") return a;
    long long x = a.x;
    long long y = a.y;
    long long z = a.z;
    if(o == "+z"){
        a.x = -z;
        a.z = x;
    }
    if(o == "+y"){
        a.x = -y;
        a.y = x;
    }
    if(o == "-z"){
        a.x = z;
        a.z = -x;
    }
    if(o == "-y"){
        a.x = y;
        a.y = -x;
    }
    return a;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n;
    while(cin>>n){
        if(n == 0) break;
        vector<string> Operaciones(n - 1);
        Punto Siguiente;
        Siguiente.x = n;
        Siguiente.y = 0;
        Siguiente.z = -0;
        Punto Actual = Siguiente;
        for(long long i = 0; i < n - 1; i++){
            cin>>Operaciones[i];
            Actual = Suma(Rotar(Resta(Siguiente, Actual), Operaciones[i]), Operar(Siguiente, Operaciones[i]));
            Siguiente.x--;
        }
        Punto Primero = Actual;
        Siguiente.x = n - 1;
        Actual = Siguiente;
        for(long long i = 1; i < n - 1; i++){
            Actual = Suma(Rotar(Resta(Siguiente, Actual), Operaciones[i]), Operar(Siguiente, Operaciones[i]));
            Siguiente.x--;
        }
        if(Primero.x > Actual.x) cout<<"+x";
        if(Primero.x < Actual.x) cout<<"-x";
        if(Primero.y > Actual.y) cout<<"+y";
        if(Primero.y < Actual.y) cout<<"-y";
        if(Primero.z > Actual.z) cout<<"+z";
        if(Primero.z < Actual.z) cout<<"-z";
        cout<<"\n";
    }
    return 0;
}
/*#include "bits/stdc++.h"
using namespace std;
struct Punto_i{
    long long x, y, z;
};
struct Punto_p{
    double m, o1, o2;
};
double pi = 4 * atan(1);
double Atan(double a, double b){
    if(a == 0) return -0;
    if(b == 0) return pi / 2;
    return atan(a / b);
}
double Acos(double a, double b){
    if(b == 0) return 0;
    else return acos(a / b);
}
long long Redondear(double a){
    long long b = a, c = b + 1;
    if((double)c - a < a - (double)b) return c;
    else return b;
}
double Distancia(Punto_i a, Punto_i b){
    long long _1 = a.x - b.x;
    long long _2 = a.y - b.y;
    long long _3 = a.z - b.z;
    return sqrt(_1 * _1 + _2 * _2 + _3 * _3);
}
Punto_i Nuevo_punto_i(Punto_i a, Punto_p b){
    Punto_i Retorno;
    Retorno.x = Redondear(b.m * sin(b.o2) * cos(b.o1)) + a.x;;
    Retorno.y = Redondear(b.m * sin(b.o2) * sin(b.o1)) + a.y;
    Retorno.z = Redondear(b.m * cos(b.o2)) + a.z;
    return Retorno;
}
Punto_p Nuevo_punto_p(Punto_i a, Punto_i b){
    Punto_p Retorno;
    Retorno.m = Distancia(a, b);
    double x = b.x - a.x, y = b.y - a.y, z = b.z - a.z;
    Retorno.o1 = Atan(y, x);
    Retorno.o2 = Acos(z, Retorno.m);
    return Retorno;
}
Punto_i Nuevo_punto_i(Punto_i a, Punto_p b, double o3){
    Punto_i Retorno;
    if(b.o1 - pi / 2 < 0.000000000000001 or b.o1 - 3 * pi / 2 < 0.000000000000001){
        Retorno.x = 0;
        //if(b.o1 - 3 * pi / 2 < 0.000000000000001) b.m /= -1;
        if(o3 - pi / 2 < 0.000000000000001){
            Retorno.z = 0;
            Retorno.y = b.m;
        } else if(o3 - 3 * pi / 2 < 0.000000000000001){
            Retorno.z = 0;
            Retorno.y = -b.m;
        } else {
            Retorno.y = Redondear(b.m * tan(o3) / sqrt(tan(o3) * tan(o3) + 1));
            Retorno.z = Redondear(b.m / sqrt(tan(o3) * tan(o3) + 1));
        }
    } else {
        Retorno.x = Redondear(b.m / sqrt(1 + tan(b.o1) * tan(b.o1) + tan(b.o2) * tan(b.o2)));
        Retorno.y = Redondear(tan(b.o1) * Retorno.x);
        Retorno.z = Redondear(tan(b.o2) * Retorno.x);
    }
    Retorno.x += a.x;
    Retorno.y += a.y;
    Retorno.z += a.z;
    return Retorno;
}
Punto_p Nuevo_punto_p(Punto_i a, Punto_i b){
    Punto_p Retorno;
    Retorno.m = Distancia(a, b);
    double x = b.x - a.x, y = b.y - a.y, z = b.z - a.z;
    Retorno.o1 = Atan(y, x);
    Retorno.o2 = Atan(z, x);
    return Retorno;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n;
    while(cin>>n){
        if(n == 0) break;
        deque<string> Operaciones(n - 1);
        Punto_i Actual;
        Actual.x = n;
        Actual.y = 0;
        Actual.z = -0;
        Punto_i Siguiente;
        Siguiente.x = n;
        Siguiente.y = 0;
        Siguiente.z = -0;
        for(long long i = 0; i < n - 1; i++){
            cin>>Operaciones[i];
            Punto_p Ahora = Nuevo_punto_p(Siguiente, Actual);
            cout<<Actual.x<<" "<<Actual.y<<" "<<Actual.z<<"\n";
            cout<<Siguiente.x<<" "<<Siguiente.y<<" "<<Siguiente.z<<"\n";
            cout<<Ahora.m<<" "<<Ahora.o1 / pi * 180<<" "<<Ahora.o2 / pi * 180<<"\n";
            Punto_i ns = Siguiente;
            double o1 = Ahora.o1;
            double o2 = Ahora.o2;
            double o3 = Atan((double)(Actual.y - Siguiente.y), (double)(Actual.z - Siguiente.z));
            if(Operaciones[i] == "+z"){
                Ahora.o1 = pi - o3;
                Ahora.o2 -= pi / 2;
                ns.z++;
            }
            if(Operaciones[i] == "+y"){
                Ahora.o1 += pi / 2;
                Ahora.o2 = -o3;
                ns.y++;
            }
            if(Operaciones[i] == "-z"){
                Ahora.o1 = o3;
                Ahora.o2 += pi / 2;
                ns.z--;
            }
            if(Operaciones[i] == "-y"){
                Ahora.o1 = o1 - pi / 2;
                Ahora.o2 = o3;
                ns.y--;
            }
           if(Operaciones[i] == "+z"){
                Ahora.o1 = pi - o3;
                Ahora.o2 += pi / 2;
                ns.z++;
            }
            if(Operaciones[i] == "+y"){
                Ahora.o1 += pi / 2;
                Ahora.o2 = o3 + pi / 2;
                ns.y++;
            }
            if(Operaciones[i] == "-z"){
                Ahora.o1 = o3;
                Ahora.o2 -= pi / 2;
                ns.z--;
            }
            if(Operaciones[i] == "-y"){
                Ahora.o1 = pi / 2 - o1;
                Ahora.o2 = pi / 2 - o3;
                ns.y--;
            }
            ns.x--;
            if(Ahora.o1 < 0) Ahora.o1 += 2 * pi;
            if(Ahora.o1 >= 2 * pi) Ahora.o1 -= 2 * pi;
            if(Ahora.o2 < 0) Ahora.o2 += 2 * pi;
            if(Ahora.o2 >= 2 * pi) Ahora.o2 -= 2 * pi;
            Actual = Nuevo_punto_i(ns, Ahora, o3);
            cout<<ns.x<<" "<<ns.y<<" "<<ns.z<<"\n";
            cout<<Ahora.m<<" "<<Ahora.o1 / pi * 180<<" "<<Ahora.o2 / pi * 180<<"\n";
            cout<<"\n";
            Siguiente.x--;
        }
        Punto_i Final = Actual;
        Siguiente.x = n - 1;
        Actual.x = n - 1;
        Actual.y = 0;
        Actual.z = -0;
        for(long long i = 1; i < n - 1; i++){
            Punto_p Ahora = Nuevo_punto_p(Siguiente, Actual);
            Punto_i ns = Siguiente;
            double o1 = Ahora.o1;
            double o2 = Ahora.o2;
            double o3 = Atan((double)(Actual.y - Siguiente.y), (double)(Actual.z - Siguiente.z));
            if(Operaciones[i] == "+z"){
                Ahora.o1 = pi - o3;
                Ahora.o2 -= pi / 2;
                ns.z++;
            }
            if(Operaciones[i] == "+y"){
                Ahora.o1 += pi / 2;
                Ahora.o2 = -o3;
                ns.y++;
            }
            if(Operaciones[i] == "-z"){
                Ahora.o1 = o3;
                Ahora.o2 += pi / 2;
                ns.z--;
            }
            if(Operaciones[i] == "-y"){
                Ahora.o1 = o1 - pi / 2;
                Ahora.o2 = o3;
                ns.y--;
            }
            if(Operaciones[i] == "+z"){
                Ahora.o1 = pi - o3;
                Ahora.o2 += pi / 2;
                ns.z++;
            }
            if(Operaciones[i] == "+y"){
                Ahora.o1 += pi / 2;
                Ahora.o2 = o3 + pi / 2;
                ns.y++;
            }
            if(Operaciones[i] == "-z"){
                Ahora.o1 = o3;
                Ahora.o2 -= pi / 2;
                ns.z--;
            }
            if(Operaciones[i] == "-y"){
                Ahora.o1 = pi / 2 - o1;
                Ahora.o2 = pi / 2 - o3;
                ns.y--;
            }
            ns.x--;
            if(Ahora.o1 < 0) Ahora.o1 += 2 * pi;
            if(Ahora.o1 >= 2 * pi) Ahora.o1 -= 2 * pi;
            if(Ahora.o2 < 0) Ahora.o2 += 2 * pi;
            if(Ahora.o2 >= 2 * pi) Ahora.o2 -= 2 * pi;
            Actual = Nuevo_punto_i(ns, Ahora, o3);
            Siguiente.x--;
        }
        cout<<Final.x<<" "<<Final.y<<" "<<Final.z<<"\n"<<Actual.x<<" "<<Actual.y<<" "<<Actual.z<<"\n";
        if(Final.x > Actual.x) cout<<"+x";
        if(Final.x < Actual.x) cout<<"-x";
        if(Final.y > Actual.y) cout<<"+y";
        if(Final.y < Actual.y) cout<<"-y";
        if(Final.z > Actual.z) cout<<"+z";
        if(Final.z < Actual.z) cout<<"-z";
        cout<<"\n";
    }
    return 0;
}*/