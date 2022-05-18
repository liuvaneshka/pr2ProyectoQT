#ifndef FORMCEDULACLIENTE_H
#define FORMCEDULACLIENTE_H

#include <QDialog>

#include <string>
using namespace std;

namespace Ui {
    class FormCedulaCliente;
}

class FormCedulaCliente : public QDialog
{
    Q_OBJECT

public:
    explicit FormCedulaCliente(QWidget *parent = 0);
    ~FormCedulaCliente();

    string getCodigoCliente();

private:
    Ui::FormCedulaCliente *ui;
};

#endif // FORMCEDULACLIENTE_H
