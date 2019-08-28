#include "pedido.hpp"

Pedido::Pedido(int estacionSalida, int estacionLlegada, int pasajeros) {
    this->estacionSalida = estacionSalida;
    this->estacionLlegada = estacionLlegada;
    this->pasajeros = pasajeros;
}

int Pedido::obtenerEstacionSalida() {
    return this->estacionSalida;
}

int Pedido::obtenerEstacionLlegada() {
    return this->estacionLlegada;
}

int Pedido::obtenerPasajeros() {
    return this->pasajeros;
}

int Pedido::beneficio() {
    return this->estacionSalida-this->estacionLlegada*this->pasajeros;
}

void Pedido::anyadirSiguiente(Pedido* pedido) {
    this->siguiente = pedido;
}

Pedido* Pedido::obtenerSiguiente() {
    return this->siguiente;
}