//*****************************************************************
// File:   heap.hpp
// Author: Andrés Gavín Murillo 716358
// Author: Andrew Mackay 737069
// Date:   Agosto 2019
// Coms:   Algoritmia básica - Práctica 2
//*****************************************************************

#ifndef PRACTICA2_HEAP_HPP
#define PRACTICA2_HEAP_HPP

#include <vector>


template <typename T> // Clase T debe tener función costeEstimado() que devuelve el peso del objeto
class Heap { // Heap de mínimos
private:
    std::vector<T*> v; // vector dinámico que almacena los datos del montículo

public:
    Heap() {
        v.clear();
    }

    ~Heap() {
        v.clear();
    }

    /* Inserta el elemento e al Heap */
    void insertar(T *e) {
        this->v.push_back(e); // Nuevo nodo hoja más a la derecha
        unsigned long pos = this->v.size() - 1, posPadre = (pos+1) / 2 - 1;
        bool continuar = pos != 0;

        while (continuar) { // Intercambiar mientras el hijo sea menor que el padre
            if (this->v[pos]->costeEstimado() < this->v[posPadre]->costeEstimado()) {
                this->v[pos] = this->v[posPadre];
                this->v[posPadre] = e;
                pos = posPadre;
                posPadre = (pos+1) / 2 - 1;
                continuar = pos != 0;
            }
            else {
                continuar = false;
            }
        }
    }

    /* Elimina del Heap el elemento en la cima y lo devuelve */
    T* primero() {
        if (!this->v.empty()) {
            T *cima = this->v[0]; // Elemento a devolver

            // Nodo hoja más a la derecha en la cima y eliminar ese nodo hoja
            this->v[0] = this->v.back();
            this->v.pop_back();

            // Hundir cima
            unsigned long pos = 0, posHijo = (pos+1) * 2 - 1;
            bool continuar = posHijo < this->v.size();
            T *aux;

            while (continuar) {
                if (posHijo+1 != this->v.size() && this->v[posHijo]->costeEstimado() > this->v[posHijo+1]->costeEstimado()) {
                    posHijo++; // Hijo derecho
                }

                if (this->v[pos]->costeEstimado() > this->v[posHijo]->costeEstimado()) { // Intercambiar mientras el hijo sea mayor que el padre
                    aux = this->v[posHijo];
                    this->v[posHijo] = this->v[pos];
                    this->v[pos] = aux;
                    pos = posHijo;
                    posHijo = (pos+1) * 2 - 1;
                    continuar = posHijo < this->v.size();
                }
                else {
                    continuar = false;
                }
            }

            return cima;
        }
        else {
            return nullptr;
        }
    }

    /* Devuelve cierto si no hay elementos en el Heap, en otro caso devuelve falso. */
    bool esVacio() {
        return this->v.empty();
    }
};


#endif //PRACTICA2_HEAP_HPP
