g++ Nadando.cpp -o Nadando.exe
for x in {1..5}; do
    ./Nadando.exe < $x.txt
done