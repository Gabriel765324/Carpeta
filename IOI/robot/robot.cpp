#include "robot.h"
#include "bits/stdc++.h"
using namespace std;
//Actual Izquierda Abajo Derecha Arriba
void program_pulibot(){
    set_instruction({0, -2, 0, 0, -2}, 1, 'E');
    set_instruction({0, -2, -1, 0, -2}, 1, 'E');
    set_instruction({0, -2, 0, -1, -2}, 1, 'S');
    //Continuar.
    set_instruction({0, 1, 0, 0, -2}, 1, 'E');
    set_instruction({0, 0, 0, -2, 1}, 1, 'S');
    set_instruction({0, 1, -2, 0, 0}, 1, 'E');
    set_instruction({0, 0, -2, 0, 1}, 1, 'E');
    set_instruction({0, 1, 0, -2, -2}, 1, 'S');
    set_instruction({0, -2, -2, 0, 1}, 1, 'E');
    set_instruction({0, 1, -2, 0, -1}, 1, 'E');
    set_instruction({0, 1, -2, -1, 0}, 1, 'N');
    set_instruction({0, -1, 1, 0, -2}, 1, 'E');
    set_instruction({0, 1, -1, 0, -2}, 1, 'E');
    set_instruction({0, 1, 0, -1, -2}, 1, 'S');
    set_instruction({0, -1, -2, 0, 1}, 1, 'E');
    set_instruction({0, 0, 1, 0, -2}, 1, 'E');
    //python3 display.py
    //Terminar.
    set_instruction({0, 0, -2, -2, 1}, 1, 'T');
    set_instruction({0, -1, -2, -2, 1}, 1, 'T');
    set_instruction({0, 1, -2, -2, -1}, 1, 'T');
    set_instruction({0, 1, -2, -2, 0}, 1, 'T');
}