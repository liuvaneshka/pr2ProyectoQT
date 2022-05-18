#include "formnuevaprenda.h"
#include "ui_formnuevaprenda.h"

#include <QDebug>
#include <QMessageBox>

FormNuevaPrenda::FormNuevaPrenda(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FormNuevaPrenda)
{
    ui->setupUi(this);

    int codigo = archivo_prenda.size();

    QString text = QString::number(codigo);
    ui->codigoLineEdit->setText(text);
}

FormNuevaPrenda::~FormNuevaPrenda()
{
    delete ui;
}

Prenda FormNuevaPrenda::getPrenda()
{
    Prenda prenda;

    int codigo = ui->codigoLineEdit->text().toInt();
    prenda.setCodigo(codigo);

    string descripcion = ui->plainTextEdit->toPlainText().toStdString();
    prenda.setDescripcion(descripcion);

    float precio = ui->precioDoubleSpinBox->value();
    prenda.setPrecio(precio);

    return prenda;
}

void FormNuevaPrenda::accept(){

    QString descripcion = ui->plainTextEdit->toPlainText();

    if(descripcion.isEmpty()){
        QMessageBox::warning(this,
                             tr("Warning"),
                             tr("Debe escribir una descripcion..."),
                             QMessageBox::Ok);
        return;
    }

    QDialog::accept();

}
