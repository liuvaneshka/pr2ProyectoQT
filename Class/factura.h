#ifndef FACTURA_H
#define FACTURA_H

#include <iva.h>
#include <string>
#include <vector>
using namespace std;

#include <QDate>

class Factura
{
    int codigo;
    QDate fecha;
    bool entregada;
    string codigo_cliente;
    vector<int> codigos_prendas;
    vector<int> cantidades_prendas;
    float subtotal;

public:
    Factura();

    /* Setters */
    void setCodigo(int codigo);
    void setEntregada(bool entregada);
    void setSubtotal(float subtotal);
    void setCodigoCliente(string codigo_cliente);
    void setCodigosPrendas(vector<int> codigos_prendas);
    void setCantidadesPrendas(vector<int> cantidades_prendas);
    void setFecha(QDate fecha);

    /* Getters */
    int getCodigo();
    bool getEntregada();
    float getSubtotal();
    string getCodigoCliente();
    vector<int> getCodigosPrendas();
    vector<int> getCantidadesPrendas();
    QDate getFecha();

    bool operator == (Factura f){
        return f.codigo == codigo;
    }
};

#endif // FACTURA_H
