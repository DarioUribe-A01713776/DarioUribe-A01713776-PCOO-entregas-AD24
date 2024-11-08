// main.cpp
#include "libreria.h"

int main() {
    //objeto de la clase Libro
    Libro libro1("1984", "George Orwell", "123456789", 299.99, 5);
    libro1.mostrarInfo();
    libro1.venderLibro();

    //objeto de la clase Cliente
    Cliente cliente1("Dario Uribe", "dariouribe@gmail.com", 101);
    cliente1.mostrarInfo();
    cliente1.actualizarCorreo("dario@gmail.com");

    // objeto de la clase Pedido
    Pedido pedido1(1, cliente1, libro1, 2);
    pedido1.mostrarDetalle();
    pedido1.procesarPedido();

    return 0;
}
