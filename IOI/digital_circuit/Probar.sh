g++ grader.cpp circuit.cpp -o circuit.exe
for x in {1..3}; do
    echo "Caso $x"
    ./circuit.exe < sample-$x.in
    echo "----"
    cat sample-$x.out
    echo ""
    echo "----"
done