//*****************************************************************
// File:   main.cpp
// Author: Andrés Gavín Murillo 716358
// Author: Andrew Mackay
// Date:   Marzo 2019
// Coms:   Algoritmia básica - Práctica 1
//*****************************************************************

#include <iostream>
#include "heap.hpp"

using namespace std;

int main() { // Pruebas
    Heap h;
    Arbol a1(50, 1), a2(40, 2);
    Arbol a12(a1, a2);

    h.insertar(a1);
    h.insertar(a2);
    h.insertar(a12);

    Arbol *aux = h.primero();

    return 0;
}