#ifndef PEDIDO_HPP
#define PEDIDO_HPP

class Pedido {
    private:
        int estacionSalida, estacionLlegada, pasajeros;
        Pedido* siguiente;
    public:
        Pedido(int estacionSalida, int estacionLlegada, int pasajeros);
        int obtenerEstacionSalida();
        int obtenerEstacionLlegada();
        int obtenerPasajeros();
        int beneficio();
        void anyadirSiguiente(Pedido* pedido);
        Pedido* obtenerSiguiente();
};

#endif