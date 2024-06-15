#ifndef REGNUM_UNITED_LAND_H
#define REGNUM_UNITED_LAND_H

#include <iostream>
#include <vector>
#include <algorithm>

#include "Combat.h"
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

    virtual void showMenu(vector<string> &options) {
    };

    virtual ~Land() = default;

    friend std::ostream& operator<<(std::ostream& os, Land& land) {
        os << "Estas en la region de " << land.name << ", con las siguientes estructuras: " << endl;
        vector<string> options(land.structure.size());
        ranges::generate(options, [&, n = 0]() mutable { return land.structure[n++]->getName(); });
        land.showMenu(options);
        return os;
    }
};

class Necrolimbo : public Land {
public:
    Necrolimbo() : Land("Necrolimbo") {}
    void showMenu(vector<string> &options) override {
        Menu(options, [] {
            normalCombat(Character("flauta", 2, 0, 160, 12, 14, 5, 9, 20),
                {Monster("jijija", 1, 25, 10, 10, 4, 8, 9, {}),
                Monster("Popopo", 2, 23, 11, 7, 5, 6, 17, {})});
        }, []{}, []{});
    }
};

class Caelid : public Land {
public:
    Caelid() : Land("Caelid") {}
    void showMenu(vector<string> &options) override {
        Menu(options, []{}, []{}, []{});
    }
};

class Ciudad_Eterna : public Land {
public:
    Ciudad_Eterna() : Land("Ciudad Eterna") {}
    void showMenu(vector<string> &options) override {
        Menu(options, []{}, []{});
    }
};

class Forja_de_gigante : public Land {
public:
    Forja_de_gigante() : Land("Forja de gigante") {}
    void showMenu(vector<string> &options) override {
        Menu(options, []{}, []{});
    }
};

#endif //REGNUM_UNITED_LAND_H
