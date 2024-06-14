// Let us cook

#ifndef SPELL_H
#define SPELL_H

#include <string>
#include <functional>
#include "Character.h"

class Spell {
public:
    Spell(std::string name, std::string elementalType, std::function<void(Character&, Character&)> formula, bool heals = false);

    const std::string &getName() const;
    const std::string &getElementalType() const;
    void use(Character &user, Character &target) const;

private:
    std::string name;
    std::string elementalType;
    std::function<void(Character&, Character&)> formula;
    bool heals;
};

#endif // SPELL_H
