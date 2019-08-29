//******************************************************************************
// File:   main.cpp
// Author: Andrés Gavín Murillo 716358
// Author: Andrew Mackay 737069
// Date:   Agosto 2019
// Coms:   Algoritmia básica - Práctica 2
//******************************************************************************

#include <fstream>
#include <iostream>
#include "tren.hpp"
#include "heap.hpp"
#include "pedido.hpp"
#include "arbol.hpp"
#include <queue>

using namespace std;

double resolverTren(Tren *tren) {
    Heap<Arbol>* vivos = new Heap<Arbol>();
    Heap<Arbol>* hojas = new Heap<Arbol>();
    Arbol* arbol = new Arbol(tren->obtenerCapacidad(), tren->obtenerPrimerPedido());
    vivos->insertar(arbol);
    while (!vivos->vacio()) {
        arbol = vivos->primero();
        arbol->expandir();
        if (arbol->izdo()->esFactible()) {
            if (arbol->izdo()->esHoja()) {
                hojas->insertar(arbol->izdo());
            } else {
                vivos->insertar(arbol->izdo());
            }
        }
        if (arbol->dcho()->esFactible()) {
            if (arbol->dcho()->esHoja()) {
                hojas->insertar(arbol->dcho());
            } else {
                vivos->insertar(arbol->dcho());
            }
        }
    }
    
    return -hojas->primero()->beneficio();
}

int main(int argc, char *argv[]) {

    if (argc != 3) {
        cout << "Sintaxis del programa: ./main fichero_entrada fichero_salida" << endl;
        return 1;
    }
    Heap<Tren> *trenes = new Heap<Tren>;
    ifstream fin (argv[1]);
    int n, m, p, entrada, salida, pasajeros, i=0;
    fin >> n >> m >> p;
    Tren *tren = new Tren();
    while ( !(n==0 && m==0 && p==0) ) {
        tren->iniciarTren(n, m, p);
        for (i=0; i<p; i++) {
            fin >> salida >> entrada >> pasajeros;            
            tren->insertarPedido(new Pedido(salida, entrada, pasajeros));
        }
        trenes->insertar(tren);
        tren = new Tren();
        fin >> n >> m >> p;
    }
    cout << resolverTren(trenes->primero()) << endl;
/**
    while (!trenes->empty()) {
        resolverTren(trenes->front());
        trenes->pop();
    }
*/
    return 0;
}