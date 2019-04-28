//*****************************************************************
// File:   arbol.cpp
// Author: Andrés Gavín Murillo 716358
// Author: Andrew Mackay 737069
// Date:   Marzo 2019
// Coms:   Algoritmia básica - Práctica 1
//*****************************************************************

#include "arbol.hpp"

unsigned char Arbol::frecuencia() const {
    return this->frec;
}

unsigned char Arbol::obtenerByte() const {
    return this->byte;
}

bool Arbol::esHoja() const {
    return this->hoja;
}

Arbol* Arbol::izdo() {
    return this->hijoI;
}

Arbol* Arbol::dcho() {
    return this->hijoD;
}
