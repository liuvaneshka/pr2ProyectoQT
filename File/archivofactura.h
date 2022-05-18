#ifndef ARCHIVOFACTURA_H
#define ARCHIVOFACTURA_H

#include <Class/factura.h>
#include <File/archivotexto.h>

class ArchivoFactura : public ArchivoTexto<Factura>
{

public:
    ArchivoFactura();

    Factura leer();
    void escribir(Factura data);

    bool borrar(Factura data);

};

#endif // ARCHIVOFACTURA_H
