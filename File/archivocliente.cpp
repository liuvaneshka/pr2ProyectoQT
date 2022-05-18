#include "archivocliente.h"

ArchivoCliente::ArchivoCliente() : ArchivoTexto("clientes.txt")
{
    /* ... */
}

Cliente ArchivoCliente::leer()
{
    Cliente cliente;

    string codigo;
    getline(file,codigo,DELIM);
    cliente.setCodigo(codigo);

    string nombre;
    getline(file,nombre,DELIM);
    cliente.setNombre(nombre);

    string apellido;
    getline(file,apellido,DELIM);
    cliente.setApellido(apellido);

    string direccion;
    getline(file,direccion,DELIM);
    cliente.setDireccion(direccion);

    string telefono;
    getline(file,telefono,DELIM);
    cliente.setTelefono(telefono);

    string email;
    getline(file,email);
    cliente.setEmail(email);

    return cliente;
}

void ArchivoCliente::escribir(Cliente data)
{
    string codigo = data.getCodigo();
    file << codigo << DELIM;

    string nombre = data.getNombre();
    file << nombre << DELIM;

    string apellido = data.getApellido();
    file << apellido << DELIM;

    string direccion = data.getDireccion();
    file << direccion << DELIM;

    string telefono = data.getTelefono();
    file << telefono << DELIM;

    string email = data.getEmail();
    file << email << endl;
}

bool ArchivoCliente::borrar(Cliente data)
{

    bool ret_val = false;

    file.open(filename.c_str(),ios::in);

    string filetmp = filename + ".tmp";
    ofstream out(filetmp.c_str());

    string line;
    getline(file,line);

    while(!file.eof()){

        string codigo = line.substr(0,line.find_first_of(DELIM));

        if(codigo != data.getCodigo())
            out << line << endl;
        else
            ret_val = true;

        getline(file,line);
    }

    out.close();
    file.close();

    remove(filename.c_str());
    rename(filetmp.c_str(),filename.c_str());

    return ret_val;

}
