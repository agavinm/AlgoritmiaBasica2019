//******************************************************************************
// File:   main.cpp
// Author: Andrés Gavín Murillo 716358
// Author: Andrew Mackay 737069
// Date:   Agosto 2019
// Coms:   Algoritmia básica - Práctica 2
//******************************************************************************

#include <fstream>
#include <iostream>
#include <iomanip>
#include <chrono>
#include "heap.hpp"
#include "arbol.hpp"

using namespace std;

/* Resuelve el bloque de pedidos cuyo primer pedido es primero. */
int resolverBloque(Pedido *primero) {
    Heap<Arbol> nodos, soluciones; // Heap de mínimos, para expandir siempre el nodo con mayor beneficio, hasta llegar a una hoja
    int u = 0; // u: Valor de la función de poda
    Arbol *a = new Arbol(primero); // Árbol de exploración

    nodos.insertar(a);
    while (!nodos.esVacio()) {
        a = nodos.primero();
        if (!a->esHoja()) {
            a->expandir();
            if (a->izdo()->costeEstimado() <= u) {
                u = -a->izdo()->beneficio(); // Se actualiza el valor de la función de poda
                nodos.insertar(a->izdo());
            }
            if (a->dcho()->costeEstimado() <= u) {
                u = -a->dcho()->beneficio(); // Se actualiza el valor de la función de poda
                nodos.insertar(a->dcho());
            }
        }
        else {
            soluciones.insertar(a);
        }
    }

    a = soluciones.primero();
    if (!a->esHoja()) {
        return 0; // No hay ninguna solución factible
    }
    else {
        return a->beneficio();
    }
}

/* Procesa el fichero de entrada fin y resuelve cada bloque guardando las soluciones en el fichero de salida fout.
 *
 * Pre: fin.is_open() AND fout.is_open() */
void procesarFicheros(ifstream &fin, ofstream &fout) {
    int n, m, p, es, el, np; // n: Capacidad del tren; m: Número de estación final; p: Número de pedidos;
                             // es: Estación de salida; el: Estación de llegada; np: Número de pasajeros
    Tren *tren;
    Pedido *primero, *auxAntes, *aux;
    Heap<Pedido> h; // Heap de mínimos, para ordenar los pedidos por beneficio
    chrono::time_point<chrono::system_clock> tiempo; // Tiempo actual
    chrono::duration<double> segundos{};

    fin >> n >> m >> p;
    while (n != 0 || m != 0 || p != 0) {
        if (p == 0) {
            fout << 0 << " " << 0.0 << endl;
        }
        else if (n == 0) {
            for (int i = 0; i < p; i++) {
                fin >> es >> el >> np;
            }
            fout << 0 << " " << 0.0 << endl;
        }
        else {
            tiempo = chrono::system_clock::now(); // Tiempo actual

            tren = new Tren(n, m, p);
            for (int i = 0; i < p; i++) {
                fin >> es >> el >> np;
                h.insertar(new Pedido(es, el, np, tren)); // Para ordenar los pedidos
            }

            primero = h.primero();
            auxAntes = primero;
            while (!h.esVacio()) {
                aux = h.primero();
                auxAntes->establecerSiguiente(aux);
                auxAntes = aux;
            }

            segundos = chrono::system_clock::now() - tiempo; // Tiempo de ejecución

            fout << resolverBloque(primero) << " " << segundos.count() << endl;
        }

        fin >> n >> m >> p;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        cout << "Sintaxis del programa: ./transporte fichero_entrada fichero_salida" << endl;
        return 1;
    }

    ifstream fin (argv[1]);
    if (fin.is_open()) {
        ofstream fout (argv[2]);
        if (fout.is_open()) {
            fout << fixed << setprecision(6);
            procesarFicheros(fin, fout);
        }
        else {
            cerr << "Error: El fichero " << argv[2] << " no se puede escribir." << endl;
            return 1;
        }
    }
    else {
        cerr << "Error: El fichero " << argv[1] << " no existe." << endl;
        return 1;
    }

    return 0;
}