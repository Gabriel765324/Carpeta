g++ grader.cpp coins.cpp -o coins.exe
for x in {1..1}; do
    echo "Caso $x:"
    ./coins.exe < 0$x.in
    echo "----"
done