#include "archivoprenda.h"
#include <cstdlib>

#include <QString>

ArchivoPrenda::ArchivoPrenda() : ArchivoTexto("prendas.txt")
{
    /* ... */
}

Prenda ArchivoPrenda::leer()
{
    string data;

    Prenda prenda;

    getline(file,data,DELIM);
    int codigo = atoi(data.c_str());
    prenda.setCodigo(codigo);

    getline(file,data,DELIM);
    string descripcion = data;
    prenda.setDescripcion(descripcion);

    getline(file,data);
//    float precio = atof(data.c_str());
    float precio = QString::fromStdString(data).toFloat();
//    cout << "precio: " << precio << endl;
    prenda.setPrecio(precio);

    return prenda;
}

void ArchivoPrenda::escribir(Prenda data)
{
    int codigo = data.getCodigo();
    file << codigo << DELIM;

    string descripcion = data.getDescripcion();
    file << descripcion << DELIM;

    float precio = data.getPrecio();
    file << precio << endl;
}

bool ArchivoPrenda::borrar(Prenda data)
{
    bool ret_val = false;

    file.open(filename.c_str(),ios::in);
    string filetmp = filename + ".tmp";
    ofstream out(filetmp.c_str());

    string line;
    getline(file,line);

    while(!file.eof()){

        string substr = line.substr(0,line.find_first_of(DELIM));
        int codigo = atoi(substr.c_str());

        if(codigo != data.getCodigo())
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
