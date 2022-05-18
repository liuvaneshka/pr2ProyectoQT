#ifndef CLIENTE_H
#define CLIENTE_H

#include <iostream>
using namespace std;

class Cliente
{

    string codigo;
    string nombre;
    string apellido;
    string direccion;
    string telefono;
    string email;

public:
    Cliente();

    string getCodigo();
    string getNombre();
    string getApellido();
    string getDireccion();
    string getTelefono();
    string getEmail();

    void setCodigo(string codigo);
    void setNombre(string nombre);
    void setApellido(string apellido);
    void setDireccion(string direccion);
    void setTelefono(string telefono);
    void setEmail(string email);

    bool operator == (Cliente c){
        return codigo == c.codigo;
    }

};

#endif // CLIENTE_H
