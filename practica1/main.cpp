//******************************************************************************
// File:   main.cpp
// Author: Andrés Gavín Murillo 716358
// Author: Andrew Mackay 737069
// Date:   Marzo 2019
// Coms:   Algoritmia básica - Práctica 1
//******************************************************************************

#include <iostream>
#include <fstream>
//#include "heap.hpp"
#include "huffman.hpp"

using namespace std;

// N es el numero de caracteres que hay.
const int N=255;

/*
 * Devuelve un vector con el numero de apariciones de cada caracter en el 
 * fichero "nombreFichero".
 */
void contar(const char* nombreFichero, unsigned char (&frecuencia)[N]) {

    // "caracter" se usa para iterar sobre los caracteres del fichero. 
    // "frecuencias" es un vector de bytes, donde frecuencias[c] almacena
    // el numero de veces que ha aparecido el caracter "c" del fichero
    // "nombreFichero".
    unsigned char caracter;
    ifstream fichero(nombreFichero);

    for (int i=0; i<N; i++) {
        frecuencia[i] = 0;
    }

    // Se cuenta el numero de apariciones de cada caracter leido del fichero.
    while (fichero.good()) {
        caracter = fichero.get();
        frecuencia[(int) caracter]++;
    }
}

/*
 * Devuelve un heap en la que se han insertado los datos del vector 
 * "frecuencia".
 */
vector<Arbol*> insertarFrecuencias(unsigned char frecuencia[N]) {

    vector<Arbol*> v;
    // Por cada elemento del vector, se crea un arbol con la frecuencia del 
    // elemento y el elemento en si, y lo inserta al heap "h"..
    for (int i=0; i<=N; i++) {
        Arbol* a = new Arbol(frecuencia[i], i);
        v.push_back(a);
    }
    return v;
}

void crearTablaCodigos(Arbol *res, string (&codigos)[N], string codigo) {
    if (res->esHoja()) {
        codigos[res->obtenerByte()] = codigo;
    } else {
        Arbol *izdo = res->izdo();
        if (izdo != nullptr) {
            crearTablaCodigos(res->izdo(), codigos, codigo + "0");
        }
        Arbol *dcho = res->dcho();
        if (dcho != nullptr) {
            crearTablaCodigos(res->dcho(), codigos, codigo + "1");
        }
    }
}

void escribirTablaCodigos(string nombreFichero, string (codigos)[N]) {
    ofstream tablaCodigos;
    tablaCodigos.open(nombreFichero);

    for (int i=0; i<= N; i++) {
        tablaCodigos << codigos[i] << endl;
    }
    tablaCodigos.close();
}

void recuperarTablaCodigos(string nombreFichero, string (&codigos)[N]) {
    ifstream tablaCodigos(nombreFichero);
    char caracter;
    string codigo;
    for (int i=0; i<=N; i++) {
        tablaCodigos >> codigo;
        codigos[i] = codigo;
    }
}

// Simplemente para debuggear!
void mostrarTablaCodigos(string (codigos)[N]) {
    for (int i=0; i<=N; i++) {
        cout << "Codigo del caracter " << (char) i << ": " << codigos[i] << endl;
    }
}


void codificarTexto(string (codigos)[N], string ficheroEntrada, string ficheroSalida) {
    unsigned char caracter, binario;
    ifstream ficheroOriginal(ficheroEntrada);
    ofstream ficheroCodificado;
    ficheroCodificado.open(ficheroSalida, ios::binary);
    string codigo;
    int i=0, tamanyo = sizeof(unsigned char)*8, j=0, k=0;
    caracter = ficheroOriginal.get();
    while (!ficheroOriginal.eof()) {
        codigo = codigos[caracter];
        while (i < codigo.size()) {
            if (codigo[i] == '1') {
                binario |= 1;
            } else {
                binario &= 0;
            }
            binario <<= 1;
            if (j%tamanyo == tamanyo-1) {
                ficheroCodificado.write(reinterpret_cast<const char*>(&binario), 1);
                j = 0;
            }
            j++;
            i++;
        }
        caracter = ficheroOriginal.get();
        i = 0;
    }
    ficheroCodificado.write(reinterpret_cast<const char*>(&binario), 1);
    ficheroCodificado.close();
    ficheroOriginal.close();
}

void decodificarTexto(string (codigos)[N], string ficheroEntrada, string ficheroSalida) {
    unsigned char caracter;
    ifstream ficheroCodificado(ficheroEntrada);
    ofstream ficheroOriginal;
    ficheroOriginal.open(ficheroSalida, ios::binary);
    while (ficheroCodificado.good()) {
        // Obtener codigos y traducirlos.
    }
}

int main() {

    unsigned char frecuencia[N] = {0};
    contar("prueba1.txt", frecuencia);
    vector<Arbol*> v = insertarFrecuencias(frecuencia);
    Arbol *res = huffman(v);
    string codigos[N];
    crearTablaCodigos(res, codigos, "");
    mostrarTablaCodigos(codigos);
    escribirTablaCodigos("tablaCodigos.txt", codigos);
    codificarTexto(codigos, "prueba1.txt", "prueba1Cod");
    string codigosRecuperados[N];
    //recuperarTablaCodigos("tablaCodigos.txt", codigosRecuperados);
    //mostrarTablaCodigos(codigosRecuperados);

    return 0;
}