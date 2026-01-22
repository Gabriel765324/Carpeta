Plantilla='#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    return 0;
}'
Entrar='
'
for x in {1..100}; do
    echo "$Plantilla" > "$x.cpp"
    Compilar="g++ $x.cpp -o $x.exe$Entrar./$x.exe"
    echo "$Compilar" > "$x.sh"
done