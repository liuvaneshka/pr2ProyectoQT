#ifndef FORMEDICIONFACTURAS_H
#define FORMEDICIONFACTURAS_H

#include <QDialog>
#include <QListWidget>

#include <vector>
using namespace std;

#include <Class/factura.h>
#include <File/archivofactura.h>

namespace Ui {
    class FormEdicionFacturas;
}

class FormEdicionFacturas : public QDialog
{
    Q_OBJECT

    ArchivoFactura archivo_factura;
    vector<Factura> facturas;

public:
    FormEdicionFacturas(QWidget *parent, vector<Factura> facturas);
    ~FormEdicionFacturas();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::FormEdicionFacturas *ui;
};

#endif // FORMEDICIONFACTURAS_H
