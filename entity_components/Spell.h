#ifndef SPELL_H
#define SPELL_H

#include <string>
#include <functional>
#include "Entity.h"

class Spell {
private:
    std::string name;
    std::string elementalType;
    std::function<void(Entity&, Entity&)> formula;
    bool heals;

public:
    Spell(std::string name, std::string elementalType, std::function<void(Entity&, Entity&)> formula, bool heals = false);

    void use(Entity &user, Entity &target) const;
    std::string getName() const;
    std::string getElementalType() const;
};

#endif // SPELL_H
