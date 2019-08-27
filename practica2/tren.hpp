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

    Heap<Pedido> pedidos;
    int n, m, p;

public:

    void iniciarTren (int n, int m, int p);

    void insertarPedido (Pedido* pedido);
    
    void mostrar();

    int beneficio();

    Pedido* primerPedido();

    bool vacio();
};

#endif