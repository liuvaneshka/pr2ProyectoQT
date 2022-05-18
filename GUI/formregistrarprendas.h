#ifndef FORMREGISTRARPRENDAS_H
#define FORMREGISTRARPRENDAS_H

#include <QDialog>
#include <QtGui>

#include <Class/cliente.h>
#include <Class/prenda.h>
#include <Class/factura.h>

#include <iva.h>

#define CODIGO 0
#define DESCRIPCION 1
#define PRECIO 2
#define CANTIDAD 3
#define MONTO 4

namespace Ui {
    class FormRegistrarPrendas;
}

class FormRegistrarPrendas : public QDialog
{
    Q_OBJECT

    Cliente cliente;

    int cant_prendas;
    vector<Prenda> prendas;

    vector<int> cantidades_prendas;

    float subtotal;
    float iva;

public:
    explicit FormRegistrarPrendas(QWidget *parent,Cliente cliente);
    ~FormRegistrarPrendas();

    Factura getFactura();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::FormRegistrarPrendas *ui;

    void listarPrenda(Prenda prenda, int row);
    void actualizarLista();

    void accept();

};

#endif // FORMREGISTRARPRENDAS_H
