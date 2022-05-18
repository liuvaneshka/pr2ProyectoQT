#ifndef VISORFACTURA_H
#define VISORFACTURA_H

#include <QDialog>

#include <iva.h>
#include <Class/factura.h>

#include <File/archivocliente.h>
#include <File/archivoprenda.h>

#include <QTextEdit>
#include <QTextTable>

namespace Ui {
    class VisorFactura;
}

class VisorFactura : public QDialog
{
    Q_OBJECT

    ArchivoCliente archivo_clientes;
    ArchivoPrenda   archivo_prendas;

    QTextCursor cursor;
    QTextFrame *topFrame;
    QTextTable * table;

public:
    VisorFactura(QWidget *parent,Factura factura);
    ~VisorFactura();

private slots:
    void on_printButton_clicked();

private:
    Ui::VisorFactura *ui;

    void imprimirCliente(string codigo_cliente);
    void facturaEntregada(bool entregada);
    void crearTablaPrendas();
    void agregarPrenda(Prenda prenda,int cantidad);
    void imprimirTotales(float subtotal);
    void construirFactura(Factura factura);

private:
    void bloques(int num){ for( int i = 0 ; i < num ; i++ ) cursor.insertBlock(); }

};

#endif // VISORFACTURA_H
