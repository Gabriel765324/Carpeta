g++ Kay_and_snowflake.cpp -o Kay_and_snowflake.exe
for x in {1..2}; do
    ./Kay_and_snowflake.exe < Kay_and_snowflake$x.txt
    echo "----------------"
done