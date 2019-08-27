#ifndef PEDIDO_HPP
#define PEDIDO_HPP

class Pedido {
    private:
        int n, m, p;
    public:
        Pedido(int n, int m, int p);
        int obtenerCapacidad();
        int obtenerParadas();
        int obtenerPedidos();
        int beneficio();
};

#endif