g++ grader.cpp dungeons.cpp -o dungeons.exe
for x in {1..2}; do
    echo "Caso $x"
    ./dungeons.exe < 0$x.in
    echo "----"
    cat 0$x.out
done