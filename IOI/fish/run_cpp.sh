g++ grader.cpp fish.cpp -o fish.exe
for x in {1..2}; do
    echo "Caso $x:"
    ./fish.exe < "$x.in"
    echo ""
    cat "$x.out"
    echo "----"
done