//******************************************************************************
// File:   main.cpp
// Author: Andrés Gavín Murillo 716358
// Author: Andrew Mackay 737069
// Date:   Mayo 2019
// Coms:   Algoritmia básica - Práctica 2
//******************************************************************************

#include <fstream>
#include <iostream>
#include "tren.hpp"
#include <queue>

using namespace std;

int main(int argc, char *argv[]) {

    if (argc != 3) {
        cout << "Sintaxis del programa: ./main fichero_entrada fichero_salida" << endl;
        return 1;
    }
    queue<Tren*> *trenes = new queue<Tren*>;
    ifstream fin (argv[1]);
    int n, m, p, entrada, salida, pasajeros, i=0;
    fin >> n >> m >> p;
    Tren *tren = new Tren();
    while ( !(n==0 && m==0 && p==0) ) {
        tren->iniciarTren(n, m, p);
        for (i=0; i<p; i++) {
            fin >> salida >> entrada >> pasajeros;            
            tren->insertarPedido(make_tuple(salida, entrada, pasajeros));
        }
        trenes->push(tren);
        fin >> n >> m >> p;
    }

    return 0;
}