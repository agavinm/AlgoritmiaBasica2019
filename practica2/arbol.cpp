//*****************************************************************
// File:   arbol.cpp
// Author: Andrés Gavín Murillo 716358
// Author: Andrew Mackay 737069
// Date:   Mayo 2019
// Coms:   Algoritmia básica - Práctica 2
//*****************************************************************

#include "arbol.hpp"

using namespace std;

/* Devuelve el hijo izquierdo. */
Arbol* Arbol::izdo() const {
    return this->hijoI;
}

/* Devuelve el hijo derecho. */
Arbol* Arbol::dcho() const {
    return this->hijoD;
}

void Arbol::expandir() {
    Pedido* pedido = this->pedido->obtenerSiguiente();
    int nuevaEstimacion = -this->cota(this->capacidad-pesoActual, this->beneficioActual, pedido->obtenerSiguiente());
    int nuevaPoda = this->poda(this->pesoActual, -this->beneficioActual, pedido->obtenerSiguiente());


} 

double Arbol::cota(int capacidadRestante, double beneficioActual, Pedido* pedido) {
    if (pedido == nullptr || capacidadRestante == 0) {
        return beneficioActual;
    } else {
        if (pedido->obtenerPasajeros() > capacidadRestante) {
            return beneficioActual + (capacidadRestante/pedido->obtenerPasajeros()*pedido->beneficio());
        } else {
            return this->cota(this->capacidad-pedido->obtenerPasajeros(), beneficioActual + pedido->beneficio(), pedido->obtenerSiguiente());
        }
    }
}

double Arbol::poda(int pesoActual, double podaFacil, Pedido* pedido) {
    int peso = pesoActual;
    double poda = podaFacil; 
    while (pedido != nullptr) {
        if (peso + pedido->obtenerPasajeros() <= this->capacidad) {
            peso += pedido->obtenerPasajeros();
            poda -= pedido->beneficio();
        }
    }
    return poda;
}

bool Arbol::fin() {
    return this->pedido == nullptr;
}


