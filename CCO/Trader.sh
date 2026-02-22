g++ Trader.cpp -o Trader.exe
for x in {1..4}; do
    echo "---------------------------"
    ./Trader.exe < $x.txt
    echo ""
    echo "---------------------------"
done