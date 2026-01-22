g++ grader.cpp insects.cpp -o insects.exe
for x in {1..1}; do
    echo "Caso $x"
    ./insects.exe < sample-$x.in
    echo ""
    cat sample-$x.out
    echo ""
    echo "----" 
done