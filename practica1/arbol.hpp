//*****************************************************************
// File:   arbol.hpp
// Author: Andrés Gavín Murillo 716358
// Author: Andrew Mackay 737069
// Date:   Mayo 2019
// Coms:   Algoritmia básica - Práctica 1
//*****************************************************************

#ifndef PRACTICA1_ARBOL_HPP
#define PRACTICA1_ARBOL_HPP

#include <fstream>
#include <queue>


class Arbol {
private:
    unsigned long frec; // clave: frecuencia
    bool hoja; // true si es árbol hoja; false en caso contrario
    unsigned char byte; // valor: byte al que corresponde (sólo si es nodo hoja)
    Arbol *hijoI, *hijoD;

    /* Dado un fichero file, guarda las frecuencias del árbol en dicho fichero y devuelve carácteres que contiene los
     * nodos hoja ordenados según se han guardado en el fichero. Además avanza el iterador hasta donde se ha leido. */
    void guardarFrecuencias(std::ofstream &file, std::queue<unsigned char> &caracteres) const;

    /* Si b es cierto, convierte el árbol en hoja. */
    void setHoja(unsigned char b);

    /* Dado un fichero file, donde se ha almacenado un árbol mediante la función guardar() y ya se han leído la
     * frecuencias y están en la cola frecuencias, devuelve el árbol p que estaba almacenado en el fichero. */
    Arbol* leerFrecuencias(std::ifstream &file, std::queue<unsigned long> &frecuencias, Arbol *const p);

    explicit Arbol(unsigned long frecuencia) : // Constructor intermedio, el árbol no es válido
            frec(frecuencia), hoja(false), byte(0), hijoI(nullptr), hijoD(nullptr) {}

public:
    Arbol(Arbol &hijoIzquierdo, Arbol &hijoDerecho) : // Constructor del árbol con hijos
            frec(hijoIzquierdo.frecuencia() + hijoDerecho.frecuencia()), hoja(false), byte(0), hijoI(&hijoIzquierdo),
            hijoD(&hijoDerecho) {}

    Arbol(const unsigned long frecuencia, const unsigned char byte) : // Constructor del árbol hoja
            frec(frecuencia), hoja(true), byte(byte), hijoI(nullptr), hijoD(nullptr) {}

    explicit Arbol(std::ifstream &file); // Constructor del árbol desde el fichero generado por la función guardar

    /* Devuelve el hijo izquierdo. */
    Arbol* izdo() const;

    /* Devuelve el hijo derecho. */
    Arbol* dcho() const;

    /* Devuelve la frecuencia. */
    unsigned long frecuencia() const;

    /* Devuelve el byte. */
    unsigned char obtenerByte() const;

    /* Devuelve cierto si es hoja, falso en caso contrario. */
    bool esHoja() const;

    /* Dado un fichero file, guarda el árbol en dicho fichero. */
    void guardar(std::ofstream &file) const;
};


#endif //PRACTICA1_ARBOL_HPP
