// Let us cook

#ifndef SPELL_H
#define SPELL_H

#include <string>
#include <functional>
#include "Character.h"
#include "Demigod.h"

class Character; // Forward declaration
class Demigod; // Forward declaration

class Spell {
public:
    Spell(std::string name, std::string elementalType, std::function<void(Entity&, Entity&)> formula, bool heals = false);

    const std::string &getName() const;
    const std::string &getElementalType() const;
    void use(Entity &user, Entity &target) const;

private:
    std::string name;
    std::string elementalType;
    std::function<void(Entity&, Entity&)> formula;
    bool heals;
};

#endif // SPELL_H
