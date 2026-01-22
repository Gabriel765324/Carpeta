#!/bin/bash
g++ islands.cpp -o islands.exe
for x in {1..11}; do
    echo "Caso $x"
    ./islands.exe < isl$x.in
    echo ""
    echo "Debería ser:"
    cat "isl$x.out"
    echo "-------------------------------------"
done
#chmod +x Compilar.sh