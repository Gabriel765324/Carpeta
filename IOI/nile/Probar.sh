g++ grader.cpp nile.cpp -o nile.exe
for x in {1..3}; do
    echo "Caso $x: "
    ./nile.exe < 0$x.in
    echo "----"
    cat 0$x.out
done
