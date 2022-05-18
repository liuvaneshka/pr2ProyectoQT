#include "cliente.h"

Cliente::Cliente()
{

    codigo = "";
    nombre = "";
    apellido = "";
    direccion = "";
    telefono = "";
    email = "";

}

string Cliente::getCodigo()
{
    return codigo;
}

string Cliente::getNombre()
{
    return nombre;
}

string Cliente::getApellido()
{
    return apellido;
}

string Cliente::getDireccion()
{
    return direccion;
}

string Cliente::getTelefono()
{
    return telefono;
}

string Cliente::getEmail()
{
    return email;
}

void Cliente::setCodigo(string codigo)
{
    this->codigo = codigo;
}

void Cliente::setNombre(string nombre)
{
    this->nombre = nombre;
}

void Cliente::setApellido(string apellido)
{
    this->apellido = apellido;
}

void Cliente::setDireccion(string direccion)
{
    this->direccion = direccion;
}

void Cliente::setTelefono(string telefono)
{
    this->telefono = telefono;
}

void Cliente::setEmail(string email)
{
    this->email = email;
}
