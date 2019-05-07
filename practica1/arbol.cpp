//*****************************************************************
// File:   arbol.cpp
// Author: Andrés Gavín Murillo 716358
// Author: Andrew Mackay 737069
// Date:   Mayo 2019
// Coms:   Algoritmia básica - Práctica 1
//*****************************************************************

#include "arbol.hpp"

using namespace std;

/* Devuelve la frecuencia. */
unsigned long Arbol::frecuencia() const {
    return this->frec;
}

/* Devuelve el byte. */
unsigned char Arbol::obtenerByte() const {
    return this->byte;
}

/* Devuelve cierto si es hoja, falso en caso contrario. */
bool Arbol::esHoja() const {
    return this->hoja;
}

/* Devuelve el hijo izquierdo. */
Arbol* Arbol::izdo() const {
    return this->hijoI;
}

/* Devuelve el hijo derecho. */
Arbol* Arbol::dcho() const {
    return this->hijoD;
}

/* Dado un fichero file, guarda las frecuencias del árbol en dicho fichero y devuelve carácteres que contiene los
 * nodos hoja ordenados según se han guardado en el fichero. Además avanza el iterador hasta donde se ha leido. */
void Arbol::guardarFrecuencias(ofstream &file, queue<unsigned char> &caracteres) const {
    file.write(reinterpret_cast<const char *>(&this->frec), sizeof(this->frec));

    if (this->esHoja()) {
        caracteres.push(this->byte);
    }

    if (this->hijoI != nullptr) {
        this->hijoI->guardarFrecuencias(file, caracteres);
    }
    else {
        unsigned long nulo = 0;
        file.write(reinterpret_cast<const char *>(&nulo), sizeof(this->frec));
    }

    if (this->hijoD != nullptr) {
        this->hijoD->guardarFrecuencias(file, caracteres);
    }
}

/* Dado un fichero file, guarda el árbol en dicho fichero. */
void Arbol::guardar(ofstream &file) const {
    if (file.is_open()) {
        queue<unsigned char> caracteres;
        guardarFrecuencias(file, caracteres);

        unsigned long nulo = 0;
        file.write(reinterpret_cast<const char *>(&nulo), sizeof(this->frec));

        unsigned char c;
        while (!caracteres.empty()) {
            c = caracteres.front();
            caracteres.pop();
            file.write(reinterpret_cast<const char *>(&c), sizeof(this->byte));
        }
    }
}

/* Si b es cierto, convierte el árbol en hoja. */
void Arbol::setHoja(unsigned char b) {
    this->hoja = true;
    this->byte = b;
}

/* Dado un fichero file, donde se ha almacenado un árbol mediante la función guardar() y ya se han leído la
 * frecuencias y están en la cola frecuencias, devuelve el árbol p que estaba almacenado en el fichero. */
Arbol* Arbol::leerFrecuencias(std::ifstream &file, std::queue<unsigned long> &frecuencias, Arbol *const p) {
    Arbol *a = nullptr;

    if (!frecuencias.empty()) {
        unsigned long frecuencia = frecuencias.front();
        frecuencias.pop();

        if (frecuencia != 0) {
            a = new Arbol(frecuencia);
            if (p != nullptr) {
                if (p->hijoI == nullptr) {
                    p->hijoI = a;
                } else {
                    p->hijoD = a;
                }
            }

            if (frecuencias.front() == 0) { // Es una hoja
                frecuencias.pop();
                unsigned char caracter;
                file.read(reinterpret_cast<char *>(&caracter), sizeof(this->byte));
                a->setHoja(caracter);
            }
            else {
                leerFrecuencias(file, frecuencias, a); // Hijo izquierdo
                leerFrecuencias(file, frecuencias, a); // Hijo derecho
            }
        }
    }

    return a;
}

Arbol::Arbol(ifstream &file) {
    if (file.is_open()) {
        queue<unsigned long> frecuencias;
        unsigned long frecuencia;
        bool nulo = false, fin = false;

        // Leer frecuencias
        while (!nulo || !fin) {
            file.read(reinterpret_cast<char *>(&frecuencia), sizeof(this->frec));
            frecuencias.push(frecuencia);

            if (frecuencia == 0) {
                if (nulo)
                    fin = true;
                else
                    nulo = true;
            }
            else {
                nulo = false;
            }
        }

        Arbol *a = nullptr;
        a = leerFrecuencias(file, frecuencias, a);

        if (a != nullptr) {
            this->frec = a->frec;
            this->byte = a->byte;
            this->hoja = a->hoja;
            this->hijoI = a->hijoI;
            this->hijoD = a->hijoD;
        }
        else {
            this->frec = -1;
            this->byte = 0;
            this->hoja = false;
            this->hijoI = nullptr;
            this->hijoD = nullptr;
        }
    }
}
