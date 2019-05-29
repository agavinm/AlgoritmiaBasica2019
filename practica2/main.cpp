//******************************************************************************
// File:   main.cpp
// Author: Andrés Gavín Murillo 716358
// Author: Andrew Mackay 737069
// Date:   Mayo 2019
// Coms:   Algoritmia básica - Práctica 2
//******************************************************************************

#include <fstream>
#include <iostream>
#include "arbol.hpp"

using namespace std;

int main(int argc, char *argv[]) {

    if (argc != 3) {
        cout << "Sintaxis del programa: ./main fichero_entrada fichero_salida" << endl;
        return 1;
    }

    ifstream fin (argv[1]);

    int n, m, p, entrada, salida, pasajeros, i=0;
    fin >> n >> m >> p;
    while ( !(n==0 && m==0 && p==0) ) {
        for (i=0; i<p; i++) {
            fin >> salida >> entrada >> pasajeros;
        }
        fin >> n >> m >> p;
    }
    return 0;
}