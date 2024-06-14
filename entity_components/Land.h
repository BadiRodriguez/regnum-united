//
// Created by User on 14/06/2024.
//

#ifndef REGNUM_UNITED_LAND_H
#define REGNUM_UNITED_LAND_H

#include <iostream>
#include <vector>
#include <memory>
#include "Structures.h"

using namespace std;

class Land {
protected:
    string name;
    vector<unique_ptr<Structures>> structures;
public:
    explicit Land(string name) : name(move(name)) {}

    template<typename T, typename... Args>
    void addStructure(Args&&... args) {
        structures.emplace_back(make_unique<T>(forward<Args>(args)...));
    }

    void printStructures() const {
        for (const auto& structure : structures) {
            structure->printName();
        }
    }

    virtual void describe() const {
        cout << "Descripción de " << name << endl;
    }

    virtual ~Land() = default;
};

class Necrolimbo : public Land {
public:
    Necrolimbo() : Land("Necrolimbo") {}
    void describe() const override {
        cout << "Estas en la región de " << name << ", conocida por su neblina perpetua." << endl;
    }
};

class Caelid : public Land {
public:
    Caelid() : Land("Caelid") {}
    void describe() const override {
        cout << "Estas en la región de " << name << ", conocida por su desolación." << endl;
    }
};

class Ciudad_Eterna : public Land {
public:
    Ciudad_Eterna() : Land("Ciudad Eterna") {}
    void describe() const override {
        cout << "Estas en la región de " << name << ", conocida por su arquitectura eterna." << endl;
    }
};

class Forja_de_gigante : public Land {
public:
    Forja_de_gigante() : Land("Forja de gigante") {}
    void describe() const override {
        cout << "Estas en la región de " << name << ", conocida por su forja inmensa." << endl;
    }
};

#endif //REGNUM_UNITED_LAND_H
