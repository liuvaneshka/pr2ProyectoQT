#include "factura.h"

Factura::Factura()
{
    entregada = false;
    subtotal = 0;
    codigo_cliente = "";
}

void Factura::setCodigo(int codigo)
{
    this->codigo = codigo;
}

void Factura::setEntregada(bool entregada)
{
    this->entregada = entregada;
}

void Factura::setSubtotal(float subtotal)
{
    this->subtotal = subtotal;
}

void Factura::setCodigoCliente(string codigo_cliente)
{
    this->codigo_cliente = codigo_cliente;
}

void Factura::setCodigosPrendas(vector<int> codigos_prendas)
{
    this->codigos_prendas = codigos_prendas;
}

void Factura::setCantidadesPrendas(vector<int> cantidades_prendas)
{
    this->cantidades_prendas = cantidades_prendas;
}

void Factura::setFecha(QDate fecha)
{
    this->fecha = fecha;
}

int Factura::getCodigo()
{
    return codigo;
}

bool Factura::getEntregada()
{
    return entregada;
}

float Factura::getSubtotal()
{
    return subtotal;
}

string Factura::getCodigoCliente()
{
    return codigo_cliente;
}

vector<int> Factura::getCodigosPrendas()
{
    return codigos_prendas;
}

vector<int> Factura::getCantidadesPrendas()
{
    return cantidades_prendas;
}

QDate Factura::getFecha()
{
    return fecha;
}
