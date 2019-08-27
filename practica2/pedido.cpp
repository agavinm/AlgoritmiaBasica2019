#include "pedido.hpp"

Pedido::Pedido(int n, int m, int p) {
    this->n = n;
    this->m = m;
    this->p = p;
}

int Pedido::obtenerCapacidad() {
    return this->n;
}

int Pedido::obtenerParadas() {
    return this->m;
}

int Pedido::obtenerPedidos() {
    return this->p;
}

int Pedido::beneficio() {
    return 1;
}