//*****************************************************************
// File:   tren.cpp
// Author: Andrés Gavín Murillo 716358
// Author: Andrew Mackay 737069
// Date:   Mayo 2019
// Coms:   Algoritmia básica - Práctica 2
//*****************************************************************

#include "tren.hpp"
#include <string>
#include <iostream>

using namespace std;

void Tren::iniciarTren (int n, int m, int p) {
    this->n = n;
    this->m = m;
    this->p = p;
}

void Tren::insertarPedido(Pedido* pedido) {
    this->pedidos.insertar(pedido);
}

void Tren::mostrar() {
    cout << "Capacidad: " << this->n << endl;
    cout << "Estaciones: " << this->m << endl;
    cout << "Pedidos: " << this->p << endl;
    int i = 1;
    Heap<Pedido> aux = this->pedidos;
    Pedido* pedido = aux.primero();
    while(pedido != nullptr) {
        cout << i << "- " << pedido->obtenerCapacidad() << " " << pedido->obtenerParadas() << " " << pedido->obtenerPedidos() << endl;
        pedido = aux.primero();
        i++;
    }
}

int Tren::beneficio() {
    return 1;
}

Pedido* Tren::primerPedido() {
    return this->pedidos.primero();
}

bool Tren::vacio() {
    return this->pedidos.vacio();
}
