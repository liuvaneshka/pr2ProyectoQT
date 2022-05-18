#include "archivofactura.h"
#include <cstdlib>
#include <sstream>

ArchivoFactura::ArchivoFactura() : ArchivoTexto("facturas.txt")
{
    /* ... */
}

Factura ArchivoFactura::leer()
{

    string data;

    Factura factura;

    getline(file,data,DELIM);
    int codigo = atoi(data.c_str());
    factura.setCodigo(codigo);

    getline(file,data,DELIM);
    bool entregada = (bool)(atoi(data.c_str()));
    factura.setEntregada(entregada);

    getline(file,data,DELIM);
    QDate fecha = QDate::fromString(QString::fromStdString(data));
    factura.setFecha(fecha);

    getline(file,data,DELIM);
//    float subtotal = atof(data.c_str());
    float subtotal = QString::fromStdString(data).toFloat();
    factura.setSubtotal(subtotal);

    getline(file,data,DELIM);
    string codigo_cliente = data;
    factura.setCodigoCliente(codigo_cliente);

    getline(file,data,DELIM);
    stringstream stream(data);

    vector<int> codigos_prendas;

    int codigo_prenda;
    while(stream >> codigo_prenda)
        codigos_prendas.push_back(codigo_prenda);

    factura.setCodigosPrendas(codigos_prendas);

    getline(file,data);
    stringstream stream2(data);

    vector<int> cantidades_prendas;

    int cantidad_prenda;
    while(stream2 >> cantidad_prenda)
        cantidades_prendas.push_back(cantidad_prenda);

    factura.setCantidadesPrendas(cantidades_prendas);

    return factura;
}

void ArchivoFactura::escribir(Factura data)
{
    int codigo = data.getCodigo();
    file << codigo << DELIM;

    bool entregada = data.getEntregada();
    file << entregada << DELIM;

    QDate fecha = data.getFecha();
    file << fecha.toString().toStdString() << DELIM;

    float subtotal = data.getSubtotal();
    file << subtotal << DELIM;

    string codigo_cliente = data.getCodigoCliente();
    file << codigo_cliente << DELIM;

    vector<int> codigos_prendas = data.getCodigosPrendas();
    for(size_t i = 0 ; i < codigos_prendas.size() ; i++)
        file << codigos_prendas[i] << " ";
    file << DELIM;

    vector<int> cantidades_prendas = data.getCantidadesPrendas();
    for(size_t i = 0 ; i < cantidades_prendas.size() ; i++)
        file << cantidades_prendas[i] << " ";
    file << endl;
}

bool ArchivoFactura::borrar(Factura data)
{
    bool ret_val = false;

    file.open(filename.c_str(),ios::in);

    string filetmp = filename + ".tmp";
    ofstream out(filetmp.c_str());

    string line;
    getline(file,line);

    while(!file.eof()){

        string codigo = line.substr(0,line.find_first_of(DELIM));
        int codigo_factura = atoi(codigo.c_str());

        if(codigo_factura != data.getCodigo())
            out << line << endl;
        else
            ret_val = true;

        getline(file,line);
    }

    out.close();
    file.close();

    remove(filename.c_str());
    rename(filetmp.c_str(),filename.c_str());

    return ret_val;
}
