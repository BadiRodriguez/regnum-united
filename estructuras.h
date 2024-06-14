//
// Created by User on 14/06/2024.
//

#ifndef REGNUM_UNITED_ESTRUCTURAS_H
#define REGNUM_UNITED_ESTRUCTURAS_H

#include <iostream>


using namespace std;


class Estructuras{
protected:
    string nombre;
public:
    Estructuras(const string nombre){
        this -> nombre = nombre;
    }

    virtual void imprimirNombre() const {
        cout << "Nombre de la estructura: " << nombre << endl;
    }
};


class Cuevas : public Estructuras {
public:
    Cuevas() : Estructuras("Cuevas") {}
    void imprimirNombre() const override {
        cout << "Hay " << nombre << endl;
    }
};

class Tuneles : public Estructuras {
public:
    Tuneles() : Estructuras("Tuneles") {}
    void imprimirNombre() const override {
        cout << "Hay " << nombre << endl;
    }
};

class Catacumbas : public Estructuras {
public:
    Catacumbas() : Estructuras("Catacumbas") {}
    void imprimirNombre() const override {
        cout << "Hay " << nombre << endl;
    }
};

class Puentes : public Estructuras {
public:
    Puentes() : Estructuras("Puentes") {}
    void imprimirNombre() const override {
        cout << "Hay " << nombre << endl;
    }
};

class CamposAbiertos : public Estructuras {
public:
    CamposAbiertos() : Estructuras("Campos Abiertos") {}
    void imprimirNombre() const override {
        cout << "Hay " << nombre << endl;
    }
};

#endif //REGNUM_UNITED_ESTRUCTURAS_H
