//******************************************************************************
// File:   main.cpp
// Author: Andrés Gavín Murillo 716358
// Author: Andrew Mackay 737069
// Date:   Marzo 2019
// Coms:   Algoritmia básica - Práctica 1
//******************************************************************************

#include <iostream>
#include <fstream>
#include "heap.hpp"

using namespace std;

// N es el numero de caracteres que hay.
const int N=255;

/*
 * Devuelve un vector con el numero de apariciones de cada caracter en el 
 * fichero "nombreFichero".
 */
void contar(const char* nombreFichero, unsigned char (&frecuencia)[N]) {

    // "caracter" se usa para iterar sobre los caracteres del fichero. 
    // "frecuencias" es un vector de bytes, donde frecuencias[c] almacena
    // el numero de veces que ha aparecido el caracter "c" del fichero
    // "nombreFichero".
    unsigned char caracter;
    ifstream fichero(nombreFichero);

    // Se cuenta el numero de apariciones de cada caracter leido del fichero.
    while (fichero.good()) {
        caracter = fichero.get();
        frecuencia[(int) caracter]++;
        cout << "Encontrado caracter: " << caracter << endl;
    }

}

/*
 * Devuelve un heap en la que se han insertado los datos del vector 
 * "frecuencia".
 */
Heap insertarFrecuencias(unsigned char frecuencia[N]) {
    Heap h;

    // Por cada elemento del vector, se crea un arbol con la frecuencia del 
    // elemento y el elemento en si, y lo inserta al heap "h"..
    for (int i=0; i<=N; i++) {
        cout << "Insertando frecuencia del caracter " << (unsigned char) i
             << ": " << (int) frecuencia[i] << endl;
        Arbol *a = new Arbol(frecuencia[i], i);
        h.insertar(*a);
    }

    for (int j=0; j<=N; j++) {
        Arbol *b = h.primero();
        cout << "Caracter : " << (*b).obtenerByte() 
             << " aparece con una frecuencia de: " << (int ) (*b).frecuencia() << endl;
    }

    return h;
}

int main() {

    /*unsigned char frecuencia[N] = {0};
    contar("prueba1.txt", frecuencia);
    Heap h = insertarFrecuencias(frecuencia);*/


    Heap h;
    Arbol a1(10, 1), a2(20, 2), a3(30, 3), a4(40, 4), a5(50, 5), a6(60, 6), 
          a7(70, 7), a8(80, 8), a9(90, 9), a0(0, 0);
    Arbol a12(a1, a2), a56(a5, a6), a1256(a12, a56), a12560(a1256, a0);

    h.insertar(a12560); h.insertar(a56); h.insertar(a12);
    h.insertar(a1); h.insertar(a2); h.insertar(a3); h.insertar(a4); 
    h.insertar(a5); h.insertar(a6); h.insertar(a7);
    h.insertar(a8); h.insertar(a9); h.insertar(a0);
    // Insertar ok, todos son montículos de mínimos

    // Primero ok, devuelve el primero y reajusta el montículo
    Arbol *aux = h.primero();

    while (aux != nullptr) {
        cout << (int)aux->frecuencia() << endl;
        aux = h.primero();
    }

    return 0;


}