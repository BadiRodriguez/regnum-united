#ifndef REGNUM_UNITED_LAND_H
#define REGNUM_UNITED_LAND_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include "Structures.h"
#include "Menu.h"

using namespace std;

class Land {
protected:
    string name;
    vector<Structures*> structure;

public:
    explicit Land(string name) : name(std::move(name)) {}

    template<typename T>
    void addStructure(const T a) {
        structure.emplace_back(new T(a));
    }

    void showMenu() const {
        vector<string> options(structure.size());
        std::generate(options.begin(), options.end(), [&, n = 0]() mutable { return structure[n++]->getName(); });

        vector<std::function<void()>> funcs(structure.size());
        std::generate(funcs.begin(), funcs.end(), [&, n = 0]() mutable {
            return [this, index = n++]() { structure[index]->printName(); };
        });

        Menu(options, funcs);
    }

    virtual ~Land() = default;

    friend std::ostream& operator<<(std::ostream& os, const Land& land) {
        os << "Estas en la region de " << land.name << ", con las siguientes estructuras: " << endl;
        land.showMenu();
        return os;
    }
};

class Necrolimbo : public Land {
public:
    Necrolimbo() : Land("Necrolimbo") {}
};

class Caelid : public Land {
public:
    Caelid() : Land("Caelid") {}
};

class Ciudad_Eterna : public Land {
public:
    Ciudad_Eterna() : Land("Ciudad Eterna") {}
};

class Forja_de_gigante : public Land {
public:
    Forja_de_gigante() : Land("Forja de gigante") {}
};

#endif //REGNUM_UNITED_LAND_H
