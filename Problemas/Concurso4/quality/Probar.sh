g++ grader.cpp quality.cpp -o quality.exe
echo "Caso 0a"
./quality.exe < grader.in.0a
cat grader.expect.0a
echo "----"
for x in {0..4}; do
    echo "Caso $x"
    ./quality.exe < grader.in.$x
    cat grader.expect.$x
    echo "----"
done