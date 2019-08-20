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

void Tren::insertarPedido (tuple<int, int, int> pedido) {
    this->pedidos.push(pedido);
}

string Tren::obtenerPedidos() {
    string tren = "";
    while(!this->pedidos.empty()) {
        tuple<int, int, int> pedido = this->pedidos.front();
        this->pedidos.pop();
        tren = tren + to_string(get<0>(pedido)) + ' ' + to_string(get<1>(pedido)) + ' ' + to_string(get<2>(pedido)) + '\n';
    }
    return tren;
}
