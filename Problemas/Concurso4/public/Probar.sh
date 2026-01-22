g++ grader.cpp books.cpp -o books.exe
for x in {1..1}; do
    echo "Caso $x"
    ./books.exe < 0$x.in
    cat 0$x.out
    echo "---"
done