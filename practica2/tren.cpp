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

int Tren::obtenerCapacidad() {
    return this->n;
}

int Tren::obtenerEstaciones() {
    return this->m;
}

int Tren::obtenerPedidos() {
    return this->p;
}

void Tren::insertarPedido(Pedido* pedido) {
    pedido->anyadirSiguiente(this->primerPedido);
    this->primerPedido = pedido;
}

void Tren::mostrar() {
    cout << "Capacidad: " << this->n << endl;
    cout << "Estaciones: " << this->m << endl;
    cout << "Pedidos: " << this->p << endl;
    int i = 1;
    Pedido* pedido = this->primerPedido;
    while(pedido != nullptr) {
        cout << i << "- " << pedido->obtenerEstacionSalida() << " " << pedido->obtenerEstacionLlegada() << " " << pedido->obtenerPasajeros() << endl;
        pedido = pedido->obtenerSiguiente();
        i++;
    }
}

int Tren::beneficio() {
    return 1;
}

Pedido* Tren::obtenerPrimerPedido() {
    return this->primerPedido;
}

bool Tren::vacio() {
    return this->primerPedido == nullptr;
}
