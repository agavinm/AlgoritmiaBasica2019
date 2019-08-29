//*****************************************************************
// File:   arbol.cpp
// Author: Andrés Gavín Murillo 716358
// Author: Andrew Mackay 737069
// Date:   Mayo 2019
// Coms:   Algoritmia básica - Práctica 2
//*****************************************************************

#include "arbol.hpp"

using namespace std;

Arbol::Arbol(int capacidad, Pedido* primerPedido) : capacidad(capacidad), pedido(primerPedido) {
    this->estimacionActual = this->cota(capacidad, 0, primerPedido);
    this->podaActual = -this->poda(0, 0, primerPedido);
}

Arbol::Arbol(int capacidad, Pedido* pedido, double nuevaPoda, double nuevaEstimacion, bool coger, double nuevoBeneficio, int nuevoPeso, bool hoja) : capacidad(capacidad), pedido(pedido), podaActual(nuevaPoda), estimacionActual(nuevaEstimacion), coger(coger), beneficioActual(nuevoBeneficio), pesoActual(nuevoPeso), hoja(hoja) {}


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
    if (pedido == nullptr) {
        this->hijoD = new Arbol(this->capacidad, pedido, podaActual, estimacionActual, false, this->beneficio(), this->pesoActual, true);
        this->hijoI = new Arbol(this->capacidad, pedido, podaActual, estimacionActual, true, this->beneficio(), this->pesoActual, true);
    } else {
        int nuevaEstimacion = -this->cota(this->capacidad-pesoActual, this->beneficioActual, pedido->obtenerSiguiente());
        int nuevaPoda = this->poda(this->pesoActual, -this->beneficioActual, pedido->obtenerSiguiente());
        this->hijoD = new Arbol(this->capacidad, pedido, nuevaPoda, nuevaEstimacion, false, pedido->beneficio(), this->pesoActual, false);
        this->hijoI = new Arbol(this->capacidad, pedido, nuevaPoda, nuevaEstimacion, true, pedido->beneficio(), this->pesoActual + pedido->obtenerPasajeros(), false);
    }
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
        pedido = pedido->obtenerSiguiente();
    }
    return poda;
}

bool Arbol::fin() {
    return this->pedido == nullptr;
}

bool Arbol::esFactible() {
    return this->capacidad >= this->pesoActual;
}

double Arbol::beneficio() {
    return this->beneficioActual;
}

bool Arbol::esHoja() {
    return this->hoja;
}


