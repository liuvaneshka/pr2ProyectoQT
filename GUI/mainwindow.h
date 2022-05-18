#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <File/archivocliente.h>
#include <File/archivoprenda.h>
#include <File/archivofactura.h>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    ArchivoCliente archivo_clientes;
    ArchivoPrenda archivo_prendas;
    ArchivoFactura archivo_facturas;

public:
    MainWindow();
    ~MainWindow();

private slots:
    void on_actionNuevo_triggered();
    void on_actionNueva_Prenda_triggered();
    void on_actionModificar_Datos_Cliente_triggered();
    void on_actionNuevoServicioLavanderia_triggered();
    void on_actionBuscar_Factura_triggered();

private:
    Ui::MainWindow *ui;

    void centerWindow();
};

#endif // MAINWINDOW_H
