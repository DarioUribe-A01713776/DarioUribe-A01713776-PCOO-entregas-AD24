#include <iostream>
#include "libro.h"
#include "libreria.h"

using namespace std;

void mostrarMenu() {
    cout << "\n--- SISTEMA DE GESTION LIBRERIA ---\n";
    cout << "1. Agregar libro fisico\n";
    cout << "2. Agregar libro digital\n";
    cout << "3. Buscar libro fisico\n";
    cout << "4. Buscar libro digital\n";
    cout << "5. Eliminar libro fisico\n";
    cout << "6. Eliminar libro digital\n";
    cout << "7. Mostrar todos los libros fisicos\n";
    cout << "8. Mostrar todos los libros digitales\n";
    cout << "9. Salir\n";
    cout << "Seleccione una opcion: ";
}

int main() {
    string nombreLibreria = "Libreria TEC jsjs";
    string direccionLibreria = "TEC";
    int capacidadLibros = 100;

    Libreria miLibreria(nombreLibreria, direccionLibreria, capacidadLibros); // Crea una libreria con capacidad para 100 libros fisicos y digitales.

    int opcion;
    do {
        mostrarMenu();
        cin >> opcion;

        switch (opcion) {
            case 1: {
                // Agregar libro fisico
                string titulo, autor, isbn, pasta, condicion;
                int numPag, stock;
                float precio;
                cout << "Ingrese el titulo: ";
                cin.ignore();
                getline(cin, titulo);
                cout << "Ingrese el autor: ";
                getline(cin, autor);
                cout << "Ingrese el numero de paginas: ";
                cin >> numPag;
                cout << "Ingrese el ISBN: ";
                cin.ignore();
                getline(cin, isbn);
                cout << "Ingrese el precio: ";
                cin >> precio;
                cout << "Ingrese el stock: ";
                cin >> stock;
                cout << "Ingrese el tipo de pasta: ";
                cin.ignore();
                getline(cin, pasta);
                cout << "Ingrese la condicion: ";
                getline(cin, condicion);

                LibroFisico nuevoLibro(titulo, autor, numPag, isbn, precio, stock, pasta, condicion);
                miLibreria.agregarLibroFisico(nuevoLibro);
                cout << "Libro fisico agregado exitosamente.\n";
                break;
            }

            case 2: {
                // Agregar libro digital
                string titulo, autor, isbn, formato;
                int numPag;
                float precio, tamanoArchivo;
                bool disponibilidad;
                cout << "Ingrese el titulo: ";
                cin.ignore();
                getline(cin, titulo);
                cout << "Ingrese el autor: ";
                getline(cin, autor);
                cout << "Ingrese el numero de paginas: ";
                cin >> numPag;
                cout << "Ingrese el ISBN: ";
                cin.ignore();
                getline(cin, isbn);
                cout << "Ingrese el precio: ";
                cin >> precio;
                cout << "Ingrese el tamano del archivo (MB): ";
                cin >> tamanoArchivo;
                cout << "Ingrese el formato: ";
                cin.ignore();
                getline(cin, formato);
                cout << "Esta disponible? (1 = si, 0 = no): ";
                cin >> disponibilidad;

                LibroDigital nuevoLibro(titulo, autor, numPag, isbn, precio, tamanoArchivo, formato, disponibilidad);
                miLibreria.agregarLibroDigital(nuevoLibro);
                cout << "Libro digital agregado exitosamente.\n";
                break;
            }

            case 3: {
                // Buscar libro fisico
                string titulo;
                cout << "Ingrese el titulo del libro fisico a buscar: ";
                cin.ignore();
                getline(cin, titulo);
                int indice = miLibreria.buscarLibroFisico(titulo);
                if (indice != -1) {
                    cout << "Libro fisico encontrado:\n";
                    miLibreria.mostrarLibrosFisicos();
                } else {
                    cout << "Libro fisico no encontrado.\n";
                }
                break;
            }

            case 4: {
                // Buscar libro digital
                string titulo;
                cout << "Ingrese el titulo del libro digital a buscar: ";
                cin.ignore();
                getline(cin, titulo);
                int indice = miLibreria.buscarLibroDigital(titulo);
                if (indice != -1) {
                    cout << "Libro digital encontrado:\n";
                    miLibreria.mostrarLibrosDigitales();
                } else {
                    cout << "Libro digital no encontrado.\n";
                }
                break;
            }

            case 5: {
                // Eliminar libro fisico
                string titulo;
                cout << "Ingrese el titulo del libro fisico a eliminar: ";
                cin.ignore();
                getline(cin, titulo);
                miLibreria.eliminarLibroFisico(titulo);
                break;
            }

            case 6: {
                // Eliminar libro digital
                string titulo;
                cout << "Ingrese el titulo del libro digital a eliminar: ";
                cin.ignore();
                getline(cin, titulo);
                miLibreria.eliminarLibroDigital(titulo);
                break;
            }

            case 7: {
                // Mostrar todos los libros fisicos
                cout << "Libros fisicos en la libreria:\n";
                miLibreria.mostrarLibrosFisicos();
                break;
            }

            case 8: {
                // Mostrar todos los libros digitales
                cout << "Libros digitales en la libreria:\n";
                miLibreria.mostrarLibrosDigitales();
                break;
            }

            case 9: {
                // Salir
                cout << "Saliendo del programa. ¡Gracias por usar el sistema!\n";
                break;
            }

            default:
                cout << "Opcion no valida. Intentelo de nuevo.\n";
                break;
        }
    } while (opcion != 9);

    return 0;
}
