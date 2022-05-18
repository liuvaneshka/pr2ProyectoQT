#ifndef FORMDATOSCLIENTE_H
#define FORMDATOSCLIENTE_H

#include <QDialog>

#include <Class/cliente.h>

namespace Ui {
    class FormDatosCliente;
}

class FormDatosCliente : public QDialog
{
    Q_OBJECT

public:
    FormDatosCliente(QWidget *parent);
    FormDatosCliente(QWidget *parent,Cliente cliente);
    ~FormDatosCliente();

    Cliente getCliente();

private:
    Ui::FormDatosCliente *ui;
};

#endif // FORMDATOSCLIENTE_H
