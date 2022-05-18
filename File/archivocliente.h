#ifndef ARCHIVOCLIENTE_H
#define ARCHIVOCLIENTE_H

#include <Class/cliente.h>
#include <File/archivotexto.h>
#include <stdio.h>

class ArchivoCliente : public ArchivoTexto<Cliente>
{
public:
    ArchivoCliente();

    Cliente leer();
    void escribir(Cliente data);

    bool borrar(Cliente data);

};

#endif // ARCHIVOCLIENTE_H
