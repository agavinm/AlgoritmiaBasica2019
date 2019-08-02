//******************************************************************************
// File:   pedido.hpp
// Author: Andrés Gavín Murillo 716358
// Author: Andrew Mackay 737069
// Date:   Agosto 2019
// Coms:   Algoritmia básica - Práctica 2
//******************************************************************************

#ifndef PRACTICA2_PEDIDO_HPP
#define PRACTICA2_PEDIDO_HPP


#include "tren.hpp"

class Pedido {
private:
    int es; // Estación de salida (mín. 0)
    int el; // Estación de llegada (máx. MAX_ESTACIONES - 1)
    int np; // Número de pasajeros
    int b; // Beneficio
    Tren *t; // Tren
    Pedido *sig; // Pedido siguiente

public:
    Pedido(int es, int el, int np, Tren *tren); // Constructor

    /* Se establece el pedido siguiente a este. */
    void establecerSiguiente(Pedido *siguiente);

    /* Devuelve el beneficio del pedido. */
    int beneficio() const;

    /* Devuelve el número de pasajeros del pedido. */
    int numPasajeros() const;

    /* Devuelve la estación de salida del pedido. */
    int estacionSalida() const;

    /* Devuelve la estación de llegada del pedido. */
    int estacionLlegada() const;

    /* Devuelve el pedido siguiente a este. */
    Pedido *siguiente() const;

    /* Devuelve el tren correspondiente al pedido. */
    Tren *tren() const;

    /* Devuelve el coste estimado del pedido. */
    int costeEstimado() const;
};


#endif //PRACTICA2_PEDIDO_HPP
