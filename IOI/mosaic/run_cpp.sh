#!/bin/bash
g++ grader.cpp mosaic.cpp -o mosaic.exe
for x in {1..3}; do
    echo "Caso $x:"
    ./mosaic.exe < "0$x.in"
    echo ""
    cat "0$x.out"
    echo "----"
done