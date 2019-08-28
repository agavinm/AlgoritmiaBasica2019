//*****************************************************************
// File:   tren.hpp
// Author: Andrés Gavín Murillo 716358
// Author: Andrew Mackay 737069
// Date:   Mayo 2019
// Coms:   Algoritmia básica - Práctica 2
//*****************************************************************

#ifndef TREN_HPP
#define TREN_HPP

#include "pedido.hpp"
#include "heap.hpp"

using namespace std;

class Tren {

private:

    Pedido* primerPedido;
    int n, m, p;

public:

    void iniciarTren (int n, int m, int p);

    int obtenerCapacidad();

    int obtenerEstaciones();

    int obtenerPedidos();

    void insertarPedido(Pedido* pedido);
    
    void mostrar();

    int beneficio();

    Pedido* obtenerPrimerPedido();

    bool vacio();
};

#endif