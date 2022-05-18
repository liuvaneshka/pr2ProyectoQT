#include "formcedulacliente.h"
#include "ui_formcedulacliente.h"

FormCedulaCliente::FormCedulaCliente(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FormCedulaCliente)
{
    ui->setupUi(this);
}

FormCedulaCliente::~FormCedulaCliente()
{
    delete ui;
}

string FormCedulaCliente::getCodigoCliente()
{
    return ui->codigoClienteLineEdit->text().toStdString();
}
