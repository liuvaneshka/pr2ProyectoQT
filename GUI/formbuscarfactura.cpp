#include "formbuscarfactura.h"
#include "ui_formbuscarfactura.h"

#include <QMessageBox>

#include <QDebug>

FormBuscarFactura::FormBuscarFactura(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FormBuscarFactura)
{
    ui->setupUi(this);

    ui->desdeDate->setDate(QDate::currentDate());
    ui->hastaDate->setDate(QDate::currentDate());

}

FormBuscarFactura::~FormBuscarFactura()
{
    delete ui;
}

void FormBuscarFactura::on_pushButton_clicked()
{

    int index = ui->stackedWidget->currentIndex();

    switch(index){
    case Codigo:
    {
        QString codigo = ui->codigoClienteLineEdit->text();

        if(codigo.isEmpty())
        {
            QMessageBox::information(this,
                                     tr("informacion"),
                                     tr("Debe rellenar el "
                                        "codigo de cliente"),
                                     QMessageBox::Ok);
            return;
        }
    }

        //qDebug("Codigo");
        // Buscar Facturas por codigo

        buscarPorCodigoCliente();
        break;

    case Recibo:
    {
        QString recibo = ui->numeroDeReciboLineEdit->text();

        if(recibo.isEmpty()){

            QMessageBox::information(this,
                                     tr("informacion"),
                                     tr("Debe rellenar el "
                                        "numero de recibo"),
                                     QMessageBox::Ok);
            return;

        }
    }

        //qDebug("Recibo");
        // Buscar Facturas por numero de recibo

        buscarPorNumeroRecibo();
        break;

    case Fecha:
    {
        QDate desde = ui->desdeDate->date();
        QDate hasta = ui->hastaDate->date();

        if( desde > hasta ){

            QMessageBox::information(this,
                                     tr("informacion"),
                                     tr("Fecha de Inicio debe "
                                        "ser inferior a la fecha de finalizacion"),
                                     QMessageBox::Ok);
            return;

        }
    }

        //qDebug("Fecha");
        // Buscar Facturas por fechas

        buscarPorFechas();
        break;

    } // end switch

    accept();
}

vector<Factura> FormBuscarFactura::getFacturas()
{
    return facturas;
}

void FormBuscarFactura::buscarPorCodigoCliente()
{

    vector<Factura> registros = archivo_facturas.toVector();

    string codigo_cliente = ui->codigoClienteLineEdit->text().toStdString();

    for( size_t i = 0 ; i < registros.size() ; i++ ){

        Factura factura = registros[i];

        string codigo = factura.getCodigoCliente();

        if( codigo == codigo_cliente )
            facturas.push_back(factura);

    }

}

void FormBuscarFactura::buscarPorNumeroRecibo()
{

    vector<Factura> registros = archivo_facturas.toVector();

    int codigo_factura = ui->numeroDeReciboLineEdit->text().toInt();

    for( size_t i = 0 ; i < registros.size() ; i++ ){

        Factura factura = registros[i];

        int codigo = factura.getCodigo();

        if( codigo == codigo_factura ){
            facturas.push_back(factura);
            return;
        }

    }

}

void FormBuscarFactura::buscarPorFechas()
{

    vector<Factura> registros = archivo_facturas.toVector();

    QDate desde = ui->desdeDate->date();
    QDate hasta = ui->hastaDate->date();

    for( size_t i = 0 ; i < registros.size() ; i++ ){

        Factura factura = registros[i];

        QDate fecha = factura.getFecha();

        if( (desde <= fecha) and (fecha <= hasta) )
            facturas.push_back(factura);

    }

}
