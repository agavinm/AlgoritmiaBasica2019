//*****************************************************************
// File:   arbol.hpp
// Author: Andrés Gavín Murillo 716358
// Author: Andrew Mackay 737069
// Date:   Mayo 2019
// Coms:   Algoritmia básica - Práctica 2
//*****************************************************************

#ifndef ARBOL_HPP
#define ARBOL_HPP

#include <fstream>
#include <queue>
#include "pedido.hpp"


class Arbol {

private:

    Arbol *hijoI, *hijoD;
    Pedido* pedido;
    int beneficioActual;
    int pesoActual;
    int capacidad;
    bool coger;
    double podaActual;
    double estimacionActual;

public:

    /* Raiz */
    Arbol(int capacidad, Pedido* primerPedido) : capacidad(capacidad), pedido(primerPedido) {
        this->estimacionActual = -this->cota(capacidad, 0, primerPedido);
        this->podaActual = -this->poda(0, 0, primerPedido);

    }

    Arbol(int capacidad, Pedido* pedido, double podaActual, double estimacionActual, bool coger, int beneficioActual) : capacidad(capacidad), pedido(pedido), podaActual(podaActual), estimacionActual(estimacionActual), coger(coger), beneficioActual(beneficioActual) {}

    /* Devuelve el hijo izquierdo. */
    Arbol* izdo() const;

    /* Devuelve el hijo derecho. */
    Arbol* dcho() const;

    void expandir(Pedido* siguiente);

    double cota(int capacidadRestante, double beneficioActual, Pedido* pedido);
    double poda(int pesoActual, double podaFacil, Pedido* pedido);

};


#endif //PRACTICA2_ARBOL_HPP