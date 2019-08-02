//*****************************************************************
// File:   arbol.hpp
// Author: Andrés Gavín Murillo 716358
// Author: Andrew Mackay 737069
// Date:   Agosto 2019
// Coms:   Algoritmia básica - Práctica 2
//*****************************************************************

#ifndef PRACTICA2_ARBOL_HPP
#define PRACTICA2_ARBOL_HPP


#include "pedido.hpp"

class Arbol {
private:
    Arbol *padre, *hijoI, *hijoD;
    bool x; // Cierto si se acepta el pedido y falso si se cancela
    Pedido *p; // Pedido correspondiente al nodo
    bool hoja; // Cierto si es un nodo hoja, en caso contrario falso
    bool fac; // Cierto si es fac, en caso contrario falso
    int b; // Beneficio
    int np[MAX_ESTACIONES]; // Número de pasajeros en cada estación, max. MAX_ESTACIONES estaciones

public:
    /* Pre: primero != NULL */
    Arbol(Pedido *primero); // Constructor raíz

    /* Pre: padre != NULL AND p != NULL */
    Arbol(Arbol *padre, bool x, Pedido *p, bool hoja); // Constructor no raíz, con pedido asociado

    /* Devuelve el hijo izquierdo. */
    Arbol* izdo() const;

    /* Devuelve el hijo derecho. */
    Arbol* dcho() const;

    /* Devuelve cierto si es un nodo hoja, y falso en otro caso. */
    bool esHoja() const;

    /* Expande el nodo creando a sus hijos. */
    void expandir();

    /* Función de coste c(x). */
    int coste() const;

    /* Función de coste estimado ĉ(x). */
    int costeEstimado() const;

    /* Devuelve el beneficio total de la rama hasta el nodo actual. */
    int beneficio() const;
};

/* Función de cota, que devuelve el beneficio estimado si se sigue expandiendo.
 *
 * pas: pasajeros en cada estación actualmente; ben: beneficio actual; p: primer pedido a considerar. */
int cota(const int pas[MAX_ESTACIONES], int ben, const Pedido *p);


#endif //PRACTICA2_ARBOL_HPP