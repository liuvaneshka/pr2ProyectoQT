#include "visorfactura.h"
#include "ui_visorfactura.h"

#include <QPrinter>
#include <QPrintDialog>

#include <QFile>
#include <QTextStream>

VisorFactura::VisorFactura(QWidget *parent, Factura factura) :
    QDialog(parent),
    ui(new Ui::VisorFactura)
{
    ui->setupUi(this);

    //-----------------------------------------------
    QTextEdit * textEdit = ui->textEdit;
    cursor = textEdit->textCursor();

    QFile file(":formato_factura.html");
    file.open(QIODevice::ReadOnly);

    QTextStream stream(&file);
    QString html = stream.readAll();

    textEdit->setHtml(html);
    //-----------------------------------------------

    construirFactura(factura);
}

VisorFactura::~VisorFactura()
{
    delete ui;
}

void VisorFactura::imprimirCliente(string codigo_cliente)
{
    QString html = ui->textEdit->toHtml();

    Cliente cliente;
    cliente.setCodigo(codigo_cliente);

    archivo_clientes.search(cliente);

    string codigo = cliente.getCodigo();
    html.replace("CODIGO_CLIENTE",QString::fromStdString(codigo));

    string nombre = cliente.getNombre() + ", " + cliente.getApellido();
    html.replace("NOMBRE_CLIENTE",QString::fromStdString(nombre));

    string direccion = cliente.getDireccion();
    html.replace("DIRECCION_CLIENTE",QString::fromStdString(direccion));

    ui->textEdit->setHtml(html);
}

void VisorFactura::facturaEntregada(bool entregada)
{
    QString text;
    if(entregada){
        cursor.insertImage(QImage(":Icons/Check.png"));
        text = "Factura Entregada";
    }
    else{
        cursor.insertImage(QImage(":Icons/Cancel.png"));
        text = "No Entregada";
    }

    cursor.insertText(text);
    bloques(4);
}

void VisorFactura::crearTablaPrendas()
{
    int filas = 1;
    int columnas = 5;

    table = cursor.insertTable(filas,columnas);

    QTextTableFormat format;
    format.setAlignment(Qt::AlignHCenter);
    format.setBorder(0.2);
    format.setWidth(QTextLength(QTextLength::PercentageLength,80));
    table->setFormat(format);

    // Titulos
    cursor = table->cellAt(0,0).firstCursorPosition();
    cursor.insertText(tr("Codigo"));

    cursor = table->cellAt(0,1).firstCursorPosition();
    cursor.insertText(tr("Descripcion"));

    cursor = table->cellAt(0,2).firstCursorPosition();
    cursor.insertText(tr("Precio"));

    cursor = table->cellAt(0,3).firstCursorPosition();
    cursor.insertText(tr("Cantidad"));

    cursor = table->cellAt(0,4).firstCursorPosition();
    cursor.insertText(tr("Monto"));
}

void VisorFactura::agregarPrenda(Prenda prenda, int cantidad)
{
    int row = table->rows();
    table->appendRows(1);

    cursor = table->cellAt(row,0).firstCursorPosition();
    cursor.insertText(QString::number(prenda.getCodigo()));

    cursor = table->cellAt(row,1).firstCursorPosition();
    cursor.insertText(QString::fromStdString(prenda.getDescripcion()));

    cursor = table->cellAt(row,2).firstCursorPosition();
    cursor.insertText(QString::number(prenda.getPrecio()));

    cursor = table->cellAt(row,3).firstCursorPosition();
    cursor.insertText(QString::number(cantidad));

    cursor = table->cellAt(row,4).firstCursorPosition();
    cursor.insertText(QString::number(cantidad*prenda.getPrecio()));
}

void VisorFactura::imprimirTotales(float subtotal)
{
    int filas = 3;
    int columnas = 2;
    table = cursor.insertTable(filas,columnas);

    QTextTableFormat format;
    format.setAlignment(Qt::AlignRight);
    format.setBorder(0.2);
    format.setWidth(QTextLength(QTextLength::PercentageLength,40));
    format.setRightMargin(75);
    table->setFormat(format);

    cursor = table->cellAt(0,0).firstCursorPosition();
    cursor.insertText(tr("SubTotal: "));

    cursor = table->cellAt(0,1).firstCursorPosition();
    cursor.insertText(QString::number(subtotal));

    cursor = table->cellAt(1,0).firstCursorPosition();
    cursor.insertText(tr("IVA: "));

    float iva = subtotal*IVA;
    cursor = table->cellAt(1,1).firstCursorPosition();
    cursor.insertText(QString::number(iva));

    cursor = table->cellAt(2,0).firstCursorPosition();
    cursor.insertText(tr("Total: "));

    float total = subtotal+iva;
    cursor = table->cellAt(2,1).firstCursorPosition();
    cursor.insertText(QString::number(total));

}

void VisorFactura::construirFactura(Factura factura)
{

    /* . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . */
    /*
     *   Numero de Recibo
     */
    QString html = ui->textEdit->toHtml();
    int codigo = factura.getCodigo();
    html.replace("NUMERO_RECIBO",QString::number(codigo));
    ui->textEdit->setHtml(html);
    /* . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . */


    /* . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . */
    /*
     *   Fecha de Recibo
     */
    QDate fecha = factura.getFecha();
    html.replace("FECHA_RECIBO",fecha.toString());
    ui->textEdit->setHtml(html);
    /* . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . */


    /* . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . */
    /*
     *   Entregada
     */
//    factura.setEntregada(true);
    bool entregada = factura.getEntregada();
    facturaEntregada(entregada);
    /* . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . */


    /* . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . */
    /*
     *   Cliente
     */
    imprimirCliente(factura.getCodigoCliente());
    /* . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . */


    /* . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . */
    /*
     *   Prendas
     */
    crearTablaPrendas();

    vector<int> codigos_prendas = factura.getCodigosPrendas();
    vector<int> cantidades_prendas = factura.getCantidadesPrendas();

    for( size_t i = 0 ; i < codigos_prendas.size() ; i++ ){

        int codigo_prenda = codigos_prendas[i];
        int cantidad = cantidades_prendas[i];

        Prenda prenda;
        prenda.setCodigo(codigo_prenda);

        archivo_prendas.search(prenda);

        agregarPrenda(prenda,cantidad);
    }
    /* . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . */

    cursor.movePosition(QTextCursor::End);
    bloques(3);

    /* . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . */
    /*
     *   Sub Total
     */
    float subtotal = factura.getSubtotal();
    imprimirTotales(subtotal);
    /* . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . */

    cursor.movePosition(QTextCursor::End);
    bloques(3);
}

void VisorFactura::on_printButton_clicked()
{
    QPrinter printer;

    QPrintDialog dialog(&printer,this);

    if(dialog.exec() != QDialog::Accepted)
        return;

    ui->textEdit->print(&printer);
}
