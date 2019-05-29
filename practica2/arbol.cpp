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

