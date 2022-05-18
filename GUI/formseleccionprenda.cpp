#include "formseleccionprenda.h"
#include "ui_formseleccionprenda.h"

FormSeleccionPrenda::FormSeleccionPrenda(QWidget *parent, vector<Prenda> prendas) :
    QDialog(parent),
    ui(new Ui::FormSeleccionPrenda)
{
    ui->setupUi(this);

    this->prendas = prendas;

    for(size_t i = 0 ; i < prendas.size() ; i++ ){

        Prenda prenda = prendas[i];

//        QString codigo = QString::number(prenda.getCodigo());
        QString descripcion = QString::fromStdString(prenda.getDescripcion());
        QString precio = QString::number(prenda.getPrecio());

        QString text = /*codigo + tr(", ") +*/ descripcion + tr(", ") + precio + tr(" Bs.F");

        ui->comboBox->addItem(text);

    }

}

Prenda FormSeleccionPrenda::getPrenda()
{
    int index = ui->comboBox->currentIndex();
    return prendas[index];
}

int FormSeleccionPrenda::getCantidad()
{
    return ui->cantidadSpinBox->value();
}

FormSeleccionPrenda::~FormSeleccionPrenda()
{
    delete ui;
}
