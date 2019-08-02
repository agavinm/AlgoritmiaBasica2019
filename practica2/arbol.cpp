//*****************************************************************
// File:   arbol.cpp
// Author: Andrés Gavín Murillo 716358
// Author: Andrew Mackay 737069
// Date:   Agosto 2019
// Coms:   Algoritmia básica - Práctica 2
//*****************************************************************

#include "arbol.hpp"
#include <limits>

using namespace std;

/* Pre: primero != NULL */
Arbol::Arbol(Pedido *primero) : // Constructor raíz
        padre(nullptr), hijoI(nullptr), hijoD(nullptr), x(false), p(primero), hoja(false), fac(true), b(0) {
    for (int i=0; i<MAX_ESTACIONES; i++) {
        this->np[i] = 0; // Número de pasajeros 0, ya que la raíz no tiene pedido
    }
}

/* Pre: padre != NULL AND p != NULL */
Arbol::Arbol(Arbol *padre, const bool x, Pedido *p, const bool hoja) : // Constructor no raíz, con pedido asociado
        padre(padre), hijoI(nullptr), hijoD(nullptr), x(x), p(p), hoja(hoja) {
    this->fac = true;
    for (int i=0; i<MAX_ESTACIONES; i++) {
        if (this->x && i >= this->p->estacionSalida() && i < this->p->estacionLlegada()) {
            this->np[i] = this->padre->np[i] + this->p->numPasajeros();
        }
        else {
            this->np[i] = this->padre->np[i];
        }

        if (this->np[i] > this->p->tren()->maxPasajeros()) {
            this->fac = false; // Nodo no factible, ya que hay exceso de pasajeros en alguna estación
        }
    }

    if (this->x) { // Se acepta el pedido
        this->b = this->padre->beneficio() + this->p->beneficio();
    }
    else { // Se deniega el pedido
        this->b = this->padre->beneficio();
    }
}

/* Devuelve el hijo izquierdo. */
Arbol* Arbol::izdo() const {
    return this->hijoI;
}

/* Devuelve el hijo derecho. */
Arbol* Arbol::dcho() const {
    return this->hijoD;
}

/* Devuelve cierto si es un nodo hoja, y falso en otro caso. */
bool Arbol::esHoja() const {
    return this->hoja;
}

/* Expande el nodo creando a sus hijos. */
void Arbol::expandir() {
    if (this->padre == nullptr) { // Raíz
        this->hijoI = new Arbol(this, true, this->p, this->p->siguiente() == nullptr);
        this->hijoD = new Arbol(this, false, this->p, this->p->siguiente() == nullptr);
    }
    else { // No es la raíz ni hoja
        this->hijoI = new Arbol(this, true, this->p->siguiente(), this->p->siguiente()->siguiente() == nullptr);
        this->hijoD = new Arbol(this, false, this->p->siguiente(), this->p->siguiente()->siguiente() == nullptr);
    }
}

/* Función de coste c(x). */
int Arbol::coste() const {
    if (!this->fac) { // No es factible
        return numeric_limits<int>::max(); // Infinito
    }
    else if (!this->hoja) { // Es factible y no es hoja
        if (this->hijoI == nullptr) {
            return this->hijoD->coste();
        }
        else if (this->hijoD == nullptr) {
            return this->hijoI->coste();
        }
        else {
            int izq = this->hijoI->coste(), der = this->hijoD->coste();
            if (izq < der) {
                return izq;
            }
            else {
                return der;
            }
        }
    }
    else { // Es factible y es hoja
        return -this->b;
    }
}

/* Función de coste estimado ĉ(x). */
int Arbol::costeEstimado() const {
    if (!this->fac) { // No es factible
        return numeric_limits<int>::max(); // Infinito
    }
    else { // Es factible
        return -cota(this->np, this->b, this->p->siguiente());
    }
}

/* Devuelve el beneficio total de la rama hasta el nodo actual. */
int Arbol::beneficio() const {
    return this->b;
}

/* Función de cota, que devuelve el beneficio estimado si se sigue expandiendo.
 *
 * pas: pasajeros en cada estación actualmente; ben: beneficio actual; p: primer pedido a considerar. */
int cota(const int pas[MAX_ESTACIONES], const int ben, const Pedido *p) {
    if (p == nullptr) {
        return ben;
    }

    int auxPas[MAX_ESTACIONES]; // Pasajeros en cada estación considerando el pedido p
    for (int i=0; i<p->tren()->numEstaciones(); i++) {
        if (i >= p->estacionSalida() && i < p->estacionLlegada()) {
            auxPas[i] = pas[i] + p->numPasajeros();
        }
        else {
            auxPas[i] = pas[i];
        }
    }

    bool lleno = true;
    for (int i=0; i<p->tren()->numEstaciones(); i++) {
        if (auxPas[i] > p->tren()->maxPasajeros()) { // Con el pedido p hay exceso de pasajeros
            return cota(pas, ben, p->siguiente()); // Se ignora el pedido p y se siguen explorando los demás pedidos
        }

        if (auxPas[i] != p->tren()->maxPasajeros()) { // El tren no está lleno con el pedido p
            lleno = false;
        }
    }

    if (lleno) {
        return ben + p->beneficio();
    }
    else {
        return cota(auxPas, ben + p->beneficio(), p->siguiente()); // Se considera el pedido p para la estimación y se
        // siguen explorando los demás pedidos
    }
}
