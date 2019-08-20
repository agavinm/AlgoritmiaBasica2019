//*****************************************************************
// File:   tren.hpp
// Author: Andrés Gavín Murillo 716358
// Author: Andrew Mackay 737069
// Date:   Mayo 2019
// Coms:   Algoritmia básica - Práctica 2
//*****************************************************************

#ifndef TREN_HPP
#define TREN_HPP

#include <queue>
#include <tuple>

using namespace std;

class Tren {

private:

    queue<tuple<int, int, int>> pedidos;
    int n, m, p;

public:

    void iniciarTren (int n, int m, int p);

    void insertarPedido (tuple<int, int, int> pedido);

    string obtenerPedidos();
};

#endif