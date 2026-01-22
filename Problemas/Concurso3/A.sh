g++ A.cpp -o A.exe
for x in {1..2}; do
    echo "Caso $x"
    ./A.exe < A$x.in
    echo ""
    cat A$x.out
    echo ""
    echo "----"
done