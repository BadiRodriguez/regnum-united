//
// Created by User on 14/06/2024.
//

#ifndef REGNUM_UNITED_LAND_H
#define REGNUM_UNITED_LAND_H

#include <iostream>
#include <vector>
#include "Structures.h"

using namespace std;

class Land{
protected:
    string name;
    vector<Structures*> structure;
public:
    explicit Land(string name){
        this -> name = std::move(name);
    };

    template<typename T>

    void addStructure(const T a){
        structure.emplace_back(new T(a));
    }

    void printStructures() const {
        for (const auto& estructura : structure) {
            estructura->printName();
        }
    }

    virtual void describe() const {
        cout << "Descripción de " << name << endl;
    }

};

class Necrolimbo : public Land{
public:
    Necrolimbo() : Land("Necrolimbo"){}
    void describe() const override {
        cout << "Estas en la region de " << name << ", conocida por su neblina perpetua." << endl;
    }
};

class Caelid : public Land{
public:
    Caelid() : Land("Caelid"){}
    void describe() const override {
        cout << "Estas en la region de " << name << ", conocida por su desolacion." << endl;
    }
};

class Ciudad_Eterna : public Land{
public:
    Ciudad_Eterna() : Land("Ciudad Eterna"){}
    void describe() const override {
        cout << "Estas en la region de " << name << ", conocida por su arquitectura eterna." << endl;
    }
};

class Forja_de_gigante : public Land{
public:
    Forja_de_gigante(): Land("Forja de gigante"){}
    void describe() const override {
        cout << "Estas en la region de " << name << ", conocida por su forja inmensa." << endl;
    }
};


#endif //REGNUM_UNITED_LAND_H
