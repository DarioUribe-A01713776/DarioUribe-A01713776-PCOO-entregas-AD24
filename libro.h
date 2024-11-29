#ifndef LIBRO_H
#define LIBRO_H


#include <iostream>
#include <string>
using namespace std;

//Clase libro 
class Libro{
    protected:
        string titulo;
        string autor;
        int numPag;
        string isbn;
        float precio;
    
    public:
        //Constructor por defecto
        Libro(): titulo(""), autor(""), numPag(0), isbn(""), precio(0.0) {}
        
        // Constructor parametrizado
        Libro(string t, string a, int n, string i, float p)
        : titulo(t), autor(a), numPag(n), isbn(i), precio(p) {}

        //Getters
        string getTitulo () const;
        string getAutor () const; 
        int getNumPag () const;
        string getIsbn () const;
        float getPrecio () const;

        //setters
        void setTitulo(string);
        void setAutor(string);
        void setNumPag(int);
        void setIsbn(string);
        void setPrecio(float);

        //Método para mostrar la información del libro
        void mostrarInfo() const {
            cout<< "Titulo: "<< titulo << ", Autor: "<< autor << 
            ", Numero de Paginas: "<< numPag << ", isbn: " << isbn <<
            ", Precio: $" << precio << endl;
        }
    };


string Libro::getTitulo() const{
    return titulo;
}
string Libro::getAutor() const{
    return autor;
}
int Libro::getNumPag() const{
    return numPag;
}
string Libro::getIsbn() const{
    return isbn;
}
float Libro::getPrecio() const{
    return precio;
}


void Libro::setTitulo(string t){
    titulo = t;
}
void Libro::setAutor(string a){
    autor = a;
}
void Libro::setNumPag(int n){
    numPag = n;
}
void Libro::setIsbn(string i){
    isbn = i;
}
void Libro::setPrecio(float p){
    precio = p;
}


//CLASE LibroFisico, hija de clase libro

class LibroFisico: public Libro{
    private:
        int stock;
        string pasta;
        string condicion;
    public:

    //constructores
        LibroFisico(): stock(0), pasta(""), condicion("") {}
        LibroFisico(string t, string a, int n, string i, float p, int st, string ps, string c)
        : Libro(t, a, n, i, p), stock(st), pasta(ps), condicion(c) {}

        int getStock() const;
        string getPasta() const;
        string getCondicion() const;

        void setStock(int);
        void setPasta(string);
        void setCondicion(string);


        //metodo para verificar stock

        bool verificarStock(string titulob) const{
            if (titulo == titulob){
                return stock;
            }
            return 0;
        }
};



int LibroFisico::getStock() const{
    return stock;
}
string LibroFisico::getPasta() const{
    return pasta;
}
string LibroFisico::getCondicion() const{
   return condicion;
}

void LibroFisico::setStock(int st){
    stock = st;
}
void LibroFisico::setPasta(string ps){
    pasta = ps;
}
void LibroFisico::setCondicion(string c){
    condicion = c;
}


//CLASE LibroDigital, hija de clase libro


class LibroDigital: public Libro{
    private:
        float tamanoArchivo;
        string formato;
        bool disponibilidad;

    public: 
        LibroDigital(): tamanoArchivo(0.0), formato(""), disponibilidad(false) {}
        LibroDigital(string t, string a, int n, string i, float p, float tm, string f, bool d)
        : Libro(t, a, n, i, p), tamanoArchivo(tm), formato(f), disponibilidad(d) {}

        float getTamanoArchivo() const;
        string getFormato() const;
        bool getDisponibilidad() const;

        void setTamanoArchivo(float);
        void setFormato(string);
        void setDisponibilidad(bool);

        bool verificarDisponibilidad(string titulob) const{
            return (titulo == titulob && disponibilidad);
        }

};


float LibroDigital::getTamanoArchivo() const{
    return tamanoArchivo;
}
string LibroDigital::getFormato() const{
    return formato;
}
bool LibroDigital::getDisponibilidad() const{
    return disponibilidad;
}

void LibroDigital::setTamanoArchivo(float tm){
    tamanoArchivo = tm;
}
void LibroDigital::setFormato(string f){
    formato = f;
}
void LibroDigital::setDisponibilidad(bool d){
    disponibilidad = d;
}

#endif

