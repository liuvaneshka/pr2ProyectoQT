#include "formregistrarprendas.h"
#include "ui_formregistrarprendas.h"

#include <File/archivoprenda.h>
#include <GUI/formseleccionprenda.h>

FormRegistrarPrendas::FormRegistrarPrendas(QWidget *parent, Cliente cliente) :
    QDialog(parent),
    ui(new Ui::FormRegistrarPrendas)
{
    ui->setupUi(this);

    this->cliente = cliente;

    subtotal = 0;
    iva = 0;

    /* . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . */
    // Creamos los Items para la tabla
    int row    = ui->tableWidget->rowCount();
    int column = ui->tableWidget->columnCount();

    for( int i = 0 ; i < row ; i++ )
        for( int j = 0 ; j < column ; j++ )
            ui->tableWidget->setItem(i,j,new QTableWidgetItem);
    /* . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . */



    /* . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . */
    // Construimos los Datos del Cliente
    QString nombre = QString::fromStdString(cliente.getNombre());
    QString apellido = QString::fromStdString(cliente.getApellido());

    QString text = nombre + tr(" ") + apellido;
    ui->clienteLineEdit->setText(text);

    text = QString::fromStdString(cliente.getDireccion());
    ui->direccionLineEdit->setText(text);

    text = QString::fromStdString(cliente.getCodigo());
    ui->codigoLineEdit->setText(text);
    /* . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . */



    /* . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . */
    // Capturamos la fecha actual
    ui->dateEdit->setDate(QDate::currentDate());
    // Capturamos la hora actual
    ui->timeEdit->setTime(QTime::currentTime());
    /* . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . */


    cant_prendas = 0;
}

FormRegistrarPrendas::~FormRegistrarPrendas()
{
    int row    = ui->tableWidget->rowCount();
    int column = ui->tableWidget->columnCount();

    for( int i = 0 ; i < row ; i++ )
        for( int j = 0 ; j < column ; j++ )
            delete ui->tableWidget->item(i,j);

    delete ui;
}

void FormRegistrarPrendas::on_pushButton_clicked()
{

    if(cant_prendas == 10)
        return;

    ArchivoPrenda archivo_prendas;
    vector<Prenda> prendas = archivo_prendas.toVector();

    FormSeleccionPrenda form(this,prendas);

    if(form.exec() != QDialog::Accepted)
        return;

    Prenda prenda = form.getPrenda();
    this->prendas.push_back(prenda);

    int cantidad = form.getCantidad();
    cantidades_prendas.push_back(cantidad);

    float monto = cantidad*prenda.getPrecio();
    subtotal += monto;

    cant_prendas++;

    actualizarLista();

}

Factura FormRegistrarPrendas::getFactura()
{
    Factura factura;

    factura.setCodigoCliente(cliente.getCodigo());

    vector<int> codigos_prendas;
    for( size_t i = 0 ; i < prendas.size() ; i++ ){

        int codigo_prenda = prendas[i].getCodigo();
        codigos_prendas.push_back(codigo_prenda);

    }
    factura.setCodigosPrendas(codigos_prendas);
    factura.setSubtotal(subtotal);
    factura.setCantidadesPrendas(cantidades_prendas);
    factura.setFecha(QDate::currentDate());

    return factura;
}

void FormRegistrarPrendas::listarPrenda(Prenda prenda, int row)
{
    QTableWidgetItem * item;

    // Codigo
    int codigo = prenda.getCodigo();
    item = ui->tableWidget->item(row,CODIGO);
    item->setText(QString::number(codigo));

    // Descripcion
    string descripcion = prenda.getDescripcion();
    item = ui->tableWidget->item(row,DESCRIPCION);
    item->setText(QString::fromStdString(descripcion));

    // Precio
    float precio = prenda.getPrecio();
    item = ui->tableWidget->item(row,PRECIO);
    item->setText(QString::number(precio));

    // Cantidad
    int cantidad = cantidades_prendas[row];
    item = ui->tableWidget->item(row,CANTIDAD);
    item->setText(QString::number(cantidad));

    // Monto
    float monto = precio*cantidad;
    item = ui->tableWidget->item(row,MONTO);
    item->setText(QString::number(monto));

    iva = subtotal*IVA;

    ui->subtotalDoubleSpinBox->setValue(subtotal);
    ui->ivaDoubleSpinBox->setValue(iva);
    ui->totalDoubleSpinBox->setValue(subtotal+iva);

}

void FormRegistrarPrendas::actualizarLista()
{

    if(prendas.size() == 0){
        ui->subtotalDoubleSpinBox->clear();
        ui->ivaDoubleSpinBox->clear();
        ui->totalDoubleSpinBox->clear();
    }

    for( size_t i = 0 ; i < prendas.size() ; i++ ){

        Prenda prenda = prendas[i];
        listarPrenda(prenda,i);

    }
}

void FormRegistrarPrendas::accept()
{
    if( cant_prendas == 0 )
    {

        QMessageBox::information(this,
                                 tr("Informacion"),
                                 tr("Debe agregar al menos una prenda..."),
                                 QMessageBox::Ok);
        return;

    }

    QDialog::accept();

}

void FormRegistrarPrendas::on_pushButton_2_clicked()
{
    int index = ui->tableWidget->currentRow();

    if( index < 0 or index >= int(prendas.size()))
        return;

    Prenda prenda = prendas[index];
    int cantidad = cantidades_prendas[index];
    subtotal -= prenda.getPrecio()*cantidad;

    int row = prendas.size() - 1;
    for( int i = 0 ; i < 5 ; i++ ){
        QTableWidgetItem * item = ui->tableWidget->item(row,i);
        item->setText("");
    }

    prendas[index] = prendas[prendas.size() - 1];
    prendas.pop_back();

    cantidades_prendas[index] = cantidades_prendas[cantidades_prendas.size() - 1];
    cantidades_prendas.pop_back();

    cant_prendas--;

    actualizarLista();

}
