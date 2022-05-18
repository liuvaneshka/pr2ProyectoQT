#ifndef FORMNUEVAPRENDA_H
#define FORMNUEVAPRENDA_H

#include <QDialog>
#include <Class/prenda.h>

#include <File/archivoprenda.h>

namespace Ui {
    class FormNuevaPrenda;
}

class FormNuevaPrenda : public QDialog
{
    Q_OBJECT

    ArchivoPrenda archivo_prenda;

public:
    explicit FormNuevaPrenda(QWidget *parent = 0);
    ~FormNuevaPrenda();

    Prenda getPrenda();

private:
    Ui::FormNuevaPrenda *ui;

    void accept();
};

#endif // FORMNUEVAPRENDA_H
