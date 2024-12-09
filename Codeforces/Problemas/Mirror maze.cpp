#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long r, c, k = 0;
    cin>>r>>c;
    vector<string> m(r), Buenos;
    for(long long i = 0; i < r; i++) cin>>m[i];
    vector< vector< vector<bool> > > Nada(r, vector< vector<bool> >(c, vector<bool>(5, 0))), Visitados;
    for(long long i = 0; i < c; i++){
        long long x = 0, y = i, d = 3;
        Visitados = Nada;
        while(x > -1 and x < r and y > -1 and y < c){
            if(Visitados[x][y][d]) break;
            Visitados[x][y][d] = 1;
            if(m[x][y] == '/'){
                switch(d){
                    case 1:
                    d = 2;
                    break;
                    case 2:
                    d = 1;
                    break;
                    case 3:
                    d = 4;
                    break;
                    case 4:
                    d = 3;
                }
            }
            if(m[x][y] == 92/*  \  */){
                switch(d){
                    case 1:
                    d = 4;
                    break;
                    case 2:
                    d = 3;
                    break;
                    case 3:
                    d = 2;
                    break;
                    case 4:
                    d = 1;
                }
            }
            switch(d){
                case 1:
                x--;
                break;
                case 2:
                y++;
                break;
                case 3:
                x++;
                break;
                case 4:
                y--;
            }
        }
        bool Bien = 1;
        for(long long j = 0; j < r and Bien; j++){
            for(long long k = 0; k < c and Bien; k++){
                if(m[j][k] != '.'){
                    bool Correcto = 0;
                    for(long long l = 0; l < 5; l++) Correcto = Correcto or Visitados[j][k][l];
                    Bien = Bien and Correcto;
                }
            }
        }
        if(Bien){
            k++;
            Buenos.push_back("N");
            string I;
            long long ci = i + 1;
            stringstream Conversor;
            Conversor<<ci;
            Conversor>>I;
            Buenos.back() += I;
        }
    }
    for(long long i = 0; i < c; i++){
        long long x = r - 1, y = i, d = 1;
        Visitados = Nada;
        while(x > -1 and x < r and y > -1 and y < c){
            if(Visitados[x][y][d]) break;
            Visitados[x][y][d] = 1;
            if(m[x][y] == '/'){
                switch(d){
                    case 1:
                    d = 2;
                    break;
                    case 2:
                    d = 1;
                    break;
                    case 3:
                    d = 4;
                    break;
                    case 4:
                    d = 3;
                }
            }
            if(m[x][y] == 92/*  \  */){
                switch(d){
                    case 1:
                    d = 4;
                    break;
                    case 2:
                    d = 3;
                    break;
                    case 3:
                    d = 2;
                    break;
                    case 4:
                    d = 1;
                }
            }
            switch(d){
                case 1:
                x--;
                break;
                case 2:
                y++;
                break;
                case 3:
                x++;
                break;
                case 4:
                y--;
            }
        }
        bool Bien = 1;
        for(long long j = 0; j < r and Bien; j++){
            for(long long k = 0; k < c and Bien; k++){
                if(m[j][k] != '.'){
                    bool Correcto = 0;
                    for(long long l = 0; l < 5; l++) Correcto = Correcto or Visitados[j][k][l];
                    Bien = Bien and Correcto;
                }
            }
        }
        if(Bien){
            k++;
            Buenos.push_back("S");
            string I;
            long long ci = i + 1;
            stringstream Conversor;
            Conversor<<ci;
            Conversor>>I;
            Buenos.back() += I;
        }
    }
    for(long long i = 0; i < r; i++){
        long long x = i, y = 0, d = 2;
        Visitados = Nada;
        while(x > -1 and x < r and y > -1 and y < c){
            if(Visitados[x][y][d]) break;
            Visitados[x][y][d] = 1;
            if(m[x][y] == '/'){
                switch(d){
                    case 1:
                    d = 2;
                    break;
                    case 2:
                    d = 1;
                    break;
                    case 3:
                    d = 4;
                    break;
                    case 4:
                    d = 3;
                }
            }
            if(m[x][y] == 92/*  \  */){
                switch(d){
                    case 1:
                    d = 4;
                    break;
                    case 2:
                    d = 3;
                    break;
                    case 3:
                    d = 2;
                    break;
                    case 4:
                    d = 1;
                }
            }
            switch(d){
                case 1:
                x--;
                break;
                case 2:
                y++;
                break;
                case 3:
                x++;
                break;
                case 4:
                y--;
            }
        }
        bool Bien = 1;
        for(long long j = 0; j < r and Bien; j++){
            for(long long k = 0; k < c and Bien; k++){
                if(m[j][k] != '.'){
                    bool Correcto = 0;
                    for(long long l = 0; l < 5; l++) Correcto = Correcto or Visitados[j][k][l];
                    Bien = Bien and Correcto;
                }
            }
        }
        if(Bien){
            k++;
            Buenos.push_back("W");
            string I;
            long long ci = i + 1;
            stringstream Conversor;
            Conversor<<ci;
            Conversor>>I;
            Buenos.back() += I;
        }
    }
    for(long long i = 0; i < r; i++){
        long long x = i, y = c - 1, d = 4;
        Visitados = Nada;
        while(x > -1 and x < r and y > -1 and y < c){
            if(Visitados[x][y][d]) break;
            Visitados[x][y][d] = 1;
            if(m[x][y] == '/'){
                switch(d){
                    case 1:
                    d = 2;
                    break;
                    case 2:
                    d = 1;
                    break;
                    case 3:
                    d = 4;
                    break;
                    case 4:
                    d = 3;
                }
            }
            if(m[x][y] == 92/*  \  */){
                switch(d){
                    case 1:
                    d = 4;
                    break;
                    case 2:
                    d = 3;
                    break;
                    case 3:
                    d = 2;
                    break;
                    case 4:
                    d = 1;
                }
            }
            switch(d){
                case 1:
                x--;
                break;
                case 2:
                y++;
                break;
                case 3:
                x++;
                break;
                case 4:
                y--;
            }
        }
        bool Bien = 1;
        for(long long j = 0; j < r and Bien; j++){
            for(long long k = 0; k < c and Bien; k++){
                if(m[j][k] != '.'){
                    bool Correcto = 0;
                    for(long long l = 0; l < 5; l++) Correcto = Correcto or Visitados[j][k][l];
                    Bien = Bien and Correcto;
                }
            }
        }
        if(Bien){
            k++;
            Buenos.push_back("E");
            string I;
            long long ci = i + 1;
            stringstream Conversor;
            Conversor<<ci;
            Conversor>>I;
            Buenos.back() += I;
        }
    }
    cout<<k<<"\n";
    for(auto E: Buenos) cout<<E<<" ";
    return 0;
}