#ifndef FORMSELECCIONPRENDA_H
#define FORMSELECCIONPRENDA_H

#include <QDialog>

#include <vector>
using namespace std;

#include <Class/prenda.h>

namespace Ui {
    class FormSeleccionPrenda;
}

class FormSeleccionPrenda : public QDialog
{
    Q_OBJECT

    vector<Prenda> prendas;

public:
    FormSeleccionPrenda(QWidget *parent,vector<Prenda> prendas);
    ~FormSeleccionPrenda();

    Prenda getPrenda();
    int getCantidad();

private:
    Ui::FormSeleccionPrenda *ui;
};

#endif // FORMSELECCIONPRENDA_H
