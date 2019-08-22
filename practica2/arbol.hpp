//*****************************************************************
// File:   arbol.hpp
// Author: Andrés Gavín Murillo 716358
// Author: Andrew Mackay 737069
// Date:   Mayo 2019
// Coms:   Algoritmia básica - Práctica 2
//*****************************************************************

#ifndef PRACTICA1_ARBOL_HPP
#define PRACTICA1_ARBOL_HPP

#include <fstream>
#include <queue>
#include "pedido.hpp"


class Arbol {

private:

    Arbol *hijoI, *hijoD;
    Pedido p;

public:
    Arbol(Arbol &hijoIzquierdo, Arbol &hijoDerecho) : // Constructor del árbol con hijos
            hijoI(&hijoIzquierdo),
            hijoD(&hijoDerecho) {}

    /* Devuelve el hijo izquierdo. */
    Arbol* izdo() const;

    /* Devuelve el hijo derecho. */
    Arbol* dcho() const;
    
};


#endif //PRACTICA2_ARBOL_HPP