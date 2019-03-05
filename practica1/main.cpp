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
    Arbol a1(10, 1), a2(20, 2), a3(30, 3), a4(40, 4), a5(50, 5), a6(60, 6), a7(70, 7), a8(80, 8), a9(90, 9), a0(0, 0);
    Arbol a12(a1, a2), a56(a5, a6), a1256(a12, a56), a12560(a1256, a0);

    h.insertar(a12560); h.insertar(a56); h.insertar(a12);
    h.insertar(a1); h.insertar(a2); h.insertar(a3); h.insertar(a4); h.insertar(a5); h.insertar(a6); h.insertar(a7);
    h.insertar(a8); h.insertar(a9); h.insertar(a0);
    // Insertar ok, todos son montículos de máximos

    // Primero ok, devuelve el primero y reajusta el montículo
    Arbol *aux = h.primero();

    while (aux != nullptr) {
        cout << (int)aux->frecuencia() << endl;
        aux = h.primero();
    }

    return 0;
}