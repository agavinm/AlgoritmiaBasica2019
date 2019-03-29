//*****************************************************************
// File:   huffman.cpp
// Author: Andrés Gavín Murillo 716358
// Author: Andrew Mackay 737069
// Date:   Marzo 2019
// Coms:   Algoritmia básica - Práctica 1
//*****************************************************************

#include "huffman.hpp"
#include "heap.hpp"

using namespace std;

/* Dado un vector de árboles hoja v, donde cada hoja contiene su símbolo y su frecuencia, devuelve el árbol
 * lexicográfico de un código libre de prefijos óptimo resultante de aplicar el algoritmo de Huffman. */
Arbol* huffman(const vector<Arbol*> &v) {
    /* Paso 1: Crear heap de los árboles hoja de v.
     * Paso 2: Aplicar algoritmo de Huffman.
     * Paso 3: Devolver el único árbol que contiene el heap. */
    Heap q;
    Arbol *z, *x, *y;

    // Paso 1
    for (Arbol* i : v) {
        q.insertar(*i);
    }

    // Paso 2
    for (int i=1; i<v.size(); i++) {
        x = q.primero();
        y = q.primero();
        z = new Arbol(*x, *y);
        q.insertar(*z);
    }

    // Paso 3
    z = q.primero();
    return z;
}