#ifndef ARCHIVOTEXTO_H
#define ARCHIVOTEXTO_H

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#define DELIM '|'

template <class T>
class ArchivoTexto
{

protected:
    string filename;
    fstream file;

public:
    ArchivoTexto(string filename = "data.txt")
    {
        this->filename = filename;

        file.open(filename.c_str(),ios::in|ios::out);

        if(!file.is_open()) // file doesn't exist?
            // create it!
            file.open(filename.c_str(),ios::out|ios::app);

        file.close();
    }

    ~ArchivoTexto(){
        if(file.is_open())
            file.close();
    }

    bool insert(T data)
    {
        file.open(filename.c_str(),ios::out|ios::app);

        if(!file)
            return false;

        escribir(data);

        file.close();
        return true;
    }

    bool search(T & data)
    {
        file.open(filename.c_str(),ios::in);

        if(!file)
            return false;

        T tmp = leer();

        while(!file.eof()){    

            if( tmp == data ){

                data = tmp;

                file.close();
                return true;
            }

            tmp = leer();

        }

        file.close();
        return false;
    }

    bool modify(T & old_data, T & new_data)
    {
        if(borrar(old_data))
            return insert(new_data);
        return false;
    }

    vector<T> toVector(){

        vector<T> array;

        file.open(filename.c_str(),ios::in);

        T tmp = leer();

        while(!file.eof()){

            array.push_back(tmp);
            tmp = leer();

        }

        return array;
    }

    int size()
    {
        file.open(filename.c_str(),ios::in);
        int tam = 0;

        leer();

        while(!file.eof()){
            tam++;
            leer();
        }

        file.close();
        return tam;
    }

protected:
    virtual T leer() = 0;
    virtual void escribir(T data) = 0;
    virtual bool borrar(T data) = 0;

};

#endif // ARCHIVOTEXTO_H
