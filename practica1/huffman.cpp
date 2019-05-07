//*****************************************************************
// File:   huffman.cpp
// Author: Andrés Gavín Murillo 716358
// Author: Andrew Mackay 737069
// Date:   Mayo 2019
// Coms:   Algoritmia básica - Práctica 1
//*****************************************************************

#include <fstream>
#include <bitset>
#include <queue>
#include <vector>
#include "huffman.hpp"
#include "arbol.hpp"
#include "heap.hpp"

using namespace std;

/* Dado un fichero file y N el número de carácteres posibles, devuelve una cola de árboles hoja, donde cada hoja
 * contiene su símbolo y su frecuencia */
void calcularFrecuencias(std::ifstream &file, queue<Arbol*> &caracteres, const unsigned int N) {
    if (file.is_open()) {
        unsigned char caracter;
        unsigned long frecuencias[N];
        for (unsigned long &frecuencia : frecuencias) {
            frecuencia = 0;
        }

        // Calcular frecuencias
        while (file.read(reinterpret_cast<char *>(&caracter), sizeof(caracter))) {
            frecuencias[caracter]++;
        }

        caracter = 0;
        for (unsigned long &frecuencia : frecuencias) {
            if (frecuencia > 0) {
                caracteres.push(new Arbol(frecuencia, caracter));
            }
            caracter++;
        }
    }
}

/* Dada una cola de árboles hoja c, donde cada hoja contiene su símbolo y su frecuencia, devuelve el árbol
 * lexicográfico de un código libre de prefijos óptimo resultante de aplicar el algoritmo de Huffman. */
Arbol* huffman(queue<Arbol*> &c) {
    /* Paso 1: Crear heap de los árboles hoja de v.
     * Paso 2: Aplicar algoritmo de Huffman.
     * Paso 3: Devolver el único árbol que contiene el heap. */
    Heap q;
    Arbol *z, *x, *y;
    int tam = c.size();

    // Paso 1
    while (!c.empty()) {
        x = c.front();
        c.pop();
        q.insertar(*x);
    }

    // Paso 2
    for (int i=1; i<tam; i++) {
        x = q.primero();
        y = q.primero();
        z = new Arbol(*x, *y);
        q.insertar(*z);
    }

    // Paso 3
    z = q.primero();
    return z;
}

/* Dado un árbol lexicográfico a de un código libre de prefijos y un vector vacío acumulados, devuelve la tabla de
 * codificación tabla. */
void tablaCodificacion(const Arbol *const a, vector<vector<bool>*> &tabla, vector<bool> &acumulados) {
    if (a != nullptr) {
        if (a->esHoja()) {
            tabla[a->obtenerByte()] = new vector<bool> (acumulados);
        }
        else {
            acumulados.push_back(false); // false = 0
            tablaCodificacion(a->izdo(), tabla, acumulados);
            acumulados.pop_back();

            acumulados.push_back(true); // true = 1
            tablaCodificacion(a->dcho(), tabla, acumulados);
            acumulados.pop_back();
        }
    }
}

/* Dado el nombre de un fichero nombreFichero, genera un fichero nombreFichero.huf comprimido mediante el algoritmo
 * de Huffman.
 * El fichero tiene el siguiente formato:
 *      1º: Árbol lexicográfico de código libre.
 *      2º: Símbolos codificados.
 *      3º: Número de símbolos descolocados en el anterior byte. */
void comprimir(const char *nombreFichero) {
    // Obtener frecuencias
    const unsigned int N = 256; // Número de caracteres posibles
    ifstream fin (nombreFichero, ios::binary);
    queue<Arbol*> q;
    calcularFrecuencias(fin, q, N);
    fin.close();

    // Obtener arbol de huffman
    Arbol *a = huffman(q);

    // Obtener tabla de codificación
    vector<vector<bool>*> tabla(N, nullptr);
    vector<bool> acumulados;
    tablaCodificacion(a, tabla, acumulados);

    // Guardar arbol de huffman
    string nombreFout(nombreFichero);
    nombreFout.append(".huf");
    ofstream fout (nombreFout.c_str(), ios::binary);
    a->guardar(fout);

    // Comprimir fichero
    fin.open(nombreFichero, ios::binary);
    queue<bool> byte;
    vector<bool> *codigo;
    unsigned char caracter, numBit;
    while (fin.read(reinterpret_cast<char *>(&caracter), sizeof(caracter))) {
        codigo = tabla[caracter];

        for (bool b : *codigo) {
            byte.push(b);
            if (byte.size() == 8) { // 1 byte (char) = 8 bits
                caracter = 0;
                numBit = 0;
                while (!byte.empty()) {
                    if (byte.front()) { // true = 1
                        caracter |= 1 << numBit;
                    }
                    byte.pop();
                    numBit++;
                }
                fout.write(reinterpret_cast<char *>(&caracter), sizeof(caracter));
            }
        }
    }

    // Indicar los bits que se han quedado sueltos (no llegan a 1 byte)
    unsigned char sueltos = byte.size();
    if (sueltos > 0) {
        caracter = 0;
        while (!byte.empty()) {
            caracter = 0;
            numBit = 8-sueltos;
            while (!byte.empty()) {
                if (byte.front()) { // true = 1
                    caracter |= 1 << numBit;
                }
                byte.pop();
                numBit++;
            }
        }
        fout.write(reinterpret_cast<char *>(&caracter), sizeof(caracter)); // Escribir los últimos bits
    }
    fout.write(reinterpret_cast<char *>(&sueltos), sizeof(sueltos)); // Escribir el número de bits sueltos

    fin.close();
    fout.close();
}

/* Dado el nombre de un fichero comprimido (mediante la función comprimir()) nombreFichero = nombre.huf, genera el
 * fichero original nombre. */
void descomprimir(const char *nombreFichero) {
    // Obtener arbol de huffman
    ifstream fin (nombreFichero, ios::binary);
    Arbol *a = new Arbol(fin);

    // Descomprimir fichero
    string nombreFout(nombreFichero);
    nombreFout.erase(nombreFout.size()-4, 4);
    ofstream fout (nombreFout.c_str(), ios::binary);
    unsigned char caracter, caracterSiguiente, caracterSiguienteSiguiente, caracterAux, numBit;
    Arbol *aux = a;

    if (fin.read(reinterpret_cast<char *>(&caracter), sizeof(caracter))) {
        if (fin.read(reinterpret_cast<char *>(&caracterSiguiente), sizeof(caracterSiguiente))) {
            while (fin.read(reinterpret_cast<char *>(&caracterSiguienteSiguiente), sizeof(caracterSiguienteSiguiente))) {
                numBit = 0;
                while (numBit<8) {
                    if (((caracter >> numBit) & 1) == 1) {
                        aux = aux->dcho();
                    }
                    else {
                        aux = aux->izdo();
                    }

                    if (aux->esHoja()) {
                        caracterAux = aux->obtenerByte();
                        fout.write(reinterpret_cast<char *>(&caracterAux), sizeof(caracterAux));
                        aux = a;
                    }

                    numBit++;
                }

                caracter = caracterSiguiente;
                caracterSiguiente = caracterSiguienteSiguiente;
            }
            numBit = 8-caracterSiguiente;
            while (numBit<8) {
                if (((caracter >> numBit) & 1) == 1) {
                    aux = aux->dcho();
                }
                else {
                    aux = aux->izdo();
                }

                if (aux->esHoja()) {
                    caracterAux = aux->obtenerByte();
                    fout.write(reinterpret_cast<char *>(&caracterAux), sizeof(caracterAux));
                    aux = a;
                }

                numBit++;
            }
        }
    }

    fin.close();
    fout.close();
}