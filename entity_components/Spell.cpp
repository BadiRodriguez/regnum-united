//
// Created by Badi on 6/14/2024.
//

#include "Spell.h"

#include <utility>

Spell::Spell(std::string name, std::string elementalType, std::function<void(Entity&, Entity&)> formula, bool heals)
        : name(std::move(name)), elementalType(std::move(elementalType)), formula(std::move(formula)), heals(heals) {}

const std::string &Spell::getName() const {
    return name;
}

const std::string &Spell::getElementalType() const {
    return elementalType;
}

void Spell::use(Entity &user, Entity &target) const {
    formula(user, target);
}
