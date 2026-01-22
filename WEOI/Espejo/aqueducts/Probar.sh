g++ grader.cpp aqueducts.cpp -o aqueducts.exe
for x in {0..1}; do
    echo "Caso $x:"
    ./aqueducts.exe < aqueducts.input$x.txt
    cat aqueducts.output$x.txt
    echo "----"
done