#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    map< pair<long long, long long>, string> Respuestas;
    Respuestas[{1, 1}] = "  1 ->  1";
    Respuestas[{1, 2}] = "  1  2 ->  2";
    Respuestas[{1, 3}] = "  1  2  3 ->  3";
    Respuestas[{1, 4}] = "  1  2  3  4 ->  4";
    Respuestas[{1, 5}] = "  1  2  3  4  5 ->  5";
    Respuestas[{1, 6}] = "  1  2  3  4  5  6 ->  6";
    Respuestas[{1, 7}] = "  1  2  3  4  5  6  7 ->  7";
    Respuestas[{1, 8}] = "  1  2  3  4  5  6  7  8 ->  8";
    Respuestas[{2, 1}] = "  1 ->  2";
    Respuestas[{2, 2}] = "  1  3 ->  4";
    Respuestas[{2, 3}] = "  1  3  4 ->  8";
    Respuestas[{2, 4}] = "  1  3  5  6 -> 12";
    Respuestas[{2, 5}] = "  1  3  5  7  8 -> 16";
    Respuestas[{2, 6}] = "  1  3  5  6 13 14 -> 20";
    Respuestas[{2, 7}] = "  1  2  5  8 11 12 13 -> 26";
    Respuestas[{3, 1}] = "  1 ->  3";
    Respuestas[{3, 2}] = "  1  3 ->  7";
    Respuestas[{3, 3}] = "  1  4  5 -> 15";
    Respuestas[{3, 4}] = "  1  4  7  8 -> 24";
    Respuestas[{3, 5}] = "  1  4  6 14 15 -> 36";
    Respuestas[{3, 6}] = "  1  3  7  9 19 24 -> 52";
    Respuestas[{4, 1}] = "  1 ->  4";
    Respuestas[{4, 2}] = "  1  3 -> 10";
    Respuestas[{4, 3}] = "  1  5  8 -> 26";
    Respuestas[{4, 4}] = "  1  3 11 18 -> 44";
    Respuestas[{4, 5}] = "  1  3 11 15 32 -> 70";
    Respuestas[{5, 1}] = "  1 ->  5";
    Respuestas[{5, 2}] = "  1  4 -> 14";
    Respuestas[{5, 3}] = "  1  6  7 -> 35";
    Respuestas[{5, 4}] = "  1  5 12 28 -> 71";
    Respuestas[{6, 1}] = "  1 ->  6";
    Respuestas[{6, 2}] = "  1  5 -> 18";
    Respuestas[{6, 3}] = "  1  7 12 -> 52";
    Respuestas[{7, 1}] = "  1 ->  7";
    Respuestas[{7, 2}] = "  1  5 -> 23";
    Respuestas[{8, 1}] = "  1 ->  8";
    long long h, k;
    while(cin>>h>>k){
        if(h == 0 and k == 0) break;
        cout<<Respuestas[{h, k}]<<"\n";
    }
    return 0;
}
/*#include "bits/stdc++.h"
using namespace std;
mt19937 Aleatorio(2);
long long Lograr, h, k;
vector<long long> Mejor;
vector< vector< vector<long long> > > Memoria;
bool Posible(long long Suma, long long Elegir, long long Posici_n){
    if(Suma == Lograr) return 1;
    if(Suma > Lograr or Elegir == h or Posici_n == Mejor.size()) return 0;
    if(Memoria[Suma][Elegir][Posici_n] != -2) return Memoria[Suma][Elegir][Posici_n];
    bool _1 = Posible(Suma + Mejor[Posici_n], Elegir + 1, Posici_n);
    bool _2 = Posible(Suma, Elegir, Posici_n + 1);
    return Memoria[Suma][Elegir][Posici_n] = _1 or _2;
}
string Cadena(long long a){
    string Retorno;
    stringstream Cambiador;
    Cambiador<<a;
    Cambiador>>Retorno;
    return Retorno;
}
int main(){
    freopen("Resolver_B.cpp", "w", stdout);
    cout<<"#include <bits/stdc++.h>\nusing namespace std;\nint main(){\n    ios_base::sync_with_stdio(0);\n    cin.tie(0);\n";
    cout<<"    map< pair<long long, long long>, string> Respuestas;\n";
    long long Ayuda = 1;
    long long L_mite = 40;
    for(h = 1; h < 9; h++){
        for(k = 1; k + h < 10; k++){
            cerr<<Ayuda<<"\n";
            Ayuda++;
            string La_respuesta = "";
            if(h == 1){
                for(long long i = 1; i <= k; i++){
                    if(i < 10) La_respuesta += "  ";
                    else if(i < 100) La_respuesta += " ";
                    La_respuesta += Cadena(i);
                }
                La_respuesta += " ->";
                if(k < 10) La_respuesta += "  ";
                else if(k < 100) La_respuesta += " ";
                La_respuesta += Cadena(k);
            } else if(k == 1){
                La_respuesta += "  1 ->";
                if(h < 10) La_respuesta += "  ";
                else if(h < 100) La_respuesta += " ";
                La_respuesta += Cadena(h);
            } else {
                Mejor.assign(k, 1);
                long long Mejor_ = h;
                vector<long long> Opciones;
                for(long long i = 1; i <= L_mite; i++){
                    Opciones.push_back(i);
                }
                vector<long long> Punteros;
                for(long long i = 0; i < k; i++) Punteros.push_back(i);
                bool Continuar = 1;
                while(Continuar){
                    vector<long long> Copia = Mejor;
                    for(long long i = 0; i < k; i++){
                        Mejor[i] = Opciones[Punteros[i]];
                    }
                    for(Lograr = 1; 1; Lograr++){
                        Memoria.assign(Lograr, vector< vector<long long> >(h, vector<long long>(Mejor.size(), -2)));
                        if(!Posible(0, 0, 0)){
                            Lograr--;
                            break;
                        }
                    }
                    if(Lograr > Mejor_) Mejor_ = Lograr;
                    else Mejor = Copia;
                    long long Iteraciones = 0;
                    for(long long i = k - 1; i > -1; i--){
                        Punteros[i]++;
                        if(Punteros[i] < L_mite - Iteraciones){
                            for(long long j = i + 1; j < k; j++){
                                Punteros[j] = Punteros[j - 1] + 1;
                            }
                            break;
                        }
                        Iteraciones++;
                        if(i == 0) Continuar = 0;
                    }
                    if(Punteros[0] > 1) Continuar = 0;
                }
                for(auto E: Mejor){
                    if(E < 10) La_respuesta += "  ";
                    else if(E < 100) La_respuesta += " ";
                    La_respuesta += Cadena(E);
                }
                La_respuesta += " ->";
                if(Mejor_ < 10) La_respuesta += "  ";
                else if(Mejor_ < 100) La_respuesta += " ";
                La_respuesta += Cadena(Mejor_);
            }
            cout<<"    Respuestas[{"<<h<<", "<<k<<"}] = \""<<La_respuesta<<"\";\n";
        }
    }
    cout<<"    long long h, k;\n";
    cout<<"    while(cin>>h>>k){\n";
    cout<<"        if(h == 0 and k == 0) break;\n";
    cout<<"        cout<<Respuestas[{h, k}]<<\"\\n\";\n";
    cout<<"    }\n";
    cout<<"    return 0;\n}";
    return 0;
}*/