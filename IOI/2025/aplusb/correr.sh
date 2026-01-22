g++ grader.cpp aplusb.cpp -o aplusb.exe
for x in {1..1}; do
    echo "Caso $x:"
    ./aplusb.exe < 0$x.in
    cat 0$x.out
    echo "----"
done