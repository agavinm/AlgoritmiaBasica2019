//******************************************************************************
// File:   tren.cpp
// Author: Andrés Gavín Murillo 716358
// Author: Andrew Mackay 737069
// Date:   Agosto 2019
// Coms:   Algoritmia básica - Práctica 2
//******************************************************************************

#include "tren.hpp"
#include <iostream>

using namespace std;

Tren::Tren(const int n, const int m, const int p) : n(n), m(m), p(p) { // Constructor
    if (n < 0) {
        cerr << "Error: n > 0" << endl;
        exit(1);
    }
    if (m < 1 || m > MAX_ESTACIONES - 1) {
        cerr << "Error: 1 <= m <= " << MAX_ESTACIONES - 1 << endl;
        exit(1);
    }
    if (p < 1 || p > MAX_PEDIDOS) {
        cerr << "Error: 1 <= p <= " << MAX_PEDIDOS << endl;
        exit(1);
    }
}

/* Devuelve la capacidad máxima de pasajeros del tren. */
int Tren::maxPasajeros() const {
    return this->n;
}

/* Devuelve el número de estaciones del tren. */
int Tren::numEstaciones() const {
    return m+1;
}
