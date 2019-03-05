//*****************************************************************
// File:   arbol.hpp
// Author: Andrés Gavín Murillo 716358
// Author: Andrew Mackay
// Date:   Marzo 2019
// Coms:   Algoritmia básica - Práctica 1
//*****************************************************************

#ifndef PRACTICA1_ARBOL_HPP
#define PRACTICA1_ARBOL_HPP


class Arbol {
private:
    unsigned char frec; // clave: frecuencia (0-100)
    unsigned char byte; // valor: byte al que corresponde (sólo si es nodo hoja)
    Arbol *hijoI, *hijoD;

public:
    Arbol(Arbol &hijoIzquierdo, Arbol &hijoDerecho) : // Constructor del árbol con hijos
            frec(hijoIzquierdo.frecuencia() + hijoDerecho.frecuencia()), byte(0), hijoI(&hijoIzquierdo),
            hijoD(&hijoDerecho) {}

    Arbol(const unsigned char frecuencia, const unsigned char byte) : // Constructor del árbol hoja
            frec(frecuencia), byte(byte), hijoI(nullptr), hijoD(nullptr) {}

    ~Arbol() {
        delete hijoI;
        delete hijoD;
    }

    const unsigned char frecuencia();
};


#endif //PRACTICA1_ARBOL_HPP
