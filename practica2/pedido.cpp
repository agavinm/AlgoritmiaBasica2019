//******************************************************************************
// File:   pedido.cpp
// Author: Andrés Gavín Murillo 716358
// Author: Andrew Mackay 737069
// Date:   Agosto 2019
// Coms:   Algoritmia básica - Práctica 2
//******************************************************************************

#include <iostream>
#include "pedido.hpp"

using namespace std;

Pedido::Pedido(const int es, const int el, const int np, Tren *tren) : // Constructor
        es(es), el(el), np(np), t(tren), sig(nullptr) {
    if (es < 0) {
        cerr << "Error: es >= 0" << endl;
        exit(1);
    }
    if (el >= MAX_ESTACIONES) {
        cerr << "Error: el < " << MAX_ESTACIONES << endl;
        exit(1);
    }
    if (np < 0) {
        cerr << "Error: np >= 0" << endl;
        exit(1);
    }
    if (tren == nullptr) {
        cerr << "Error: tren != NULL" << endl;
        exit(1);
    }

    this->b = (this->el - this->es) * this->np;
}

/* Se establece el pedido siguiente a este. */
void Pedido::establecerSiguiente(Pedido *siguiente) {
    this->sig = siguiente;
}

/* Devuelve el beneficio del pedido. */
int Pedido::beneficio() const {
    return this->b;
}

/* Devuelve el número de pasajeros del pedido. */
int Pedido::numPasajeros() const {
    return this->np;
}

/* Devuelve la estación de salida del pedido. */
int Pedido::estacionSalida() const {
    return this->es;
}

/* Devuelve la estación de llegada del pedido. */
int Pedido::estacionLlegada() const {
    return this->el;
}

/* Devuelve el pedido siguiente a este. */
Pedido *Pedido::siguiente() const {
    return this->sig;
}

/* Devuelve el tren correspondiente al pedido. */
Tren *Pedido::tren() const {
    return this->t;
}

/* Devuelve el coste estimado del pedido. */
int Pedido::costeEstimado() const {
    return -this->b;
}
