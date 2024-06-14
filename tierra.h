//
// Created by User on 14/06/2024.
//

#ifndef REGNUM_UNITED_TIERRA_H
#define REGNUM_UNITED_TIERRA_H

#include <iostream>
#include <vector>
#include "estructuras.h"

using namespace std;

class tierra{
protected:
    string nombre;
    vector<Estructuras*> es;
public:
    tierra(string nombre1){
        this -> nombre = nombre1;
    };

    template<typename T>

    void agregarEstructura(const T a){
        es.emplace_back(new T(a));
    }

    void imprimirEstructuras() const {
        for (const auto& estructura : es) {
            estructura->imprimirNombre();
        }
    }

    virtual void descripcion() const {
        cout << "Descripción de " << nombre << endl;
    }

};

class Necrolimbo : public tierra{
public:
    Necrolimbo() : tierra("Necrolimbo"){}
    void descripcion() const override {
        cout << "Estas en la region de " << nombre << ", conocida por su neblina perpetua." << endl;
    }
};

class Caelid : public tierra{
public:
    Caelid() : tierra("Caelid"){}
    void descripcion() const override {
        cout << "Estas en la region de " << nombre << ", conocida por su desolacion." << endl;
    }
};

class Ciudad_Eterna : public tierra{
public:
    Ciudad_Eterna() : tierra("Ciudad Eterna"){}
    void descripcion() const override {
        cout << "Estas en la region de " << nombre << ", conocida por su arquitectura eterna." << endl;
    }
};

class Forja_de_gigante : public tierra{
public:
    Forja_de_gigante(): tierra("Forja de gigante"){}
    void descripcion() const override {
        cout << "Estas en la region de " << nombre << ", conocida por su forja inmensa." << endl;
    }
};


#endif //REGNUM_UNITED_TIERRA_H
