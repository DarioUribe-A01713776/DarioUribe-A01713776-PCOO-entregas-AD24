#ifndef LIBRERIA_H
#define LIBRERIA_H

#include <iostream>
#include <string>
using namespace std;

// Clase Libro
class Libro {
private:
    string titulo;
    string autor;
    string isbn;
    double precio;
    int stock;

public:
    // Constructor
    Libro(string t, string a, string i, double p, int s)
        : titulo(t), autor(a), isbn(i), precio(p), stock(s) {}

    // Métodos
    void mostrarInfo() const {
        cout << "Libro: " << titulo << ", Autor: " << autor
             << ", ISBN: " << isbn << ", Precio: $" << precio
             << ", Stock: " << stock << endl;
    }

    bool verificarDisponibilidad() const {
        return stock > 0;
    }

    void venderLibro() {
        if (verificarDisponibilidad()) {
            stock--;
            cout << "Libro vendido. Stock restante: " << stock << endl;
        } else {
            cout << "Lo siento, no hay stock disponible." << endl;
        }
    }
};

// Clase Cliente
class Cliente {
private:
    string nombre;
    string correo;
    int id;

public:
    // Constructor
    Cliente(string n, string c, int i)
        : nombre(n), correo(c), id(i) {}

    // Métodos
    void mostrarInfo() const {
        cout << "Cliente: " << nombre << ", Correo: " << correo
             << ", ID: " << id << endl;
    }

    void actualizarCorreo(string nuevoCorreo) {
        correo = nuevoCorreo;
        cout << "Correo actualizado a: " << correo << endl;
    }
};

// Clase Pedido
class Pedido {
private:
    int idPedido;
    Cliente cliente;
    Libro libro;
    int cantidad;

public:
    // Constructor
    Pedido(int id, Cliente c, Libro l, int qty)
        : idPedido(id), cliente(c), libro(l), cantidad(qty) {}

    // Métodos
    void mostrarDetalle() const {
        cout << "ID Pedido: " << idPedido << endl;
        cliente.mostrarInfo();
        libro.mostrarInfo();
        cout << "Cantidad: " << cantidad << endl;
    }

    void procesarPedido() {
        for (int i = 0; i < cantidad; i++) {
            libro.venderLibro();
        }
    }
};

#endif // LIBRERIA_H
