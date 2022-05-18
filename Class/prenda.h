#ifndef PRENDA_H
#define PRENDA_H

#include <iostream>
using namespace std;

class Prenda
{
    // Codigo de la prenda
    int codigo;

    // Descripcion
    string descripcion;

    // Precio por lavar la prenda
    float  precio;

public:
    Prenda();

    int getCodigo();
    string getDescripcion();
    float getPrecio();

    void setCodigo(int codigo);
    void setDescripcion(string descripcion);
    void setPrecio(float precio);

    bool operator == (Prenda p){
        return codigo == p.codigo;
    }

};

#endif // PRENDA_H
