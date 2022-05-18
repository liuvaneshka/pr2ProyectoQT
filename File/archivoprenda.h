#ifndef ARCHIVOPRENDA_H
#define ARCHIVOPRENDA_H

#include <File/archivotexto.h>
#include <Class/prenda.h>

class ArchivoPrenda : public ArchivoTexto<Prenda>
{
public:
    ArchivoPrenda();

    Prenda leer();
    void escribir(Prenda data);

    bool borrar(Prenda data);
};

#endif // ARCHIVOPRENDA_H
