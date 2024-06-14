//
// Created by User on 14/06/2024.
//

#ifndef REGNUM_UNITED_STRUCTURES_H
#define REGNUM_UNITED_STRUCTURES_H

#include <iostream>


using namespace std;


class Structures{
protected:
    string name;
public:
    explicit Structures(const string& name){
        this -> name = name;
    }

    virtual void printName() const {
        cout << "Name of the structure: " << name << endl;
    }
};


class Cuevas : public Structures {
public:
    Cuevas() : Structures("Cuevas") {}
    void printName() const override {
        cout << "Hay " << name << endl;
    }
};

class Tuneles : public Structures {
public:
    Tuneles() : Structures("Tuneles") {}
    void printName() const override {
        cout << "Hay " << name << endl;
    }
};

class Catacumbas : public Structures {
public:
    Catacumbas() : Structures("Catacumbas") {}
    void printName() const override {
        cout << "Hay " << name << endl;
    }
};

class Puentes : public Structures {
public:
    Puentes() : Structures("Puentes") {}
    void printName() const override {
        cout << "Hay " << name << endl;
    }
};

class CamposAbiertos : public Structures {
public:
    CamposAbiertos() : Structures("Campos Abiertos") {}
    void printName() const override {
        cout << "Hay " << name << endl;
    }
};

#endif //REGNUM_UNITED_STRUCTURES_H
