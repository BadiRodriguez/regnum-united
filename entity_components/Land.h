#ifndef LAND_H
#define LAND_H

#include <iostream>
#include <vector>
#include <algorithm>
#include "Combat.h"
#include "Structures.h"
#include "Menu.h"
#include "Character.h"
#include "Monster.h"

class Land {
protected:
    std::string name;
    std::vector<Structures*> structure;
    std::vector<std::string> structureNames;

public:
    explicit Land(std::string name) : name(std::move(name)) {}

    template<typename T>
    void addStructure(const T& a) {
        structure.emplace_back(new T(a));
        structureNames.push_back(a.getName());
    }

    virtual void showMenu(Character &player) {
    }

    virtual ~Land() {
        for (auto& s : structure) {
            delete s;
        }
    }
};

class Necrolimbo : public Land {
private:
    bool catacumbasCleared = false;
public:
    Necrolimbo() : Land("Necrolimbo") {}
    void showMenu(Character &player) override {
        std::vector<std::string> options = structureNames;
        options.push_back("Volver al menú principal"); // Add option to return to main menu

        Menu(options, [&player, this] {
            if (!catacumbasCleared) {
                std::cout << "Entering Catacumbas...\n";
                std::vector<Monster> monsters = {Monster("Goblin", 1, 100, 30, 10, 5, 8, 2, {})}; // Example monsters
                if (normalCombat(player, std::move(monsters))) {
                    catacumbasCleared = true;
                }
            } else {
                std::cout << "Catacumbas already cleared!\n";
            }
        }, []{}, []{}, []{}); // Adjust for the number of structures added
    }
};

class Caelid : public Land {
public:
    Caelid() : Land("Caelid") {}
    void showMenu(Character &player) override {
        std::vector<std::string> options = structureNames;
        options.push_back("Volver al menú principal"); // Add option to return to main menu
        Menu(options, []{}, []{}, []{}, []{}); // Adjust for the number of structures added
    }
};

class Ciudad_Eterna : public Land {
public:
    Ciudad_Eterna() : Land("Ciudad Eterna") {}
    void showMenu(Character &player) override {
        std::vector<std::string> options = structureNames;
        options.push_back("Volver al menú principal"); // Add option to return to main menu
        Menu(options, []{}, []{}, []{}); // Adjust for the number of structures added
    }
};

class Forja_de_gigante : public Land {
public:
    Forja_de_gigante() : Land("Forja de gigante") {}
    void showMenu(Character &player) override {
        std::vector<std::string> options = structureNames;
        options.push_back("Volver al menú principal"); // Add option to return to main menu
        Menu(options, []{}, []{}, []{}); // Adjust for the number of structures added
    }
};

#endif // LAND_H
