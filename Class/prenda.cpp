#include "prenda.h"

Prenda::Prenda()
{
    descripcion = "";
    precio = 0;
}

string Prenda::getDescripcion()
{
    return descripcion;
}

int Prenda::getCodigo()
{
    return codigo;
}

float Prenda::getPrecio()
{
    return precio;
}

void Prenda::setCodigo(int codigo)
{
    this->codigo = codigo;
}

void Prenda::setDescripcion(string descripcion)
{
    this->descripcion = descripcion;
}

void Prenda::setPrecio(float precio)
{
    this->precio = precio;
}
