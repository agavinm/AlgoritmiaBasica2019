//******************************************************************************
// File:   tren.hpp
// Author: Andrés Gavín Murillo 716358
// Author: Andrew Mackay 737069
// Date:   Agosto 2019
// Coms:   Algoritmia básica - Práctica 2
//******************************************************************************

#ifndef PRACTICA2_TREN_HPP
#define PRACTICA2_TREN_HPP

#define MAX_ESTACIONES 8
#define MAX_PEDIDOS 22

class Tren {
private:
    int n; // Capacidad del tren >=0
    int m; // Número de estación final (m+1 estaciones en total) {1..7}
    int p; // Número de pedidos {1..22}

public:
    Tren(int n, int m, int p); // Constructor

    /* Devuelve la capacidad máxima de pasajeros del tren. */
    int maxPasajeros() const;

    /* Devuelve el número de estaciones del tren. */
    int numEstaciones() const;
};


#endif //PRACTICA2_TREN_HPP
