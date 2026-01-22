g++ grader.cpp fulbo.cpp -o fulbo.exe
for x in {1..5}; do
    echo "Caso $x:"
    ./fulbo.exe < 0$x.in
    cat 0$x.out
    echo ""
    echo "----"
done