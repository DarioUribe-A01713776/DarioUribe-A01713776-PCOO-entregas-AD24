#ifndef LIBRERIA_H
#define LIBRERIA_H

#include <string>
#include "libro.h" 

using namespace std;

class Libreria {
private:
    string nombre;
    string direccion;
    LibroFisico librosFisicos[100]; // Arreglo estático de libros físicos (capacidad 10)
    LibroDigital librosDigitales[100]; // Arreglo estático de libros digitales (capacidad 10)
    int totalFisicos;
    int totalDigitales;
    int capacidad; // Capacidad total de libros (físicos y digitales)

public:
    Libreria(string nom, string dir, int cap) : nombre(nom), direccion(dir), capacidad(cap), totalFisicos(0), totalDigitales(0) {}

    // Método para agregar un libro físico
    void agregarLibroFisico(const LibroFisico& libro) {
        if (totalFisicos < capacidad) {
            librosFisicos[totalFisicos++] = libro;
        } else {
            cout << "No hay espacio para mas libros físicos.\n";
        }
    }

    // Método para agregar un libro digital
    void agregarLibroDigital(const LibroDigital& libro) {
        if (totalDigitales < capacidad) {
            librosDigitales[totalDigitales++] = libro;
        } else {
            cout << "No hay espacio para mas libros digitales.\n";
        }
    }

    // Método para buscar un libro físico por título
    int buscarLibroFisico(const string& titulo) {
        for (int i = 0; i < totalFisicos; i++) {
            if (librosFisicos[i].getTitulo() == titulo) {
                return i; // Retorna el índice si el libro está encontrado
            }
        }
        return -1;
    }

    // Método para buscar un libro digital por título
    int buscarLibroDigital(const string& titulo) {
        for (int i = 0; i < totalDigitales; i++) {
            if (librosDigitales[i].getTitulo() == titulo) {
                return i; // Retorna el índice si el libro está encontrado
            }
        }
        return -1;
    }

    // Método para eliminar un libro físico por título
    void eliminarLibroFisico(const string& titulo) {
        int index = buscarLibroFisico(titulo);
        if (index != -1) {
            for (int i = index; i < totalFisicos - 1; i++) {
                librosFisicos[i] = librosFisicos[i + 1];
            }
            totalFisicos--;
            cout << "Libro fisico eliminado exitosamente.\n";
        } else {
            cout << "No se encontro el libro fisico a eliminar.\n";
        }
    }

    // Método para eliminar un libro digital por título
    void eliminarLibroDigital(const string& titulo) {
        int index = buscarLibroDigital(titulo);
        if (index != -1) {
            for (int i = index; i < totalDigitales - 1; i++) {
                librosDigitales[i] = librosDigitales[i + 1];
            }
            totalDigitales--;
            cout << "Libro digital eliminado exitosamente.\n";
        } else {
            cout << "No se encontro el libro digital a eliminar.\n";
        }
    }

    // Método para mostrar todos los libros físicos
    void mostrarLibrosFisicos() const {
        if (totalFisicos == 0) {
            cout << "No hay libros fisicos registrados.\n";
        } else {
            for (int i = 0; i < totalFisicos; i++) {
                librosFisicos[i].mostrarInfo();
            }
        }
    }

    // Método para mostrar todos los libros digitales
    void mostrarLibrosDigitales() const {
        if (totalDigitales == 0) {
            cout << "No hay libros digitales registrados.\n";
        } else {
            for (int i = 0; i < totalDigitales; i++) {
                librosDigitales[i].mostrarInfo();
            }
        }
    }
};

#endif
