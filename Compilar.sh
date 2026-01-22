#!/bin/bash
g++ a.cpp -o a.exe
for x in {1..4}; do
    echo "Caso $x"
    ./a.exe < Entradas/Caso$x
    echo "Debería ser:"
    cat "Salidas/Caso$x"
    echo "-------------------------------------"
done
#chmod +x Compilar.sh