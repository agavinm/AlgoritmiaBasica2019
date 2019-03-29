//*****************************************************************
// File:   arbol.hpp
// Author: Andrés Gavín Murillo 716358
// Author: Andrew Mackay 737069
// Date:   Marzo 2019
// Coms:   Algoritmia básica - Práctica 1
//*****************************************************************

#ifndef PRACTICA1_ARBOL_HPP
#define PRACTICA1_ARBOL_HPP


class Arbol {
private:
    unsigned char frec; // clave: frecuencia (0-100)
    bool hoja; // true si es árbol hoja; false en caso contrario
    unsigned char byte; // valor: byte al que corresponde (sólo si es nodo hoja)
    Arbol *hijoI, *hijoD;

public:
    Arbol(Arbol &hijoIzquierdo, Arbol &hijoDerecho) : // Constructor del árbol con hijos
            frec(hijoIzquierdo.frecuencia() + hijoDerecho.frecuencia()), hoja(false), byte(0), hijoI(&hijoIzquierdo),
            hijoD(&hijoDerecho) {}

    Arbol(const unsigned char frecuencia, const unsigned char byte) : // Constructor del árbol hoja
            frec(frecuencia), hoja(true), byte(byte), hijoI(nullptr), hijoD(nullptr) {}

    unsigned char frecuencia() const;

    unsigned char obtenerByte() const;

    bool esHoja() const;
};


#endif //PRACTICA1_ARBOL_HPP
