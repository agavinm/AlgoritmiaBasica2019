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
    bool coger;

public:

    Arbol(Pedido* pedido) : pedido(pedido), coger(true) {}

    Arbol(Pedido* pedido, bool coger) : pedido(pedido), coger(coger) {}

    Arbol(Arbol &hijoIzquierdo, Arbol &hijoDerecho) : // Constructor del árbol con hijos
            hijoI(&hijoIzquierdo),
            hijoD(&hijoDerecho) {}

    /* Devuelve el hijo izquierdo. */
    Arbol* izdo() const;

    /* Devuelve el hijo derecho. */
    Arbol* dcho() const;

    void establecerDcho(Pedido* pedido, bool coger);
    
    void establecerIzdo(Pedido* pedido, bool coger) ;

};


#endif //PRACTICA2_ARBOL_HPP