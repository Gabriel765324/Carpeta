g++ Seguro.cpp -o Seguro.exe
for x in {1..2}; do
    ./Seguro.exe < $x.txt
done