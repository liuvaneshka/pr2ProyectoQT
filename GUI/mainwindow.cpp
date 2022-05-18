#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <GUI/formdatoscliente.h>
#include <GUI/formcedulacliente.h>
#include <GUI/formregistrarprendas.h>
#include <GUI/formnuevaprenda.h>
#include <GUI/formbuscarfactura.h>
#include <GUI/visorfactura.h>
#include <GUI/formedicionfacturas.h>

#include <QDebug>
#include <QMessageBox>

MainWindow::MainWindow() :
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // center on screen
    centerWindow();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionNuevo_triggered()
{
    FormDatosCliente form(this);

    if(form.exec() != QDialog::Accepted)
        return;

    Cliente cliente = form.getCliente();

    QString message;

    if(archivo_clientes.search(cliente))
        message = tr("Cliente ya existe");
    else if( archivo_clientes.insert(cliente) )
        message = tr("Cliente insertado correctamente");
    else
        message = tr("No se puede almacenar el cliente");

    // Ventana de Informacion
    QMessageBox::information(this,
                             trUtf8("Información"),
                             message,
                             QMessageBox::Ok);
}

void MainWindow::on_actionNueva_Prenda_triggered()
{
    FormNuevaPrenda form(this);

    if(form.exec() != QDialog::Accepted)
        return;

    Prenda prenda = form.getPrenda();
    archivo_prendas.insert(prenda);
}

void MainWindow::centerWindow()
{
    QSize desktop = QApplication::desktop()->size();

    int x = ( desktop.width() - width()) / 2;
    int y = ( desktop.height() - height()) / 2;

    setGeometry(x,y,width(),height());
}

void MainWindow::on_actionModificar_Datos_Cliente_triggered()
{

    FormCedulaCliente formCedula(this);

    if(formCedula.exec() != QDialog::Accepted)
        return;

    string codigo = formCedula.getCodigoCliente();

    Cliente cliente;
    cliente.setCodigo(codigo);

    if(!archivo_clientes.search(cliente)){
        QMessageBox::information(this,tr("information"),
                                 tr("Cliente no encontrado"),QMessageBox::Ok);
        return;
    }

    FormDatosCliente form(this,cliente);

    if(form.exec() != QDialog::Accepted)
        return;

    Cliente cliente_nuevo = form.getCliente();
    archivo_clientes.modify(cliente,cliente_nuevo);

}

void MainWindow::on_actionNuevoServicioLavanderia_triggered()
{
    FormCedulaCliente form(this);

    if(form.exec() != QDialog::Accepted)
        return;

    string codigo = form.getCodigoCliente();

    Cliente cliente;
    cliente.setCodigo(codigo);

    if( !archivo_clientes.search(cliente) ){

        // No Encontrado
        // Entonces Crearlo

        FormDatosCliente formCliente(this);

        if(formCliente.exec() != QDialog::Accepted)
            return;

        cliente = formCliente.getCliente();

        if(archivo_clientes.search(cliente)){

            // cliente ya existe

            QMessageBox::information(this,
                                     trUtf8("Información"),
                                     tr("Cliente ya existe"),
                                     QMessageBox::Ok);
            return;
        }

        archivo_clientes.insert(cliente);

    }

    FormRegistrarPrendas formPrendas(this,cliente);

    if(formPrendas.exec() != QDialog::Accepted)
        return;

    int codigo_factura = archivo_facturas.size();

    Factura factura = formPrendas.getFactura();
    factura.setCodigo(codigo_factura);

    archivo_facturas.insert(factura);

    // Generar Recibo Factura
    VisorFactura visorFactura(this,factura);
    visorFactura.exec();

}

void MainWindow::on_actionBuscar_Factura_triggered()
{
    FormBuscarFactura form(this);

    if(form.exec() != QDialog::Accepted)
        return;

    vector<Factura> facturas = form.getFacturas();

    if(facturas.empty())
    {
        QMessageBox::information(this,
                                 tr("informacion"),
                                 tr("No se han encontrado facturas "
                                    "con el criterio de bsuqueda..."),
                                 QMessageBox::Ok);
        return;
    }

    /* . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . */

    // Aqui se deben mostrar las facturas encontradas
    // Y poder seleccionar alguna para colocarla como
    // entregada...

    /* . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . */

    FormEdicionFacturas formEdicionFacturas(this,facturas);
    formEdicionFacturas.exec();

}
