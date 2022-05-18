#include "formdatoscliente.h"
#include "ui_formdatoscliente.h"

FormDatosCliente::FormDatosCliente(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FormDatosCliente)
{
    ui->setupUi(this);
}

FormDatosCliente::FormDatosCliente(QWidget *parent, Cliente cliente) :
    QDialog(parent),
    ui(new Ui::FormDatosCliente)
{
    ui->setupUi(this);

    QString codigo = QString::fromStdString(cliente.getCodigo());
    ui->codigoLineEdit->setText(codigo);
    ui->codigoLineEdit->setReadOnly(true);

    QString nombre = QString::fromStdString(cliente.getNombre());
    ui->nombreLineEdit->setText(nombre);

    QString apellido = QString::fromStdString(cliente.getApellido());
    ui->apellidoLineEdit->setText(apellido);

    QString direccion = QString::fromStdString(cliente.getDireccion());
    ui->plainTextEdit->setPlainText(direccion);

    QString telefono = QString::fromStdString(cliente.getTelefono());
    ui->telefonoLineEdit->setText(telefono);

    QString email = QString::fromStdString(cliente.getEmail());
    ui->emailLineEdit->setText(email);

}

FormDatosCliente::~FormDatosCliente()
{
    delete ui;
}

Cliente FormDatosCliente::getCliente()
{
    Cliente cliente;

    QString codigo = ui->codigoLineEdit->text();
    cliente.setCodigo(codigo.toStdString());

    QString nombre = ui->nombreLineEdit->text();
    cliente.setNombre(nombre.toStdString());

    QString apellido = ui->apellidoLineEdit->text();
    cliente.setApellido(apellido.toStdString());

    QString direccion = ui->plainTextEdit->toPlainText();
    cliente.setDireccion(direccion.toStdString());

    QString telefono = ui->telefonoLineEdit->text();
    cliente.setTelefono(telefono.toStdString());

    QString email = ui->emailLineEdit->text();
    cliente.setEmail(email.toStdString());

    return cliente;
}
