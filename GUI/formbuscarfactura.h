#ifndef FORMBUSCARFACTURA_H
#define FORMBUSCARFACTURA_H

#include <QDialog>

#include <Class/factura.h>
#include <File/archivofactura.h>

namespace Ui {
    class FormBuscarFactura;
}

class FormBuscarFactura : public QDialog
{
    Q_OBJECT

    enum Page
    {
        Codigo = 0,
        Recibo = 1,
        Fecha  = 2
    };

    vector<Factura> facturas;
    ArchivoFactura archivo_facturas;

public:
    FormBuscarFactura(QWidget *parent);
    ~FormBuscarFactura();

    vector<Factura> getFacturas();

private slots:
    void on_pushButton_clicked();

private:
    Ui::FormBuscarFactura *ui;

    void buscarPorCodigoCliente();
    void buscarPorNumeroRecibo();
    void buscarPorFechas();


};

#endif // FORMBUSCARFACTURA_H
