g++ grader.cpp roads.cpp -o roads.exe
for x in {0..2}; do
    echo "Caso $x:"
    ./roads.exe < roads.input$x.txt
    cat roads.output$x.txt
    echo "----"
done