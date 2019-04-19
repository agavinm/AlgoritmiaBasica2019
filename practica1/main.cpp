//******************************************************************************
// File:   main.cpp
// Author: Andrés Gavín Murillo 716358
// Author: Andrew Mackay 737069
// Date:   Marzo 2019
// Coms:   Algoritmia básica - Práctica 1
//******************************************************************************

#include <iostream>
#include <fstream>
//#include "heap.hpp"
#include "huffman.hpp"

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
vector<Arbol*> insertarFrecuencias(unsigned char frecuencia[N]) {

    vector<Arbol*> v;
    // Por cada elemento del vector, se crea un arbol con la frecuencia del 
    // elemento y el elemento en si, y lo inserta al heap "h"..
    for (int i=0; i<=N; i++) {
        cout << "Insertando frecuencia del caracter " << (unsigned char) i
             << ": " << (int) frecuencia[i] << endl;
        Arbol a(frecuencia[i], i);
        v.push_back(&a);
    }
    return v;
}

int main() {

    /*unsigned char frecuencia[N] = {0};
    contar("prueba1.txt", frecuencia);
    Heap h = insertarFrecuencias(frecuencia);*/


    /*Heap h;
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

    vector<Arbol*> v;

    Arbol f(5, 'f'), e(9, 'e'), c(12, 'c'), b(13, 'b'), d(16, 'd'), a(45, 'a');
    bool hoja = f.esHoja();
    v.push_back(&e);
    v.push_back(&f);
    v.push_back(&a);
    v.push_back(&c);
    v.push_back(&d);
    v.push_back(&b);
    */
    unsigned char frecuencia[N] = {0};
    contar("prueba1.txt", frecuencia);
    vector<Arbol*> v = insertarFrecuencias(frecuencia);
    Arbol *res = huffman(v);
    cout << "FIN" << endl;
    return 0;
}