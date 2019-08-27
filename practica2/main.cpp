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

void resolverTren(Tren *tren) {
    tren->mostrar();
    Arbol* arbol = new Arbol(tren->primerPedido());
    Pedido* aux;
    while (!tren->vacio()) {
        aux = tren->primerPedido();
        arbol->establecerDcho(aux, false);
        arbol->establecerIzdo(aux, true);
        arbol = arbol->izdo();
    }
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
    resolverTren(trenes->primero());
/**
    while (!trenes->empty()) {
        resolverTren(trenes->front());
        trenes->pop();
    }
*/
    return 0;
}