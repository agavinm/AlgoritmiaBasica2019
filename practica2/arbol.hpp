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
#include <iostream>


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
    bool hoja;

public:

    /* Raiz */
    Arbol(int capacidad, Pedido* primerPedido);

    Arbol(int capacidad, Pedido* pedido, double nuevaPoda, double nuevaEstimacion, bool coger, double nuevoBeneficio, int nuevoPeso, bool hoja);

    /* Devuelve el hijo izquierdo. */
    Arbol* izdo() const;

    /* Devuelve el hijo derecho. */
    Arbol* dcho() const;

    void expandir();

    bool fin();

    double cota(int capacidadRestante, double beneficioActual, Pedido* pedido);
    double poda(int pesoActual, double podaFacil, Pedido* pedido);

    bool esFactible();

    double beneficio();

    bool esHoja();

};


#endif //PRACTICA2_ARBOL_HPP