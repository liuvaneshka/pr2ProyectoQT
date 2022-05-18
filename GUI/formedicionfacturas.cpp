#include "formedicionfacturas.h"
#include "ui_formedicionfacturas.h"

#include <GUI/visorfactura.h>

FormEdicionFacturas::FormEdicionFacturas(QWidget *parent, vector<Factura> facturas) :
    QDialog(parent),
    ui(new Ui::FormEdicionFacturas)
{
    ui->setupUi(this);

    this->facturas = facturas;

    QListWidget * listWidget = ui->listWidget;

    for( size_t i = 0 ; i < facturas.size() ; i++ ){

        Factura factura = facturas[i];

        QString text;

        int codigo = factura.getCodigo();
        text += tr("Codigo: ") + QString::number(codigo) + tr(" ");

        string codigo_cliente = factura.getCodigoCliente();
        text += tr("Cliente: ") + QString::fromStdString(codigo_cliente) + tr(" ");

        QDate fecha = factura.getFecha();
        text += tr("Fecha: ") + fecha.toString();

        QIcon icon = factura.getEntregada() ? QIcon(":/Icons/Check.png") : QIcon(":/Icons/Cancel.png");
        QListWidgetItem * item = new QListWidgetItem(icon,text);

        listWidget->addItem(item);

    }
}

FormEdicionFacturas::~FormEdicionFacturas()
{
    delete ui;
}

void FormEdicionFacturas::on_pushButton_clicked()
{
    int index = ui->listWidget->currentRow();

    if( (index < 0) or (index > int(facturas.size())) )
        return;

    Factura factura = facturas[index];

    VisorFactura visorFactura(this,factura);
    visorFactura.exec();
}

void FormEdicionFacturas::on_pushButton_2_clicked()
{
    int index = ui->listWidget->currentRow();

    if( (index < 0) or (index > int(facturas.size())) )
        return;

    Factura old_factura = facturas[index];

    if(old_factura.getEntregada())
        return;

    Factura new_factura = facturas[index];
    new_factura.setEntregada(true);

    archivo_factura.modify(old_factura,new_factura);
    facturas[index] = new_factura;

    QListWidgetItem * item = ui->listWidget->item(index);
    item->setIcon(QIcon(":/Icons/Check.png"));
}
